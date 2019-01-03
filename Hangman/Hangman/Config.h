#pragma once
class Config
{
public:
	~Config();
	static Config *getInstance(int maxwords, int maxtries);
	int getMaxWords();
	int getMaxTries();


private:
	Config(int maxwords, int maxtries);
	static Config *instance;
	int maxwords;
	int maxtries;
};

