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

#ifndef __DEMO_FRAMEWORK_H__
#define __DEMO_FRAMEWORK_H__

/**
 * @file demo_framework.h
 * @brief Demo MRCP Application Framework
 */ 

#include "mrcp_types.h"

APT_BEGIN_EXTERN_C

/** Opaque demo framework declaration */
typedef struct demo_framework_t demo_framework_t;

/** 
 * Create demo framework.
 */
demo_framework_t* demo_framework_create();

/** 
 * Destroy demo framework.
 * @param framework the framework to destroy
 */
apt_bool_t demo_framework_destroy(demo_framework_t *framework);

APT_END_EXTERN_C

#endif /*__DEMO_FRAMEWORK_H__*/
