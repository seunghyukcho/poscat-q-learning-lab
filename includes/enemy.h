#ifndef ENEMY_H
#define ENEMY_H
#include <map>
#include <vector>
#include <string>
#define TEST_NUMBER 5000

class Enemy
{
private:
	int testCaseNumbers;
	char testCases[TEST_NUMBER + 1][4][4];
	double actionScore[TEST_NUMBER + 1][10];
	std::map<int, int> testCaseIdx;

public:
	Enemy();
	void importTestCase(int testCase, std::string fileName);
	int getTestCaseNumbers();
	int action(char board[][4]);
	int convertToState(char board[][4], bool player);
	void getTestCase(int testCase, char board[][4]);
	void getSolution(int testCase, std::vector<int>& ret);
};

#endif