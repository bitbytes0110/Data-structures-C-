
using namespace std;


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#define s 10        // size of the array

void fillArray(int arr[])
{
    for(int i =0 ; i<s ; i++)
    {
        arr[i] = rand()%100;
    }
}

void displayArray(int arr[])
{
    for(int i =0 ; i<s ; i++)
    {
        cout <<arr[i] <<endl;
    }
}

int findTheSmallestElement(int arr[], int limit)
{
    int indexOfSmallestValue = limit;
    for(int i=limit+1; i<s; i++)
    {
        if(arr[i]<arr[indexOfSmallestValue])
        {
            indexOfSmallestValue = i;
        }
    }

    return indexOfSmallestValue;
}
void swapNum(int arr[], int fNum, int sNum)
{
    int temp = arr[fNum];
    arr[fNum]= arr[sNum];
    arr[sNum]= temp;
}
void sortArray(int arr[])
{

    for(int i =0 ; i<s ;i++)
    {
        int small =findTheSmallestElement(arr,i);
       // cout<<"Smallest Number : "<<small<<endl;
        swapNum(arr, i, small);
    }

}

int main()
{
    srand(time(NULL));
    cout<<"-Insertion Sort"<<endl<<endl;
    int arr[s];
    fillArray(arr);

    cout<<"Before Sorting :\n";
    displayArray(arr);
    sortArray(arr);
    cout<<"\n\nAfter Sorting :\n";
    displayArray(arr);
}
