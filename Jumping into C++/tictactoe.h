using namespace std;

#include <iostream>



/* Add to main
#include "tictactoe.h"

int main()
{
    char choice ='y';
    do
    {
        initializeGame();
        displayBoard();
        while(!gameOver)
        {
            gameLoop();
        }
        displayGameStatus();
        cout<<"\n Do you want to play again ? (y/n)";
        choice = getch();
    }while (choice=='y');
}


*/









#include <string>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#define s 3        // size of the array


char arr[3][3];
enum player{X,O};
player currentTurn = X;
char winner ='t';
bool gameOver = false ;
int movesMade =0;



void displayBoard()
{
    cout<<"Tic - Tac - Tow \n";
    for(int i = 0; i<s; i++)
    {
        for(int j = 0; j<s; j++)
        {
            cout<<"\t"<<arr[i][j];
        }
        cout<<endl;
    }
}
void initializeGame()
{
    cout<<"Initializing Game..\n";
    system("cls");
    gameOver = false;
    movesMade =0;
    for(int i = 0; i<s; i++)
    {
        for(int j = 0; j<s; j++)
        {
            arr[i][j] = '-';
        }
    }
}
void getInput()
{
    player nextTurn;
    char toPlace;
    if(currentTurn == X)
    {
        cout<<"X turn\n";
        toPlace = 'X';
        nextTurn = O;
    }
    else
    {
        cout<<"O turn\n";
        toPlace = 'O';
        nextTurn = X;
    }

    if (movesMade==8)
    {
        for(int i = 0; i<s; i++)
        {
            for(int j = 0; j<s; j++)
            {
                if(arr[i][j]=='-')
                {
                    arr[i][j]= toPlace;
                    return;
                }
            }
        }
    }


    int ch = 1;

    while(1)
    {

        while(1)
        {
            ch = getch() - '0';
            if(!(ch>0 && ch<10))
                cout<<"Invalid input !\nEnter Again !\n"<<endl;
            else
                break;

        }
        int i1 = ch/3;
        int i2 = (ch%3)-1;

        if(arr[i1][i2]=='-')
        {
            arr[i1][i2] = toPlace;
            movesMade++;
            currentTurn = nextTurn;
            system("cls");
            break;
        }
        else
            continue;
    }
}


bool BoardFilled()
{
    for(int i = 0; i<s; i++)
    {
        for(int j = 0; j<s; j++)
        {
            if(arr[i][j] == '-')
                return false;
       }
    }

    return true;
}


bool checkHorizontal()
{
    for(int i=0; i<s; i++)
    {
        if   ( (arr[i][0]==arr[i][1]) && (arr[i][1]==arr[i][2])  && (arr[i][0]!='-'))
        {
            winner =  arr[i][0];
             return true;
        }
    }
    return false;
}

bool checkVertical()
{
    for(int i=0; i<s; i++)
    {
        if   ( (arr[0][i]==arr[1][i]) && (arr[1][i]==arr[2][i])  && (arr[0][i]!='-'))
            {
                winner =  arr[0][i];
                return true;
            }
    }
    return false;
}

bool checkCross()
{
    if   ((arr[0][2]==arr[1][1]) && (arr[1][1]==arr[2][0])  && (arr[0][2]!='-')          )
          {
                winner = arr[0][2];
                return true;
          }
    else if   ( (arr[0][0]==arr[1][1]) && (arr[1][1]==arr[2][2])  && (arr[0][0]!='-'))

          {
                winner = arr[0][0];
                return true;
          }


    return false;
}

void checkIfWon()
{
    if ( checkHorizontal() || checkVertical() || checkCross() )
        gameOver = true;
}

void gameLoop()
{
    getInput();
    displayBoard();
    if(BoardFilled())
        gameOver = true;
    checkIfWon();
}

void displayGameStatus()
{
    if(winner == 'X' || winner == 'O')
        cout<<winner<<" won !\n";
    else
        cout<<"The match is a Tie !!\n";
}
