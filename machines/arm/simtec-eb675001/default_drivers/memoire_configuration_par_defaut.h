/**
 * @addtogroup pilote_arm_memoire
 * @{
 */

/**
 * @file memoire_configuration_par_defaut.h
 *
 * @brief Configuration par d�faut du contr�leur m�moire
 *
 * $Author$
 * $Date$
 *
 * @version 1.0
 * $Revision$
 */

#ifndef H_MEMOIRE_CONFIGURATION_PAR_DEFAUT
#define H_MEMOIRE_CONFIGURATION_PAR_DEFAUT

/**
 * @name Valeurs par d�faut des registres du contr�leur m�moire
 * @{
 */

/**
 * @brief Configuration par d�faut du bus m�moire externe
 *
 * Bus d'entr�es/sorties :
 * - ROM externe : 16 bits
 * - RAM externe : non
 * - I/O 0 et 1 (Ethernet) : 16 bits
 * - I/O 2 et 3 (CPLD) : 16 bits
 */
#define MEMOIRE_BWC_PAR_DEFAUT 0x0288

/**
 * @brief Taille par d�faut du bus de donn�es vers la SDRAM
 * 
 * Ce param�tre est contraint par le cablage de la m�moire sur la carte EB675001.
 * Le mod�le m�moire choisi a un bus de donn�es sur 16 bits.
 */
#define MEMOIRE_DBWC_PAR_DEFAUT 0x02

/**
 * @brief Type de SDRAM par d�faut
 *
 * - SDRAM avec adresses de colonnes sur 9 bits (A8 � A0).
 * - Le temps de pr�chargement est fix� � 2 p�riodes d'horloge.
 * - Le rafra�chissement automatique CBR est activ�.
 * - La mise en veille automatique n'est pas activ�e.
 */
#define MEMOIRE_DRMC_PAR_DEFAUT 0x81

/**
 * @brief Temps d'acc�s par d�faut � la SDRAM
 *
 * - tRCD = 20 ns < 2 Tclk
 * - tRAS = 45 ns < 3 Tclk
 * - tRP  = 20 ns < 2 Tclk
 * - tDPL = 15 ns < 1 Tclk
 */
#define MEMOIRE_DRPC_PAR_DEFAUT 0x02

/**
 * @brief Mode de fonctionnement par d�faut
 *
 * - Latence CAS = 3 p�riodes d'horloge
 * - Modifier la configuration du contr�leur
 */
#define MEMOIRE_SDMD_PAR_DEFAUT 0x81

/**
 * @brief Facteur de division de fr�quence par d�faut pour le rafra�chissement CBR automatique
 *
 * Rafra�chissement de la m�moire compl�te en 64 ms.
 * Pour 8192 lignes, cela nous donne 128000 lignes par seconde.
 *
 * Pour une raison inconnue, les sources fournis avec la carte EB675001
 * effectue un r�glage � 64150 Hz avec doublement de p�riode (soit 32 KHz).
 * Les tests confirment que cela suffit.
 */
#define MEMOIRE_RFSH1_PAR_DEFAUT 0x0399

/**
 * @brief Division de fr�quence suppl�mentaire pour le rafra�chissement CBR automatique
 *
 * Doublement de p�riode
 */
#define MEMOIRE_RFSH0_PAR_DEFAUT 0x00

/**
 * @brief D�lai de mise en veille par d�faut
 *
 * Fix� � 16 p�riode d'horloges.
 * Inutilis� pour le moment.
 */
#define MEMOIRE_RDWC_PAR_DEFAUT 0x0F

/** @brief Valeur de d�verrouillage du registre de remapping de la banque m�moire 0 en DRAM */
#define MEMOIRE_RMPCON_DEVERROUILLER 0x3C

/** @brief Remapping de la banque m�moire 0 en DRAM */
#define MEMOIRE_RMPCON_DRAM 0x09

/** @brief Remapping de la banque m�moire 0 en ROM */
#define MEMOIRE_RMPCON_ROM 0x00

/** @brief Remapping de la banque m�moire 0 en ROM */
#define MEMOIRE_RMPCON_MASQUE_ROM 0x08

/** @} */

#endif

/** @} */

