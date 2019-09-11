//Fellipe Ferreira Lopes 
// CS163
//This file contains the client program which calls the
//functions and receives back the results, being able to
//determine whether or not further action is needed.

#include <iostream>
#include <cctype>
#include <cstring>
#include "game.h"

using namespace std;


int main()
{
    Game agame;
    avatar personagem; 
    
    const int SIZE = 100;
    int caso= 0;
    int decision = 0;


    do
    {
        //menu part 
        cout <<"===================================="       <<  '\n'
             <<"           Main menu                "       <<  '\n'
             <<"What would you like to do?          "       <<  '\n'
             <<"1- Add a new game "                         <<  '\n'
             <<"2- Remove a game "                          <<  '\n'
             <<"3- Display all games"                       <<  '\n'
             <<"4- Add an avatar to an existing game"       <<  '\n'
             <<"5- Edit avatar"                             <<  '\n'
             <<"6- Display avatar of a game"                <<  '\n'
             <<"7- Exit"                                    <<  '\n'
             <<"===================================="       <<  endl;
            

        cin>> decision;
        cin.ignore(100, '\n');

        switch(decision)
        {
            case 1://newgame
                char gamename1[SIZE];
                caso= 1;

                cout<< "What is the name of the game you want to add?" <<endl;
                cin.get(gamename1, SIZE, '\n');
                cin.ignore(SIZE, '\n');
                gamename1[0]= toupper(gamename1[0]);
                
                if(agame.gamesearch(gamename1, caso)==1)
                {
                    cout<< "Game already added!" <<endl;
                }
                
                break;
            case 2://delgame
                char gamename2[SIZE];
                caso= 2;

                cout<< "What is the game you want to delete called?" <<endl;
                cin.get(gamename2, SIZE, '\n');
                cin.ignore(SIZE, '\n');
                gamename2[0]= toupper(gamename2[0]);
                
                if(agame.gamesearch(gamename2, caso)==0)
                {   
                    cerr<<                                           '\n'
                        <<                                           '\n'
                        <<"Game not found! Please check your input." 
                        <<                                           '\n'
                        <<                                           '\n'
                        <<endl;
                }
                else
                {
                    cout<<                                           '\n'
                        <<                                           '\n'
                        <<'\t'<<"Game deleted successifully." 
                        <<                                           '\n'
                        <<                                           '\n'
                        <<endl;
                } 
                break;
            case 3://displayall
                agame.displayall();
                
                break;
            case 4://newavatar
                char gamename3[SIZE];
                caso= 1;

                cout<<" In what game would you like to add an avatar?" <<endl;
                cin.get(gamename3, SIZE, '\n');
                cin.ignore(SIZE, '\n');
                gamename3[0]= toupper(gamename3[0]);
                
                if(agame.gamesearch(gamename3, caso)==0)
                {
                    char decide [10];

                    cout<< "Game not found! would you like to add it now?" <<endl;
                    cin.get(decide, 10, '\n');
                    cin.ignore(10, '\n');
                    
                    if(strcmp(decide, "yes")==0)
                    {
                        agame.newgame(gamename3);
                    }
                    else
                    {
                        cout<<                   '\n' 
                            <<"Check your input" 
                            <<                   '\n'
                            <<                   '\n'
                            <<endl;
                        break;
                    }
                }
                else
                {
                    char hero[SIZE];
                    char charac[SIZE];

                    cout<< "What is the avatar's name?"<<endl;
                    cin.get(hero, SIZE, '\n');
                    cin.ignore(SIZE, '\n');
                    hero[0]= toupper(hero[0]);
                    personagem.aname= new char [strlen(hero)+1];
                    strcpy(personagem.aname, hero);
                    
                    cout<< "What is the avatar's characteristics?"<<endl;
                    cin.get(charac, SIZE, '\n');
                    cin.ignore(SIZE, '\n');
                    charac[0]= toupper(charac[0]);
                    personagem.charac1= new char[strlen(charac)+1];
                    strcpy(personagem.charac1, charac);
                    
                    agame.getinfo(personagem, gamename3);

                }

                break;

            case 5://edit avatar
                char gamename4 [SIZE];
                caso= 5;
                cout<< "In what game would you like to edit the avatar?" <<endl;
                cin.get(gamename4, SIZE, '\n');
                cin.ignore(SIZE, '\n');


                agame.gamesearch(gamename4, caso);

                break; 
            case 6:
                char gamename5 [SIZE];
                caso= 4;
                cout<< " What is the game you want to show avatars from?" <<endl;
                cin.get(gamename5, SIZE, '\n');
                cin.ignore(SIZE, '\n');

                if(agame.gamesearch(gamename5, caso)==0)
                {
                    cout<< "Game not found. Check your input" <<endl;
                }
                
                break;
            case 7://exit
                
                cout<< "Thanks for using this program" <<endl;
                break;
        }

    }while(decision!= 7); 

    return 0;
}
