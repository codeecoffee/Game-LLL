//Fellipe F Lopes
//CS163
//This file coordinates all the functions declared in the associated H file. 
//All the functions that requires access to the head of the list receives
//information from the wrapper functions. 

#include "game.h"

Game::Game()
{
    ghead= NULL;
}
Game::~Game()
{
    while(ghead)
    {
        g_node* temp;
        temp= ghead-> next;
        delete [] temp->gname;
        
        if(ghead->head)
        {    
            while(ghead->head)
            {
                a_node* temp;
                temp= ghead->head->next;
                delete [] temp->personagem.aname;
                delete [] temp->personagem.charac1;
                delete temp;
                ghead->head= temp;
            }
        }
        delete ghead;
        ghead= temp;
    }
}

bool Game::gamesearch(char gamename [], int dowhat)
{
    gamesearch(ghead, gamename, dowhat);
}
bool Game::gamesearch(g_node*& ghead, char gamename [], int dowhat)
{
    int flag= 0;
    g_node* temp= ghead;
    
    while(flag==0)
    {
        if(!temp)
        {
            break;
        }

        if(strcmp(temp->gname, gamename)==0)
        {
            flag= 1;
        }

        temp= temp->next;
    }

    switch(dowhat)
    {
        case 1:
            if(flag == 1)
                return flag;
            else
                newgame(gamename);

            break;

        case 2:
            if(flag == 0)
                return flag;
            else
                delgame(temp);//maybe pass pointer ?

            break;
        case 3: //new avatar
            if(flag == 0)
                return flag;
            else

            break;
        case 4://display avatars of an specific game
            if(flag == 1)
                displaychar(temp);
            else
                return flag;
            break;
      /*  case 5://edit
            if(flag ==1)
            {
            
            }
            break;*/
    }
}

bool Game::newgame(char gamename [])
{
    g_node* temp= new g_node;

    temp->gname= new char[strlen(gamename)+1];
    strcpy(temp->gname, gamename);

    if(!ghead)
    {
        ghead= temp;
        temp= NULL;
        return 0;
    }

    temp->next= ghead;
    ghead= temp;
    temp= NULL;

    return 0;
}
bool Game::getinfo(avatar personagem, char gamename3 [])
{
    getinfo(ghead, personagem, gamename3);
}
bool Game::getinfo(g_node*& ghead, avatar personagem, char gamename3 [])
{
    if(!ghead)
        return 0;
    if(strcmp(gamename3, ghead->gname)==0)
    {
        newavatar(ghead, personagem);
    }
    getinfo(ghead->next, personagem, gamename3);
}
bool Game::newavatar(g_node*& ghead, avatar personagem)
{
    a_node* temp= new a_node;
    temp->next= NULL;

    temp->personagem.aname= new char[strlen(personagem.aname)+1];
    strcpy(temp->personagem.aname, personagem.aname);

    temp->personagem.charac1= new char[strlen(personagem.charac1)+1];
    strcpy(temp->personagem.charac1, personagem.charac1);

    if(!ghead->head)
    {
        ghead->head= temp;
        temp= NULL; 
        
        return 0;
    }
    
    ghead->head->next= temp;
    temp= NULL;

    return 0;   
}
bool Game::displayall()
{
    displayall(ghead);
}
bool Game::displayall(g_node* ghead)
{
    if(!ghead)
    {
        return 0;
    }
    
    cout<<'\t'<<'\t'<<"==========================="     <<'\n'
        <<'\t'<<'\t'<<"+    "<<ghead->gname<<"    +"     <<'\n'
        <<endl;
    
    if(ghead->head)
    {
        displaychar(ghead); //pass pointer; make private?
    }
    displayall(ghead->next);
}

bool Game::delgame(g_node*& temp)
{
    g_node* prev= ghead;
    
    if(temp == ghead)
    {
        ghead= temp->next;
        delete temp;
        return 0;
    }
    
    else
    {
        while(prev->next!=temp)
        {
            prev= prev->next;
        }
        if(temp->next)
        {
            prev->next= temp->next;
            delete temp;
        }
        else 
        {
            delete temp;
            prev->next= NULL;
        }
    }
    return 0;
}
bool Game::displaychar(g_node* ghead) //needs to pass a head->next to the func to make it recursive `
{
        cout<<'\n'
            <<'\t'<<'\t'<<"++++++++++++++++++++++++++++++"                  <<'\n'
            <<'\t'<<'\t'<<"+  "<< ghead->head->personagem.aname<<"  +"      <<'\n'
            <<'\t'<<'\t'<<"+  "<< ghead->head->personagem.charac1<<"    +"  <<'\n'
            <<'\t'<<'\t'<<"++++++++++++++++++++++++++++++"                  <<endl;
        if(ghead->head->next)
        {
            ghead->head= ghead->head->next;
            
            cout<<'\n'
                <<'\t'<<'\t'<<"++++++++++++++++++++++++++++++"                  <<'\n'
                <<'\t'<<'\t'<<"+  "<< ghead->head->personagem.aname<<"  +"      <<'\n'
                <<'\t'<<'\t'<<"+  "<< ghead->head->personagem.charac1<<"    +"  <<'\n'
                <<'\t'<<'\t'<<"++++++++++++++++++++++++++++++"                  <<endl;
        }


    return 0;
}

