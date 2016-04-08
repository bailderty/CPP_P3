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
    Student * find = new Student();
    Student * s0 = new Student(5);
    Student * s1 = new Student(12);
    Student * s2 = new Student(6);
    Student * s3 = new Student(4);
    Student * s4 = new Student(2);
    Student * s5 = new Student(8);
    sl->insert(s0);
    sl->insert(s1);
    sl->insert(s2);
    sl->insert(s3);
    sl->insert(s4);
    sl->insert(s5);
    find = sl->find(1);
    find->print();
    sl->print();
    
}

int main()
{
    test1();
    test2();
    return 0;
}