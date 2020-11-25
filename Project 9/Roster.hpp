/*
Jason Cho
CSCI 235
Professor Ligorio
Project 9 BST-Roster ADT
Roster.hpp
Header file for the Roster ADT
*/

#include "Student.hpp"
#include "BinaryNode.hpp"
#include "Printer.hpp"
#include "Visitor.hpp"
#include <vector>
#include <iostream>
#include <string>

class Roster
{
	public:
		Roster();
		//defualt constructor
		Roster(const Roster& tree); 
		//copy constructor
		~Roster();
		//destructor
		bool isEmpty(); 
		//checks if left tree or right tree is null
		void add(const Student& new_student); 
		//adds the student object while maintaining BST
		void add(std::vector<Student> student_list); 
		//adds all the Student objects found in the vector argument, maintaining BST property
		void remove(const Student& remove_student);
		int getHeight(); 
		//returns the number of nodes on the longest path from root to leaf
		void display(); 
		// print all students inorder (as per inorder traversal), 
		// one per line, separated by comma ( i.e. “id, first_name, last_name\n” )
		void inorderTraversal(std::shared_ptr<BinaryNode<Student>> tree_ptr,Printer& print_student);
		//traversal function
	
		void rotateLeft();
		void rotateRight();
	
	private:
		std::shared_ptr<BinaryNode<Student>> root_ptr_;
		
		/////////////////////////////////////////////////////////////////////////////////
		////////////////////////////HELPER FUNCTIONS/////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////
		std::shared_ptr<BinaryNode<Student>> copyTree(std::shared_ptr<BinaryNode<Student>> old_tree_root_ptr);
		//helper function for the copy constructor
    		void destroyTree(std::shared_ptr<BinaryNode<Student>> sub_tree_ptr);
		//helper function for the destructor
    		std::shared_ptr<BinaryNode<Student>> placeNode(std::shared_ptr<BinaryNode<Student>> sub_tree_ptr, 
							       std::shared_ptr<BinaryNode<Student>> new_node_ptr);
		//helper for ADD function
    		std::shared_ptr<BinaryNode<Student>> removeValue(std::shared_ptr<BinaryNode<Student>> subtree_ptr,
								 const Student& target);
		//helper for REMOVE function
    		std::shared_ptr<BinaryNode<Student>> removeNode(std::shared_ptr<BinaryNode<Student>> node_ptr);
		//helper for removeValue
    		std::shared_ptr<BinaryNode<Student>> removeLeftmostNode(std::shared_ptr<BinaryNode<Student>> node_ptr, 
									Student& inOrderSucessor);
		//helper for removeNode
    		int getHeightHelper(std::shared_ptr<BinaryNode<Student>> sub_tree_ptr);
		//helper for getHeight
		bool is_same(const Student obj1, const Student obj2)const;
		//helper function comparing and seeing if two students are the same
		bool compare(const Student obj1, const Student obj2)const;
		//helper function comparing and seein which student has priority based off last name



};
