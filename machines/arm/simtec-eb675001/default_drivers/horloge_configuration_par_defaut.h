/**
 * @addtogroup pilote_arm_horloge
 * @{
 */

/**
 * @file horloge_configuration_par_defaut.h
 *
 * @brief Valeurs par d�faut des param�tres de configuration du g�n�rateur d'horloge
 *
 * $Author$
 * $Date$
 *
 * @version 1.0
 * $Revision$
 */

#ifndef H_HORLOGE_CONFIGURATION_PAR_DEFAUT
#define H_HORLOGE_CONFIGURATION_PAR_DEFAUT

/**
 * @name R�glages par d�faut du g�n�rateur d'horloges
 * @{
 */

/** @brief Facteur de division par d�faut pour la fr�quence de l'horloge CPU */
#define HORLOGE_DIVISEUR_CPU_PAR_DEFAUT 1

/** @brief Facteur de division par d�faut pour la fr�quence d'horloge des timers et interfaces s�rie */
#define HORLOGE_DIVISEUR_COMPTEURS_PAR_DEFAUT 1

/** @brief Fr�quence d'horloge syst�me */
#define HORLOGE_FREQUENCE_HCLK 59000000

/** @} */

#endif

/** @} */

