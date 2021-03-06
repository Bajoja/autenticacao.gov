/*-****************************************************************************

 * Copyright (C) 2017-2019 Adriano Campos - <adrianoribeirocampos@gmail.com>
 * Copyright (C) 2017 André Guerreiro - <aguerreiro1985@gmail.com>
 * Copyright (C) 2019 João Pinheiro - <joao.pinheiro@caixamagica.pt>
 * Copyright (C) 2019 Miguel Figueira - <miguelblcfigueira@gmail.com>
 *
 * Licensed under the EUPL V.1.2

****************************************************************************-*/

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include <QIcon>
#include <QProcess>
#include "appcontroller.h"
#include "gapi.h"
#include "eidlib.h"
#include "singleapplication.h"
#include <QDesktopWidget> 
#include <QCommandLineParser> 
#include "pteidversions.h"

using namespace eIDMW;

int main(int argc, char *argv[])
{
    int retValue = 0;

    AppController::initApplicationScale();

	PTEID_InitSDK();

	// GUISettings init
	GUISettings settings;
	// AppController init
	AppController controller(settings);

	if (settings.getGraphicsAccel() == 0)
	{
		qDebug() << "C++: Starting App without graphics acceleration";
		QCoreApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);
	}
#ifdef WIN32
	else if (settings.getGraphicsAccel() == 2) {
		qDebug() << "C++: Starting App with ANGLE emulation for OpenGL";
		QCoreApplication::setAttribute(Qt::AA_UseOpenGLES);
	}
#endif
	else
	{
		qDebug() << "C++: Starting App with graphics acceleration";
	}

	SingleApplication app(argc, argv);

	app.setOrganizationName("Portuguese State");
	app.setApplicationVersion(settings.getGuiVersion() + " - " + REVISION_NUM_STRING + " [ " + REVISION_HASH_STRING + " ]");

	// Set app icon
	app.setWindowIcon(QIcon(":/appicon.ico"));

	QQuickStyle::setStyle("Material");
	//QQuickStyle::setStyle("Universal");
	//QQuickStyle::setStyle("Default");

    QQmlApplicationEngine *engine = new QQmlApplicationEngine();

    PTEID_Config sam_server(PTEID_PARAM_GENERAL_SAM_SERVER);

    // GAPI init
    GAPI gapi;
    GAPI::declareQMLTypes();

    // Default is production mode
    PTEID_Config::SetTestMode(false);
    sam_server.setString("pki.cartaodecidadao.pt:443");

    // Parse command line arguments
    QCommandLineParser parser;
    const char *signSimpleDescription = "open application in Simple Signature submenu.";
    const char *signAdvancedDescription = "open application in Advanced Signature submenu.";
    QString modeDescription("Mode of the application. Possible values are:\n ");
    modeDescription.append("\"\" (empty): default mode\n");
    modeDescription.append("\"signSimple\": ").append(signSimpleDescription).append("\n");
    modeDescription.append("\"signAdvanced\": ").append(signAdvancedDescription);
    parser.addPositionalArgument("mode", modeDescription);

    const QCommandLineOption helpOption = parser.addHelpOption();
    const QCommandLineOption versionOption = parser.addVersionOption();
    const QCommandLineOption testModeOption(QStringList() << "t" << "test", "Enable test mode");
    parser.addOption(testModeOption);

    parser.parse(QCoreApplication::arguments());

    if (parser.isSet(versionOption)) {
        gapi.quitApplication();
        PTEID_ReleaseSDK();
        parser.showVersion();
    }

    if (parser.isSet(testModeOption))
    {
        PTEID_Config::SetTestMode(true);
        sam_server.setString("pki.teste.cartaodecidadao.pt:443");
        settings.setTestMode(true);
        qDebug() << "Starting App in test mode";
    }

    QStringList args = parser.positionalArguments();
    const QString mode = args.isEmpty() ? QString() : args.first();
    if (mode == "")
    {
        if(!parser.parse(QCoreApplication::arguments())) {
            qDebug() << "ERROR: default no-arguments mode: " << parser.errorText().toStdString().c_str();
            gapi.quitApplication();
            PTEID_ReleaseSDK();
            exit(1);
        }

        if (parser.isSet(helpOption)) {
            gapi.quitApplication();
            PTEID_ReleaseSDK();
            parser.showHelp();
        }
    }
    else if (mode == "signAdvanced" || mode == "signSimple")
    {
        parser.clearPositionalArguments();
        parser.addPositionalArgument(mode, (mode == "signSimple" ? signSimpleDescription : signAdvancedDescription));
        QString inputDescription((mode == "signSimple" ? "File " : "List of files "));
        inputDescription.append("to be loaded for signing.");
        parser.addPositionalArgument("input", inputDescription);

        const QCommandLineOption timestampingOption("tsa", "Check timestamping");
        const QCommandLineOption reasonOption(QStringList() << "m" << "motivo", "Set default reason", "reason");
        const QCommandLineOption locationOption(QStringList() << "l" << "localidade", "Set default location", "location");
        if (mode == "signAdvanced")
        {
            parser.addOption(timestampingOption);
            parser.addOption(reasonOption);
            parser.addOption(locationOption);
        }

        const QCommandLineOption outputOption(QStringList() << "d" << "destino", "Set output folder", "output");
        parser.addOption(outputOption);

        if(!parser.parse(QCoreApplication::arguments())) {
            qDebug() << "ERROR: " << mode << ": " << parser.errorText().toStdString().c_str();
            gapi.quitApplication();
            PTEID_ReleaseSDK();
            exit(1);
        }

        if (parser.isSet(helpOption)) {
            gapi.quitApplication();
            PTEID_ReleaseSDK();
            parser.showHelp();
        }

        args = parser.positionalArguments(); // some option values were interpreted as positional args before. call this again
        if (args.size() < 2)
        {
            qDebug() << "ERROR: " << mode << ": " << "No input files were provided.";
            gapi.quitApplication();
            PTEID_ReleaseSDK();
            exit(1);
        }
        for (int i = 1; i < args.size(); i++)
        {
            if (QFileInfo::exists(args[i])){
                qDebug() << "Adding file: " << args[i];
                gapi.addShortcutPath(args[i]);
            }else
            {
                qDebug() << "ERROR: Cannot load file for signature. File/folder does not exist: " << args[i];
                gapi.quitApplication();
                PTEID_ReleaseSDK();
                exit(1);
            }
        }

        if (mode == "signAdvanced")
        {
            gapi.setShortcutFlag(GAPI::ShortcutIdSignAdvanced);
            gapi.setShortcutTsa(parser.isSet(timestampingOption));
            gapi.setShortcutReason(parser.value(reasonOption));
            gapi.setShortcutLocation(parser.value(locationOption));
        } else {
            if (args.size() != 2)
            {
                qDebug() << "ERROR: signSimple can only take one file as input.";
                gapi.quitApplication();
                PTEID_ReleaseSDK();
                exit(1);
            }
            
            gapi.setShortcutFlag(GAPI::ShortcutIdSignSimple);
        }
        
        if (parser.isSet(outputOption) && !QFileInfo::exists(parser.value(outputOption)))
        {
            qDebug() << "ERROR: File/folder does not exist for output folder: " << parser.value(outputOption);
            gapi.quitApplication();
            PTEID_ReleaseSDK();
            exit(1);
        }
        gapi.setShortcutOutput(parser.value(outputOption));
    }
    else
    {
        qDebug() << "ERROR: Unknown mode: " << mode;
        gapi.quitApplication();
        PTEID_ReleaseSDK();
        exit(1);
    }

    // Embedding C++ Objects into QML with Context Properties
    QQmlContext* ctx = engine->rootContext();
    ctx->setContextProperty("gapi", &gapi);
    ctx->setContextProperty("controler", &controller);
    ctx->setContextProperty("image_provider_pdf", gapi.image_provider_pdf);

    engine->addImageProvider("myimageprovider", gapi.buildImageProvider());
    engine->addImageProvider("pdfpreview_imageprovider", gapi.buildPdfImageProvider());

    // Load translation files
    gapi.initTranslation();
    controller.initTranslation();

    // Load main QML file
    engine->load(QUrl(QStringLiteral("qrc:/main.qml")));

    // Each starting instance will make the running instance to restore.
    QObject::connect(
        &app,
        &SingleApplication::instanceStarted,
        &controller,
        &AppController::restoreScreen);

    retValue = app.exec();

    PTEID_ReleaseSDK();

    if (retValue == RESTART_EXIT_CODE) {
        QProcess proc;
        QString cmd("\"");
        for (QString arg : QCoreApplication::arguments()) {
            cmd.append(arg).append(" ");
        }
        cmd = cmd.remove(cmd.length()-1,1); // remove last space
        cmd.append("\"");
        if (!proc.startDetached(cmd)){
            qDebug() << "Error restarting application: could not start process.";
        }
    }

    return retValue;
}
