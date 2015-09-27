/*
 ID: dhruv.s2
 PROG: ride
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <limits>


using namespace std;

int letter_to_number(char n)
{
    int number = n - 'A';
    return number + 1;
}


ifstream& GotoLine(ifstream& file, unsigned int num){
    file.seekg(ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return file;
}

int main() {
    /*
     /Users/hitesh/Documents/USACO/OnlineTraining/Section1.1/YourRideIsHere/YourRideIsHere/
    */
    ofstream fout ("/Users/hitesh/Documents/USACO/OnlineTraining/Section1.1/YourRideIsHere/YourRideIsHere/ride.out");
    ifstream fin ("/Users/hitesh/Documents/USACO/OnlineTraining/Section1.1/YourRideIsHere/YourRideIsHere/ride.in");
    
    string cometName;
    getline(fin, cometName, '\n');
    
    GotoLine(fin, 2);
    string groupName;
    fin >> groupName;
    
    cout << cometName << endl;
    cout << groupName << endl;
    
    int cometNumber = 1;
    int groupNumber = 1;
    
    for(std::string::size_type i = 0; i < cometName.size(); ++i) {
        char c = cometName[i];
        int number = letter_to_number(c);
        cometNumber *= number;
    }
    for(std::string::size_type i = 0; i < groupName.size(); ++i) {
        char c = groupName[i];
        int number = letter_to_number(c);
        groupNumber *= number;
    }
    
    int finalComet = cometNumber%47;
    int finalGroup = groupNumber%47;
    
    
    if(finalGroup == finalComet) {
        fout << "GO\n";
    }
    else {
        fout << "STAY\n";
    }
     
    return 0;

}


