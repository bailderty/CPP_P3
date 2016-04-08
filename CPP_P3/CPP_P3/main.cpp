//
//  main.cpp
//  CPP_P3
//
//  Created by Brett Meyer on 4/7/16.
//  Copyright © 2016 Brett Meyer. All rights reserved.
//

#include <iostream>
#include "Student.h"
#include "SortedList.h"


//tests Student.cpp
void test1()
{
    Student * s1 = new Student();
    Student * s2 = new Student(0);
    Student * s3 = new Student(0,0,0.0);
    if (s1->getID() != s2->getID()) {
        std::cout<<"Error constructor Student(int ID) in Student.cpp\n";
        exit(1);
    }
    if (s1->getID() != s3->getID() || s1->getCredits() != s3->getCredits() || s1->getGPA() != s3->getGPA()) {
        std::cout<<"Error constructor Student(int ID, int cr, double grPtAv) in Student.cpp\n";
        exit(1);
    }
    std::cout<<"Test1 passed\n";
}

//tests SortedList.cpp
void test2()
{
    SortedList * sl = new SortedList();
    Student * s1 = new Student(1);
    Student * s2 = new Student(0);
    sl->insert(s1);
    sl->insert(s2);
    sl->print();
    
}

int main()
{
    test1();
    return 0;
}