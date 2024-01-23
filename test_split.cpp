/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    Node* evens = NULL;
    Node* odds = NULL;

    Node* head;
    Node* one = NULL;
    Node* two = NULL;
    Node* three = NULL;
    Node* four = NULL;

    // TESTCASE1:Evens and odds
    one = new Node(1, NULL);
    two = new Node(2, NULL);
    three = new Node(3, NULL);
    four = new Node(4, NULL);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = NULL;

    head = one;
    evens = NULL;
    odds = NULL;

    split(head, odds, evens);

    cout << "Evens:" << endl;
    Node* temp = evens;
    while(temp != NULL){
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "Odds:" << endl;
    temp = odds;
    while(temp != NULL){
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;

    // TESTCASE2:Just evens

    one->value = 2;
    two->value = 2;
    three->value = 4;
    four->value = 6;

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = NULL;

    head = one;
    evens = NULL;
    odds = NULL;

    split(head, odds, evens);

    cout << "Evens:" << endl;
    temp = evens;
    while(temp != NULL){
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "Odds:" << endl;
    temp = odds;
    while(temp != NULL){
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;

    // TESTCASE3:Just odds

    one->value = 3;
    two->value = 3;
    three->value = 3;
    four->value = 9;

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = NULL;

    head = one;
    evens = NULL;
    odds = NULL;

    split(head, odds, evens);

    cout << "Evens:" << endl;
    temp = evens;
    while(temp != NULL){
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "Odds:" << endl;
    temp = odds;
    while(temp != NULL){
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;

    // Deallocate memory
    Node* curr = odds;
    Node* next = NULL;
    while (curr != NULL){
        next = curr->next;
        delete curr;
        curr = next;
    }

    curr = evens;
    next = NULL;
    while (curr != NULL){
        next = curr->next;
        delete curr;
        curr = next;
    }
}
