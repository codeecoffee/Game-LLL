//Fellipe Ferreira Lopes
//CS 163 


#include "game.h"



Avatar::Avatar()
{
   head= NULL; 
}

Avatar::~Avatar()
{
    while(head)
    {
        a_node* temp;
        temp= head->next;
        delete [] temp->aname;
        delete [] temp->charac1;
        delete temp;
        head= temp;
    }
}

bool Avatar::newavatar(char avatarname[], char avatarchar[])
{
    if(!head)
    {
        head= new a_node;
        head->next= NULL;

        head->aname= new char[strlen(avatarname)+1];
        strcpy(head->aname, avatarname);
        
        head->charac1= new char[strlen(avatarchar)+1];
        strcpy(head->charac1, avatarchar);

        return 0;
    }
    
    a_node* temp= new a_node;
    temp= head->next;
    temp->next= NULL;

    temp->aname= new char[strlen(avatarname)+1];
    strcpy(temp->aname,avatarname);

    temp->charac1= new char[strlen(avatarchar)+1];
    strcpy(temp->charac1, avatarchar);

    return 0;
}
//Need to make an edit func for editing avatar's 
//charac. 
/*
bool Avatar::addcharac(char addchar[])
{

}
*/
/*
bool Avatar::displaychar()
{
    return displaychar(head);
}
*/
bool Avatar::displaychar(a_node* head)
{
    if(!head)
    {    
        return 0;
    }     
    cout<< '\n'
        <<'\t'<<'\t'<<"+++++++++++++++++++++++++++++++"         <<'\n'
        <<'\t'<<'\t'<<"+"<<'\t'<<head->aname       << "+"<<'\n'
        <<'\t'<<'\t'<<"+"<<'\t'<<head->charac1     << "+"<<'\n'
        <<'\t'<<'\t'<<"================================"        <<endl;
/*
    cout<< '\t'<<'\t'<< "+++++++++++++++++++++++++"     <<'\n'
        << '\t'<<'\t'<< "|"<< head->aname         << "|"<<'\n'
        << '\t'<<'\t'<< "|"<< head->charac1       << "|"<<'\n'
        << '\t'<<'\t'<< "+++++++++++++++++++++++++"     <<endl;
*/
    displaychar(head->next);
}
