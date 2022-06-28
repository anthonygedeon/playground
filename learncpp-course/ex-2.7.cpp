#include <iostream>

int add(int x, int y)
{
     return x + y;
}

int add(int x, int y) // violation of ODR, we've already defined function add
{
     return x + y;
}

int main()
{
    int y;
    int x; // violation of ODR, we've already defined x
}
