/*
 Program Name: LinkedList.cpp
 Programmer: Moris Gomez
 Date: Saturday 03/15/2024
 Version Control: 20.0
 About: Week 5, CSCI 2, HW.
 Description:
  Create a Linked List object that 1) adds Nodes to the end of
  Linked List, 2) gets the size of said Linked List and 3)
  searches for a specific matching data member from a Node.
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
public:
//default constructor:
    Node()
    {
        data = 0;
        next = NULL;
    }
    
//constructor w/ 1 argument:
    Node(int d)
    {
        data = d;
        next = NULL;
    }
}; //end Node class.

class LinkedList
{
public:
    Node *head; //empty pointer for 'head' Node.
    Node *temp; //empty pointer for 'temp' Node. //has to have class scope to link Nodes!
public:
//default constructor:
    LinkedList()
    {
        head = NULL; //'head' pointer assigned address of NULL.
        temp = new Node; //'temp' pointer assigned address of a new Node.
    }
    
//FUNCTION #1: to create 'head' of the Linked List:
    void createHead(int data)
    {
        Node *n = new Node(data); //new Node created w/ address in 'n'.
        head = n; //'head' pointer assigned address of new Node 'n'.
        temp = n; //'temp' pointer also assigned address of new Node 'n'.
    } //end createHead function.
   
//FUNCTION #2: to add a new Node to end of Linked List:
    void add(int data)
    {
        Node *n = new Node(data); //new Node created w/ address in 'n'.
        temp->next = n; //link Node in 'temp' w/ new Node 'n'.
        temp = n; //now that previous 'temp' is linked w/ new Node 'n,' assign 'n' to 'temp.'
    } //end add function.
    
//FUNCTION #3: return the size of the linked list (number of nodes)
    int getSize()
    {
        Node *current = head;
        int counter = 0; //tracks each Node passed in current.
        while(current != NULL) //as long as 'current' points to an actual Node...
        {
            counter = counter + 1; //add 1 for each iteration.
            current = current->next; //make 'current' point to Node's 'next' address.
        }
        return counter;
    } //end getSize function.
    
//FUNCTION #4: to display Linked List object:
    void display()
    {
        Node *current = head;
        int counter = 1; //tracks each Node passed in current.
        while(current != NULL)
        {
            cout << "this is Node " << counter << " with address of: " << current << endl;
            cout << "it has a 'data' value of: " << current->data << endl;
            cout << "it points to next address of: " << current->next << endl;
            cout << "----------------" << endl;
            current = current->next; //current is Node #2 via 'next' attribute.
            counter = counter + 1;
        } //end while loop.
    } //end display function.
    
//FUNCTION #5: to check list for a specific node and return true or false:
    bool search(int data)
    {
        Node *current;
        current = head; //point to 'head'
        bool flag = false;
        while (current != NULL)
        {
            if (data == current->data) //data argument matches data of 'current' node.
            {
                flag = true; //matching Node found in List.
                break; //exit loop as soon as we find matching 'data'.
            }
            else
            {
                current = current->next; //move to 'next' Node.
            }
        } //end loop.
        return flag;
    } //end search function.
}; //end LinkedList class.

//FUNCTION #MAIN: driver for program:
int main()
{
//create a Linked List object:
    LinkedList listOne;
    listOne.createHead(1); //makes 'head' of list w/ 'data' value of 1.
    listOne.add(2); //adds a Node w/ 'data' value of 2.
    listOne.add(3); //adds a Node w/ 'data' value of 3.
    listOne.add(4); //adds a Node w/ 'data' value of 4.
    //'next' value is 'NULL' bc no new Node to link w/.
    //last node will always have a 'next' value of 'NULL' bc of Node class constructors.
    //unless directly changed, a Node data type will have a 'NULL' for 'next'.
    listOne.display();
    cout << "your Linked List is made of: " << listOne.getSize() << " Nodes."<< endl;
    cout << "is there a Node in the List w/ a 'data' value of 3 (0 = F, 1 = F)? " << listOne.search(3)  << endl;
    return 0;
} //end main driver function.
