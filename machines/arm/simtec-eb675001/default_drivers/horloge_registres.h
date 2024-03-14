/**
 * @addtogroup pilote_arm_horloge
 * @{
 */

/**
 * @file horloge_registres.h
 *
 * @brief D�finition des registres du g�n�rateur d'horloge
 *
 * $Author$
 * $Date$
 *
 * @version 1.0
 * $Revision$
 */

#ifndef H_HORLOGE_REGISTRES
#define H_HORLOGE_REGISTRES

#include "miro_types.h"

/**
 * @name Adressage des registres du g�n�rateur d'horloges
 * @{
 */

/** @brief Registre de contr�le du g�n�rateur d'horloge pour les timers et interfaces s�ries */
#define HORLOGE_REG_BCKCTL 0xB7000004

/** @brief Registre de configuration des diviseurs de fr�quence */
#define HORLOGE_REG_CGBNT0 0xB8000008

/** @} */

/** @brief Type du registre d'activation/d�sactivation des horloges */
typedef UInt16 Horloge_RegBckctl;

/** @brief Structure de donn�e pour l'acc�s au registre de configuration des diviseurs de fr�quence */
typedef struct
{
   /** @brief R�glage du diviseur de fr�quence CPU */
   unsigned division_cpu : 3;

   unsigned : 1;

   /** @brief R�glage du diviseur de fr�quence pour les timers et interfaces s�ries */
   unsigned division_compteurs : 3;

   unsigned : 25;

} Horloge_RegCgbnt0;

#endif

/** @} */

