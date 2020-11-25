/*
CSCI-235
Jason Cho
Project 2
Professor Ligorio
mammal.cpp
*/

#include "Mammal.hpp"

Mammal::Mammal() //default constructor
{
	hair_ = false;
	airborne_ = false;
	aquatic_ = false;
	toothed_ = false;
	fins_ = false;
	tail_ = false;
	legs_ = 0;
	name_ = "";
	domestic_ = false;
	predator_ = false;
}

Mammal::Mammal(std::string name, bool domestic, bool predator)  //paramatized constructor from animal constructor
{
	hair_ = false;
	airborne_ = false;
	aquatic_ = false;
	toothed_ = false;
	fins_ = false;
	tail_ = false;
	legs_ = 0;
	name_ = name;
	predator_ = predator;
	domestic_ = domestic;
}

bool Mammal::hasHair() const //returns whether the mammal has hair
{
	return hair_;
}

bool Mammal::isAirborne() const //returns whether the mammal is airborne
{
	return airborne_;
}

bool Mammal::isAquatic() const //returns whether the mammal is aquatic
{
	return aquatic_;
}

bool Mammal::isToothed() const //returns whether the mammal has teeth
{
	return toothed_;
}

bool Mammal::hasFins() const //returns whether the mammal has fins
{
	return fins_;
}

bool Mammal::hasTail() const
{
	return tail_;
}

int Mammal::legs() const //returns whether the mammal has legs
{
	return legs_;
}

void Mammal::setHair() //returns whether the mammal has hair
{
	hair_ = true;
}

void Mammal::setAirborne() //makes the mammal airborne
{
	airborne_ = true;
}

void Mammal::setAquatic() //makes the mammal aquatic
{
	aquatic_ = true;
}

void Mammal::setToothed() //gives the mammal teeth
{
	toothed_ = true;
}

void Mammal::setFins()
{
	fins_ = true; //gives the mammal fins
}

void Mammal::setTail() //gives the mammal a tail
{
	tail_ = true;
}

void Mammal::setLegs(int legs) //gives the mammal legs depending on the input
{
	legs_ = legs;
}
