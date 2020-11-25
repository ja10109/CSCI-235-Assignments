/*
CSCI-235
Jason Cho
Project 2
Professor Ligorio
bird.hpp
*/

#ifndef BIRD_HPP_
#define BIRD_HPP_

#include <iostream>
#include "Animal.hpp"

class Bird : public Animal //public animal necessary to set name, domestic, and predator for bird
{
	public:
		Bird();
		Bird(std::string name, bool domestic = false, bool predator = false);
		bool isAirborne() const;
		bool isAquatic() const;
		void setAirborne();
		void setAquatic();
		
	private:
		bool airborne_;
		bool aquatic_;
};

#endif
