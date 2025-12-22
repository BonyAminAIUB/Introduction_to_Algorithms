#include <bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(10);
    pq.push(5);
    //cout << pq.top() << endl; // 5

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq1;
    pq1.push({10,1});
    pq1.push({5,2});
    cout << pq1.top().first << " " << pq1.top().second << endl;  // 5 2
    return 0;
}