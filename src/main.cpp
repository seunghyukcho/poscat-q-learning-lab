#include "tester.h"
#include <iostream>

int main()
{
	Tester *tester = new Tester();
	tester->train();
	tester->testAll();
}