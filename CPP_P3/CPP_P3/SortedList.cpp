
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

// copy constructor
SortedList::SortedList(const SortedList &S)
{
    copyList(S.head);
}

// destructor
SortedList::~SortedList()
{
    freeList(head);
}

// assignment
SortedList & SortedList::operator=(const SortedList &S)
{
    if (this != &S) {
        copyList(S.head);
    }
    return *this;
}

// If a student with the same ID is not already in the list, inserts
// the given student into the list in the appropriate place and returns
// true.  If there is already a student in the list with the same ID
// then the list is not changed and false is returned.
bool SortedList::insert(Student *s)
{
    Listnode * newNode = new Listnode();
    newNode->student = s;
    //first node
    if (head->next == NULL || head->student->getID() >= newNode->student->getID())
    {
        //student id are equal return false
        if (head->student != NULL && head->student->getID() == newNode->student->getID())
        {
            newNode->student=NULL;
            delete newNode;
            return false;
        }
        newNode->next = head;
        head = newNode;
        newNode = NULL;
        delete newNode;
        return true;
    }
    //rest of nodes;
    else
    {
        Listnode * current;
        current = head;
        //find node before so we have pointer to node that is larger.
        while (current->next->next != NULL && current->next->student->getID() < newNode->student->getID())
        {
            current = current->next;

        }
        //student id are equal return false
        if (current->next->student != NULL && current->next->student->getID() == newNode->student->getID())
        {
            newNode->student = NULL;
            delete newNode;
            return false;
        }
        newNode->next = current->next;
        current->next = newNode;
        newNode = NULL;
        delete newNode;
        return true;
    }
}

// Searches the list for a student with the given student ID.  If the
// student is found, it is returned; if it is not found, NULL is returned.
Student * SortedList::find(int studentID)
{
    Listnode * n = head;
    //look at each id to see if they match if not return NULL
    while (n->next != NULL)
    {
        if (n->student->getID() == studentID)
        {
            return n->student;
        }
        n = n->next;
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
        if (n->student->getID() > studentID)
        {
            return NULL;
        }
        if (n->next->student->getID() == studentID)
        {
            s = n->next->student;
            Listnode * temp = n->next;
            n->next = n->next->next;
            delete temp;
            return s;
        }
        n = n->next;
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
        std::cout<<n->student->getID()<<std::endl;
        n = n->next;
    }
}


//private

// removes all nodes from this list. Be sure to free all memory
void SortedList::freeList(SortedList::Listnode *L)
{
    Listnode * n = L;

    //delete all nodes
    while (n != NULL)
    {
        L = L->next;
        delete n;
        n = L;
    }
    
}

// returns a pointer to the first node of a list with a
// copy of all nodes of the sorted list
SortedList::Listnode * SortedList::copyList(SortedList::Listnode *L)
{
    //if L is null return NULL
    if (L == NULL) {
        return NULL;
    }
    //first node
    Listnode * temp = L;
    Listnode * n = new Listnode();
    n->student = new Student(*L->student);
    n->next = NULL;
    //rest of nodes
    Listnode * const head = n;
    while(temp != NULL)
    {
        n = new Listnode();
        n->student = new Student(*temp->student);
        n->next = NULL;
        temp = temp->next;
    }
    //return head pointer
    return head;
}
