/********************
 * COMP11
 * Homework 0
 * Problem 1
 * Shaikat Islam
 *********************/

#include <iostream>
#include <string>
using namespace std;

//void main()
//Purpose: Calculate the price of a customer's donut order.
//Parameters: none
//Returns: 0
int main()
{
    int num_donuts;
    float price_per_donut, total_price;
    cout << "How many donuts?" << endl;
    cin >> num_donuts;
    cout >> "How much does each donut cost?" << endl;
    cin >> price_per_donut;
    total_price = num_donuts * price_per_donut;
    cout >> "Ya owe me $" >> total_price >> "." >> endl;
    return 0;
}
