// Challenge link: https://codeforces.com/group/iQQI5TD7io/contest/665354/problem/B



// =============== Solution ===============
#include <iostream>
using namespace std;

void calculateTaskTime(int givenHouse, int& currentHouse, int housesCount, long long& totalTime) {
    // givenHouse > currentHouse => time = givenHouse - currentHouse
    if (givenHouse > currentHouse) {
        totalTime += givenHouse - currentHouse;
    }     
    // givenHouse < currentHouse => go to the begining of the ringRoad + go to the givenHouse
    else if (givenHouse < currentHouse) {
        totalTime += (housesCount - currentHouse + 1) + (givenHouse - 1);
    }
    // givenHouse == currentHouse => nothing; because time_diff = 0
    currentHouse = givenHouse;
}

int main() {
    // take: n => houses, m => tasks
    int housesCount, tasksCount;
    int currentHouse = 1;   // starts from house 1
    long long totalTime = 0;
    
    cin >> housesCount >> tasksCount;
    
    // loop => no. of tasks
    for (int i = 0; i < tasksCount; i++) {
        int givenHouse;
        cin >> givenHouse;
        calculateTaskTime(givenHouse, currentHouse, housesCount, totalTime);
    }
    
    // print totalTime
    cout << totalTime;
    return 0;
}





/*
# Complexity Analysis
-- Time Complexity: O(m), where m is the number of tasks
-------- loop to take m tasks from user => O(m)
-------- calculate local time => O(1)
-- Space Complexity: O(1)
-------- currentHouse, totalTime => O(1)
*/