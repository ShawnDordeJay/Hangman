#pragma once
#include "Config.h"
#include "HangmanException.h"
#include <string>
#include <chrono>
#include <vector>
#include <iostream>

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
	vector <string> words;
	vector <char> hiddenword;
	vector <char> chosenword;
	int maxwords;
	int maxtries;

	void getRandomWord();
	void checkLetter(char letter);
	milliseconds getTime();
	void hideword();
	void printHiddenword();
	bool checkWin();

};

