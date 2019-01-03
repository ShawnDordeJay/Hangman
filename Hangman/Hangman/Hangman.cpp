//Zeitaufwand ca 2,5-3 Stunde inkl debug

#include "pch.h"
#include <iostream>
#include "Config.h"
#include "Game.h"

int main()
{

	//config singleton inkl setzen von maxwords und maxtries
	Config *config = Config::getInstance(10, 10);

	//spiel starten
	Game *hangman = new Game(config);
	//hangman initialisieren
	hangman->init();
	//hangman spielen
	hangman->play();

	system("pause");
}

