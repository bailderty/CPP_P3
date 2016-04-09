#include <stdlib.h>
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
    
    Student * s4 = new Student(10,0,0.0);
    s4->update('A', 1);
    s4->update('B', 1);
    if (s4->getGPA() != 3.5) {
        std::cout<<"Error Student.cpp update does not work\n";
        exit(1);
    }
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    std::cout<<"Test1 passed\n";

}

//tests SortedList.cpp
void test2()
{
    SortedList * sl = new SortedList();
    Student * find;
    Student * s0 = new Student(6);
    Student * s1 = new Student(15);
    Student * s2 = new Student(9);
    Student * s3 = new Student(3);
    Student * s4 = new Student(0);
    Student * s5 = new Student(12);
    find = s1;
    sl->insert(s0);
    sl->insert(s1);
    sl->insert(s2);
    sl->insert(s3);
    sl->insert(s4);
    sl->insert(s5);
    if (sl->insert(s0) != false)
    {
        std::cout<<"Error: SortedList.cpp insert should have returned false\n";\
        exit(1);
    }
    if (sl->insert(s4) != false)
    {
        std::cout<<"Error: SortedList.cpp insert should have returned false\n";\
        exit(1);
    }

    find = sl->find(6);
    if (find->getID() != 6)
    {
        std::cout<<"Error: SortedList.cpp find did not find id 5\n";
        exit(1);
    }
    find = sl->find(-1);
    if (find != NULL)
    {
        std::cout<<"Error: SortedList.cpp find did not return NULL when given an id not in the list\n";
        exit(1);
    }
    
    for (int i = 0; i < 6; i++) {
        s1 = sl->find(i*3);
        if (s1->getID() != i * 3) {
            std::cout<<"Error: SortedList.cpp insert\n";
            exit(1);
        }
    }
    //remove middle
    sl->remove(6);
    //remove first node
    sl->remove(0);
    //remove last node
    sl->remove(15);
    
    if (sl->remove(0) != NULL)
    {
        std::cout<<"Error: SortedList.cpp remove should have returned NULL\n";
        exit(1);
    }
    
    if (sl->remove(0) != NULL)
    {
        std::cout<<"Error: SortedList.cpp remove should have returned NULL\n";
        exit(1);
    }
    
    //should print 3 9 12 and it does
    //sl->print();
    
    delete s0;
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
    delete find;
    delete sl;
    
    std::cout<<"Test2 passed\n";
}

int main()
{
    //test Student.cpp
    test1();
    //test SortedList.cpp
    test2();
    std::cout<<"All Tests have passed\n";
    return 0;
}