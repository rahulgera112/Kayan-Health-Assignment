#include<bits/stdc++.h>
#define ll long long
using namespace std;

void swapCharacters(string &inputString,char &character1,char &character2) {
    for(char &character : inputString) {
        if (character == character1) character = character2;
        else if (character == character2) character = character1;
    }
}

int main(){
    string inputString;
    char character1,character2;

    cin>>inputString>>character1>>character2;

    swapCharacters(inputString,character1,character2);

    cout << inputString;
}


