/*
 ID: dhruv.s2
 PROG: gift1
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>

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
ifstream& GotoLine(ifstream& file, unsigned int num){
    file.seekg(ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return file;
}

unsigned long split(const string &txt, vector<string> &strs, char ch)
{
    size_t pos = txt.find(ch);
    size_t initialPos = 0;
    strs.clear();
    
    // Decompose statement
    while(pos != string::npos) {
        strs.push_back( txt.substr( initialPos, pos - initialPos + 1 ) );
        initialPos = pos + 1;
        
        pos = txt.find(ch, initialPos );
    }
    
    // Add the last one
    strs.push_back( txt.substr( initialPos, min( pos, txt.size() ) - initialPos + 1 ) );
    
    return strs.size();
}

int main(int argc, const char * argv[])
{
    /*
/Users/hitesh/Documents/USACO/OnlineTraining/Section1.1/GreedyGiftGivers/GreedyGiftGivers/
     */
    ofstream fout("gift1.out");
    ifstream fin ("gift1.in");
    
    map<string,int> finalMoney;

    string NPString;
    getline(fin, NPString, '\n');
    int NP = atoi(NPString.c_str());
    
    string* groupMembers = new string[NP];
    
    for (int i = 0; i < NP; i++) {
        GotoLine(fin, i + 2);
        string memberName;
        fin >> memberName;
        groupMembers[i] = memberName;
        finalMoney[memberName] = 0;
    }
    int line = NP + 2;
    for (int i = 0; i < NP; i++) {
        GotoLine(fin, line);
        string gifter;
        fin >> gifter;
        cout << gifter << endl << endl;
        
        line += 1;
        
        string numbers = GetlineX(fin, line);
        vector<string> record;
        split(numbers, record, ' ');
        string gifterMoneyStr = record[0];
        int gifterMoney = atoi(gifterMoneyStr.c_str());
        
        string gifterPeopleStr = record[1];
        int gifterPeople = atoi(gifterPeopleStr.c_str());
        
        cout << "MONEY: " << gifterMoney << " PEEPS: " << gifterPeople << endl;
        cout << endl;
        
        int eachPersonGets;
        int leftOverMoney;
        if (gifterPeople == 0) {
            eachPersonGets = 0;
            leftOverMoney = 0;
        }
        else {
            eachPersonGets = gifterMoney / gifterPeople;
            leftOverMoney = gifterMoney % gifterPeople;

        }
        
        finalMoney[gifter] -= gifterMoney;
        finalMoney[gifter] += leftOverMoney;
        
        line += 1;

        // Each person the gifter is gifting
        for (int i = 0; i < gifterPeople; i++) {
            GotoLine(fin, line);
            string giftedPerson;
            fin >> giftedPerson;
            cout << giftedPerson << endl;
            finalMoney[giftedPerson] += eachPersonGets;
            line += 1;
        }
        cout << "DONE!" << endl;
        cout << endl;
        cout << endl;

        
    }
    cout << "SUP!" << endl;
    cout << NP << endl;
    ostringstream stream;
    for (int i = 0; i < NP; i++) {
        string groupMember = groupMembers[i];
        stream << groupMember << " " << finalMoney[groupMember] << endl;
    }
    
    string output = stream.str();
    cout << output << endl;
    fout << output;
    
    return 0;
}

