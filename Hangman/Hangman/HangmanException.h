#pragma once
#include <exception>
#include <iostream>

using namespace std;

class HangmanException
{
public:
	virtual const char* what() const throw()
	{
		return "Moegliche Versuche aufgebraucht. Sie haben verloren\nSpiel wird beendet";
	}
};