/*Assignment:Stack and Valid Parentheses (COMP 218- Data Structures) (Assignment Number): 2
Author(s):Rylie Seaberg
Due Date: Sunday, 11/4/2024 11:59:00 PM
Description: This first part of this project aims to implement a generic stack container as
 an adaptor class template without using vector, queue, or stack. The second part of the project aims
 to determine if a string is valid given  '(',')','{','}','['']'. The string is valid if the brackets
 are in the correct closing order.
Comments:
Honor Pledge: I have abided by the Wheaton Honor Code and
all work below was performed by Rylie Seaberg .*/


#include <iostream>
#include "stack.h"
using namespace std;


int main() {

    stack<int> s;
    s.push(1);
    s.push(2);
    s.pop();


    return 0;
}
