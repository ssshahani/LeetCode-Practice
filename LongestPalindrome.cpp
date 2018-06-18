/*
 * basics.cpp
 *
 *  Created on: 17-Jun-2018
 *      Author: Sahil S
 */

#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
bool checkPalidrome(string s);

bool checkPalidrome(string s){
    bool flag = true;
    int l = 0,h = s.length() - 1;
    while(h > l){
        if(s[l] != s[h]){
            flag = false;
            break;
        }
        l++;
        h--;
    }
    return flag;
}
//BruteForce
string longestPalindrome_BruteForce(string s) {
    int len = s.length();

    if(len == 0)
        return NULL;

    int max_len = 0;
    string longest = "";
    for(int i = 0; i<len; i++){
        for(int j = i+1; j<len; j++){
		string temp = s.substr(i,j);
        	if(checkPalidrome(temp)){
                max_len = max(max_len, int(temp.length()));
                if(temp.length() == max_len)
                    longest = temp;
            }
        }
    }
    return longest;
}
// This algorithm has time complexity O(N^2) and Space Complexity O(1)
// This algorithm expands around center. Even Length and Odd Length Palindromes.
string longestPalindrome(string s) {

       int len = s.length();
       int maxLength = 1;
       int start = 0;
       int low,high;
       for(int i = 1; i<len; ++i){

           low = i - 1;                                     // pointer
           high =  i;                                       // pointer
           //for odd length palindromes
           while(low >= 0 && high < len && s[low] == s[high]){

               if (high-low+1 > maxLength){
                       start = low;
                       maxLength = high-low+1;
               }

               --low;
               ++high;
           }

           low = i-1;
           high = i+1;

           //for even length palindromes
           while(low >= 0 && high < len and  s[low] == s[high]){

               if(high-low+1 > maxLength){
                   start = low;                            //start index
                   maxLength = high-low+1;                 //length of palindrome + 1 (because 0 index)
               }

               --low;
               ++high;
           }
       }
       return s.substr(start,maxLength);
}

int main(){
	string p = "abcracecarefg";
	cout << longestPalindrome(p);
	return 0;
}

