/*Write a program in C++ to take one command-line argument as a number N and outputs first N
terms for Fibonacci numbers. You need to check if number of arguments in command-line is correct or
not. Then check whether N is greater than or equal to 1 and less than or equal to MAX ,where MAX is
defined as a constant defined during compilation as compiler argument –D. If not defined by the
compiler, a default value of 10 can be taken as value of MAX.*/

#include <iostream>
#include <cstdlib>
#ifndef MAX
#define MAX 15
#endif

using namespace std;

void fibo(int n) {
    int i = 2, c, a = 0, b = 1;
    cout << a << endl << b << endl;
    while (i < n) {
        c = a + b;
        cout << c << endl;
        a = b;
        b = c;
        i++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Enter valid number of arguments" << endl;
        return 1;
    }

    int n = atoi(argv[1]);
    if (n > MAX) {
        n = MAX;
    }

    fibo(n);
    return 0;
}

/*SAMPLE OUTPUT
daria@DG MINGW64 ~/OneDrive/Documents/New
$ g++ fibo.cpp -o fibo

daria@DG MINGW64 ~/OneDrive/Documents/New
$ ./fibo 12
0
1
1
2
3
5
8
13
21
34
55
89

daria@DG MINGW64 ~/OneDrive/Documents/New
$ g++ -DMAX=7  fibo.cpp -o fibo

daria@DG MINGW64 ~/OneDrive/Documents/New
$ ./fibo 12
0
1
1
2
3
5
8
*/
