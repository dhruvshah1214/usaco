/*
 ID: dhruv.s2
 PROG: friday
 LANG: C++11
 */
/* TASK:
 That is, does the 13th of the month land on a Friday less often than on any other day of the week? To answer this question, write a program that will compute the frequency that the 13th of each month lands on Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, and Saturday over a given period of N years. The time period to test will be from January 1, 1900 to December 31, 1900+N-1 for a given number of years, N. N is positive and will not exceed 400.
 
 Note that the start year is NINETEEN HUNDRED, not 1990.
 
 There are few facts you need to know before you can solve this problem:
 
 January 1, 1900 was on a Monday.
 Thirty days has September, April, June, and November, all the rest have 31 except for February which has 28 except in leap years when it has 29.
 Every year evenly divisible by 4 is a leap year (1992 = 4*498 so 1992 will be a leap year, but the year 1990 is not a leap year)
 The rule above does not hold for century years. Century years divisible by 400 are leap years, all other are not. Thus, the century years 1700, 1800, 1900 and 2100 are not leap years, but 2000 is a leap year.
 Do not use any built-in date functions in your computer language.
 
 Don't just precompute the answers, either, please.
 
 PROGRAM NAME: friday
 
 INPUT FORMAT
 
 One line with the integer N.
 
 
 SAMPLE INPUT (file friday.in)
 
 20
 
 
 OUTPUT FORMAT
 
 Seven space separated integers on one line. These integers represent the number of times the 13th falls on Saturday, Sunday, Monday, Tuesday, ..., Friday.
 
 
 SAMPLE OUTPUT (file friday.out)
 
 36 33 34 33 35 35 34
*/



#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>

// NOTE
// January 1, 1900 to December 31, 1900+N-1

using namespace std;

bool isLeapYear (int yr)
{
	bool isLeapYear;
    
    if ((yr % 4 == 0) && !(yr % 100 == 0))
        isLeapYear = true;
    else if (yr % 400 == 0)  // year divisible by 4 but not by 100
        isLeapYear = true;
    else
        isLeapYear = false;
    return isLeapYear;
    
}


int daysInMonth (int month, int year) {
    if (month == 4 || month == 6 || month == 9 || month == 11 ) {
        return 30;
    }
    else if (month == 2){
        if (isLeapYear(year)) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else {
        return 31;
    }
}

vector<vector<int>> calculateWholeYear(vector<int> dayArr, int year, int startingDay) {
    vector<int> startList = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    
    
    // JANUARY
    int dayOfThirteenth = startingDay - 2;
    if (dayOfThirteenth == 0 || dayOfThirteenth == -1) {
        dayOfThirteenth += 7;
    }
    
    (dayArr[dayOfThirteenth - 1])++;
    startList[0] = dayOfThirteenth;
    
    // FEB ONWARDS
    for (int i = 2; i < 12 + 1; i++) {
        int daysInDaMonth = daysInMonth(i - 1, year);
        int daysToAdd = daysInDaMonth % 7;
        dayOfThirteenth += daysToAdd;
        if (dayOfThirteenth > 7) {
            dayOfThirteenth -= 7;
        }
        (dayArr[dayOfThirteenth - 1])++;
        startList[i-1] = dayOfThirteenth;

    }
    
    return vector<vector<int>> {dayArr, startList};
}

int main(int argc, const char * argv[])
{
    /*
/Users/hitesh/Documents/USACO/OnlineTraining/Section1.1/FridayTheThirteenth/FridayTheThirteenth/
     */
    ofstream fout("friday.out");
    ifstream fin ("friday.in");
    
    string NStr;
    fin >> NStr;
    int noOfYrs = atoi(NStr.c_str());

    int startingDay = 1; // NOTHING;; Monday = 1
    // M TU W TH F SAT SUN

    vector<int> dayArr = {0, 0, 0, 0, 0, 0, 0};
    vector<int> startList = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } ;
    

    for (int i = 1900; i < 1900 + noOfYrs; i++) {
        dayArr = calculateWholeYear(dayArr, i, startingDay)[0];
        startList = calculateWholeYear(dayArr, i, startingDay)[1];

        if (isLeapYear(i)) {
            startingDay += 2;

            if (startingDay > 7) {
                startingDay -= 7;
            }
        }
        else {
            if (startingDay == 7) {
                startingDay = 1;
            }
            else {
                startingDay += 1;
            }
        }
        
        cout << endl;
        cout << endl;
        cout << "startlist    ";
        for (int i=0; i< startList.size();i++){
            cout << startList[i] << " ";
        }
        cout << endl;
        cout << "DAYARR       ";
        for (int i=0; i< dayArr.size();i++){
            cout << dayArr[i] << " ";
        }
        cout << endl;
    }
    
    cout << endl << endl << "OUTPUT FINAL:" << endl;
    ostringstream stream;
     stream  << dayArr[5] << " " << dayArr[6] << " " << dayArr[0] << " " << dayArr[1] << " " << dayArr[2] << " " << dayArr[3]
        << " " <<  dayArr[4] << endl;
    string output = stream.str();
    cout << output << endl;
    fout << output;

    

    
}

