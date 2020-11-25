//
//  Printer.hpp
//  BST
//
//  Created by Tiziana Ligorio on 12/5/18.
//  Copyright © 2018 Tiziana Ligorio. All rights reserved.
//
// Description: a derived class of Visitor, used in tree traversals to print Student objects

#ifndef Printer_hpp
#define Printer_hpp

#include "Visitor.hpp"
#include "Student.hpp"
#include <iostream>
#include <string>


class Printer: public Visitor<Student>
{
public:
    
    /**@post prints Student information in the form "id_, first_name_, last_name_"  **/
    void operator()(Student&) override;
    
    /**@post prints Student information in the form "id_, first_name_, last_name_"  for both parameters, one per line**/
    void operator()(Student&, Student&) override;
    
};


#endif /* Printer_hpp */
