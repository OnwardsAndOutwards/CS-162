#include <iostream>
#include <string>

using namespace std;

void printArray(string [][3]);
string arraytest[3][3] = {{"X","X","X"},{"X","X","X"},{"X","X","X"}};

int main()
{
    printArray(arraytest);
    return 0;
}
void printArray(string x[][3])
{
    for (int i=0;i<3;i++)
        {
        for(int j=0;j<3;j++)
        {
            cout << x[i][j];
            cout << "  ";
        }
        cout << endl;


}
}

