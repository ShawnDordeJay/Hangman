#include "pch.h"
#include "Game.h"


Game::Game(Config *config)
{
	this->maxwords = config->getMaxWords;
	this->maxtries = config->getMaxTries;
}


Game::~Game()
{
}

void Game::init()
{
	string word;

	cout << "HANGMAN" << endl;
	cout << "Geben Sie " << this->maxwords << " Woerter ein. Bestaetigen Sie jede Eingabe mit Enter." << endl;
	
	for (unsigned int i = 0; i < this->maxwords; i++) {

		cin >> word;
		this->words.push_back(word);
	}

	cout << endl << "Sie haben " << this->maxtries << " Versuche das Wort zu erraten." << endl;

	this->getRandomWord();
}

void Game::play()
{
	char letter;

	milliseconds start = this->getTime();

	while (1) {
		try {
			if (this->maxtries > 0) {

				this->printHiddenword();
				cout << "Waehlen Sie einen Buchstaben und bestaetigen Sie mit Enter";
				cin >> letter;

				this->checkLetter(letter);
				this->maxtries--;
				
				if (checkWin()) {
					cout << "Sie haben das Wort erraten und somit gewonnen. Spiel wird beendet." << endl;
					return;
				}
			}
			else {
				throw HangmanException();
			}
		}
		catch(HangmanException &ex){
			cout << ex.what() << endl;
			return;
		}
	}
	
}

void Game::getRandomWord()
{
	srand(time(NULL));

	int position = rand() % 10;

	string word = this->words[position];

	vector <char> chosen(word.begin(), word.end());
	this->chosenword = chosen;
	this->hiddenword = chosen;

}

void Game::checkLetter(char letter)
{
	bool found = false;
	for (unsigned int i = 1; i < (this->chosenword.size()-1); i++) {
		if (letter == this->chosenword[i]) {
			found = true;
			this->hiddenword[i] = toupper(letter);
		}
	}

	if (found) {
		cout << "Buchstabe gefunden" << endl;
		return;
	}
	else {
		cout << "Buchstabe nicht gefunden" << endl;;
		return;
	}
}

milliseconds Game::getTime()
{
	milliseconds ms = duration_cast<milliseconds>(high_resolution_clock::now().time_since_epoch());
	return ms;
}

void Game::hideword()

{
	this->hiddenword[0] = toupper(this->hiddenword[0]);
	this->hiddenword[this->hiddenword.size -1] = toupper(this->hiddenword.size - 1);

	for (unsigned int i = 1; i < (this->chosenword.size()-1); i++) {

		this->hiddenword[i] = '-';

	}
}

void Game::printHiddenword()
{
	for (char letter : this->hiddenword) {
		cout << letter << " ";
	}
	cout << endl;
}

bool Game::checkWin()
{
	for (unsigned int i = 0; i < this->hiddenword.size(); i++) {
		if (this->hiddenword[i] == '-') {
			return false;
		}
	}
	return true;;
}
