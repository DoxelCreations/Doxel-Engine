/*

FILE DESCRIPTION

This is a simple header that define a simple console printing function.

*/

#pragma once

#include <iostream>

/*

This function print things to the console.

How to use:
When you want to print something to the console, type:
Debug_Log("X")  where X is the text you want to print.

If you want to print a veriable, you can just put it inside the parenthesis.

If there are multiple things you want to print in one call, use  the << operator to seperate them.

*/
#define Debug_Log(x) std::cout << x << std::endl
