/**
 * @addtogroup pilote_arm_memoire
 * Pilote du contr�leur m�moire du microcontr�leur OKI ML675001
 * @{
 */

/**
 * @file memoire.h
 *
 * @brief Interface du pilote du contr�leur m�moire du microcontr�leur OKI ML675001
 *
 * $Author$
 * $Date$
 *
 * @version 1.0
 * $Revision$
 */

#ifndef H_MEMOIRE
#define H_MEMOIRE

/**
 * @brief Initialiser le contr�leur m�moire
 *
 * Cette fonction initialise la gestion des bus externes et le contr�leur
 * de RAM dynamique.
 * Elle met � z�ro la m�moire des variables statiques (section BSS).
 *
 * Si l'application est actuellement charg�e en m�moire morte, cette fonction
 * effectue automatiquement le basculement en m�moire vive : pour ce faire, les
 * sections de programme et de donn�es sont int�gralement recopi�es de la ROM vers la
 * DRAM, puis la banque 0 de la m�moire est reconfigur�e pour pointer vers la DRAM.
 */
void Memoire_initialiser ();

void Memoire_basculer_dram ();

int Memoire_execution_en_rom ();

int Memoire_execution_en_dram ();

#endif

/** @} */

