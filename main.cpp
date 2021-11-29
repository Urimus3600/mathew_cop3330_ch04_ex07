/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Austin Mathew
 */

#include "std_lib_facilities.h"

double word2digit(string strNum);

double calculator(string operation, double num1, double num2);

string operator2word(string operation);

int main() {
    cout << "Simple Calculator\n";
    cout << "Enter an expression for calculation in the following format:\n";
    cout << "Number Operator Number\n\n";
    cout << "Possible Operators: +, -, *, /\n";
    cout << "Numbers can only be single digit positive integers in the form of words or digits.\n\n";
    cout << "Expression for Calculation: ";
    //specifies input instructions to user and the expected function of the program

    string operation, strNum1, strNum2;
    //makes strings for operator and numbers
    double num1, num2, out;
    //makes an ints for storing first, second, and output numbers

    cin >> strNum1 >> operation >> strNum2;
    // reads in inputs

    if(strNum1.length() > 1){
        num1 = word2digit(strNum1);
    }
    else{
        num1 = strNum1[0]-48;
        if(num1 < 0 || num1 > 9)
            cout << "Incorrect Input: " << strNum1 << "\n Input should be in the range 0-9\n";

    }
    //checks if it is a possible meaningful word, otherwise it converts to an integer and checks validity

    if(strNum2.length() > 1){
        num2 = word2digit(strNum2);
    }
    else{
        num2 = strNum2[0]-48;
        if (num2 < 0 || num2 > 9)
            cout << "Incorrect Input: " << strNum2 << "\n Input should be in the range 0-9\n";
    }
    //checks if it is a possible meaningful word, otherwise it converts to an integer and checks validity

    out = calculator(operation, num1, num2);

    cout << "\nMathematical Equation:\n";
    cout << num1 << operation << num2 << "=" << out << endl;
    //prints out operation in a mathematical equation for understanding

    operation = operator2word(operation);
    //converts to word form, as needed by output string

    cout << "Written Answer:\n";
    cout << "The " << operation << " of " << strNum1 << " and " << strNum2 << " is " << out << endl;
    // prints final answer in written form

    return 0;
}

string operator2word(string operation) {
    if (operation=="+"){
        operation = "sum";
    }
    else if (operation=="-"){
        operation = "difference";
    }
    else if (operation=="*"){
        operation = "product";
    }
    else if (operation=="/"){
        operation = "quotient";
    }
    else{
        cout<< "Incorrect Operator";
        exit(1);
    }
    //checks for each possible operator, changes to correct word
    //if not a possible operation, error message is printed and program ends

    return operation;
}

double calculator(string operation, double num1, double num2) {
    double out;

    if (operation=="+"){
        out = num1 + num2;
    }
    else if (operation=="-"){
        out = num1 - num2;
    }
    else if (operation=="*"){
        out = num1 * num2;
    }
    else if (operation=="/"){
        out = num1 / num2;
    }
    else{
        cout<< "Incorrect Operator";
        exit(1);
    }
    //checks for each operator case, performs correct operation
    //if not a possible operation, error message is printed and program ends

    return out;
}

double word2digit(string strNum) {
    for (int i = 0; i < strNum.length(); ++i) strNum[i] = tolower(strNum[i]);
    //converts string to lowercase

    vector<string> digits = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    //for recognizing values of words
    //the words have the same value as their index

    double num;

    int i=0;
    for(;i<10; i++){
        if(strNum == digits[i]){
            num = i;
            break;
        }
    }
    //checks until match is found, as words correlate to their indices, num is set to the match's index

    if(i == 10){
        cout << "Incorrect input, range of integers should be 0-9\n";
        cout << "Incorrect input is " << strNum << endl;
        exit(1);
    }
    //if no match is found, the word must be an incorrect input and program will end

    return num;
}
