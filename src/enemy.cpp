#include "enemy.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

Enemy::Enemy()
{
	testCaseNumbers = 4491;
	for(int i = 0; i <= testCaseNumbers; i++)
		importTestCase(i, "test" + std::to_string(i) + ".txt");
}

int Enemy::getTestCaseNumbers()
{
	return testCaseNumbers;
}

void Enemy::importTestCase(int testCase, std::string fileName)
{
	std::ifstream inFile("./testcases/" + fileName);

	if(!inFile)
	{
		std::cout << "Testcase #" << testCase << " file not exists... Plz check your ./testfiles folder" << std::endl;
		exit(1);
	}

	try 
	{
		std::string inputState;
		inFile >> inputState;

		for(int i = 1; i < 10; i++)
			inFile >> actionScore[testCase][i];

		for(int r = 1; r < 4; r++)
			for(int c = 1; c < 4; c++)
				testCases[testCase][r][c] = inputState[(r - 1) * 3 + c - 1];

		testCaseIdx[convertToState(testCases[testCase], true)] = testCase;
	}
	catch(...)
	{
		std::cout << "Testcase #" << testCase << " has wrong format... Plz check your file in ./testfiles folder" << std::endl;
		exit(1);
	}
}

int Enemy::convertToState(char board[][4], bool player = false)
{
	int ret = 0;
	for(int i = 0; i < 9; i++)
	{
		char ch = board[i / 3 + 1][i % 3 + 1];
		ret += (int)pow(3, i) * (ch == '.' ? 0 : ((player && ch == 'O') || (!player && ch == 'X') ? 1 : 2));
	}

	return ret;
}

int Enemy::action(char board[][4])
{
	int key = convertToState(board), idx;
	std::vector<int> sol;

	idx = testCaseIdx[key];
	getSolution(idx, sol);

	return (sol.empty() ? 1 : sol[0]);
}

void Enemy::getTestCase(int testCase, char board[][4])
{
	for(int r = 1; r < 4; r++)
		for(int c = 1; c < 4; c++)
			board[r][c] = testCases[testCase][r][c];
}

void Enemy::getSolution(int testCase, std::vector<int>& ret)
{
	double mx = -1.0;
	for(int i = 1; i < 10; i++)
	{
		double score = actionScore[testCase][i];
		if(mx < score)
		{
			ret.clear();
			mx = score;
			ret.push_back(i);
		}
		else if(mx == score)
			ret.push_back(i);
	}
}