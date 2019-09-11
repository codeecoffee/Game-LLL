//Fellipe Ferreira Lopes 

#include <iostream>
#include <cctype>
#include <cstring>
#include "game.h"

using namespace std;


int main()
{
    Game agame;
    Avatar personagem; 
    
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
             <<"5- Exit"                                    <<  '\n'
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
                    
                    cout<< "What is the avatar's characteristics?"<<endl;
                    cin.get(charac, SIZE, '\n');
                    cin.ignore(SIZE, '\n');
                    charac[0]= toupper(charac[0]);
                    
                    agame.getinfo(hero, charac, gamename3);

                }

                break;
                
            case 5:
                cout<< "Thanks for using this program" <<endl;
                break;
        }

    }while(decision!= 5); 

    return 0;
}
