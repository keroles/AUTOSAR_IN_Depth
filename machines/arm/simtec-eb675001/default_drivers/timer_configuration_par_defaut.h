/**
 * @addtogroup pilote_arm_timer
 * @{
 */

/**
 * @file timer_configuration_par_defaut.h
 *
 * @brief R�glages par d�faut pour la configuration des timers du microcontr�leur OKI ML675001
 *
 * $Author$
 * $Date$
 *
 * @version 2.0
 * $Revision$
 */

#ifndef H_TIMER_CONFIGURATION_PAR_DEFAUT
#define H_TIMER_CONFIGURATION_PAR_DEFAUT

#include "timer_parametres_possibles.h"

/**
 * @name R�glages par d�faut
 * @{
 */

/** @brief Mode de comptage par d�faut */
#define TIMER_MODE_PAR_DEFAUT TIMER_INTERVAL

/** @brief Facteur de pr�division par d�faut */
#define TIMER_PREDIVISEUR_PAR_DEFAUT TIMER_PREDIVISEUR_1

/** @brief Valeur initiale par d�faut */
#define TIMER_VALEUR_INITIALE_PAR_DEFAUT 0

/** @brief Valeur finale par d�faut */
#define TIMER_VALEUR_FINALE_PAR_DEFAUT 1024

/** @} */

#endif

/** @} */

