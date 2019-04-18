//
//  recursion.cpp
//  Recursion
//
//  Created by jim bailey on 1/23/19.
//  This work by Jim Bailey is licensed under a Creative Commons Attribution 4.0 International License.
//

#include "recursion.h"
#include <iostream>

using namespace std;

// this is your recursive palindrome program
// it might have different arguments, depending on how you solved the problem
bool recPalindrome(std::string word)
{
    // put your code here
    
    // dummy return to keep compiler happy, delete
    return false;
}


// this is the wrapper that calls your recursive palendrome testing program
bool isPalindrome(std::string word)
{
     // change this as needed for your recursive program
    return recPalindrome(word);
}

// this is your recursive subset generating program
// you might have a different set of arguments, depending on how you code it
void recPrintAllSubsets(std::string word, std::string output)
{
    // put your code here
    
    // dummy output for testing purposes
    cout << "subsets of " << word << endl;
}

// this is the wrapper that calls your subset generating program
// change it to match your function signature
void printAllSubsets(std::string word)
{
    recPrintAllSubsets(word, "");
}

