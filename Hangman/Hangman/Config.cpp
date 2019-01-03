#include "pch.h"
#include "Config.h"


Config::Config(int maxwords, int maxtries)
{
	this->maxtries = maxtries;
	this->maxwords = maxwords;
}


Config::~Config()
{
}

Config *Config::instance = 0;

Config * Config::getInstance(int maxwords, int maxtries)
{
	if (instance == 0) {

		instance = new Config(maxwords, maxtries);
	}

	return instance;
}

int Config::getMaxWords()
{
	return this->maxwords;
}

int Config::getMaxTries()
{
	return this->maxtries;
}




