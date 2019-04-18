#include <iostream>

using namespace std;

//void towersOfHanoi (int n);
//void recTowersOfHanoi (int n, char src, char dst, char mid);

void mergeSort(int arr[], int left, int right);

int main()
{
//    towersOfHanoi(10);


    return 0;
}
//void towersOfHanoi (int n)
//{
//    recTowersOfHanoi(n, 'A', 'B', 'C');
//}
//void recTowersOfHanoi (int n, char src, char dst, char mid)
//{
//    if (n == 1)
//    {
//        cout << "Move disk 1 from " << src << " to " << dst << endl;
//        return;
//    }
//    recTowersOfHanoi(n - 1, src, mid, dst);
//    cout << "Move disk " << n << " from " << src << " to " << dst << endl;
//    recTowersOfHanoi(n - 1, mid, dst, src);
//}
void mergeSort(int arr[], int left, int right)
{
    if (left == right)
        return;

    int mid = (left + right) / 2;void mergeSort(int arr[], int start, int end);

    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);

    merge(arr, left, mid, mid+1, right);
}
void merge()
