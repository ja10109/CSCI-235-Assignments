/*
Jason Cho
CSCI - 235
Project 8
CodewordGenerator.cpp
--implementation for the codewordgenerator class--
*/

#include "CodewordGenerator.hpp"

CodewordGenerator::CodewordGenerator(){}
//default constructor

/**
@post generateShortestWord takes a string pattern and returns the shortest string that matches the pattern
exploring the space of possible alphabet permutations in Breadth First Search order (QUEUE).
@param input string pattern is the pattern used for regex check
@return shortest_string the shortest possible string that matterns the pattern
*/
std::string CodewordGenerator::generateShortestWord(std::string pattern)
{
    	std::string alphabet = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	//all uppercase alphabet letters used in this regex assignment
	std::queue<std::string> pattern_queue;
	std::string shortest_string = "";
	std::string temp_string = "";
	std::string current_string = "";
	std::regex re(pattern);
	pattern_queue.push(shortest_string); //empty string on the queue
	while(!pattern_queue.empty()) //will stop when all strings have been removed from the queue
	{
		current_string = pattern_queue.front();
		pattern_queue.pop();//removes string from the queue
		shortest_string = current_string;  //will then be checked if string matches the pattern
		if(std::regex_match(shortest_string,re) == true)
		{
			return shortest_string;
			//if shortest_string matches the pattern, return.
		}
		else
		{
			for(int i = 0; i < alphabet.length();i++)
			{
				temp_string = current_string + alphabet[i];
				pattern_queue.push(temp_string);
				//for every character in the alphabet,
				//append alphabets[i] to shortest_string and enqueue it
				//adds 26 new strings to the queue
			}
		}
	}
}

/**
@post takes a string pattern and an integer n and returns a string of length n that
matches the pattern exploring the space of possible alphabet permutations in
Depth First Search order (STACK).
@param the input string pattern is the pattern used for the regex check.
int length represents how long the string should be.
@return return_string that matches the pattern and has the same length as the length input
*/
std::string CodewordGenerator::generateLengthWord(std::string pattern, int length)
{
    	std::string alphabet = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	//all uppercase alphabet letters used in this regex assignment
	std::stack<std::string> pattern_stack;
	std::string return_string = "";
	std::string temp_string = "";
	std::string current_string = "";
	std::regex re(pattern);
	pattern_stack.push(return_string); //push empty string onto the stack
	while(!pattern_stack.empty())//will stop when all strings have been removed from the stack
	{
		current_string = pattern_stack.top();
		pattern_stack.pop(); //removes the string from the stack
		return_string = current_string;  //will then be checked if string matches pattern
		if(std::regex_match(return_string,re) == true && current_string.length() == length) //lengths also has to match in DFS
		{
			return return_string;
			//return return_string if it matches the pattern and the string's length
			//matches the length input
		}
		else if(current_string.length() < length)
		{
			for(int i = 0; i < alphabet.length(); i++)
			{
				temp_string = current_string + alphabet[i];
				pattern_stack.push(temp_string);
				//for every character in the alphabet, append to pattern_string
				//and push it
				//adds 26 new strings to the stack
			}
		}
	}
}
