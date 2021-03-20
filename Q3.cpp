#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's
// and return its area.

vector<int> nearestSmallestToLeft(vector<int> &V) {
    int n = V.size();

    stack<int> s;
    vector<int> left; // resultant vector telling nearest smallest element in left direction

    for(int i=0;i<n;i++) {
        if (s.empty()) left.push_back(-1);
        else if (V[s.top()] < V[i]) left.push_back(s.top());
        else {
            while(!s.empty() && V[s.top()] >= V[i]) s.pop();

            if (s.empty()) left.push_back(-1);
            else left.push_back(s.top());
        }
        s.push(i);
    }
    return left;
}

vector<int> nearestSmallestToRight(vector<int> &V) {
    int n = V.size();

    stack<int> s;
    vector<int> right; // resultant vector telling nearest smallest element in right direction

    for(int i=n-1;i>=0;i--) {
        if (s.empty()) right.push_back(n);
        else if (V[s.top()] < V[i]) right.push_back(s.top());
        else {
            while(!s.empty() && V[s.top()] >= V[i]) s.pop();

            if (s.empty()) right.push_back(n);
            else right.push_back(s.top());
        }
        s.push(i);
    }
    return right;
}

// FUNCTION TO FIND MAXIMUM AREA WITH BARS WHERE ARRAY VALUES REPRESENT THE BAR LENGTH
int maximumAreaWithBars(vector<int> &arr) {
    int n = arr.size();

    vector<int> left = nearestSmallestToLeft(arr);
    vector<int> right = nearestSmallestToRight(arr);

    reverse(right.begin(),right.end());

    int maximumArea = -1;
    for(int i=0;i<n;i++) {
        maximumArea = max(maximumArea, (right[i]-left[i]-1)*arr[i]);
    }
    return maximumArea;
}

int largestRectangularArea(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int columns = A[0].size();

    vector<int> barsArray = matrix[0];
    int maximumArea = maximumAreaWithBars(barsArray);

    // KEEP UPDATING BARS ARRAY WITH CUMULATIVE SUM
    for(int i=1;i<rows;i++) {
        for(int j=0;j<columns;j++) {
            if (matrix[i][j] == 0) barsArray[j] = 0;
            else barsArray[j] += 1;
        }
        maximumArea = max(maximumArea,maximumAreaWithBars(barsArray));
    }

    return maximumArea;
}

int main(){
    vector<vector<int>> inputArray = {
        {1,0,1,0,0},
        {1,0,1,1,1},
        {1,1,1,1,1},
        {1,0,0,1,0},
    };

    cout << largestRectangularArea(inputArray);

}


