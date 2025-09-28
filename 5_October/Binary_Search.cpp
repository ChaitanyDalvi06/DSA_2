#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int x)
{
    int len = 0, r = n - 1;
    while (len <= r)
    {
        int m = len + (r - len) / 2;
        if (arr[m] == x)
        {
            return m;
        }

        if (arr[m] < x)
        {
            len = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return -1; // Return -1 if the element is not found
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, n, x);
    if (result != -1)
    {
        cout << "Element is present at index " << result;
    }
    else
    {
        cout << "Element is not present in array";
    }

    return 0;
}