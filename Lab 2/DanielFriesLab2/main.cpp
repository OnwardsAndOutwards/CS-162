// Daniel Fries
// CS162
// Lab2
// Dungeon Crawl

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//  Global variables and constants

const int MAX_SIZE = 16;           // change me to make the dungeon larger or smaller
char dungeon[MAX_SIZE][MAX_SIZE];  // dungeon

//  Functions

void createBoard();
void createDungeon();
void randomTrap();
int getMove(char playerMove);
bool checkMove(int playerY, int playerX);
bool checkDeath(int playerY, int playerX);
void clearScreen();



int main()

{
    char playerMove;
    createDungeon();
    randomTrap();
    bool gameOver = false;
    cout << "   You are the heroic Dan: D \n\n";
    cout << "   You seek the treasure : X \n\n";
    cout << "Try not to fall down any holes: O \n\n";
    system("pause");


    while(gameOver == false)  //  It's a game loop
    {


        createBoard();

        cout << "\n   Pick a direction to move:\n\n";
        cout << "             w = up\n";
        cout << " a = left    s = down    d = right\n";
        cin >> playerMove;
        playerMove = (tolower(playerMove));  //  in case the user input an upper case letter
        bool endGame = false;
        while (!endGame)
        {

            switch(playerMove)
            {
            case 'w':
            case 's':
            case 'a':
            case 'd':
                endGame = true;
                break;
            default:
                cout << "\n Not a valid move.  Please try again, but harder.\n \n";
                cin >> playerMove;
            }
        }
        randomTrap();                      //    If uncommented, more traps appear every turn
        gameOver = getMove(playerMove);
        playerMove = '.';
    }
}

void createDungeon()  //  At first, there was only darkness
{
    int playerX = 0,playerY = 0;

    for(int i=0; i<MAX_SIZE; i++)
    {
        for(int j=0; j<MAX_SIZE; j++)
        {
            dungeon[i][j] = '.';  //  change this char to whatever you want the background to be
        }
    }

    while(playerX+playerY == 0)  // Treasure
    {
        srand(time(0));
        playerX = rand() % MAX_SIZE;
        playerY = rand() % MAX_SIZE;
        dungeon[playerY][playerX] = 'X';
    }

//  Places our hero in the middle of the board
    dungeon[MAX_SIZE/2][MAX_SIZE/2] = 'D';

}

void createBoard()
{
    clearScreen();

    for(int playerY=0; playerY<MAX_SIZE; playerY++)
    {
        cout << "\t ";
        for(int playerX=0; playerX<MAX_SIZE; playerX++)
        {
            cout << dungeon[playerY][playerX];
        }
        cout << "\n";
    }
}
void randomTrap()
{
    int playerX, playerY;
    bool ok = false;
    while(ok == false)
    {
        playerX = rand() % MAX_SIZE;
        playerY = rand() % MAX_SIZE;
        if(dungeon[playerY][playerX]=='.')
        {
            dungeon[playerY][playerX] = 'O';
            ok=true;
        }
    }
}
int getMove(char playerMove)
{
    int playerX,playerY;

    for(int i=0; i<MAX_SIZE; i++)
    {
        for(int j=0; j<MAX_SIZE; j++)
        {
            if(dungeon[j][i] == 'D')
            {
                playerX = i;
                playerY = j;
                break;
            }
        }
    }

//  Prevents player from violating the rules of this simple universe

    dungeon[playerY][playerX] = '.';
    if(playerMove =='w' and playerY!=0)
    {
        playerY--;
    }
    else if(playerMove =='s' && playerY!=(MAX_SIZE-1))
    {
        playerY++;
    }
    else if(playerMove =='a' && playerX!=0)
    {
        playerX--;
    }
    else if(playerMove =='d' && playerX!=(MAX_SIZE-1))
    {
        playerX++;
    }

//  Check if you win
    if (checkMove(playerY,playerX) == true)
    {
        cout << "\n Congrats!  You found the treasure. \n";
        cout << "  You're a shame to archeologists   \n";
        cout << "  everwhere for your grave robbing! \n";
        return true;
    }
//  Check if you lose
    else if(checkDeath(playerY,playerX) == true)
    {
        cout << "\n Sorry you LOSE!\n\n\n";
        return true;
    }
    else
    {
        dungeon[playerY][playerX] ='D';
        return false;
    }
}

bool checkMove(int playerY, int playerX)  //  If you're on the treasure you win!
{

    if(dungeon[playerY][playerX] == 'X')
    {
        return true;
        createBoard();
    }
    else
    {
        return false;
    }
}
bool checkDeath(int playerY, int playerX)  //  Its a trap!
{
    if(dungeon[playerY][playerX] == 'O')
    {
        return true;
        createBoard();
    }
    else
    {
        return false;
    }
}
void clearScreen()
{
    cout << string( MAX_SIZE, '\n' );
}
