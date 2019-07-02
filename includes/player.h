#ifndef PLAYER_H
#define PLAYER_H
#include "enemy.h"

class Player
{
private:
	// Add variables if you need.

public:
	void train(Enemy *enemy);
	int selectAction(char board[][4]);
};

#endif