/*
 * Copyright 2008 Arsen Chaloyan
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __MRCPV2_CONNECTION_DESCRIPTOR_H__
#define __MRCPV2_CONNECTION_DESCRIPTOR_H__

/**
 * @file mrcpv2_connection_descriptor.h
 * @brief MRCPv2 Connection Descriptor
 */ 

#include "mrcp_types.h"

APT_BEGIN_EXTERN_C

/** MRCP proto transport (v2) */
typedef enum {
	MRCP_PROTO_TCP,
	MRCP_PROTO_TLS,

	MRCP_PROTO_COUNT,
	MRCP_PROTO_UNKNOWN = MRCP_PROTO_COUNT
}mrcp_proto_type_e;


/** MRCP attributes */
typedef enum {
	MRCP_ATTRIB_SETUP,
	MRCP_ATTRIB_CONNECTION,
	MRCP_ATTRIB_RESOURCE,
	MRCP_ATTRIB_CHANNEL,
	MRCP_ATTRIB_CMID,

	MRCP_ATTRIB_COUNT,
	MRCP_ATTRIB_UNKNOWN = MRCP_ATTRIB_COUNT
}mrcp_attrib_e;


/** MRCP setup attributes */
typedef enum {
	MRCP_SETUP_TYPE_ACTIVE,
	MRCP_SETUP_TYPE_PASSIVE,

	MRCP_SETUP_TYPE_COUNT,
	MRCP_SETUP_TYPE_UNKNOWN = MRCP_SETUP_TYPE_COUNT
} mrcp_setup_type_e;

/** MRCP connection attributes */
typedef enum {
	MRCP_CONNECTION_TYPE_NEW,
	MRCP_CONNECTION_TYPE_EXISTING,

	MRCP_CONNECTION_TYPE_COUNT,
	MRCP_CONNECTION_TYPE_UNKNOWN = MRCP_CONNECTION_TYPE_COUNT
} mrcp_connection_type_e;


/** MRCP control descriptor declaration */
typedef struct mrcp_connection_descriptor_t mrcp_connection_descriptor_t;

/** MRCP connection descriptor */
struct mrcp_connection_descriptor_t {
	mrcp_proto_type_e      proto;
	mrcp_setup_type_e      setup_type;
	mrcp_connection_type_e connection_type;
	apt_str_t              resource_name;
	apt_str_t              session_id;
	apr_size_t             cmid;
};

/** Initialize MRCP connection descriptor */
static APR_INLINE void mrcp_connection_descriptor_init(mrcp_connection_descriptor_t *descriptor)
{
	descriptor->proto = MRCP_PROTO_UNKNOWN;
	descriptor->setup_type = MRCP_SETUP_TYPE_UNKNOWN;
	descriptor->connection_type = MRCP_CONNECTION_TYPE_UNKNOWN;
	apt_string_reset(&descriptor->resource_name);
	apt_string_reset(&descriptor->session_id);
	descriptor->cmid = 0;
}

/** Get MRCP protocol transport name by identifier */
MRCP_DECLARE(const apt_str_t*) mrcp_proto_get(mrcp_proto_type_e proto);

/** Find MRCP protocol transport identifier by name */
MRCP_DECLARE(mrcp_proto_type_e) mrcp_proto_find(const apt_str_t *attrib);


/** Get MRCP attribute name by identifier */
MRCP_DECLARE(const apt_str_t*) mrcp_attrib_str_get(mrcp_attrib_e attrib_id);

/** Find MRCP attribute identifier by name */
MRCP_DECLARE(mrcp_attrib_e) mrcp_attrib_id_find(const apt_str_t *attrib);


/** Get MRCP setup type name by identifier */
MRCP_DECLARE(const apt_str_t*) mrcp_setup_type_get(mrcp_setup_type_e setup_type);

/** Find MRCP setup type identifier by name */
MRCP_DECLARE(mrcp_setup_type_e) mrcp_setup_type_find(const apt_str_t *attrib);


/** Get MRCP connection type name by identifier */
MRCP_DECLARE(const apt_str_t*) mrcp_connection_type_get(mrcp_connection_type_e connection_type);

/** Find MRCP connection type identifier by name */
MRCP_DECLARE(mrcp_connection_type_e) mrcp_connection_type_find(const apt_str_t *attrib);


APT_END_EXTERN_C

#endif /*__MRCPV2_CONNECTION_DESCRIPTOR_H__*/