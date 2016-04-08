//
//  SortedList.cpp
//  CPP_P3
//
//  Created by Brett Meyer on 4/7/16.
//  Copyright © 2016 Brett Meyer. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "SortedList.h"

// constructor
SortedList::SortedList()
{
    Listnode * head = new Listnode();
    this->head = head;
    this->head->student = NULL;
    this->head->next = NULL;
}

// If a student with the same ID is not already in the list, inserts
// the given student into the list in the appropriate place and returns
// true.  If there is already a student in the list with the same ID
// then the list is not changed and false is returned.
bool SortedList::insert(Student *s)
{
    //insert into first node
    if (head->student == NULL)
    {
        head->student = s;
        return true;
    }
    //insert into any node after first node
    else
    {
        //set newNode
        Listnode * newNode = new Listnode();
        newNode->student = s;
        //while newNode's ID is > next node's id continue otherwise break
        Listnode * n = head;
        while (s->getID() > n->next->student->getID())
        {
            if (n->next != NULL)
            {
                n->next = n->next->next;
            }
            else if (n->next == NULL)
            {
                break;
            }
        }
        //if newNode's id is equal to next node's id return false
        if (s->getID() == n->next->student->getID())
        {
            return false;
        }
        //insert node
        else
        {
            newNode->next = n->next;
            n->next = newNode;
            return true;
        }
    }
}

// Searches the list for a student with the given student ID.  If the
// student is found, it is returned; if it is not found, NULL is returned.
Student * SortedList::find(int studentID)
{
    Listnode * n = head;
    while (n->next != NULL)
    {
        if (n->student->getID() == studentID)
        {
            return n->student;
        }
    }
    return NULL;
}

// Searches the list for a student with the given student ID.  If the
// student is found, the student is removed from the list and returned;
// if no student is found with the given ID, NULL is returned.
// Note that the Student is NOT deleted - it is returned - however,
// the removed list node should be deleted.
Student * SortedList::remove(int studentID)
{
    Student * s;
    //if head is the only node and it matches studentID
    if (head->student->getID() == studentID && head->next == NULL)
    {
        s = head->student;
        head->student = NULL;
        return s;
    }
    //if head is not the only node and it matches studentID
    else if (head->student->getID() == studentID)
    {
        s = head->student;
        Listnode * n = head->next;
        delete head;
        head = n;
        return s;
    }
    //if a middle node matches studendID
    Listnode * n = head;
    while (n->next->next != NULL)
    {
        if (n->next->student->getID() == studentID)
        {
            s = n->next->student;
            Listnode * temp = n->next;
            n->next = n->next->next;
            delete temp;
            return s;
        }
    }
    //if last node matches studentID
    if (n->next->student->getID() == studentID)
    {
        s = n->next->student;
        n = n->next;
        delete n;
        return s;
    }
    //no node matched studendID
    return NULL;
}

// Prints out the list of students to standard output.  The students are
// printed in order of student ID (from smallest to largest), one per line
void SortedList::print() const
{
    Listnode * n = head;
    while (n->next != NULL)
    {
        if (n->next->next != NULL)
        {
            std::cout<<n->student->getID()<<",";
        }
        else
        {
            std::cout<<n->student->getID();
        }
    }
}

//private

// removes all nodes from this list. Be sure to free all memory
void SortedList::freeList(SortedList::Listnode *L)
{
    Listnode * n = L;

    //delete all but last node
    while (L->next != NULL)
    {
        L = L->next;
        delete n;
        n = L;
    }
    //delete last node
    delete L;
}

// returns a pointer to the first node of a list with a
// copy of all nodes of the sorted list
SortedList::Listnode * SortedList::copyList(SortedList::Listnode *L)
{
    return NULL;
}
