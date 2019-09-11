//Fellipe F Lopes 
//CS 163
//This file has all the structs and classes necessary 
//for the program to work. The head of the list is hidden
//as a private member of the class. 


#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;

struct avatar
{
    char* aname;
    char* charac1;
};
struct a_node
{
    avatar personagem;
    a_node* next;
};

struct g_node
{
    char* gname;
    g_node* next;
    a_node* head{};
};

class Game
{
    public:
        Game();
        ~Game();
        bool newgame(char gamename []);//OK
        bool displayall();//OK
        bool gamesearch(char gamename [], int dowhat);//OK
        bool getinfo(avatar personagem, char gamename3 []);//OK

        //bool editavatar(char gamename []);

    private:
        bool delgame(g_node*& temp);//OK
        bool gamesearch(g_node*& ghead, char gamename [], int dowhat);//OK
        bool displayall(g_node* ghead);//OK
        bool getinfo(g_node*& ghead, avatar personagem, char gamename3 []);//OK
        bool newavatar(g_node*& ghead, avatar personagem);//OK

        bool displaychar(g_node* ghead);//OK
        //bool editavatar();
        
        
        g_node* ghead;
};
