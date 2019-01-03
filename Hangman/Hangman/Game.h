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
	
	vector <string> words; //eingegebenen W�rter
	vector <char> hiddenword; //gew�hlte Wort zensiert
	vector <char> chosenword; //gew�hlte Wort
	int maxwords;
	int maxtries;

	void getRandomWord(); //sucht zuf�llig ein Wort aus den eingegebenen W�rtern
	void checkLetter(char letter); //sucht nach eingebenen Buchstaben im ausgew�hlten Wort
	milliseconds getTime(); //name ist programm
	void hideword(); //ausgew�hltes Wort zensieren
	void printHiddenword(); //name ist programm
	bool checkWin(); //name ist programm

};

