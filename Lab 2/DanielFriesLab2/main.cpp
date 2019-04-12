#include <iostream>
#include <string>
//GLOBAL VARIABLES
char board[8][10];
//FUNCTIONS
void buildboard();
void initialize();
int moveplayer(char userinput);
bool checkwin(int row, int col);
void settrap();
bool checklose(int row, int col);
void ClearScreen();
int main()
{
 //INITIALIZE
 char userinput;
 initialize();
 settrap();
 bool stop = false;

 //DO WHILE NO WINNER OR LOSER
 while(stop == false){

 buildboard();
 settrap();

 std::cout << "\n Player move up, down, left, right (w,s,a,d)?\n\n\n\n";
 std:: cout << " ";
 std::cin >> userinput;
 bool quit = false;
 while (!quit){

 switch(userinput){
 case 'w':
 case 's':
 case 'a':
 case 'd':
 quit = true;
 break;
 default:
 std::cout << "\n Invalid move, try again(w,s,a,d)\n";
 std:: cout << " ";
 std::cin >> userinput;
 }
 }

 stop = moveplayer(userinput);
 userinput = '.'; //RESET
 }
}

void initialize()
{
 int col = 0,row = 0;
 //GIVES ALL SPACES NULL VALUE
 for(int i=0; i<8; i++)
 {
 for(int j=0; j<10; j++)
 {
 board[i][j] = '.';
 }
 }

 //TREASURE RANDOM
 while(col+row == 0){
 srand(time(0));
 col = rand() % 10;
 row = rand() % 8;
 board[row][col] = 'X';
 }

 //PLAYER AT 0,0.
 board[0][0] = 'G';

}

void buildboard()
{
 ClearScreen();
 std::cout << "\n DUNGEON CRAWL \n";
 std::cout << "\n Hurry they're multiplying... \n\n";

 for(int row=0; row<8; row++)
 {
 std::cout << "\t ";
 for(int col=0; col<10; col++)
 {
 std::cout << board[row][col];
 }
 std::cout << "\n";
 }
}

int moveplayer(char userinput)
{
 int col,row;
 //need to set m,n to player's position
 for(int i=0; i<10; i++){
 for(int j=0; j<8; j++){
 if(board[j][i] == 'G'){
 col = i;
 row = j;
 break;
 }
 }
 }

 //W UP, S DOWN, A LEFT, D RIGHT;
 //DOES NOT LET PLAYER MOVE OFF BOARD
 board[row][col] = '.';
 if(userinput =='w' && row!=0){
 row--;
 }
 else if(userinput =='s' && row!=7){
 row++;
 }
 else if(userinput =='a' && col!=0){
 col--;
 }
 else if(userinput =='d' && col!=9){
 col++;
 }
 //before reassigning G check for treasure or trap!!******
 //if win
 if (checkwin(row,col) == true){
 std::cout << "\n WINNER!\n\n\n";
 return true;
 }
 //if lose
 else if(checklose(row,col) == true){
 std::cout << "\n Sorry you LOSE!\n\n\n";
 return true;
 }
 else{
 board[row][col] ='G';
 return false;
 }
}

void settrap()
{
 //TRAP RANDOM
 int col, row;
 bool ok = false;
 while(ok == false){
 col = rand() % 10;
 row = rand() % 8;
 if(board[row][col]=='.'){
 board[row][col] = 'T';
 ok=true;
 }
 }
}

bool checkwin(int row, int col)
{
 //IF PLAYER G FINDS TREASURE X
 if(board[row][col] == 'X'){
 return true;
 buildboard();
 }
 else
 {
 return false;
 }
}
bool checklose(int row, int col)
{
 //IF PLAYER G FINDS TRAP
 if(board[row][col] == 'T'){
 return true;
 buildboard();
 }
 else
 {
 return false;
 }
}
void ClearScreen()
{
 std::cout << std::string( 100, '\n' );
}
