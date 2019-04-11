#include <iostream>
// bubba sort

using namespace std;

void bubble_sort(int arr[], int arr_size);


int main()
{

    int values[7] = {4, 5, 3, 2, 5, 9, 11};

    bubble_sort(values, 7);

    for (int i=0; i <7; i++)
        cout << values[i] << " ";

    return 0;
}
void bubble_sort(int arr[], int arr_size)
{
    //  repeat pass size -1 times to sort all elements
    for (int j =0; j < arr_size -1; j++)
    {
        // one pass through array, swapping pairs that are out of order
        for (int i = 0; i < (arr_size-1); i++)
        {
            if (arr[i] > arr[i+1])
            {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i=1] = temp;
            }
        }
    }
}
