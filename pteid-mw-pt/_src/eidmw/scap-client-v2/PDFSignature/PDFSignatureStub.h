/* PDFSignatureStub.h
   Generated by gSOAP 2.8.28 from SCAP-PDFSignature.h

gSOAP XML Web services tools
Copyright (C) 2000-2016, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#include <deque>
#include <list>
#include <vector>
#include <set>
#define SOAP_NAMESPACE_OF_ns1	"http://www.cartaodecidadao.pt/ccc/sccc/services/PDFSignature"

#ifndef PDFSignatureStub_H
#define PDFSignatureStub_H
#ifndef WITH_NOGLOBAL
#define WITH_NOGLOBAL
#endif
#include "stdsoap2.h"
#if GSOAP_VERSION != 20828
# error "GSOAP VERSION 20828 MISMATCH IN GENERATED CODE VERSUS LIBRARY CODE: PLEASE REINSTALL PACKAGE"
#endif


namespace PDFSignature {

/******************************************************************************\
 *                                                                            *
 * Enumerations                                                               *
 *                                                                            *
\******************************************************************************/


/* SCAP-PDFSignature.h:203 */
#ifndef SOAP_TYPE_PDFSignature_ns1__SignatureOrientationEnumType
#define SOAP_TYPE_PDFSignature_ns1__SignatureOrientationEnumType (29)
/* ns1:SignatureOrientationEnumType */
enum ns1__SignatureOrientationEnumType
{
	ns1__SignatureOrientationEnumType__LANDSCAPE = 0,
	ns1__SignatureOrientationEnumType__PORTRAIT = 1
};
#endif

/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Classes, Structs, and Unions                                               *
 *                                                                            *
\******************************************************************************/

class xsd__base64Binary;	/* SCAP-PDFSignature.h:140 */
class ns1__SignRequest;	/* SCAP-PDFSignature.h:159 */
class ns1__PersonalDataType;	/* SCAP-PDFSignature.h:162 */
class ns1__AttributeListType;	/* SCAP-PDFSignature.h:165 */
class ns1__AttributeType;	/* SCAP-PDFSignature.h:168 */
class ns1__AttributeSupplierType;	/* SCAP-PDFSignature.h:171 */
class ns1__MainAttributeType;	/* SCAP-PDFSignature.h:174 */
class ns1__LegalActListType;	/* SCAP-PDFSignature.h:177 */
class ns1__SubAttributeListType;	/* SCAP-PDFSignature.h:180 */
class ns1__SubAttributeType;	/* SCAP-PDFSignature.h:183 */
class ns1__SignResponse;	/* SCAP-PDFSignature.h:186 */
class ns1__Status;	/* SCAP-PDFSignature.h:189 */
struct __ns1__Sign;	/* SCAP-PDFSignature.h:630 */

/* SCAP-PDFSignature.h:140 */
#ifndef SOAP_TYPE_PDFSignature_xsd__base64Binary
#define SOAP_TYPE_PDFSignature_xsd__base64Binary (11)
/* base64Binary schema type: */
class SOAP_CMAC xsd__base64Binary
{
public:
	unsigned char *__ptr;
	int __size;
	char *id;	/* optional element of XSD type xsd:string */
	char *type;	/* optional element of XSD type xsd:string */
	char *options;	/* optional element of XSD type xsd:string */
	struct soap *soap;	/* transient (not serialized) */
public:
	/// Return the unique type ID value SOAP_TYPE_PDFSignature_xsd__base64Binary (11)
	virtual int soap_type(void) const { return 11; }
	/// Set object's data members to default values
	virtual void soap_default(struct soap*);
	/// Serialize object to prepare for SOAP 1.1/1.2 encoded output (or with SOAP_XML_GRAPH) by analyzing its (cyclic) structures
	virtual void soap_serialize(struct soap*) const;
	/// Output object in XML, compliant with SOAP 1.1 encoding style, return error code or SOAP_OK
	virtual int soap_put(struct soap*, const char *tag, const char *type) const;
	/// Output object in XML, with tag and optional id attribute and xsi:type, return error code or SOAP_OK
	virtual int soap_out(struct soap*, const char *tag, int id, const char *type) const;
	/// Get object from XML, compliant with SOAP 1.1 encoding style, return pointer to object or NULL on error
	virtual void *soap_get(struct soap*, const char *tag, const char *type);
	/// Get object from XML, with matching tag and type (NULL matches any tag and type), return pointer to object or NULL on error
	virtual void *soap_in(struct soap*, const char *tag, const char *type);
	/// Return a new object of type xsd__base64Binary, default initialized and not managed by a soap context
	virtual xsd__base64Binary *soap_alloc(void) const { return SOAP_NEW(xsd__base64Binary); }
	         xsd__base64Binary() { xsd__base64Binary::soap_default(NULL); }
	virtual ~xsd__base64Binary() { }
	friend SOAP_FMAC1 xsd__base64Binary * SOAP_FMAC2 soap_instantiate_xsd__base64Binary(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* SCAP-PDFSignature.h:159 */
#ifndef SOAP_TYPE_PDFSignature_ns1__SignRequest
#define SOAP_TYPE_PDFSignature_ns1__SignRequest (18)
/* ns1:SignRequest complex type: */
class SOAP_CMAC ns1__SignRequest
{
public:
	std::string ProcessId;	/* required element of XSD type xsd:string */
	ns1__PersonalDataType *PersonalData;	/* required element of XSD type ns1:PersonalDataType */
	ns1__AttributeListType *AttributeList;	/* required element of XSD type ns1:AttributeListType */
	std::string SignatureFieldName;	/* required element of XSD type xsd:string */
	xsd__base64Binary SignDocument;	/* required element of XSD type xsd:base64Binary */
	int *LTV;	/* optional element of XSD type xsd:int */
	int Page;	/* required element of XSD type xsd:int */
	int X;	/* required element of XSD type xsd:int */
	int Y;	/* required element of XSD type xsd:int */
	enum ns1__SignatureOrientationEnumType Orientation;	/* required element of XSD type ns1:SignatureOrientationEnumType */
	struct soap *soap;	/* transient (not serialized) */
public:
	/// Return the unique type ID value SOAP_TYPE_PDFSignature_ns1__SignRequest (18)
	virtual int soap_type(void) const { return 18; }
	/// Set object's data members to default values
	virtual void soap_default(struct soap*);
	/// Serialize object to prepare for SOAP 1.1/1.2 encoded output (or with SOAP_XML_GRAPH) by analyzing its (cyclic) structures
	virtual void soap_serialize(struct soap*) const;
	/// Output object in XML, compliant with SOAP 1.1 encoding style, return error code or SOAP_OK
	virtual int soap_put(struct soap*, const char *tag, const char *type) const;
	/// Output object in XML, with tag and optional id attribute and xsi:type, return error code or SOAP_OK
	virtual int soap_out(struct soap*, const char *tag, int id, const char *type) const;
	/// Get object from XML, compliant with SOAP 1.1 encoding style, return pointer to object or NULL on error
	virtual void *soap_get(struct soap*, const char *tag, const char *type);
	/// Get object from XML, with matching tag and type (NULL matches any tag and type), return pointer to object or NULL on error
	virtual void *soap_in(struct soap*, const char *tag, const char *type);
	/// Return a new object of type ns1__SignRequest, default initialized and not managed by a soap context
	virtual ns1__SignRequest *soap_alloc(void) const { return SOAP_NEW(ns1__SignRequest); }
	         ns1__SignRequest() { ns1__SignRequest::soap_default(NULL); }
	virtual ~ns1__SignRequest() { }
	friend SOAP_FMAC1 ns1__SignRequest * SOAP_FMAC2 soap_instantiate_ns1__SignRequest(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* SCAP-PDFSignature.h:162 */
#ifndef SOAP_TYPE_PDFSignature_ns1__PersonalDataType
#define SOAP_TYPE_PDFSignature_ns1__PersonalDataType (19)
/* ns1:PersonalDataType complex type: */
class SOAP_CMAC ns1__PersonalDataType
{
public:
	std::string Name;	/* required element of XSD type xsd:string */
	std::string NIC;	/* required element of XSD type xsd:string */
	struct soap *soap;	/* transient (not serialized) */
public:
	/// Return the unique type ID value SOAP_TYPE_PDFSignature_ns1__PersonalDataType (19)
	virtual int soap_type(void) const { return 19; }
	/// Set object's data members to default values
	virtual void soap_default(struct soap*);
	/// Serialize object to prepare for SOAP 1.1/1.2 encoded output (or with SOAP_XML_GRAPH) by analyzing its (cyclic) structures
	virtual void soap_serialize(struct soap*) const;
	/// Output object in XML, compliant with SOAP 1.1 encoding style, return error code or SOAP_OK
	virtual int soap_put(struct soap*, const char *tag, const char *type) const;
	/// Output object in XML, with tag and optional id attribute and xsi:type, return error code or SOAP_OK
	virtual int soap_out(struct soap*, const char *tag, int id, const char *type) const;
	/// Get object from XML, compliant with SOAP 1.1 encoding style, return pointer to object or NULL on error
	virtual void *soap_get(struct soap*, const char *tag, const char *type);
	/// Get object from XML, with matching tag and type (NULL matches any tag and type), return pointer to object or NULL on error
	virtual void *soap_in(struct soap*, const char *tag, const char *type);
	/// Return a new object of type ns1__PersonalDataType, default initialized and not managed by a soap context
	virtual ns1__PersonalDataType *soap_alloc(void) const { return SOAP_NEW(ns1__PersonalDataType); }
	         ns1__PersonalDataType() { ns1__PersonalDataType::soap_default(NULL); }
	virtual ~ns1__PersonalDataType() { }
	friend SOAP_FMAC1 ns1__PersonalDataType * SOAP_FMAC2 soap_instantiate_ns1__PersonalDataType(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* SCAP-PDFSignature.h:165 */
#ifndef SOAP_TYPE_PDFSignature_ns1__AttributeListType
#define SOAP_TYPE_PDFSignature_ns1__AttributeListType (20)
/* ns1:AttributeListType complex type: */
class SOAP_CMAC ns1__AttributeListType
{
public:
	std::vector<ns1__AttributeType *> Attribute;	/* required element of XSD type ns1:AttributeType */
	struct soap *soap;	/* transient (not serialized) */
public:
	/// Return the unique type ID value SOAP_TYPE_PDFSignature_ns1__AttributeListType (20)
	virtual int soap_type(void) const { return 20; }
	/// Set object's data members to default values
	virtual void soap_default(struct soap*);
	/// Serialize object to prepare for SOAP 1.1/1.2 encoded output (or with SOAP_XML_GRAPH) by analyzing its (cyclic) structures
	virtual void soap_serialize(struct soap*) const;
	/// Output object in XML, compliant with SOAP 1.1 encoding style, return error code or SOAP_OK
	virtual int soap_put(struct soap*, const char *tag, const char *type) const;
	/// Output object in XML, with tag and optional id attribute and xsi:type, return error code or SOAP_OK
	virtual int soap_out(struct soap*, const char *tag, int id, const char *type) const;
	/// Get object from XML, compliant with SOAP 1.1 encoding style, return pointer to object or NULL on error
	virtual void *soap_get(struct soap*, const char *tag, const char *type);
	/// Get object from XML, with matching tag and type (NULL matches any tag and type), return pointer to object or NULL on error
	virtual void *soap_in(struct soap*, const char *tag, const char *type);
	/// Return a new object of type ns1__AttributeListType, default initialized and not managed by a soap context
	virtual ns1__AttributeListType *soap_alloc(void) const { return SOAP_NEW(ns1__AttributeListType); }
	         ns1__AttributeListType() { ns1__AttributeListType::soap_default(NULL); }
	virtual ~ns1__AttributeListType() { }
	friend SOAP_FMAC1 ns1__AttributeListType * SOAP_FMAC2 soap_instantiate_ns1__AttributeListType(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* SCAP-PDFSignature.h:168 */
#ifndef SOAP_TYPE_PDFSignature_ns1__AttributeType
#define SOAP_TYPE_PDFSignature_ns1__AttributeType (21)
/* ns1:AttributeType complex type: */
class SOAP_CMAC ns1__AttributeType
{
public:
	ns1__AttributeSupplierType *AttributeSupplier;	/* required element of XSD type ns1:AttributeSupplierType */
	ns1__MainAttributeType *MainAttribute;	/* required element of XSD type ns1:MainAttributeType */
	struct soap *soap;	/* transient (not serialized) */
public:
	/// Return the unique type ID value SOAP_TYPE_PDFSignature_ns1__AttributeType (21)
	virtual int soap_type(void) const { return 21; }
	/// Set object's data members to default values
	virtual void soap_default(struct soap*);
	/// Serialize object to prepare for SOAP 1.1/1.2 encoded output (or with SOAP_XML_GRAPH) by analyzing its (cyclic) structures
	virtual void soap_serialize(struct soap*) const;
	/// Output object in XML, compliant with SOAP 1.1 encoding style, return error code or SOAP_OK
	virtual int soap_put(struct soap*, const char *tag, const char *type) const;
	/// Output object in XML, with tag and optional id attribute and xsi:type, return error code or SOAP_OK
	virtual int soap_out(struct soap*, const char *tag, int id, const char *type) const;
	/// Get object from XML, compliant with SOAP 1.1 encoding style, return pointer to object or NULL on error
	virtual void *soap_get(struct soap*, const char *tag, const char *type);
	/// Get object from XML, with matching tag and type (NULL matches any tag and type), return pointer to object or NULL on error
	virtual void *soap_in(struct soap*, const char *tag, const char *type);
	/// Return a new object of type ns1__AttributeType, default initialized and not managed by a soap context
	virtual ns1__AttributeType *soap_alloc(void) const { return SOAP_NEW(ns1__AttributeType); }
	         ns1__AttributeType() { ns1__AttributeType::soap_default(NULL); }
	virtual ~ns1__AttributeType() { }
	friend SOAP_FMAC1 ns1__AttributeType * SOAP_FMAC2 soap_instantiate_ns1__AttributeType(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* SCAP-PDFSignature.h:171 */
#ifndef SOAP_TYPE_PDFSignature_ns1__AttributeSupplierType
#define SOAP_TYPE_PDFSignature_ns1__AttributeSupplierType (22)
/* ns1:AttributeSupplierType complex type: */
class SOAP_CMAC ns1__AttributeSupplierType
{
public:
	std::string Id;	/* required element of XSD type xsd:anyURI */
	std::string Name;	/* required element of XSD type xsd:string */
	std::string *Type;	/* optional element of XSD type xsd:string */
	struct soap *soap;	/* transient (not serialized) */
public:
	/// Return the unique type ID value SOAP_TYPE_PDFSignature_ns1__AttributeSupplierType (22)
	virtual int soap_type(void) const { return 22; }
	/// Set object's data members to default values
	virtual void soap_default(struct soap*);
	/// Serialize object to prepare for SOAP 1.1/1.2 encoded output (or with SOAP_XML_GRAPH) by analyzing its (cyclic) structures
	virtual void soap_serialize(struct soap*) const;
	/// Output object in XML, compliant with SOAP 1.1 encoding style, return error code or SOAP_OK
	virtual int soap_put(struct soap*, const char *tag, const char *type) const;
	/// Output object in XML, with tag and optional id attribute and xsi:type, return error code or SOAP_OK
	virtual int soap_out(struct soap*, const char *tag, int id, const char *type) const;
	/// Get object from XML, compliant with SOAP 1.1 encoding style, return pointer to object or NULL on error
	virtual void *soap_get(struct soap*, const char *tag, const char *type);
	/// Get object from XML, with matching tag and type (NULL matches any tag and type), return pointer to object or NULL on error
	virtual void *soap_in(struct soap*, const char *tag, const char *type);
	/// Return a new object of type ns1__AttributeSupplierType, default initialized and not managed by a soap context
	virtual ns1__AttributeSupplierType *soap_alloc(void) const { return SOAP_NEW(ns1__AttributeSupplierType); }
	         ns1__AttributeSupplierType() { ns1__AttributeSupplierType::soap_default(NULL); }
	virtual ~ns1__AttributeSupplierType() { }
	friend SOAP_FMAC1 ns1__AttributeSupplierType * SOAP_FMAC2 soap_instantiate_ns1__AttributeSupplierType(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* SCAP-PDFSignature.h:174 */
#ifndef SOAP_TYPE_PDFSignature_ns1__MainAttributeType
#define SOAP_TYPE_PDFSignature_ns1__MainAttributeType (23)
/* ns1:MainAttributeType complex type: */
class SOAP_CMAC ns1__MainAttributeType
{
public:
	std::string AttributeID;	/* required element of XSD type xsd:string */
	std::string *Description;	/* optional element of XSD type xsd:string */
	ns1__LegalActListType *LegalActList;	/* optional element of XSD type ns1:LegalActListType */
	ns1__SubAttributeListType *SubAttributeList;	/* optional element of XSD type ns1:SubAttributeListType */
	struct soap *soap;	/* transient (not serialized) */
public:
	/// Return the unique type ID value SOAP_TYPE_PDFSignature_ns1__MainAttributeType (23)
	virtual int soap_type(void) const { return 23; }
	/// Set object's data members to default values
	virtual void soap_default(struct soap*);
	/// Serialize object to prepare for SOAP 1.1/1.2 encoded output (or with SOAP_XML_GRAPH) by analyzing its (cyclic) structures
	virtual void soap_serialize(struct soap*) const;
	/// Output object in XML, compliant with SOAP 1.1 encoding style, return error code or SOAP_OK
	virtual int soap_put(struct soap*, const char *tag, const char *type) const;
	/// Output object in XML, with tag and optional id attribute and xsi:type, return error code or SOAP_OK
	virtual int soap_out(struct soap*, const char *tag, int id, const char *type) const;
	/// Get object from XML, compliant with SOAP 1.1 encoding style, return pointer to object or NULL on error
	virtual void *soap_get(struct soap*, const char *tag, const char *type);
	/// Get object from XML, with matching tag and type (NULL matches any tag and type), return pointer to object or NULL on error
	virtual void *soap_in(struct soap*, const char *tag, const char *type);
	/// Return a new object of type ns1__MainAttributeType, default initialized and not managed by a soap context
	virtual ns1__MainAttributeType *soap_alloc(void) const { return SOAP_NEW(ns1__MainAttributeType); }
	         ns1__MainAttributeType() { ns1__MainAttributeType::soap_default(NULL); }
	virtual ~ns1__MainAttributeType() { }
	friend SOAP_FMAC1 ns1__MainAttributeType * SOAP_FMAC2 soap_instantiate_ns1__MainAttributeType(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* SCAP-PDFSignature.h:177 */
#ifndef SOAP_TYPE_PDFSignature_ns1__LegalActListType
#define SOAP_TYPE_PDFSignature_ns1__LegalActListType (24)
/* ns1:LegalActListType complex type: */
class SOAP_CMAC ns1__LegalActListType
{
public:
	std::vector<std::string> LegalAct;	/* required element of XSD type xsd:string */
	struct soap *soap;	/* transient (not serialized) */
public:
	/// Return the unique type ID value SOAP_TYPE_PDFSignature_ns1__LegalActListType (24)
	virtual int soap_type(void) const { return 24; }
	/// Set object's data members to default values
	virtual void soap_default(struct soap*);
	/// Serialize object to prepare for SOAP 1.1/1.2 encoded output (or with SOAP_XML_GRAPH) by analyzing its (cyclic) structures
	virtual void soap_serialize(struct soap*) const;
	/// Output object in XML, compliant with SOAP 1.1 encoding style, return error code or SOAP_OK
	virtual int soap_put(struct soap*, const char *tag, const char *type) const;
	/// Output object in XML, with tag and optional id attribute and xsi:type, return error code or SOAP_OK
	virtual int soap_out(struct soap*, const char *tag, int id, const char *type) const;
	/// Get object from XML, compliant with SOAP 1.1 encoding style, return pointer to object or NULL on error
	virtual void *soap_get(struct soap*, const char *tag, const char *type);
	/// Get object from XML, with matching tag and type (NULL matches any tag and type), return pointer to object or NULL on error
	virtual void *soap_in(struct soap*, const char *tag, const char *type);
	/// Return a new object of type ns1__LegalActListType, default initialized and not managed by a soap context
	virtual ns1__LegalActListType *soap_alloc(void) const { return SOAP_NEW(ns1__LegalActListType); }
	         ns1__LegalActListType() { ns1__LegalActListType::soap_default(NULL); }
	virtual ~ns1__LegalActListType() { }
	friend SOAP_FMAC1 ns1__LegalActListType * SOAP_FMAC2 soap_instantiate_ns1__LegalActListType(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* SCAP-PDFSignature.h:180 */
#ifndef SOAP_TYPE_PDFSignature_ns1__SubAttributeListType
#define SOAP_TYPE_PDFSignature_ns1__SubAttributeListType (25)
/* ns1:SubAttributeListType complex type: */
class SOAP_CMAC ns1__SubAttributeListType
{
public:
	std::vector<ns1__SubAttributeType *> SubAttribute;	/* required element of XSD type ns1:SubAttributeType */
	struct soap *soap;	/* transient (not serialized) */
public:
	/// Return the unique type ID value SOAP_TYPE_PDFSignature_ns1__SubAttributeListType (25)
	virtual int soap_type(void) const { return 25; }
	/// Set object's data members to default values
	virtual void soap_default(struct soap*);
	/// Serialize object to prepare for SOAP 1.1/1.2 encoded output (or with SOAP_XML_GRAPH) by analyzing its (cyclic) structures
	virtual void soap_serialize(struct soap*) const;
	/// Output object in XML, compliant with SOAP 1.1 encoding style, return error code or SOAP_OK
	virtual int soap_put(struct soap*, const char *tag, const char *type) const;
	/// Output object in XML, with tag and optional id attribute and xsi:type, return error code or SOAP_OK
	virtual int soap_out(struct soap*, const char *tag, int id, const char *type) const;
	/// Get object from XML, compliant with SOAP 1.1 encoding style, return pointer to object or NULL on error
	virtual void *soap_get(struct soap*, const char *tag, const char *type);
	/// Get object from XML, with matching tag and type (NULL matches any tag and type), return pointer to object or NULL on error
	virtual void *soap_in(struct soap*, const char *tag, const char *type);
	/// Return a new object of type ns1__SubAttributeListType, default initialized and not managed by a soap context
	virtual ns1__SubAttributeListType *soap_alloc(void) const { return SOAP_NEW(ns1__SubAttributeListType); }
	         ns1__SubAttributeListType() { ns1__SubAttributeListType::soap_default(NULL); }
	virtual ~ns1__SubAttributeListType() { }
	friend SOAP_FMAC1 ns1__SubAttributeListType * SOAP_FMAC2 soap_instantiate_ns1__SubAttributeListType(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* SCAP-PDFSignature.h:183 */
#ifndef SOAP_TYPE_PDFSignature_ns1__SubAttributeType
#define SOAP_TYPE_PDFSignature_ns1__SubAttributeType (26)
/* ns1:SubAttributeType complex type: */
class SOAP_CMAC ns1__SubAttributeType
{
public:
	std::string AttributeID;	/* required element of XSD type xsd:string */
	std::string *Description;	/* optional element of XSD type xsd:string */
	std::string *Value;	/* optional element of XSD type xsd:string */
	ns1__LegalActListType *LegalActList;	/* optional element of XSD type ns1:LegalActListType */
	std::string *Type;	/* optional element of XSD type xsd:string */
	struct soap *soap;	/* transient (not serialized) */
public:
	/// Return the unique type ID value SOAP_TYPE_PDFSignature_ns1__SubAttributeType (26)
	virtual int soap_type(void) const { return 26; }
	/// Set object's data members to default values
	virtual void soap_default(struct soap*);
	/// Serialize object to prepare for SOAP 1.1/1.2 encoded output (or with SOAP_XML_GRAPH) by analyzing its (cyclic) structures
	virtual void soap_serialize(struct soap*) const;
	/// Output object in XML, compliant with SOAP 1.1 encoding style, return error code or SOAP_OK
	virtual int soap_put(struct soap*, const char *tag, const char *type) const;
	/// Output object in XML, with tag and optional id attribute and xsi:type, return error code or SOAP_OK
	virtual int soap_out(struct soap*, const char *tag, int id, const char *type) const;
	/// Get object from XML, compliant with SOAP 1.1 encoding style, return pointer to object or NULL on error
	virtual void *soap_get(struct soap*, const char *tag, const char *type);
	/// Get object from XML, with matching tag and type (NULL matches any tag and type), return pointer to object or NULL on error
	virtual void *soap_in(struct soap*, const char *tag, const char *type);
	/// Return a new object of type ns1__SubAttributeType, default initialized and not managed by a soap context
	virtual ns1__SubAttributeType *soap_alloc(void) const { return SOAP_NEW(ns1__SubAttributeType); }
	         ns1__SubAttributeType() { ns1__SubAttributeType::soap_default(NULL); }
	virtual ~ns1__SubAttributeType() { }
	friend SOAP_FMAC1 ns1__SubAttributeType * SOAP_FMAC2 soap_instantiate_ns1__SubAttributeType(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* SCAP-PDFSignature.h:186 */
#ifndef SOAP_TYPE_PDFSignature_ns1__SignResponse
#define SOAP_TYPE_PDFSignature_ns1__SignResponse (27)
/* ns1:SignResponse complex type: */
class SOAP_CMAC ns1__SignResponse
{
public:
	std::string ProcessId;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of XSD type xsd:string */
	ns1__Status *Status;	/* required element of XSD type ns1:Status */
	xsd__base64Binary *SignedDocument;	/* optional element of XSD type xsd:base64Binary */
	struct soap *soap;	/* transient (not serialized) */
public:
	/// Return the unique type ID value SOAP_TYPE_PDFSignature_ns1__SignResponse (27)
	virtual int soap_type(void) const { return 27; }
	/// Set object's data members to default values
	virtual void soap_default(struct soap*);
	/// Serialize object to prepare for SOAP 1.1/1.2 encoded output (or with SOAP_XML_GRAPH) by analyzing its (cyclic) structures
	virtual void soap_serialize(struct soap*) const;
	/// Output object in XML, compliant with SOAP 1.1 encoding style, return error code or SOAP_OK
	virtual int soap_put(struct soap*, const char *tag, const char *type) const;
	/// Output object in XML, with tag and optional id attribute and xsi:type, return error code or SOAP_OK
	virtual int soap_out(struct soap*, const char *tag, int id, const char *type) const;
	/// Get object from XML, compliant with SOAP 1.1 encoding style, return pointer to object or NULL on error
	virtual void *soap_get(struct soap*, const char *tag, const char *type);
	/// Get object from XML, with matching tag and type (NULL matches any tag and type), return pointer to object or NULL on error
	virtual void *soap_in(struct soap*, const char *tag, const char *type);
	/// Return a new object of type ns1__SignResponse, default initialized and not managed by a soap context
	virtual ns1__SignResponse *soap_alloc(void) const { return SOAP_NEW(ns1__SignResponse); }
	         ns1__SignResponse() { ns1__SignResponse::soap_default(NULL); }
	virtual ~ns1__SignResponse() { }
	friend SOAP_FMAC1 ns1__SignResponse * SOAP_FMAC2 soap_instantiate_ns1__SignResponse(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* SCAP-PDFSignature.h:189 */
#ifndef SOAP_TYPE_PDFSignature_ns1__Status
#define SOAP_TYPE_PDFSignature_ns1__Status (28)
/* ns1:Status complex type: */
class SOAP_CMAC ns1__Status
{
public:
	std::string Code;	/* required element of XSD type xsd:string */
	std::string Message;	/* required element of XSD type xsd:string */
	std::string *Field;	/* optional element of XSD type xsd:string */
	std::string *FieldValue;	/* optional element of XSD type xsd:string */
	struct soap *soap;	/* transient (not serialized) */
public:
	/// Return the unique type ID value SOAP_TYPE_PDFSignature_ns1__Status (28)
	virtual int soap_type(void) const { return 28; }
	/// Set object's data members to default values
	virtual void soap_default(struct soap*);
	/// Serialize object to prepare for SOAP 1.1/1.2 encoded output (or with SOAP_XML_GRAPH) by analyzing its (cyclic) structures
	virtual void soap_serialize(struct soap*) const;
	/// Output object in XML, compliant with SOAP 1.1 encoding style, return error code or SOAP_OK
	virtual int soap_put(struct soap*, const char *tag, const char *type) const;
	/// Output object in XML, with tag and optional id attribute and xsi:type, return error code or SOAP_OK
	virtual int soap_out(struct soap*, const char *tag, int id, const char *type) const;
	/// Get object from XML, compliant with SOAP 1.1 encoding style, return pointer to object or NULL on error
	virtual void *soap_get(struct soap*, const char *tag, const char *type);
	/// Get object from XML, with matching tag and type (NULL matches any tag and type), return pointer to object or NULL on error
	virtual void *soap_in(struct soap*, const char *tag, const char *type);
	/// Return a new object of type ns1__Status, default initialized and not managed by a soap context
	virtual ns1__Status *soap_alloc(void) const { return SOAP_NEW(ns1__Status); }
	         ns1__Status() { ns1__Status::soap_default(NULL); }
	virtual ~ns1__Status() { }
	friend SOAP_FMAC1 ns1__Status * SOAP_FMAC2 soap_instantiate_ns1__Status(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* SCAP-PDFSignature.h:630 */
#ifndef SOAP_TYPE_PDFSignature___ns1__Sign
#define SOAP_TYPE_PDFSignature___ns1__Sign (48)
/* Operation wrapper: */
struct __ns1__Sign
{
public:
	ns1__SignRequest *ns1__SignRequest_;	/* optional element of XSD type ns1:SignRequest */
public:
	int soap_type() const { return 48; } /* = unique type id SOAP_TYPE_PDFSignature___ns1__Sign */
	         __ns1__Sign();
	friend SOAP_FMAC1 __ns1__Sign * SOAP_FMAC2 soap_instantiate___ns1__Sign(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* SCAP-PDFSignature.h:694 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_PDFSignature_SOAP_ENV__Header
#define SOAP_TYPE_PDFSignature_SOAP_ENV__Header (49)
/* SOAP Header: */
struct SOAP_ENV__Header
{
public:
	int soap_type() const { return 49; } /* = unique type id SOAP_TYPE_PDFSignature_SOAP_ENV__Header */
	         SOAP_ENV__Header();
	friend SOAP_FMAC1 SOAP_ENV__Header * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Header(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/* SCAP-PDFSignature.h:694 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_PDFSignature_SOAP_ENV__Code
#define SOAP_TYPE_PDFSignature_SOAP_ENV__Code (50)
/* Type SOAP_ENV__Code is a recursive data type (in)directly referencing itself through its (base) class members */
/* SOAP Fault Code: */
struct SOAP_ENV__Code
{
public:
	char *SOAP_ENV__Value;	/* optional element of XSD type xsd:QName */
	struct SOAP_ENV__Code *SOAP_ENV__Subcode;	/* optional element of XSD type SOAP-ENV:Code */
public:
	int soap_type() const { return 50; } /* = unique type id SOAP_TYPE_PDFSignature_SOAP_ENV__Code */
	         SOAP_ENV__Code();
	friend SOAP_FMAC1 SOAP_ENV__Code * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Code(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/* SCAP-PDFSignature.h:694 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_PDFSignature_SOAP_ENV__Detail
#define SOAP_TYPE_PDFSignature_SOAP_ENV__Detail (52)
/* SOAP-ENV:Detail complex type: */
struct SOAP_ENV__Detail
{
public:
	char *__any;
	int __type;	/* any type of element <fault> (defined below)
	   WARNING: do not create a cyclic data structure graph throught this element unless SOAP encoding or SOAP_XML_GRAPH are used for id-ref serialization */
	void *fault;	/* transient (not serialized) */
public:
	int soap_type() const { return 52; } /* = unique type id SOAP_TYPE_PDFSignature_SOAP_ENV__Detail */
	         SOAP_ENV__Detail();
	friend SOAP_FMAC1 SOAP_ENV__Detail * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Detail(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/* SCAP-PDFSignature.h:694 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_PDFSignature_SOAP_ENV__Reason
#define SOAP_TYPE_PDFSignature_SOAP_ENV__Reason (55)
/* SOAP-ENV:Reason complex type: */
struct SOAP_ENV__Reason
{
public:
	char *SOAP_ENV__Text;	/* optional element of XSD type xsd:string */
public:
	int soap_type() const { return 55; } /* = unique type id SOAP_TYPE_PDFSignature_SOAP_ENV__Reason */
	         SOAP_ENV__Reason();
	friend SOAP_FMAC1 SOAP_ENV__Reason * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Reason(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/* SCAP-PDFSignature.h:694 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_PDFSignature_SOAP_ENV__Fault
#define SOAP_TYPE_PDFSignature_SOAP_ENV__Fault (56)
/* SOAP Fault: */
struct SOAP_ENV__Fault
{
public:
	char *faultcode;	/* optional element of XSD type xsd:QName */
	char *faultstring;	/* optional element of XSD type xsd:string */
	char *faultactor;	/* optional element of XSD type xsd:string */
	struct SOAP_ENV__Detail *detail;	/* optional element of XSD type SOAP-ENV:Detail */
	struct SOAP_ENV__Code *SOAP_ENV__Code;	/* optional element of XSD type SOAP-ENV:Code */
	struct SOAP_ENV__Reason *SOAP_ENV__Reason;	/* optional element of XSD type SOAP-ENV:Reason */
	char *SOAP_ENV__Node;	/* optional element of XSD type xsd:string */
	char *SOAP_ENV__Role;	/* optional element of XSD type xsd:string */
	struct SOAP_ENV__Detail *SOAP_ENV__Detail;	/* optional element of XSD type SOAP-ENV:Detail */
public:
	int soap_type() const { return 56; } /* = unique type id SOAP_TYPE_PDFSignature_SOAP_ENV__Fault */
	         SOAP_ENV__Fault();
	friend SOAP_FMAC1 SOAP_ENV__Fault * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Fault(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/


/* SCAP-PDFSignature.h:1 */
#ifndef SOAP_TYPE_PDFSignature__QName
#define SOAP_TYPE_PDFSignature__QName (5)
typedef char *_QName;
#endif

/* SCAP-PDFSignature.h:1 */
#ifndef SOAP_TYPE_PDFSignature__XML
#define SOAP_TYPE_PDFSignature__XML (6)
typedef char *_XML;
#endif

/* SCAP-PDFSignature.h:148 */
#ifndef SOAP_TYPE_PDFSignature_xsd__anyURI
#define SOAP_TYPE_PDFSignature_xsd__anyURI (17)
typedef std::string xsd__anyURI;
#endif

/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


} // namespace PDFSignature


#endif

/* End of PDFSignatureStub.h */