#include "player.h"

void Player::train(Enemy *enemy)
{
	char state[4][4];
	// Replace the under code with yours
	
	enemy->action(state); // it will return the actions of enemy if the state is given.
}

int Player::selectAction(char board[][4])
{
	return 0;
}