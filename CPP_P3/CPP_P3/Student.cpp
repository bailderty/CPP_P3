//
//  Student.cpp
//  StudentDatabase
//
//  Created by Brett Meyer on 2/29/16.
//  Copyright © 2016 BDM. All rights reserved.
//

#include <stdio.h>
#include "Student.h"
using namespace std;

//Constructor
Student::Student(int id, int numCourses)
{

}
//return gpa of student
float Student::getGPA()
{
    //if gpa has not been calculated
    if (gpa == 0) {
        float totalGPA = 0;
        float totalCredits = 0;
        for (int i = 0; i< Courses.size(); i++) {
            Coursetype c = Courses.at(i);
            if(c.grade.compare("A")==0)
            {
                totalGPA = totalGPA + (4 * c.credits);
            }
            else if (c.grade.compare("AB")==0)
            {
                totalGPA = totalGPA + (3.5 * c.credits);
            }
            else if (c.grade.compare("B")==0)
            {
                totalGPA = totalGPA + (3 * c.credits);
            }
            else if (c.grade.compare("BC")==0)
            {
                totalGPA = totalGPA + (2.5 * c.credits);
            }
            else if (c.grade.compare("D")==0)
            {
                totalGPA = totalGPA + (2 * c.credits);
            }
            else
            {
                totalGPA = totalGPA + (0 * c.credits);
            }
            totalCredits = totalCredits + c.credits;
        }
        gpa =  totalGPA / totalCredits;
        return gpa;
    }
    //return already calculated gpa
    else
    {
        return gpa;
    }
}

//return number of courses
int Student::getNumCourses()
{
    return nCourses;
}

//return student id
int Student::getId()
{
    return studentID;
}
//parameters int course number, int credits, char * grade
//add course to student
void Student::addStudentCourseInfo(int cNumber, int cCredits, char * g)
{
    Coursetype c;
    c.courseNum = cNumber;
    c.credits = cCredits;
    c.grade = g;
    transform(c.grade.begin(), c.grade.end(), c.grade.begin(), toupper);
    Courses.push_back(c);
}

//parameters int course number
//return true if student took course
bool Student::tookCourse(int courseNumber)
{
    for (int i = 0; i< Courses.size(); i++) {
        Coursetype c = Courses.at(i);
        if (c.courseNum == courseNumber) {
            return true;
        }
    }
    return false;
}

/*
 void Student::print()
 {
 std::cout << "student id: " << studentID << std::endl;
 cout << "num Courses: " << nCourses << endl;
 for(int i = 0; i < Courses.size(); i++)
 {
 Coursetype c = Courses.at(i);
 cout << "couse number: " << c.courseNum << endl;
 cout << "credits: " << c.credits << endl;
 cout << "grade: " << c.grade << endl;
 }
 }
 */