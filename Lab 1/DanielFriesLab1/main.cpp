//  Daniel Fries
//  CS162+
//  Lab 1
//  Tic Tac Toe


#include <iostream>

using namespace std;

int player = 0;
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
    checkDraw(board, player);
    checkWin(board, player);

    }
    while(winner != true);
    cout << "You win!" << endl;

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
        for(int j=0;j<3;j++)
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
    //  switch or if statement checking if three in a row is present
}
bool checkDraw(char [][3], int)
{

}
