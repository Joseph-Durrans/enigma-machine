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

void Rotors::start(char character)
{
	char initChar = toupper(character);
	int initCharPos = 0;

	for (int i = 0; i < sizeof(this->alpha) / sizeof(this->alpha[0]); i++)
	{
		if (this->alpha[i] == initChar)
		{
			initCharPos = i;
			break;
		}
	}
}

int Rotors::TraverseRotors(int charIndex, int rotorPositions[])
{

	for (int rotor = 0; rotor < sizeof(this->rotors) / sizeof(this->rotors[0]); rotor++)
	{
		for (int i = 0; i < charIndex; i++)
		{
			rotorPositions[rotor] += 1;

			if (rotorPositions[rotor] > sizeof(this->alpha) / sizeof(this->alpha[0]) - 1)
			{
				rotorPositions[rotor] = 0;
			}
		}

		for (int i = 0; i < sizeof(this->alpha) / sizeof(this->alpha[0]); i++)
		{

			if (this->alpha[i] == this->rotors[rotor][rotorPositions[rotor]])
			{
				charIndex = i;
				break;
			}
		}

		std::cout << this->rotors[rotor][rotorPositions[rotor]] << std::endl;
	}


	std::cout << charIndex << std::endl;

	return 1;
}



