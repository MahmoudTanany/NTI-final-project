#ifndef HEADERFILE_H_INCLUDED
#define HEADERFILE_H_INCLUDED
#define NULL    0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct to store the history of operation for each customer
typedef struct History
{
    float arr; // to store the value of the operation
    int type; // the type of operation 1=deposite , 0=withdraw
}history;

//struct for each customer contains all the data needed about each customer
typedef struct Data
{
    char ID[30];  // Customer ID
    char name[30]; // customer name
    char birthdate[20]; // customer birthdate
    char address[100]; // customer address
    char phone[30]; // customer phone number
    char balance[200]; // customer balance of money
    history customerh[6]; // struct defined before for the history of operations of the customer
    int counter2; // counter to count the number of operations done by the customer
}data;
// defining a struct for the each node in the linked list
typedef struct node
{
    data entry; // struct in the node contains the data in details entered by the user
    struct node* next; // struct of the same node to contain the next cell in the linked list
}node;

//struct defining the head of the list and the its size
typedef struct Linkedlist
{
    node *head;  // the head of the linked list
    int num_ofcustomers; // number of nodes in the list
}linkedlist;

char welcome_fn(linkedlist *ptr_List); // welcoming function to the user contains what the system offer
void CreateList(linkedlist *ptr_List); // once called function to start the linked list and create it
void AddNode(linkedlist *ptr_List); // adding new customer to the list
void printList(linkedlist *ptr_List); // printing all the customers signed up in the system
void DeleteCustomer(linkedlist *ptr_List); // deleting customer from the system
void UpdateCustomerInfo(linkedlist *ptr_List); // updating any of customer info
void Transact(linkedlist *ptr_List);  // depositing or withdrawn from customer money
void Customerhistory(linkedlist *ptr_List); // printing the history of operations for the customer
void specific(linkedlist *ptr_List); // printing a specific user information

#endif // HEADERFILE_H_INCLUDED
