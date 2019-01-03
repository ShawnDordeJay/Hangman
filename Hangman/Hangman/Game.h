#pragma once
#include "Config.h"
#include "HangmanException.h"
#include <string>
#include <chrono>
#include <vector>
#include <iostream>
#include <time.h>

using namespace std;
using namespace std::chrono;

class Game
{
public:
	Game(Config *config);
	~Game();

	
	void init();
	void play();
	
	
private:
	
	vector <string> words; //eingegebenen Wörter
	vector <char> hiddenword; //gewählte Wort zensiert
	vector <char> chosenword; //gewählte Wort
	int maxwords;
	int maxtries;

	void getRandomWord(); //sucht zufällig ein Wort aus den eingegebenen Wörtern
	void checkLetter(char letter); //sucht nach eingebenen Buchstaben im ausgewählten Wort
	milliseconds getTime(); //name ist programm
	void hideword(); //ausgewähltes Wort zensieren
	void printHiddenword(); //name ist programm
	bool checkWin(); //name ist programm

};

