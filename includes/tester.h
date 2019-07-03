#ifndef TESTER_H
#define TESTER_H

#include <iostream>
#include "player.h"
#include "enemy.h"
#include "colormode.h"

class Tester
{
private:
	Player *player;
	Enemy *enemy;

public:
	Tester();
	void train(int episodes);
	void testAll();
	int test(int testCase);
	bool isCorrect(char board[][4]);
};

#endif