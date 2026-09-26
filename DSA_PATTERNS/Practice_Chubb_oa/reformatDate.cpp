// date given 2nd oct 2025, represent it as 2025-10-02
#include<iostream>
#include <sstream>
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>

using namespace std;

class solution {
    public:
        string reformDate(string date) {
            unordered_map<string, string> months = {
                {"Jan","01"}, {"Feb","02"}, {"Mar","03"}, {"Apr","04"},
                {"May","05"}, {"Jun","06"}, {"Jul","07"}, {"Aug","08"},
                {"Sep","09"}, {"Oct","10"}, {"Nov","11"}, {"Dec","12"}
            };
            stringstream ss(date);
            string day, month, year;

            ss >> day >> month >> year;

            string dayNum = day.substr(0, day.size() - 2);
            if(dayNum.size() == 1) dayNum = "0" + dayNum;

            return year + "-" + months[month] + "-" + dayNum;
        }
};