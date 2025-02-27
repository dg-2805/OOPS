/*Write a program in C++ to take Lower bound and upper bound to display prime numbers within the
range. You need to check if the range given by the user is within MIN and MAX limit defined by macro. if
not, It prints prime numbers within the range defined by macro. Like check if lb is smaller than MIN then
it reset it to MIN value defined as a constant during compilation as compiler argument –D. If not defined
by the compiler, a default value of 1 can be taken as value of MIN. Similarly for MAX default value is 100.*/

#include <iostream>

using namespace std;

#ifndef MAX
#define MAX 100
#endif

#ifndef MIN
#define MIN 1
#endif

void prime(int lb, int ub) {
    int i, j, flag;

    for (i = lb; i <= ub; i++) {
        flag = 0;
        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0 && i > 1) {
            cout << i << endl;
        }
    }
}

int main() {
    int lb, ub;

    cout << "Enter lower bound: ";
    cin >> lb;

    cout << "Enter upper bound: ";
    cin >> ub;

    if (lb < MIN) {
        lb = MIN;
    }

    if (ub > MAX) {
        ub = MAX;
    }

    prime(lb, ub);

    return 0;
}


/*SAMPLE OUTPUT

daria@DG MINGW64 ~/OneDrive/Documents/New
$ g++ prime.cpp -o prime

daria@DG MINGW64 ~/OneDrive/Documents/New
$ ./prime
Enter lower bound: -5
Enter upper bound: 200
2
3
5
7
11
13
17
19
23
29
31
37
41
43
47
53
59
61
67
71
73
79
83
89
97

daria@DG MINGW64 ~/OneDrive/Documents/New
$ g++ -DMIN=5 -DMAX=50 prime.cpp -o prime

daria@DG MINGW64 ~/OneDrive/Documents/New
$ ./prime
Enter lower bound: 0
Enter upper bound: 90
2
3
5
7
11
13
17
19
23
29
31
37
41
43
47

*/
