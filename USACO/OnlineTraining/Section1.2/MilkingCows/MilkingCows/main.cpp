/*
 ID: dhruv.s2
 PROG: milk2
 LANG: C++11
*/

#include <algorithm>
#include <bitset>
#include <limits>
#include <climits>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>






#define READY_FOR_SUBMIT 1

using namespace std;

string GetlineX(ifstream& file, unsigned int x){
    file.seekg(ios::beg);
    int i = 0;
    string line;
    while (i < x) {
        getline(file, line);
        i++;
    }
    return line;
}

bool isWithinRange(int first, int second, int number) {
    if (first < number) {
        if (number < second) {
            return true;
        }
    }
    return false;
}

bool isSetInBetween(vector<int> set, vector<int> range) {
    if ((isWithinRange(range[0], range[1], set[0]) == true) && (isWithinRange(range[0], range[1], set[1]) == true)) {
        return true;
    }
    else {
        return false;
    }
}

bool wayOfSort(vector<int> i, vector<int> j) { return i[0] < j[0]; }


int main(int argc, const char * argv[])
{
    /*
     /Users/hitesh/Documents/ProblemSolving/USACO/OnlineTraining/Section1.2/MilkingCows/MilkingCows/
     */
    ifstream in;
    ofstream out;
    if (READY_FOR_SUBMIT) {
         in.open ("milk2.in");
         out.open ("milk2.out");

    }
    else {
         in.open("/Users/hitesh/Documents/ProblemSolving/USACO/OnlineTraining/Section1.2/MilkingCows/MilkingCows/milk2.in");
         out.open("/Users/hitesh/Documents/ProblemSolving/USACO/OnlineTraining/Section1.2/MilkingCows/MilkingCows/milk2.out");

    }
    
    int no_of_farmersAndCows = atoi(GetlineX(in, 1).c_str());
    int longestMilked = 0;
    int longestNotMilked = 0;
    /*
    string firstWord;
    
    while (in >> firstWord)
    {
        cout << firstWord << endl;
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    */
    vector<vector<int>> finalPairs;
    vector<int> startTimes;
    vector<int> endTimes;

    
    vector<int> milkedStreaks;
    vector<int> nonMilkedTimes;



    string line;
    
    for (int lineNum = 1; getline(in, line); lineNum++)
    {
        stringstream ss(line);
        string word;
        
        int start = 0;
        int end = 0;
        
        for (int wordNum = 1; ss >> word; wordNum++)
        {
            if (wordNum == 1) {
                start = atoi(word.c_str());
            }
            else {
                end = atoi(word.c_str());
            }
        }
        vector<int> pair = {start, end};
        finalPairs.push_back(pair);
        startTimes.push_back(start);
        endTimes.push_back(end);


    }
    sort(startTimes.begin(), startTimes.end());
    sort(endTimes.begin(), endTimes.end());

    sort(finalPairs.begin(), finalPairs.end(), wayOfSort);
    
    int currentMilkStreak = 0;
    int currentNotMilkStreak = 0;
    
    if (no_of_farmersAndCows == 1) {
        longestMilked = finalPairs[0][1] - finalPairs[0][0];
    }
    else {
        cout << "HI" << endl;
        vector<vector<int>>::iterator row;
        vector<int>::iterator col;
        cout << "FINALPAIRS:" << endl;
        for ( vector<vector<int>>::size_type i = 0; i < finalPairs.size(); i++ )
        {
            for (vector<int>::size_type j = 0; j < finalPairs[i].size(); j++ )
            {
                cout << finalPairs[i][j] << ' ';
            }
            cout << endl;
        }
        int streakStart = finalPairs[0][0];
        int streakEnd = finalPairs[0][1];
        for (int i = 0; i < no_of_farmersAndCows; i++) {
            int currFirst = finalPairs[i][0];
            int currLast = finalPairs[i][1];
            
            
            if (i == (finalPairs.size() - 1)) {
                if (currFirst > streakStart && currLast < streakEnd) {
                }
                else {
                    streakEnd = currLast;
                }
                currentMilkStreak = streakEnd - streakStart;
                milkedStreaks.push_back(currentMilkStreak);
            }
            else if (i == 0) {
                int nextFirst = finalPairs[1][0];
                int nextLast = finalPairs[1][1];
                if (nextFirst > streakStart && nextLast < streakEnd) {

                
                }
                else if (nextFirst <= streakEnd && nextLast >= streakEnd) {
                    streakEnd = nextLast;
                }
                else if (nextFirst > streakEnd) {
                    currentMilkStreak = streakEnd - streakStart;
                    currentNotMilkStreak = nextFirst - streakEnd;
                    milkedStreaks.push_back(currentMilkStreak);
                    nonMilkedTimes.push_back(currentNotMilkStreak);
                    streakStart = nextFirst;
                    streakEnd = nextLast;

                }
            }
            else {
                int nextFirst = finalPairs[i + 1][0];
                int nextLast = finalPairs[i + 1][1];
                cout << endl << streakEnd << endl;
                if (nextFirst > streakStart && nextLast < streakEnd) {

                }
                else if (nextFirst <= streakEnd && nextLast > streakEnd) {
                    streakEnd = nextLast;
                }
                else if (nextFirst > streakEnd) {
                    currentMilkStreak = streakEnd - streakStart;
                    currentNotMilkStreak = nextFirst - streakEnd;
                    milkedStreaks.push_back(currentMilkStreak);
                    nonMilkedTimes.push_back(currentNotMilkStreak);
                    streakStart = nextFirst;
                    streakEnd = nextLast;
                    
                    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << currFirst << " " << currLast << " " << currentNotMilkStreak << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                }
                
            }
        }
        sort(milkedStreaks.begin(), milkedStreaks.end());
        sort(nonMilkedTimes.begin(), nonMilkedTimes.end());
    
        cout << "milkedstreaks: " << endl;
        for(vector<int>::const_iterator i = milkedStreaks.begin(); i != milkedStreaks.end(); ++i) {
            cout << *i << endl;
        }
        cout << endl << endl;
        if (milkedStreaks.size() == 0) {
            longestMilked = 0;
        }
        else {
            longestMilked = milkedStreaks.back();
        }
    
        if (nonMilkedTimes.size() == 0) {
            longestNotMilked = 0;
        }
        else {
            longestNotMilked = nonMilkedTimes.back();
        }
        
        
        
    }
    
    
    
    cout << "longestMlked " << longestMilked << " longestnotmilked " << longestNotMilked << endl;

    
    cout << "starttimes: " << endl;
    for(vector<int>::const_iterator i = startTimes.begin(); i != startTimes.end(); ++i)
        cout << *i << endl;
    cout << endl << endl;
    
    
    cout << "finalPairs: " << endl;
    for (vector<vector<int>>::size_type i = 0; i < finalPairs.size(); i++ )
    {
        for (vector<int>::size_type j = 0; j < finalPairs[i].size(); j++ )
        {
            cout << finalPairs[i][j] << " ";
        }
        cout << endl;
    }
    /*
    int longestWasMilked = 0;
    int longestNotMilked = 0;
    
    if (no_of_farmersAndCows == 1) {
        longestNotMilked = 0;
        longestWasMilked = finalPairs[0][1] - finalPairs[0][0];
    }
    else {
        for (int i = 0; i < no_of_farmersAndCows; ++i) {
            int currentWasMilked = 0;
            int currentNotMilked = 0;
            
            
            if (i == 0) {
                currentWasMilked = finalPairs - startTime;
                currentNotMilked = 0;
            }
            else {
                
                
                int endOfI = atoi(str.substr(pos+1).c_str());
                
                if (i == no_of_farmersAndCows - 1) {
                    
                    string str = GetlineX(in, i);
                    string::size_type pos = str.find(' ', 0);
                    
                    int startOfLastLine = atoi(str.substr(0, pos).c_str());
                    int endOfFile = atoi(str.substr(pos+1).c_str());
                    
                    if (startOfLastLine < endOfI) {
                        currentWasMilked = endOfFile - startOfLastStreak;
                        currentNotMilked = 0;
                    }
                    else {
                        currentNotMilked = startOfLastLine - endOfI;
                        currentWasMilked = endOfFile - startOfLastLine;
                    }
                }
                else {
                    string str = GetlineX(in, i + 1);
                    string::size_type pos = str.find(' ', 0);
                    
                    int startOfNext = atoi(str.substr(0, pos).c_str());
                    cout << endl << "StartOfNext is " << startOfNext << endl;
                    
                    if (startOfNext < endOfI) {
                        continue;
                    }
                    else {
                        cout << endl << "endofI is   " << endOfI << "  startoflaststreak is  " << startOfLastStreak << endl << endl;
                        currentNotMilked = startOfNext - endOfI;
                        currentWasMilked = endOfI - startOfLastStreak;
                        startOfLastStreak = startOfNext;
                        cout << endl << "endofI is   " << endOfI << "  startoflaststreak is  " << startOfLastStreak << endl << endl;
                        
                    }
                    
                }
            }
            
            cout << "ENDOFFOR loop i is  " << i << " Now, " << currentWasMilked <<  " " << currentNotMilked  << "     " << longestWasMilked << " " << longestNotMilked << endl << endl << endl << endl << endl;
            if (currentWasMilked > longestWasMilked) {
                longestWasMilked = currentWasMilked;
            }
            if (currentNotMilked > longestNotMilked) {
                longestNotMilked = currentNotMilked;
            }
        }
    }
     */
    
    ostringstream stream;
    stream << longestMilked << " " << longestNotMilked << endl;
    
    string output = stream.str();
    out << output;
    cout << endl << endl << endl << output << endl << endl;
    
    return 0;

}




/*
 
 string str = GetlineX(in, 2);
 string::size_type pos = str.find(' ', 0);
 
 
 int startTime = atoi(str.substr(0, pos).c_str());
 int endOfFirst = atoi(str.substr(pos+1).c_str());
 
 
 
 
 */

