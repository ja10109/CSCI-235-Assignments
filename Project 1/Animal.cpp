/*
Jason Cho
CSCI - 235
Project 1
animal.cpp
the implementation for the class animal
*/

#include "Animal.hpp" //includes the Animal.hpp file
#include <string>

Animal::Animal() //default constructor, set name empty, domestic and predator false.
{
	name_ = "";
	domestic_ = false;
	predator_ = false;
}

Animal::Animal(std::string name, bool domestic, bool predator)//implemented constructor
{
	name_ = name;
	predator_ = predator;
	domestic_ = domestic;
}

std::string Animal::getName() const //displays the animal name
{
	return name_;
}

bool Animal::isDomestic() const //returns whether the animal is domestic
{
	if(domestic_ == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Animal::isPredator() const //returns whether the animal is predator
{
	if(predator_ == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Animal::setName(std::string name) //changes the animal name
{
	name_ = name;
}

void Animal::setDomestic() //makes the animal domestic
{
	domestic_ = true;
}

void Animal::setPredator() //makes the animal a predator
{
	predator_ = true;
}
