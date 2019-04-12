// Daniel Fries
// CS162
// Lab2
// Dungeon Crawl

#include <iostream>

using namespace std;

//  Functions

char createDungeon (int, int);
void displayDungeon();
char getMove();
bool checkMove();
char updateDungeon();

const int MAX_SIZE = 11;
char dungeon[MAX_SIZE][MAX_SIZE];

int main()
{
    createDungeon(MAX_SIZE,MAX_SIZE);
    displayDungeon();
    return 0;
}
char createDungeon (int x, int y)
{
//    int col = 0,row = 0;
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<y; j++)
        {
            dungeon[i][j] = '.';
        }
    }
 }
void displayDungeon()
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

}
char getMove()
{

}
bool checkMove()
{

}
char updateDungeon()
{

}
