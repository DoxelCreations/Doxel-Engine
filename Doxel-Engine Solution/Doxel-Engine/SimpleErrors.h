/*

FILE DESCRIPTION

This is a simple header that define a simple console printing function.

How to use:

When you want to print something to the console, type:
Debug_Log("X")  where X is the text you want to print.

if you want to print is a veriable, you can just put it inside the parenthesis.

if there are multiple things you want to print in one call, use  the << operator to seperate between them.

*/
#pragma once

#include <iostream>

#define Debug_Log(x) std::cout << x << std::endl; // a simple wraper for cout

