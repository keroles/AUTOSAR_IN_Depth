/**
 * @file tpl_os_std_types.h
 *
 * @section descr File description
 *
 * Trampoline standard types. Here for MISRA rule 13 compliance
 * and for platform specific type definition
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef TPL_OS_STD_TYPES_H
#define TPL_OS_STD_TYPES_H

/**
 * @typedef boolean
 *
 * 8 bits unsigned boolean
 * @note must be used together with the definition TRUE and FALSE
 */
typedef unsigned char   boolean;

/**
 * @typedef u8
 *
 * 8 bits unsigned number
 */
typedef unsigned char   uint8;

/**
 * @typedef s8
 *
 * 8 bits signed number
 */
typedef signed char     sint8;

/**
 * @typedef u16
 *
 * 16 bits unsigned number
 */
typedef unsigned short  uint16;

/**
 * @typedef s16
 *
 * 16 bits signed number
 */
typedef signed short    sint16;

/**
 * @typedef u32
 *
 * 32 bits unsigned number
 */
typedef unsigned long   uint32;

/**
 * @typedef s32
 *
 * 32 bits signed number
 */
typedef signed long     sint32;

#endif /* TPL_OS_STD_TYPES_H */

/* End of file tpl_os_std_types.h */
