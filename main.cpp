//
//  main.cpp
//  mathtutor
//
//  Created by andy kim on 2/4/16.
//  Copyright © 2016 andy kim. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//function returns number of digits of an integer
int numberOfDigits(int num) {
    int digits=1;
    while ( num /= 10) {
        digits++;
    }
    return digits;
}

//function to determine correct number of whitespace to align numbers of problem
string numSpaces(int numDigits) {
    //string variable to store correct number of whitespace to indent
    string indent;
    if (numDigits>3) {
        indent = "";
    }
    else if (numDigits>2) {
        indent = " ";
    }
    else {
        indent = "  ";
    }
    return indent;
}

//function to format and display problem to user such that digits are aligned
void printProblem(int n1, int n2) {
    //declare string variables to store lines of problem
    string line1, line2;
    
    //int variables to store number of digits
    int length1 = numberOfDigits(n1);
    int length2 = numberOfDigits(n2);
    
    //compare number of digits to ensure num with less digits is in line2
    if (length1 < length2) {
        //switch length1 and length2
        int temp = length2;
        length2 = length1;
        length1 = temp;
        
        //switch n1 and n2
        temp = n2;
        n2 = n1;
        n1 = temp;
    }
    
    //storing formatted lines of problem to be displayed
    line1 = numSpaces(length1) + to_string(n1);
    line2 = numSpaces(length2) + to_string(n2);

    //simply replacing first space for "+" sign in line2
    line2[0] = '+';
    
    //display math problem to user
    cout << line1 << endl;
    cout << line2 << endl;
    cout << "------";
}




int main(int argc, const char * argv[]) {
    //declare 2 int variables to store rand numbers to be summed
    int num1, num2;
    
    //seed srand function with current time to produce new random numbers every run
    srand((unsigned)time(NULL));
    
    //initialize random values (0-999) for num1 and num2
    num1 = rand() % 1000 + 1;
    num2 = rand() % 1000 + 1;
    
    //display problem to user
    printProblem(num1, num2);
    
    //pause program and wait for user to press ENTER to show solution
    cout << "\n\nPress ENTER to see the answer . . .\n";
    cin.get();
    
    printProblem(num1, num2);
    
    //display sum with digits correctly aligned with rest of problem
    int sum = num1+num2;
    cout << "\n" << numSpaces(numberOfDigits(sum)) << sum << endl;

    return 0;
}
