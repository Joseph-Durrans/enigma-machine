#include "headers/Rotors.h"

Rotors::Rotors(int slowRotorPosition, int mediumRotorPosition, int fastRotorPosition)
{
	this->slowRotorPosition = slowRotorPosition;
	this->mediumRotorPosition = mediumRotorPosition;
	this->fastRotorPosition = fastRotorPosition;
}

void Rotors::CycleRotors()
{
	this->fastRotorPosition += 1;

	if (this->fastRotorPosition > 26)
	{
		this->fastRotorPosition = 1;
		this->mediumRotorPosition += 1;
	}

	if (this->mediumRotorPosition > 26)
	{
		this->mediumRotorPosition = 1;
		this->slowRotorPosition += 1;
	}

	if (this->slowRotorPosition > 26)
	{
		this->slowRotorPosition = 1;
	}
}

int Rotors::TraverseRotors(int rotorIndex, int &charIndex, int rotorPosition)
{
	int rotorCharIndex = rotorPosition;

	for (int i = 0; i < charIndex; i++)
	{
		rotorCharIndex += 1;

		if (rotorCharIndex > sizeof(this->alpha) / sizeof(this->alpha[0]) - 1)
		{
			rotorCharIndex = 0;
		}
	}

	for (int i = 0; i < sizeof(this->alpha) / sizeof(this->alpha[0]); i++)
	{
		if (this->alpha[i] == this->rotors[rotorIndex][rotorCharIndex])
		{
			charIndex = i;
			break;
		}
	}

	if (rotorIndex != sizeof(this->rotors) / sizeof(this->rotors[0]) - 1)
	{
		return rotorIndex + TraverseRotors(rotorIndex + 1, charIndex, this->rotorPositions[rotorIndex + 1]);
	}

	return charIndex;
}

int Rotors::Reflect(int& lastCharIndex, int lastRotorPos)
{
	int reflectorCharIndex = lastRotorPos;

	for (int i = 0; i < lastCharIndex; i++)
	{
		reflectorCharIndex += 1;

		if (reflectorCharIndex > sizeof(this->alpha) / sizeof(this->alpha[0]) - 1)
		{
			reflectorCharIndex = 0;
		}
	}

	for (int i = 0; i < sizeof(this->alpha) / sizeof(this->alpha[0]); i++)
	{
		if (this->alpha[i] == this->ukwB[reflectorCharIndex])
		{
			lastCharIndex = i;
			break;
		}
	}

	return lastCharIndex;
}

int Rotors::TraverseRotorsInverse(int rotorIndex, int& charIndex, int rotorPosition)
{
	int rotorAlphaCharIndex = rotorPosition;

	for (int i = 0; i < charIndex; i++)
	{
		rotorAlphaCharIndex += 1;

		if (rotorAlphaCharIndex > sizeof(this->alpha) / sizeof(this->alpha[0]) - 1)
		{
			rotorAlphaCharIndex = 0;
		}
	}

	for (int i = 0; i < sizeof(this->alpha) / sizeof(this->alpha[0]); i++)
	{
		if (this->rotors[rotorIndex][i] == this->alpha[rotorAlphaCharIndex])
		{
			charIndex = i;
			break;
		}
	}

	if (rotorIndex != 0)
	{
		return rotorIndex + TraverseRotorsInverse(rotorIndex - 1, charIndex, this->rotorPositions[rotorIndex - 1]);
	}

	return charIndex;
}

int Rotors::Output(int& lastCharIndex, int firstRotorPos)
{
	int firstRotorCharIndex = firstRotorPos;

	for (int i = 0; i < lastCharIndex; i++)
	{
		firstRotorCharIndex += 1;

		if (firstRotorCharIndex > sizeof(this->alpha) / sizeof(this->alpha[0]) - 1)
		{
			firstRotorCharIndex = 0;
		}
	}

	return lastCharIndex;
}

char Rotors::EncodeCharacter(int charIndex)
{
	TraverseRotors(0, charIndex, this->rotorPositions[0]);

	Reflect(charIndex, this->rotorPositions[sizeof(this->rotorPositions) / sizeof(this->rotorPositions[0]) - 1]);

	TraverseRotorsInverse(sizeof(this->rotors) / sizeof(this->rotors[0]) - 1, charIndex, this->rotorPositions[sizeof(this->rotorPositions) / sizeof(this->rotorPositions[0]) - 1]);

	Output(charIndex, this->rotorPositions[0]);

	return this->alpha[charIndex];
}



