/***************************************************************************
 *
 * $Id: StDStarMesonZero.hh,v 1.1 2010/01/28 19:31:41 jwebb Exp $
 *
 * Author: Thomas Ullrich, May 99 (based on Geant4 code, see below) 
 ***************************************************************************
 *
 * The design of the StParticleDefinition class and all concrete
 * classes derived from it is largely based on the design of the 
 * G4ParticleDefinition class from Geant4 (RD44).
 * Although the code is in large parts different (modified or rewritten)
 * and adapted to the STAR framework the basic idea stays the same.
 *
 ***************************************************************************
 *
 * $Log: StDStarMesonZero.hh,v $
 * Revision 1.1  2010/01/28 19:31:41  jwebb
 * Added the D* mesons (D^{*\pm} and D^{0}/\bar{D^{0}}^{*}.  This makes the
 * particles available in the StParticleTable.
 *
 * Revision 1.1  1999/05/14 18:49:19  ullrich
 * Initial Revision
 *
 **************************************************************************/
#ifndef StDStarMesonZero_hh
#define StDStarMesonZero_hh

#include "StMeson.hh"

class StDStarMesonZero : public StMeson {
public:
    static StDStarMesonZero* instance() {return &mDStarMesonZero;}
    static StDStarMesonZero* dStarMesonZero() {return &mDStarMesonZero;}
    
private:
    static StDStarMesonZero mDStarMesonZero;
    
    StDStarMesonZero(const string  &  aName,  
		 double           mass,     
		 double           width,
		 double           charge,   
		 int              iSpin,
		 int              iParity,
		 int              iConjugation,
		 int              iIsospin,   
		 int              iIsospinZ, 
		 int              gParity,
		 const string  &  pType,
		 int              lepton,
		 int              baryon,
		 int              encoding,
		 bool             stable,
		 double           lifetime);
};

#endif
