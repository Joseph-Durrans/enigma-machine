#include "headers/Rotors.h"

#include <iostream>


int main()
{
    Rotors rotor(1,1,1);
    char fastRotor[26] = { 'E','K','M','F','L','G','D','Q','V','Z','N','T','O','W','Y','H','X','U','S','P','A','I','B','R','C','J' };
    int rotorPos[3] = { 1,1,1 };
    rotor.TraverseRotors(0, rotorPos);
}
