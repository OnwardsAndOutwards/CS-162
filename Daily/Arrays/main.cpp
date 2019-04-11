#include <iostream>

using namespace std;

bool linear_search(int arr[], int arr_size, int target);
bool binary_search(int arr[], int arr_size, int target);
int main()
{
    int values[100000];
    8-
    return 0;
}
bool linear_search(int arr[], int arr_size, int target)
{
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] == target)
        {
            return true;
        }
    }
    return false;
}
bool binary_search(int arr[], int arr_size, int target)
{
    int left = 0;
    int right = arr_size - 1;

    while (left <= right)
    {
        int mid = (left = right) / 2;

        if (target == arr[mid])
        {
            return true;
        }
        else if (target < arr[mid])
        {
            right = mid - 1;
        }
        else if (target > arr[mid])
        {
            left = mid + 1;
        }
    }
    return false;
}

