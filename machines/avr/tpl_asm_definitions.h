/**
 * @file tpl_asm_definitions.h
 *
 * @section descr File description
 *
 * Common definitions for AVR assembler source files
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation and ARM port
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 */

/*
 * tpl_kern data structure offsets (for use into assembler sources)
 */
.equ TPL_KERN_OFFSET_S_RUNNING,		0
.equ TPL_KERN_OFFSET_S_ELECTED,		2
.equ TPL_KERN_OFFSET_RUNNING,		4
.equ TPL_KERN_OFFSET_ELECTED,		6
.equ TPL_KERN_OFFSET_RUNNING_ID,	8
.equ TPL_KERN_OFFSET_ELECTED_ID,	12
.equ TPL_KERN_OFFSET_NEED_SWITCH,	16
.equ TPL_KERN_OFFSET_NEED_SCHEDULE, 17


/* Enf of file tpl_asm_definitions.h */
