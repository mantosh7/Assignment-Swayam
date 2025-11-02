/*
Problem statement
Given a string, write a program to count the number of vowels, consonants, and spaces in that string.

EXAMPLE :
Input: ‘N’= 25, ‘s’ =”Take u forward is Awesome”
Output: 10 11 4
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> countVowelsConsonantsSpaces(string &s, int n) {
    int vowel = 0, consonants = 0, spaces = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            vowel++;
        } 
        else if (s[i] == ' ') {
            spaces++;
        } 
        else {
            consonants++;
        }
    }
    return {vowel, consonants, spaces};
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    vector<int> result = countVowelsConsonantsSpaces(s, s.size());

    cout << "Vowels: " << result[0] << endl;
    cout << "Consonants: " << result[1] << endl;
    cout << "Spaces: " << result[2] << endl;

    return 0;
}
