#include "tester.h"

Tester::Tester()
{
	player = new Player();
    enemy = new Enemy();
}

void Tester::train(int episodes)
{
	for(int episode = 0; episode < episodes; episode++)
        player->train(enemy);
}

void Tester::testAll()
{
    int correctTestCases = 0, result, totalTestCases = enemy->getTestCaseNumbers();;
    std::string message;
    Color::Modifier red(Color::FG_RED);
    Color::Modifier blue(Color::FG_BLUE);
    Color::Modifier def(Color::FG_DEFAULT);
    Color::Modifier green(Color::FG_GREEN);

    std::cout << "\n***Start Testing!***" << std::endl << std::endl;

    for(int t = 0; t < totalTestCases; t++)
    {
        std::cout << "[TC #";
        if(t + 1 < 10) std::cout << "0";
        std::cout << t + 1 << "] ";
        result = test(t + 1);

        switch(result)
        {
            case 0:
                correctTestCases++;
                std::cout << green;
                message = "CORRECT!";
                break;
            case 1:
                std::cout << red;
                message = "WRONG ANSWER";
                break;
            case 2:
                std::cout << red;
                message = "INVALID ACITON";
                break;
            default:
                message = "System Error... Plz contact to the developer";
        }

        std::cout << message << def << std::endl;
        if(result != 0)
            break;
    }

    std::cout << "\nTotal Result: " << correctTestCases << " / " << totalTestCases << std::endl;
    if(correctTestCases == totalTestCases)
    {
        std::cout << green << "\nCongratulations! You're now the best tic-tac-toe player in the history!" << def << std::endl;
    }
}

int Tester::test(int testCase)
{
    char testState[4][4];
	std::vector<int> sol;
    int userAction;

    enemy->getTestCase(testCase, testState);
    enemy->getSolution(testCase, sol);
    userAction = player->selectAction(testState);

    if(userAction < 1 || userAction > 9)
        return 2;

    if(sol.empty())
        return 0;

    for(int solution : sol)
    {
        if(solution == userAction)
            return 0;
    }

    return 1;
}