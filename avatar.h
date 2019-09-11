//Fellipe Ferreira Lopes 

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
        //bool displaychar();

    private:
        bool displaychar(a_node* head);
//        a_node* head;

};
