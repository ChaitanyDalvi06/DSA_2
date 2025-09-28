#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter the size of array: ";
    cin >> num;
    int arr[num];

    for (int i = 0; i < num; i++)
    {
        cout << "Enter the element at index " << i << ": ";
        cin >> arr[i];
    }

    int prefixSum[num];
    prefixSum[0] = arr[0];

    for (int i = 1; i < num; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    cout << "Prefix Sum Array: ";
    for (int i = 0; i < num; i++)
    {
        cout << prefixSum[i] << " ";
    }
    cout << endl;

    return 0;
}