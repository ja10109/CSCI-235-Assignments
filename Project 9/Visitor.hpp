//
//  Visitor.hpp
//  BST
//
//  Created by Tiziana Ligorio on 12/5/18.
//  Copyright © 2018 Tiziana Ligorio. All rights reserved.
//
// Description: an abstract Visitor used to derive functors to be used in tree traversals

#ifndef Visitor_hpp
#define Visitor_hpp

#include <stdio.h>
#include <string>

template<class T>
class Visitor
{
public:
    
    //abstract method forces ooverloaded operator() with one parameter
    virtual void operator()(T&) = 0;
    
    //abstract method forces ooverloaded operator() with two parameter
    virtual void operator()(T&, T&) = 0;
    
};

#endif /* Visitor_hpp */
