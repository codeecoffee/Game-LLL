//Fellipe Ferreira Lopes 
//CS163

#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;


struct a_node
{
    char* aname;
    char* charac1;
   // char* charac2;
   // char* charac3;
    a_node* next; 
};

class Avatar
{
    public:
        Avatar();
        ~Avatar();
        bool newavatar(char avatarname[], char avatarchar[]);
        //bool addcharac(char addchar[]);
        bool displaychar();

    private:
        bool displaychar(a_node* head);
        a_node* head;

};

struct g_node
{
    char* gname;
    g_node* next;
    Avatar personagem; 
    a_node* head;
};

class Game
{
    public:
        Game();
        ~Game();
        bool newgame(char gamename[]);
        bool delgame(char gamename[]);
        bool displayall();
        bool gamesearch(char gamename[], int dowhat);
        bool getinfo(char avaname [], char avacharac [], char gamename []);
    private:
        g_node* ghead;
        bool gamesearch(g_node*& ghead, char gamename[], int dowhat);
        bool displayall(g_node* ghead);
        bool getinfo(g_node*& ghead, char avaname [], char avacharac [], char gamename []);
};
