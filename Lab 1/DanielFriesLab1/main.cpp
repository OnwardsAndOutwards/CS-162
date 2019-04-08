//  Daniel Fries
//  CS162+
//  Lab 1
//  Tic Tac Toe


#include <iostream>
#include <windows.h>  //  for the system functions

using namespace std;

int player = 0;
int turns = 0;
bool winner = false;

char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

void displayInstructions();
void showBoard(char [][3]);
int getMove();
bool checkWin(char [][3], int);
bool checkDraw(char [][3], int);


int main()
{
    displayInstructions();
    system("pause");
    system("cls");

    do  // ye olde game loop
    {

    showBoard(board);
    getMove();
    turns++;
    checkDraw(board, player);
    checkWin(board, player);

    }
    while(winner != true);


    return 0;
}
void displayInstructions()

{
    cout << "Welcome to Tic Tac Toe!\n\nPlayers take turns placing markers on the board.\n\nIf you get three in a row, you win!\n" << endl;
}
void showBoard(char board[][3])
{
    cout << "The board looks like this:\n\n" << endl;
    for (int i=0;i<3;i++)
        {
        for(int j=0;j<3;j++)  // Yo dawg I heard you like loops so I put some loops in your loop
        {
            cout << board[i][j];
            cout << "  ";
        }
        cout << endl;
        if(i!=2)
        {
            cout << "-------" << endl;
        }
    }
}
int getMove()
{
    int x, y, input;
    cout << "Enter x coordinate" << endl;
    cin >> x;
    x=x-1;  //  Adjusts from human thinking to computer thinking
    if ((x<0)||(x>2))
    {
        cout << "Invalid entry, try again." << endl;
        cin >> x;
    }
    cout << "Enter y coordinate" << endl;
    cin >> y;
    y=y-1;
    if ((y<0)||(y>2))
    {
        cout << "Invalid entry, try again." << endl;
        cin >> y;
    }
    if (board[x][y] != ' ')
    {
        cout << "Invalid entry, try again." << endl;
        getMove();
    }
    if (player == 1)
    {
        board[x][y] = 'X';
    }
    else
    {
        board[x][y] = 'O';
    }
    if (player==0)
        player=1;
    else
        player=0;
    system("cls");
}
bool checkWin(char [][3], int)
{
    int n;
    for(n=0;n<3;n++) {
        if(board[n][0]==board[n][1] && board[n][0]==board[n][2]) {
            if(board[n][0]=='O' || board[n][0]=='X') {
                winner=true;
                cout << "You win!" << endl;
            }
        }
    }
    for(n=0;n<3;n++) {
        if(board[0][n]==board[1][n]&&board[0][n]==board[2][n]) {
            if(board[0][n]=='O' || board[0][n]=='X') {
                winner=true;
                cout << "You win!" << endl;
            }
        }
    }
    if(board[0][0]==board[1][1]&&board[0][0]==board[2][2]) {
        if(board[0][0]=='O' || board[0][0]=='X') {
            winner=true;
            cout << "You win!" << endl;
        }
    }
    if(board[0][2]==board[1][1]&&board[1][1]==board[2][2]) {
        if(board[0][2]=='O' || board[0][2]=='X') {
            winner=true;
            cout << "You win!" << endl;
        }
    }
}
bool checkDraw(char [][3], int)  //  I'm so clever
{
    if (turns>=9)  //  Way lazier than the first thing I tried.
    cout << "It's a draw!" << endl;
}
