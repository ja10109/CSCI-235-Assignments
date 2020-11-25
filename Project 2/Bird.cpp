
/*
CSCI-235
Jason Cho
Project 2
Professor Ligorio
Bird.cpp
*/

#include "Bird.hpp"

Bird::Bird() //default constructor for bird
{
	name_ = "";
	predator_ = false;
	domestic_ = false;
	airborne_ = false;
	aquatic_ = false;
}

Bird::Bird(std::string name, bool domestic, bool predator) //paramatized constructor from anaimal hpp file
{
	name_ = name;
	predator_ = predator;
	domestic_ = domestic;
	airborne_ = false;
	aquatic_ = false;
}

bool Bird::isAirborne() const //returns whether the bird is airborne or not
{
	return airborne_;
}

bool Bird::isAquatic() const //returns whether bird is aquatic or not
{
	return aquatic_;
}

void Bird::setAirborne()  //makes bird airborne
{
	airborne_ = true;
}

void Bird::setAquatic()  //makes bird aquatic
{
	aquatic_ = true;
}
