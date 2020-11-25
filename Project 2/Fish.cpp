/*
CSCI-235
Jason Cho
Project 2
Professor Ligorio
fish.cpp
*/

#include "Fish.hpp"

Fish::Fish() //default constructor
{
	name_ = "";
	domestic_ = false;
	predator_ = false;
	venomous_ = false;
}

Fish::Fish(std::string name, bool predator, bool domestic) //paramatized constructor from animal.hpp file
{
	name_ = name;
	predator_ = predator;
	domestic_ = domestic;
	venomous_ = false;
}

bool Fish::isVenomous() const //returns value of venemous 
{
	return venomous_;
}

void Fish::setVenomous() //makes fish venemous
{
	venomous_ = true;
}
