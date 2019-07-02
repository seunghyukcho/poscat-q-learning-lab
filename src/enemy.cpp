#include "enemy.h"
#include <iostream>
#include <string>
#include <fstream>
#include <dirent.h>
#include <cmath>

void readDirectory(const std::string& name, std::vector<std::string>& v)
{
    DIR* dirp = opendir(name.c_str());
    struct dirent *dp;

    if(dirp == NULL)
    {
    	std::cout << "cannot open... please check your directory\n";
    	exit(1);
    }

    while ((dp = readdir(dirp)) != NULL) {
    	if(strlen(dp->d_name) == 0 || strstr(dp->d_name, ".txt") == NULL)
    		continue;
        v.push_back(dp->d_name);
    }

    closedir(dirp);
}

Enemy::Enemy()
{
	std::vector<std::string> fileNames;
	readDirectory("testcases", fileNames);

	testCaseNumbers = fileNames.size();
	for(int i = 1; i <= testCaseNumbers; i++)
		importTestCase(i, fileNames[i - 1]);
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
		for(int i = 1; i < 10; i++)
			inFile >> actionScore[testCase][i];
		for(int r = 1; r < 4; r++)
			for(int c = 1; c < 4; c++)
				testCases[testCase][r][c] = fileName[(r - 1) * 3 + c - 1];

		testCaseIdx[convertToState(testCases[testCase])] = testCase;
	}
	catch(...)
	{
		std::cout << "Testcase #" << testCase << " has wrong format... Plz check your file in ./testfiles folder" << std::endl;
		exit(1);
	}
}

int Enemy::convertToState(char board[][4])
{
	int ret = 0;
	for(int i = 1; i < 10; i++)
	{
		char ch = board[i / 3 + 1][i % 3 + 1];
		ret += (int)pow(3, i - 1) * (ch == '.' ? 0 : (ch == 'O' ? 1 : 2));
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
	for(int i = 1; i < 10; i++)
		if(actionScore[testCase][i] > 0.5)
			ret.push_back(i);
}