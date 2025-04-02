/*Write a class Time which has three data member hour, minute and second and three member
functions:setTime(list of arguments) : Which set three data members of class addTime( ...): To add two
time values. object of Time class is passed as argument of addTime(). showTime(): To display the time
information. Write a program in c++ to test addition of two time objects and display result in proper
format*/

#CODE
#include <iostream>
using namespace std;

class Time {
private:
    int hour, minute, second;

public:
    Time() : hour(0), minute(0), second(0) {}

    void setTime(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
    }

    Time addTime(const Time &t) {
        Time temp;
        temp.second = second + t.second;
        temp.minute = minute + t.minute + (temp.second / 60);
        temp.second %= 60;
        temp.hour = hour + t.hour + (temp.minute / 60);
        temp.minute %= 60;
        temp.hour %= 24; // Keep within 24-hour format
        return temp;
    }

    void showTime() {
        cout << (hour < 10 ? "0" : "") << hour << ":"
             << (minute < 10 ? "0" : "") << minute << ":"
             << (second < 10 ? "0" : "") << second << endl;
    }
};

int main() {
    Time t1, t2, t3;
    int h, m, s;
    
    cout << "Enter first time (HH MM SS): ";
    cin >> h >> m >> s;
    t1.setTime(h, m, s);
    
    cout << "Enter second time (HH MM SS): ";
    cin >> h >> m >> s;
    t2.setTime(h, m, s);
    
    cout << "Time 1: ";
    t1.showTime();
    cout << "Time 2: ";
    t2.showTime();
    
    t3 = t1.addTime(t2);
    
    cout << "Sum of Time: ";
    t3.showTime();
    
    return 0;
}

/* OUTPUT

Enter first time (HH MM SS): 12 35 44
Enter second time (HH MM SS): 13 35 2
Time 1: 12:35:44
Time 2: 13:35:02
Sum of Time: 02:10:46
*/
