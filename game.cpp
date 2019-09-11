//Fellipe Ferreira Lopes
//CS163 


#include "game.h"


Game::Game()
{
    ghead= NULL;
}
Game::~Game()
{
    while(!ghead)
    {
        g_node* temp;
        temp= ghead->next;
        delete [] temp->gname;
        delete ghead;
        ghead= temp;
    }
}
bool Game::gamesearch(char gamename[], int dowhat)
{
    gamesearch(ghead, gamename, dowhat);
}
bool Game::gamesearch(g_node*& ghead, char gamename[], int dowhat)
{
    g_node* temp= ghead;
    int flag= 0;

    while(flag==0)
    {
        
        if(!temp)
        {
            break;
        }
        
        if(strcmp(temp->gname,gamename)==0)
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
                delgame(gamename);

            break;

        case 3:
            //nothing yet...
            break;
/*
        case 4:
            if(flag == 1)
             
            else 
                return flag;
            break;
*/  
    }
}

/* call search inside other func to be able to get info for getinfo,
 return pointer by reference (return *&ptr)  */

bool Game::getinfo(char avaname [], char avacharac [], char gamename [])
{
    getinfo(ghead, avaname, avacharac, gamename);
}

bool Game::getinfo(g_node*& ghead, char avaname [], char avacharac [], char gamename [])
{
    if(!ghead)
        return 0;
    else
    {
        //change statement in h file

        if(strcmp(gamename, ghead->gname)==0)
        {
            ghead->personagem.newavatar(avaname, avacharac);
        
        }
        getinfo(ghead->next, avaname, avacharac, gamename);
    }
}

bool Game::newgame(char gamename[])
{
    g_node* temp= new g_node;
    temp->next= NULL;

    temp->gname= new char[strlen(gamename)+1];
    strcpy(temp->gname, gamename);

    if(!ghead)
    {
        ghead= temp;
        temp= NULL;
        return 0;
    }

    ghead->next= temp;
        
    return 0;
}
bool Game::delgame(char gamename[])
{
   //if()
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

    cout<<'\t'<<'\t'<<"==============================="         <<'\n'
        <<'\t'<<'\t'<<"+"<<'\t'<<ghead->gname             << "+"<<'\n'
        <<endl;
    if(ghead->head)
    {
        ghead->personagem.displaychar(ghead->head);  
    }
    displayall(ghead->next);
}

