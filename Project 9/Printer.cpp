//
//  Printer.cpp
//  BST
//
//  Created by Tiziana Ligorio on 12/5/18.
//  Copyright © 2018 Tiziana Ligorio. All rights reserved.
//
// Description: a derived class of Visitor, used in tree traversals to print Student objects

#include "Printer.hpp"


/**@post prints Student information in the form "id_, first_name_, last_name_"  **/
void Printer::operator()(Student& student)
{
    std::cout << student.getID() << ", " << student.getFirstName() << ", " << student.getLastName() << std::endl;
}


/**@post prints Student information in the form "id_, first_name_, last_name_"  for both parameters, one per line**/
void Printer::operator()(Student& a, Student& b)
{
    std::cout << a.getID() << ", " << a.getFirstName() << ", " << a.getLastName() << std::endl;
    std::cout << b.getID() << ", " << b.getFirstName() << ", " << b.getLastName() << std::endl;
}
