/**
 * @addtogroup pilote_arm_horloge
 * Pilote du g�n�rateur d'horloge du microcontr�leur OKI ML675001
 * @{
 */

/**
 * @file horloge.h
 *
 * @brief Interface du pilote du g�n�rateur d'horloge du microcontr�leur OKI ML675001
 *
 * $Author$
 * $Date$
 *
 * @version 1.0
 * $Revision$
 */

#ifndef H_HORLOGE
#define H_HORLOGE

#include "horloge_parametres_possibles.h"
#include "horloge_configuration_par_defaut.h"

/**
 * @name Fonction d'initialisation
 * @{
 */

/**
 * @brief Initialiser le contr�leur des signaux d'horloge interne
 *
 * Le contr�leur des signaux d'horloge est initialis� avec les r�lgages par d�faut
 * d�finis dans le fichier horloge_configuration_par_defaut.h
 *
 * @post Toutes les horloges des p�riph�riques sont d�sactiv�es
 */
void Horloge_initialiser ();

/** @} */

/**
 * @name Fonctions de configuration de la g�n�ration des signaux d'horloge
 * @{
 */

/**
 * @brief Activation de signaux d'horloges
 *
 * Cette fonction active les signaux indiqu�s en param�tre.
 *
 * @param sources Masque des signaux d'horloge � activer (valeurs possibles : HORLOGE_CONVERTISSEUR_ANALOGIQUE_NUMERIQUE, HORLOGE_PWM, HORLOGE_TIMER0, HORLOGE_TIMER1, HORLOGE_TIMER2, HORLOGE_TIMER3, HORLOGE_TIMER4, HORLOGE_TIMER5, HORLOGE_DRAM, HORLOGE_DMA, HORLOGE_UART, HORLOGE_SSIO, HORLOGE_I2C ; ces valeurs peuvent �tre combin�es � l'aide de l'op�rateur '|')
 *
 * @pre Le contr�leur d'horloge doit avoir �t� initialis�
 */
void Horloge_activer (int sources);

/**
 * @brief D�sactivation de signaux d'horloges
 *
 * Cette fonction d�sactive les signaux indiqu�s en param�tre.
 *
 * @param sources Masque des signaux d'horloge � d�sactiver (valeurs possibles : HORLOGE_CONVERTISSEUR_ANALOGIQUE_NUMERIQUE, HORLOGE_PWM, HORLOGE_TIMER0, HORLOGE_TIMER1, HORLOGE_TIMER2, HORLOGE_TIMER3, HORLOGE_TIMER4, HORLOGE_TIMER5, HORLOGE_DRAM, HORLOGE_DMA, HORLOGE_UART, HORLOGE_SSIO, HORLOGE_I2C ; ces valeurs peuvent �tre combin�es � l'aide de l'op�rateur '|')
 *
 * @pre Le contr�leur d'horloge doit avoir �t� initialis�
 */
void Horloge_desactiver (int sources);

/**
 * @brief R�glage des diviseurs de fr�quence
 *
 * Cette fonction configure les diviseurs de fr�quence pour l'horloge CPU et pour les signaux d'horloge
 * destin�s aux p�riph�riques (timers, interfaces s�ries, convertisseur A/N, g�n�rateur de PWM)
 *
 * @param facteur_cpu Facteur de division de fr�quence CPU (valeurs possibles : 1, 2, 4, 8, 16, 32)
 * @param facteur_compteurs Facteur de division de fr�quence pour l'horloge des p�riph�riques (valeurs possibles : 1, 2, 4, 8, 16, 32)
 *
 * @pre Le contr�leur d'horloge doit avoir �t� initialis�
 */
void Horloge_set_diviseurs (int facteur_cpu, int facteur_compteurs);

/** @} */

/**
 * @name Fonction de calcul de fr�quence d'horloge
 * @{
 */

/**
 * @brief Calcul de la fr�quence du signal d'horloge destin� aux p�riph�riques
 *
 * @return La valeur de la fr�quence, en Hz
 *
 * @pre Le contr�leur d'horloge doit avoir �t� initialis�
 */
int Horloge_get_frequence_compteurs ();

/** @} */

#endif

/** @} */

