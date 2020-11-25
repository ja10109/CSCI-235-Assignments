/*
Jason Cho
CSCI 235
Professor Ligorio
Porject 8
CodewordGenerator.hpp
--header file for the CodewordGenerator class --
*/

#ifndef CODEWORD_GENERATOR_HPP_
#define CODEWORD_GENERATOR_HPP_

#include <regex>
#include <queue>
#include <stack>
#include <iostream>

class CodewordGenerator
{
  public:
      CodewordGenerator();
			//default constructor
	
      std::string generateShortestWord(std::string pattern);
			/**
			@post generateShortestWord takes a string pattern and returns the shortest string that matches the pattern
			exploring the space of possible alphabet permutations in Breadth First Search order (QUEUE).
			@param input string pattern is the pattern used for regex check
			@return shortest_string the shortest possible string that matterns the pattern
			*/
	
      std::string generateLengthWord(std::string pattern, int length);
			/**
			@post takes a string pattern and an integer n and returns a string of length n that
			matches the pattern exploring the space of possible alphabet permutations in
			Depth First Search order (STACK).
			@param the input string pattern is the pattern used for the regex check.
			int length represents how long the string should be.
			@return return_string that matches the pattern and has the same length as the length input
			*/
};

#endif
