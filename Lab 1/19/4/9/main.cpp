#include <iostream>

using namespace std;

void add_item(int arr[], int item, int capacity, int &cur_size);

int remove_last_item(int arr[], int &cur_size);

bool find_item(int arr[], int cur_size, int target);

int main()
{
    int numbers[6];
    int space_used = 0;

    add_item(numbers, 8, 6, space_used);
    add_item(numbers, 12, 6, space_used);

    int value;

    cin >> value;
    if (find_item(numbers, space_used, value))
    {
        cout << "That item is in the array" << endl;
    }
    else
    {
        cout << "That item is not in the array" << endl;
    }

//    remove_last_item(numbers, space_used);

//    int removed_value = remove_last_item(numbers, space_used);
//
//    cout << "took out " << removed_value << endl;

    for (int i=0; i<space_used;i++)
    {
        cout << numbers[i] << endl;
    }
    return 0;
}

void add_item(int arr[], int item, int capacity, int &cur_size)
{
    if (cur_size >= capacity)
    {
        cout << "Array is full" << endl;
        return;
    }
    arr[cur_size] = item;
    cur_size++;
}

int remove_last_item(int arr[], int &cur_size)
{
    //function if no return value
    //cur_size--;

    //function if returning a value
    return arr[--cur_size];
}

bool find_item(int arr[], int cur_size, int target)
{
    for (int i = 0; i < cur_size; i++)
    {
        if(arr[i]==target)
        {
            return true;
        }
    }
    return false;
}

