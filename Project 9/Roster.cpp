/*
Jason Cho
CSCI 235
Professor Ligorio
Project 9
Roster.cpp
--implementation file for the Roster ADT--
*/

#include "Roster.hpp"


//********CONSTRUCTORS//DESTRUCTORS*********//
//******************************************//
Roster::Roster() {} //defualt constructor

Roster::Roster(const Roster& tree) 
{
        root_ptr_ = copyTree(tree.root_ptr_);
} //copy constructor

Roster::~Roster()
{
        destroyTree(root_ptr_);
}

bool Roster::isEmpty()
{
        return root_ptr_ == nullptr;
}

void Roster::add(const Student& new_student)
{
        std::shared_ptr<BinaryNode<Student>> new_student_ptr = std::make_shared<BinaryNode<Student>>(new_student);
        root_ptr_ = placeNode(root_ptr_, new_student_ptr);
}

void Roster::add(std::vector<Student> student_list)
{
        for(int i = 0; i < student_list.size();i++)
        {
                add(student_list[i]);
        }
}
void Roster::remove(const Student& remove_student)
{
        root_ptr_ = removeValue(root_ptr_,remove_student);
}
        
int Roster::getHeight()
{
        return getHeightHelper(root_ptr_);
}
        
void Roster::display()
{
        Printer display;
        inorderTraversal(root_ptr_,display);
}

void Roster::rotateLeft()
{
}

void Roster::rotateRight()
{
}

////////////////////////////////////////////////////////////////
//*************TRAVERSALS*************************************//
////////////////////////////////////////////////////////////////
void Roster::inorderTraversal(std::shared_ptr<BinaryNode<Student>> tree_ptr,Printer& print_student)
{
        if(tree_ptr != nullptr)
        {
                inorderTraversal(tree_ptr->getLeftChildPtr(),print_student);
                Student curr_student = tree_ptr->getItem();
                print_student(curr_student);
                inorderTraversal(tree_ptr->getRightChildPtr(),print_student);
        }
}
        

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//************************************************PRIVATE HELPER FUNCTIONS**********************************************//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//private helper function for the copy constructor
std::shared_ptr<BinaryNode<Student>> Roster::copyTree(std::shared_ptr<BinaryNode<Student>> old_tree_root_ptr)
{
        std::shared_ptr<BinaryNode<Student>> new_tree_ptr = nullptr;
        //copy tree nodes during a preorder traversal
        if(old_tree_root_ptr != nullptr)
        {
                //copy node
                new_tree_ptr = std::make_shared<BinaryNode<Student>>(old_tree_root_ptr->getItem(), nullptr, nullptr);
                new_tree_ptr->setLeftChildPtr(copyTree(old_tree_root_ptr->getLeftChildPtr()));
                new_tree_ptr->setRightChildPtr(copyTree(old_tree_root_ptr->getRightChildPtr()));
        }
        
        return new_tree_ptr;
}

//private helper function for the destructor
void Roster::destroyTree(std::shared_ptr<BinaryNode<Student>> sub_tree_ptr)
{
        if(sub_tree_ptr != nullptr)
        {
                destroyTree(sub_tree_ptr->getLeftChildPtr());
                destroyTree(sub_tree_ptr->getRightChildPtr());
                sub_tree_ptr.reset();
        }
}

//private helper function for getHeight
int Roster::getHeightHelper(std::shared_ptr<BinaryNode<Student>> sub_tree_ptr)
{
        if(sub_tree_ptr == nullptr)
        {
                return 0;
        }
        else
        {
                return 1 + std::max(getHeightHelper(sub_tree_ptr -> getLeftChildPtr()), 
                                    getHeightHelper(sub_tree_ptr -> getRightChildPtr()));
        }
}

//private helper function for ADD
std::shared_ptr<BinaryNode<Student>> Roster::placeNode(std::shared_ptr<BinaryNode<Student>> subtree_ptr,
                                                       std::shared_ptr<BinaryNode<Student>> new_node_ptr)
{
        if(subtree_ptr == nullptr)
        {
                return new_node_ptr;
        }
        else if(is_same(subtree_ptr->getItem(),new_node_ptr->getItem()))
        {
                return subtree_ptr;
        }
        else
        {
                if(compare(subtree_ptr->getItem(),new_node_ptr->getItem()))
                {
                        subtree_ptr->setLeftChildPtr(placeNode(subtree_ptr->getLeftChildPtr(),new_node_ptr));
                }
                else
                {
                        subtree_ptr->setRightChildPtr(placeNode(subtree_ptr->getRightChildPtr(),new_node_ptr));
                }
                return subtree_ptr;
        }
}

//private helper function for REMOVE
std::shared_ptr<BinaryNode<Student>> Roster::removeValue(std::shared_ptr<BinaryNode<Student>> subtree_ptr, 
                                                         const Student& target)
{
        //target is not in the tree
        if(subtree_ptr == nullptr)
        {
                return subtree_ptr;
        }
        //target has been found and removed
        else if(is_same(subtree_ptr->getItem(),target))
        {
                return removeNode(subtree_ptr);
        }
        else
        {
                if(compare(subtree_ptr->getItem(),target))
                {
                        subtree_ptr->setLeftChildPtr(removeValue(subtree_ptr->getLeftChildPtr(),target));
                }
                else
                {
                        subtree_ptr->setRightChildPtr(removeValue(subtree_ptr->getRightChildPtr(),target));
                }
                return subtree_ptr;
        }
}

//helper function for removeValue
std::shared_ptr<BinaryNode<Student>> Roster::removeNode(std::shared_ptr<BinaryNode<Student>> node_ptr)
{
        //Case 1-- node is a leaf, its deleted
        if(node_ptr->isLeaf())
        {
                node_ptr.reset();
                return node_ptr;
                //deleted node and return nullptr
        }
        //Case 2-- node has one child
        else if(node_ptr->getLeftChildPtr() == nullptr) //only has a right child
        {
                return node_ptr->getRightChildPtr();
        }
        else if(node_ptr->getRightChildPtr() == nullptr) //only has a left child
        {
                return node_ptr->getLeftChildPtr();
        }
        //Case 3-- has two children
        else
        {
                Student replace_student(0,"","");
                //will find leftmost leaf in right subtree, save value in new_node_value and delete
                node_ptr->setRightChildPtr(removeLeftmostNode(node_ptr->getRightChildPtr(),replace_student));
                node_ptr->setItem(replace_student);
                return node_ptr;
        }
}

//helper function for removeNode
std::shared_ptr<BinaryNode<Student>> Roster::removeLeftmostNode(std::shared_ptr<BinaryNode<Student>> nodePtr,
                                                                Student& inOrderSucessor)
{
        if(nodePtr->getLeftChildPtr() == nullptr)
        {
                inOrderSucessor = nodePtr->getItem();
                return removeNode(nodePtr);
        }
        else
        {
                nodePtr->setLeftChildPtr(removeLeftmostNode(nodePtr->getLeftChildPtr(),inOrderSucessor));
                return nodePtr;
        }
}

//helper function comparing to see if two students are equal
bool Roster::is_same(Student obj1, Student obj2) const
{
	    if(obj1.getFirstName() == obj2.getFirstName() && obj1.getLastName() == obj2.getLastName())
	    {
		return true;
	    }
	    else
	    {
		return false;
	    }
}

//helper fucntion comarping and seeing which student has priority based off last name
bool Roster::compare(Student obj1, Student obj2) const
{
    	if((obj1.getLastName() > obj2.getLastName()) ||
	   (obj1.getLastName() == obj2.getLastName() && obj1.getFirstName() > obj2.getFirstName()))
	{
        	return true;
    	}
    	else
	{
        	return false;
    	}
}

