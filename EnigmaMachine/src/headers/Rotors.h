#pragma once

#include <iostream>

class Rotors
{
private:
	char alpha[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	char ukwB[26] = { 'Y','R','U','H','Q','S','L','D','P','X','N','G','O','K','M','I','E','B','F','Z','C','W','V','J','A','T' };

	char rotors[3][26] = {
		{ 'E','K','M','F','L','G','D','Q','V','Z','N','T','O','W','Y','H','X','U','S','P','A','I','B','R','C','J' },
		{ 'A','J','D','K','S','I','R','U','X','B','L','H','W','T','M','C','Q','G','Z','N','P','Y','F','V','O','E' },
		{ 'B','D','F','H','J','L','C','P','R','T','X','V','Z','N','Y','E','I','W','G','A','K','M','U','S','Q','O' }
	};
	
	int slowRotorPosition;
	int mediumRotorPosition;
	int fastRotorPosition;

	int rotorPositions[3] = { 0,0,0 };


	void CycleRotors();

	int TraverseRotors(int rotorIndex, int& charIndex, int rotorPosition);
	int Reflect(int& lastCharIndex, int lastRotorPos);
	int TraverseRotorsInverse(int rotorIndex, int& charIndex, int rotorPosition);
	int Output(int& lastCharIndex, int firstRotorPos);

public:


	Rotors(int slowRotorPosition, int mediumRotorPosition, int fastRotorPosition);

	char EncodeCharacter(int charIndex);
};