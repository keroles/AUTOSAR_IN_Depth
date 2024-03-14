/**
 * @addtogroup pilote_arm_timer
 * Pilote des timers du microcontr�leur OKI ML675001
 * @{
 */

/**
 * @file timer.h
 *
 * @brief Interface du pilote des timers du microcontr�leur OKI ML675001
 *
 * $Author$
 * $Date$
 *
 * @version 2.0
 * $Revision$
 */

#ifndef H_TIMER
#define H_TIMER

#include "timer_parametres_possibles.h"
#include "miro_types.h"

/**
 * @name Fonction d'initialisation
 * @{
 */

/**
 * @brief Initialisation de tous les timers
 *
 * Cette fonction initialise tous les timers avec les r�glages par d�faut d�finis dans le
 * fichier timer_configuration_par_defaut.h.
 * Toutes les timers sont arr�t�s et toutes les interruptions timers sont d�sactiv�es.
 */
void Timer_initialiser ();

/** @} */

/**
 * @name Fonctions de configuration
 * @{
 */

/**
 * @brief R�glage du mode de fonctionnement d'un timer
 *
 * @param timer Le num�ro du timer � configurer (entre 0 et 5)
 * @param mode Le mode de comptage (valeurs possibles : TIMER_INTERVAL, TIMER_ONE_SHOT)
 */
void Timer_set_mode (int timer, int mode);

/**
 * @brief R�glage du pr�diviseur d'un timer
 *
 * @param timer Le num�ro du timer � configurer (entre 0 et 5)
 * @param pre Le facteur de pr�division (valeurs possibles : TIMER_PREDIVISEUR_1 � TIMER_PREDIVISEUR_32)
 */
void Timer_set_prediviseur (int timer, int pre);

/**
 * @brief R�glage de la valeur initiale d'un timer
 *
 * Lorsque le timer atteind sa valeur finale, il se recharge automatiquement avec sa valeur initiale.
 *
 * @param timer Le num�ro du timer � configurer (entre 0 et 5)
 * @param valeur La valeur initiale � affecter au timer
 */
void Timer_set_valeur_initiale (int timer, UInt16 valeur);

/**
 * @brief R�glage de la valeur finale d'un timer
 *
 * Lorsque le timer atteind sa valeur finale, il se recharge automatiquement avec sa valeur initiale.
 *
 * @param timer Le num�ro du timer � configurer (entre 0 et 5)
 * @param valeur La valeur finale � affecter au timer
 */
void Timer_set_valeur_finale (int timer, UInt16 valeur);

/**
 * @brief R�glage automatique d'un timer pour une dur�e fix�e, en microsecondes
 *
 * Cette fonction calcule automatiquement le modulo et le facteur de pr�division du timer
 * pour atteindre la dur�e souhait�e.
 * Si cette dur�e exc�de les possibilit�s du timer, elle retourne un facteur de post-division
 * � appliquer.
 *
 * @param timer Le num�ro du timer � configurer (entre 0 et 5)
 * @param duree La dur�e entre deux rebouclages, en microsecondes
 * @return Un facteur de postdivision, si n�cessaire
 */
UInt32 Timer_set_periode (int timer, UInt32 duree);

/** @} */

/**
 * @name Fonctions de gestion des �v�nements
 * @{
 */

/**
 * @brief Activer les demandes d'interruption pour un timer
 *
 * @param timer Le num�ro du timer � configurer (entre 0 et 5)
 */
void Timer_activer_interruptions (int timer);

/**
 * @brief D�sactiver les demandes d'interruption pour un timer
 *
 * @param timer Le num�ro du timer � configurer (entre 0 et 5)
 */
void Timer_desactiver_interruptions (int timer);

/**
 * @brief Tester l'�tat d'un timer
 *
 * @param timer Le num�ro du timer � tester (entre 0 et 5)
 * @return 0 si le timer n'a pas encore atteint sa valeur finale, une valeur non nulle si le timer a d�marr� un nouveau cycle de comptage
 */
int Timer_evenement (int timer);

/**
 * @brief Acquitter un �v�nement timer
 *
 * Cette fonction remet � z�ro l'indicateur de d�bordement d'un timer.
 *
 * @param timer Le num�ro du timer (entre 0 et 5)
 */
void Timer_acquitter_evenement (int timer);

/** @} */

/**
 * @name Fonctions de contr�le du fonctionnement d'un timer
 * @{
 */

/**
 * @brief D�marrer un timer
 *
 * @param timer Le num�ro du timer � d�marrer (entre 0 et 5)
 */
void Timer_demarrer (int timer);

/**
 * @brief Arr�ter un timer
 *
 * @param timer Le num�ro du timer � arr�ter (entre 0 et 5)
 */
void Timer_arreter (int timer);

/**
 * @brief Lire la valeur courante du compteur
 *
 * @param timer Le num�ro du timer � tester (entre 0 et 5)
 * @return La valeur courante du compteur
 */
UInt16 Timer_get_valeur (int timer);

/**
 * @brief Temporisation bloquante
 *
 * Cette fonction utilise le timer 1 pour mettre le programme en attente pendant
 * une dur�e fix�e.
 *
 * @param timer Le num�ro du timer � utiliser (entre 0 et 5)
 * @param duree Dur�e d'attente, en microsecondes
 */
void Timer_attendre (int timer, UInt32 duree);

/** @} */

#endif

/** @} */

