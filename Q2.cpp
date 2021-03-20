#include<bits/stdc++.h>
#define ll long long
using namespace std;

// PROGRAM TO PRINT EACH NO. FROM 1 TO 100 ON A NEW LINE
// PRINT "BATMAN" FOR MULTIPLE OF 3
// PRINT "ROBIN" FOR MULTIPLE OF 5
// PRINT "BATMAN ROBIN" FOR MULTIPLE OF 3 AND 5

int main(){
    for(int currentNumber=1;currentNumber<=100;currentNumber++) {
        if (currentNumber % 3 == 0) {
            cout << "BATMAN\n";
        }
        else if (currentNumber % 5 == 0) {
            cout << "ROBIN\n";
        }
        else if (currentNumber % 15 == 0) {
            cout << "BATMAN ROBIN\n";
        }
        else cout << currentNumber << "\n";
    }
}


