/*
Name:Ashraf Omer Obied Ali
Class:Second
Department:Computer
*/
#include<iostream>
#include <stdlib.h>
#include <string >
using namespace std;
struct node
{
   string name , number;
   node *next;
};
node *head = NULL , *newnode , *temp;
int len = 0 ;
void C_node ()
{
	//input and output code
    newnode = new node;
    cout<<"Enter The Name ";
    cin>>newnode->name;
    cout<<"Enter The Number ";
    cin>>newnode->number;
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
        temp = newnode;
    }
    else
    {
        temp->next= newnode;
        temp = newnode;
    }
}
void display () // for show contact list that you input
{
    if(head == NULL)
    {
        cout<<"Contact list is Empty "<<endl;
    }
    else
    {
        node *trav = head ;
        while (trav != NULL)
        {
            cout<<"\n\t\tFull Name "<<trav->name<<endl;
            cout<<"\t\tPhone Number "<<trav->number<<endl;
            trav= trav->next;
            len++;
        }
        cout<<"Total contacts in the list = "<<len<<endl;
    }
}
void search_contact () // for serach contact
{
    node *search_node = head;
    string srch;
    int count = 1;
    cout<<"Enter your desired contact you want to search ";
    cin>>srch;
    bool found = false;
    if(head == NULL)
    {
        cout<<"\nList is Empty "<<endl;
    }
    else
    {
        while (search_node != NULL) // while function
        {
            if(srch == search_node->name || srch == search_node->number)
            {
                cout<<"\n\t\tFull name: "<<search_node->name<<endl;
                cout<<"\t\tPhone number: "<<search_node->number<<endl;
                found =true;
                break;
            }
            search_node = search_node->next;
            count++;
        }
    }
    if(found == true)
    {

        cout<<"\t\tIndex of the Contact = "<<count<<endl;
    }
    else
    {
        cout<<"Desired contact not fount "<<endl;
    }
}
void at_given () ///delete output
{
    int pos ;
    node *next_node;
    temp = head;
    cout<<"Enter Your Desired Position From Where You Want To Delete Contact "<<endl;
    cin>>pos;
    if(head == NULL) //if function
    {
        cout<<"List is Empty "<<endl;
    }
    else if (pos > len)
    {
        cout<<"Invalid Position "<<endl;
    }
    else if(pos == 0)
    {
        temp = head;
        head = head->next;
        delete temp;
        cout<<"Contact has been deleted "<<endl;
    }
    else // delete contact
    {
        for (int i = 1 ; i<pos ; i++)
        {
            temp = temp->next;
        }
        next_node = temp->next;
        temp->next = next_node->next;
        delete next_node;
        cout<<"Contact Has Been Deleted "<<endl;
    }
}
void clear_all () //to clear all list
{
    if(head == NULL)
    {
        cout<<"List is Empty "<<endl;
    }
    else
    {
        temp = head ;
        while (head != NULL)
        {
            head = head->next;
            delete temp;
        }
        cout<<"\n\t\tALL contact list has been deleted "<<endl;
    }
}
void menu () //cases to input number you want
{
    cout<<"Enter 1 to add contact "<<endl;
    cout<<"Enter 2 to display all contact "<<endl;
    cout<<"Enter 3 to search contact "<<endl;
    cout<<"Enter 4 to delete contact "<<endl;
    cout<<"Enter 5 to clear All contact "<<endl;
}
int main () //main code
{
	// main switch cases
    int op;
    while (true )
    {
        menu();
        cin>>op;
        switch (op)
        {
        case 1:
            C_node();
            break;
        case 2:
            len = 0;
            display();
            break;
        case 3:
            search_contact();
            break;
        case 4:
            at_given();
            break;
        case 5:
            clear_all();
            break;
        default:
            cout<<"Invalid Option "<<endl;
            //end code
        }
    }
}

