//
//  Student.cpp
//  StudentDatabase
//
//  Created by Brett Meyer on 2/29/16.
//  Copyright © 2016 BDM. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Student.h"

// Constructors
// Constructs a default student with an ID of 0, 0 credits, and 0.0 GPA.
Student::Student()
{
    studentID = 0;
    credits = 0;
    GPA = 0.0;

}

// Constructs a student with the given ID, 0 credits, and 0.0 GPA.
Student::Student(int ID)
{
    studentID = ID;
    credits = 0;
    GPA = 0.0;
}

// Constructs a student with the given ID, number of credits, and GPA.
Student::Student(int ID, int cr, double grPtAv)
{
    studentID = ID;
    credits = cr;
    GPA = grPtAv;
}

// Accessors
// returns the student ID
int Student::getID() const
{
    return studentID;
}

// returns the number of credits
int Student::getCredits() const
{
    return credits;
}

// returns the GPA
double Student::getGPA() const
{
    return GPA;
}

// Other methods

// Updates the total credits and overall GPA to take into account the
// additions of the given letter grade in a course with the given number
// of credits.  The update is done by first converting the letter grade
// into a numeric value (A = 4.0, B = 3.0, etc.).  The new GPA is
// calculated using the formula:
//
//            (oldGPA * old_total_credits) + (numeric_grade * cr)
//   newGPA = ---------------------------------------------------
//                        old_total_credits + cr
//
// Finally, the total credits is updated (to old_total_credits + cr)
void Student::update(char grade, int cr)
{
    int g = 0;
    if(grade == 'A')
    {
        g = 4;
    }
    else if (grade == 'B')
    {
        g = 3;
    }
    else if (grade == 'C')
    {
        g = 2;
    }
    else if (grade == 'D')
    {
        g = 1;
    }
    else if (grade == 'F')
    {
        g = 0;
    }
    
    GPA = (GPA * credits) + (g * cr) / (credits + cr);
    credits = credits + cr;
}

// Prints out the student to standard output in the format:
//   ID,credits,GPA
// Note: the end-of-line is NOT printed after the student information
void Student::print() const
{
    std::cout<<studentID<<","<<credits<<","<<GPA;
}
