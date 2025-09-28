// wap to write a sliding window protocol
#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int windowSize;
    cout << "Enter the size of the sliding window: ";
    cin >> windowSize;

    int sum = 0;
    for (int i = 0; i < windowSize; i++)
    {
        sum += arr[i];
    }

    cout << "Sum of the first " << windowSize << " elements: " << sum << endl;

    for (int i = windowSize; i < size; i++)
    {
        sum = sum - arr[i - windowSize] + arr[i];
        cout << "Sum of the next " << windowSize << " elements: " << sum << endl;
    }

    return 0;
}