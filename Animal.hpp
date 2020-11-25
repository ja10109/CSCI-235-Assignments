/*
Jason Cho
CSCI-235
Professor Ligorio
Project 1: OOP-a very simple class
animal.hpp
*/


#ifndef ANIMAL_HPP_
#define ANIMAL_HPP_

#include <string>

class Animal
{
	public:
		Animal();
		Animal(std::string name, bool domestic = false, bool predator = false);
		std::string getName() const;
		bool isDomestic() const;
		bool isPredator() const;
		void setName(std::string name);
		void setDomestic();
		void setPredator();
	
	private:
		std::string name_;
		bool domestic_;
		bool predator_;

};

#endif
