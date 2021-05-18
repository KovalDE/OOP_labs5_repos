#pragma once
#include <string>
#include <iostream>

using namespace std;

class Error
{
	string name;
public:
	Error(string name1) { name = name1; }
	string What() { return name; }
};

