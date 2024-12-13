#pragma once

//Checks if RPGRPGLOGIC_EXPORTS is defined (usually when building the DLL)
#ifdef RPGRPGLOGIC_EXPORTS
    // Defines the symbol as dllexport (for building the DLL)
#define RPGRPGLOGIC_API __declspec(dllexport)
#else
    //Defines the symbol as dllimport (for using the DLL)
#define RPGRPGLOGIC_API __declspec(dllimport)
#endif

//Include for standard input/output operations
#include <iostream>

//Include for random generator
#include <cstdlib>

//Include for time to have a seed for the random generator
#include <ctime>   


//Declare the attack function
RPGRPGLOGIC_API float attack(float userDmg);

//Declare the defend function 
RPGRPGLOGIC_API float defend(float userDef, float dmgRecived);