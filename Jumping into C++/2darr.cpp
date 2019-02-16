#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL));
    int arr[3][3];
    for(int i =0; i<3; i++)
    {
        for(int j =0; j<3; j++)
        {
            arr[i][j] = rand()%10;
        }
    }
   for(int i =0;i<3; i++)
    {
        for(int j =0;j<3; j++)
        {
            cout<<(int)&arr[i][j]<<endl;
        }
    }
}


