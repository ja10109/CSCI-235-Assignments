//
/** @file  Student.cpp */
//  Project9 for CSCI 235 - Software Design and Analysis II
//
//  Created by Tiziana Ligorio on 3/4/19.
//  Modified for Project9 Fall2019 on 11/29/19
//  Copyright © 2019 Tiziana Ligorio. All rights reserved.
//
/** Description:
    A simple Student class, serves as an illustrative example of OOP
 **/

#include "Student.hpp"

/** parameterized constructor
 @param id the student's unique identifier
 @param first the student's first name
 @param last the student's last name
 */
Student::Student(int id, std::string first, std::string last) :id_(id), first_name_(first), last_name_(last), major_(""), gpa_(0.0){}

/**copy constructor
 @param another_student student object to be copied
 */
Student::Student(const Student& another_student): id_(another_student.getID()), first_name_(another_student.getFirstName()), last_name_(another_student.getLastName()){}


/** @return: id_ */
int Student::getID() const
{
    return id_;
}

/** @return: returns first_name_ */
std::string Student::getFirstName() const
{
    return first_name_;
}

/** @return: returns last_name_ */
std::string Student::getLastName() const
{
    return last_name_;
}

/** @return: major_ the student's major */
std::string Student::getMajor() const
{
    return major_;
}
/** @return: gpa_ the student's gpa */
double Student::getGpa() const
{
    return gpa_;
}


//mutator methods

/** @param major the student's major */
void Student::setMajor(const std::string major)
{
    major_ = major;
}

/** @param gpa the student's gpa */
void Student::setGpa(const double gpa)
{
    gpa_ = gpa;
}

/** @post display Student data in the format
 first_name_ last_name_ majors in major_ with gpa: gpa_
 */
void Student::displayMember()
{
    std::cout << first_name_ << " " << last_name_ << " " << "majors in " << major_ << " with gpa: " << gpa_ << std::endl;
    
}


/**
 @param another_student student object to be copied
 */
void Student::operator= (const Student& another_student)
{
    id_ = another_student.getID();
    first_name_ = another_student.getFirstName();
    last_name_ = another_student.getLastName();
}
