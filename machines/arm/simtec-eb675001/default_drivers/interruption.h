/**
 * @addtogroup pilote_arm_interruption
 * Pilote du contr�leur d'interruptions du microcontr�leur OKI ML675001
 * @{
 */

/**
 * @file interruption.h
 *
 * @brief Interface du pilote du contr�leur d'interruptions du microcontr�leur OKI ML675001
 *
 * $Author$
 * $Date$
 *
 * @version 2.0
 * $Revision$
 */

#ifndef H_INTERRUPTION
#define H_INTERRUPTION

#include "interruption_parametres_possibles.h"

#include "miro_types.h"

/** @brief Type de fonction acceptable comme gestionnaire d'interruption */
typedef void (*Interruption_Gestionnaire)(void *arguments);

/** @brief Type de fonction acceptable comme gestionnaire d'appel syst�me (SWI) */
typedef UInt32 (*Interruption_GestionnaireAppelSysteme)(UInt32 *arguments);

/**
 * @name Fonction d'initialisation 
 * @{
 */ 

/**
 * @brief Initialisation de la gestion des interruptions
 *
 * @post Les interruptions sont masqu�es
 */
void Interruption_initialiser (); 
 
/** @}*/ 
 
/**
 * @name Fonctions de configuration
 * @{
 */

/**
 * @brief Affectation d'un niveau de priorit� � une source d'interruption donn�e
 *
 * Les identifiants des sources d'interruptions sont d�taill�s dans le fichier interruption_parametres_possibles.h.
 * Un niveau de priorit� doit �tre compris entre 0 (source d'interruption d�sactiv�e) et 7 (priorit� la plus �lev�e).
 *
 * @param source Num�ro de la source d'interruption
 * @param niveau Niveau de priorit�
 */
void Interruption_set_priorite (int source, int niveau);

/**
 * @brief Lecture du niveau de priorit� d'une source d'interruption
 *
 * Les identifiants des sources d'interruptions sont d�taill�s dans le fichier interruption_parametres_possibles.h.
 *
 * @param source Num�ro de la source d'interruption
 * @param niveau Niveau de priorit�
 */
int Interruption_get_priorite (int source);

/**
 * @brief Installation d'une fonction de traitement d'interruption pour une source donn�e
 *
 * @param source Num�ro de la source d'interruption
 * @param gestionnaire Pointeur vers la fonction de traitement
 */
void Interruption_set_gestionnaire_irq (int source, Interruption_Gestionnaire gestionnaire, void *arguments);

/**
 * @brief Installation d'une fonction de traitement d'interruption rapide
 *
 * @param gestionnaire Pointeur vers la fonction de traitement
 */
void Interruption_set_gestionnaire_fiq (Interruption_Gestionnaire gestionnaire, void *arguments);

/**
 * @brief Installation d'une fonction de traitement des interruptions logicielles
 *
 * @param gestionnaire Pointeur vers la fonction de traitement
 */
void Interruption_set_gestionnaire_swi (UInt32 numero_service, Interruption_GestionnaireAppelSysteme gestionnaire);

/**
 * @brief R�glage du mode de d�tection d'une demande d'interruption externe
 *
 * @param source Num�ro de la source d'interruption (doit correspondre � une interruption externe)
 * @param mode Niveau ou front actif de l'entr�e interruption
 */
void Interruption_set_detection (int source, int mode);

/**
 * @brief Acquitte le niveau d'interruption courant
 */
void Interruption_acquitter_niveau_courant ();

/** @} */

/**
 * @name Fonctions de gestion des �v�nements
 * @{
 */

/**
 * @brief Donne le num�ro de la source d'interruption IRQ
 *
 * @return num�ro de la source la plus prioritaire � avoir
 * provoqu� une interruption sur l'entr�e IRQ (compris entre
 * 0 et 31)
 */
int Interruption_get_source ();

/**
 * @brief Activer la d�tection des IRQ par le processeur
 */
void Interruption_activer_irq ();

/**
 * @brief D�sactiver la d�tection des IRQ par le processeur
 */
void Interruption_desactiver_irq ();

/**
 * @brief Activer la d�tection des FIQ par le processeur
 */
void Interruption_activer_fiq ();

/**
 * @brief D�sactiver la d�tection des FIQ par le processeur
 */
void Interruption_desactiver_fiq ();

/** @} */

#endif

/** @}*/ 

