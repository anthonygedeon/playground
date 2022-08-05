#include <iostream>

void foo();

int x;
int y { 5 };
//x = 5;

using namespace std;

int main() {
    ::cout << ::y << "hello world";
    return 0;
}

void goo();
