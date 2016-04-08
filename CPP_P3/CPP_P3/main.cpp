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


void test3()
{
    SortedList * sl = new SortedList();
    Student * s1 = new Student(1);
    Student * s2 = new Student(0);
    sl->insert(s1);
    sl->insert(s2);
    sl->print();
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    test3();
    return 0;
}