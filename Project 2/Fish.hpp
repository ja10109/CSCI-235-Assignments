
/*
CSCI-235
Jason Cho
Project 2
Professor Ligorio
fish.hpp
*/

#ifndef FISH_HPP_
#define FISH_HPP_
#include <iostream>
#include "Animal.hpp"

class Fish : public Animal //public animal necessary to set fish name, domestic and predator
{
	public:
		Fish();
		Fish(std::string name,bool domestic = false, bool predator = false);
		bool isVenomous() const;
		void setVenomous();
		
	private:
		bool venomous_;
};

#endif
