/* SCAPAttributeSupplierBindingProxy.cpp
   Generated by gSOAP 2.8.28 from SCAP-Services.h

gSOAP XML Web services tools
Copyright (C) 2000-2016, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#include "SCAPAttributeSupplierBindingProxy.h"

AttributeSupplierBindingProxy::AttributeSupplierBindingProxy()
{	this->soap = soap_new();
	this->soap_own = true;
	AttributeSupplierBindingProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

AttributeSupplierBindingProxy::AttributeSupplierBindingProxy(const AttributeSupplierBindingProxy& rhs)
{	this->soap = rhs.soap;
	this->soap_own = false;
	this->soap_endpoint = rhs.soap_endpoint;
}

AttributeSupplierBindingProxy::AttributeSupplierBindingProxy(struct soap *_soap)
{	this->soap = _soap;
	this->soap_own = false;
	AttributeSupplierBindingProxy_init(_soap->imode, _soap->omode);
}

AttributeSupplierBindingProxy::AttributeSupplierBindingProxy(const char *url)
{	this->soap = soap_new();
	this->soap_own = true;
	AttributeSupplierBindingProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
	soap_endpoint = url;
}

AttributeSupplierBindingProxy::AttributeSupplierBindingProxy(soap_mode iomode)
{	this->soap = soap_new();
	this->soap_own = true;
	AttributeSupplierBindingProxy_init(iomode, iomode);
}

AttributeSupplierBindingProxy::AttributeSupplierBindingProxy(const char *url, soap_mode iomode)
{	this->soap = soap_new();
	this->soap_own = true;
	AttributeSupplierBindingProxy_init(iomode, iomode);
	soap_endpoint = url;
}

AttributeSupplierBindingProxy::AttributeSupplierBindingProxy(soap_mode imode, soap_mode omode)
{	this->soap = soap_new();
	this->soap_own = true;
	AttributeSupplierBindingProxy_init(imode, omode);
}

AttributeSupplierBindingProxy::~AttributeSupplierBindingProxy()
{	if (this->soap_own)
		soap_free(this->soap);
}

void AttributeSupplierBindingProxy::AttributeSupplierBindingProxy_init(soap_mode imode, soap_mode omode)
{	soap_imode(this->soap, imode);
	soap_omode(this->soap, omode);
	soap_endpoint = NULL;
	static const struct Namespace namespaces[] =
{
	{"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
	{"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"ns4", "http://www.cartaodecidadao.pt/ccc/commons/messages/Types", NULL, NULL},
	{"xop", "http://www.w3.org/2004/08/xop/include", NULL, NULL},
	{"xmime5", "http://www.w3.org/2005/05/xmlmime", "http://www.w3.org/2004/11/xmlmime", NULL},
	{"ns5", "http://www.w3.org/2000/09/xmldsig#", NULL, NULL},
	{"ns3", "http://www.cartaodecidadao.pt/ccc/commons/messages/Attribute", NULL, NULL},
	{"ns6", "http://uri.etsi.org/01903/v1.3.2#", NULL, NULL},
	{"ns7", "http://www.cartaodecidadao.pt/ccc/commons/messages/SVG", NULL, NULL},
	{"wsa", "http://schemas.xmlsoap.org/ws/2004/08/addressing", NULL, NULL},
	{"ns1", "http://www.cartaodecidadao.pt/ccc/sccc/services/AttributeClientService", NULL, NULL},
	{"ns2", "http://www.cartaodecidadao.pt/ccc/sccc/messages/AttributeClientService", NULL, NULL},
	{"ns8", "http://www.cartaodecidadao.pt/ccc/sccc/services/AttributeSupplierService", NULL, NULL},
	{"ns9", "http://www.cartaodecidadao.pt/ccc/sccc/messages/AttributeSupplierService", NULL, NULL},
	{"pdf", "http://www.cartaodecidadao.pt/ccc/sccc/services/PDFSignature", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};
	soap_set_namespaces(this->soap, namespaces);
}

#ifndef WITH_PURE_VIRTUAL
AttributeSupplierBindingProxy *AttributeSupplierBindingProxy::copy()
{	AttributeSupplierBindingProxy *dup = SOAP_NEW_COPY(AttributeSupplierBindingProxy);
	if (dup)
		soap_copy_context(dup->soap, this->soap);
	return dup;
}
#endif

AttributeSupplierBindingProxy& AttributeSupplierBindingProxy::operator=(const AttributeSupplierBindingProxy& rhs)
{	if (this->soap_own)
		soap_free(this->soap);
	this->soap = rhs.soap;
	this->soap_own = false;
	this->soap_endpoint = rhs.soap_endpoint;
	return *this;
}

void AttributeSupplierBindingProxy::destroy()
{	soap_destroy(this->soap);
	soap_end(this->soap);
}

void AttributeSupplierBindingProxy::reset()
{	this->destroy();
	soap_done(this->soap);
	soap_initialize(this->soap);
	AttributeSupplierBindingProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

void AttributeSupplierBindingProxy::soap_noheader()
{	this->soap->header = NULL;
}

void AttributeSupplierBindingProxy::soap_header(char *wsa__MessageID, struct wsa__Relationship *wsa__RelatesTo, struct wsa__EndpointReferenceType *wsa__From, struct wsa__EndpointReferenceType *wsa__ReplyTo, struct wsa__EndpointReferenceType *wsa__FaultTo, char *wsa__To, char *wsa__Action)
{	::soap_header(this->soap);
	this->soap->header->wsa__MessageID = wsa__MessageID;
	this->soap->header->wsa__RelatesTo = wsa__RelatesTo;
	this->soap->header->wsa__From = wsa__From;
	this->soap->header->wsa__ReplyTo = wsa__ReplyTo;
	this->soap->header->wsa__FaultTo = wsa__FaultTo;
	this->soap->header->wsa__To = wsa__To;
	this->soap->header->wsa__Action = wsa__Action;
}

const SOAP_ENV__Header *AttributeSupplierBindingProxy::soap_header()
{	return this->soap->header;
}

const SOAP_ENV__Fault *AttributeSupplierBindingProxy::soap_fault()
{	return this->soap->fault;
}

const char *AttributeSupplierBindingProxy::soap_fault_string()
{	return *soap_faultstring(this->soap);
}

const char *AttributeSupplierBindingProxy::soap_fault_detail()
{	return *soap_faultdetail(this->soap);
}

int AttributeSupplierBindingProxy::soap_close_socket()
{	return soap_closesock(this->soap);
}

int AttributeSupplierBindingProxy::soap_force_close_socket()
{	return soap_force_closesock(this->soap);
}

void AttributeSupplierBindingProxy::soap_print_fault(FILE *fd)
{	::soap_print_fault(this->soap, fd);
}

#ifndef WITH_LEAN
#ifndef WITH_COMPAT
void AttributeSupplierBindingProxy::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this->soap, os);
}
#endif

char *AttributeSupplierBindingProxy::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this->soap, buf, len);
}
#endif

int AttributeSupplierBindingProxy::AttributeSuppliers(const char *endpoint, const char *soap_action, ns9__AttributeSupplierResponseType &ns9__AttributeSupplierResponse)
{	struct soap *soap = this->soap;
	struct __ns8__AttributeSuppliers soap_tmp___ns8__AttributeSuppliers;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://preprod.scap.autenticacao.gov.pt/DSS/ASService";
	if (soap_action == NULL)
		soap_action = "http://www.cartaodecidadao.pt/CCC/Attribute/AttributeSupplier/services/AttributeSupplierService/AttributeSupplierList";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize___ns8__AttributeSuppliers(soap, &soap_tmp___ns8__AttributeSuppliers);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns8__AttributeSuppliers(soap, &soap_tmp___ns8__AttributeSuppliers, "-ns8:AttributeSuppliers", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns8__AttributeSuppliers(soap, &soap_tmp___ns8__AttributeSuppliers, "-ns8:AttributeSuppliers", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&ns9__AttributeSupplierResponse)
		return soap_closesock(soap);
	ns9__AttributeSupplierResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns9__AttributeSupplierResponse.soap_get(soap, "ns9:AttributeSupplierResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}
/* End of client proxy code */
