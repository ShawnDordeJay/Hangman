#include "pch.h"
#include "Game.h"


Game::Game(Config *config)
{
	this->maxwords = config->getMaxWords();
	this->maxtries = config->getMaxTries();
}


Game::~Game()
{
}

void Game::init()
{
	string word;

	cout << "HANGMAN" << endl;
	cout << "Geben Sie " << this->maxwords << " Woerter ein. Bestaetigen Sie jede Eingabe mit Enter." << endl;
	
	//einlesen der wörter
	for (unsigned int i = 0; i < this->maxwords; i++) {

		cin >> word;
		this->words.push_back(word);
	}

	cout << endl << "Sie haben " << this->maxtries << " Versuche das Wort zu erraten." << endl;

	//zufällig eins auswählen von den 10 Wörtern
	this->getRandomWord();
}

void Game::play()
{
	char letter;
	int versuche = 0;

	milliseconds start = this->getTime();

	//wenn die versuche größer als die maxtries -> wirf exception
	while (1) {
		try {
			if (this->maxtries >= versuche) {

				system("cls");
				this->printHiddenword();
				cout << "Waehlen Sie einen Buchstaben und bestaetigen Sie mit Enter" << endl;
				cin >> letter;

				this->checkLetter(letter);
				versuche++;
				
				if (checkWin()) {
					milliseconds end = this->getTime();
					milliseconds duration = end - start;
					int min = duration.count() / 60000;
					int sec = (duration.count() - (duration.count() / 60000)) / 1000;

					cout << "Sie haben das Wort erraten und somit gewonnen." << endl;
					cout << "Versuche " << versuche << " von " << this->maxtries << endl;
					cout << "Benoetigte Zeit: " << min << " min " << sec << " sec" << endl;
					return;
				}
				system("pause");
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

	//gewähltes wort in char vector konvertieren
	vector <char> chosen(word.begin(), word.end());
	//zuweisen
	this->chosenword = chosen;
	this->hiddenword = chosen;
	//zensieren
	this->hideword();

}

void Game::checkLetter(char letter)
{
	bool found = false;
	//erst und letzter buchstabe wird ausgelassen da schon bekannt
	for (unsigned int i = 1; i < (this->chosenword.size()-1); i++) {
		//case unsensitive
		if ((toupper(letter) == this->chosenword[i]) || (tolower(letter) == this->chosenword[i])) {
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
	//ersten und letzten Buchstaben groß schreiben
	this->hiddenword[0] = toupper(this->hiddenword[0]);
	this->hiddenword[this->hiddenword.size() -1] = toupper(this->hiddenword[this->hiddenword.size() - 1]);

	//zensur
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
