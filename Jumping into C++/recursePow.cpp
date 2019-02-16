//power function using recurse
#include <iostream>
using namespace std;

int pow(int base, int raise )
{
    if(raise  == 0)
        return 1;
    else
        return base * pow(base, raise - 1);
}
int main ()
{
    cout<<pow(2, 10);
}
