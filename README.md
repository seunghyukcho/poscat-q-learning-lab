<p align="center">
  <img src="https://i.imgur.com/miWq6xI.png" title="source: imgur.com" height="200" width="200" />
</p>

# Q-Learning Lab

POSCAT(POSTECH Computer Algorithm Team)에서 만든 Game AI lab으로, 가장 기초적인 강화학습인 [Q-Learning](https://en.wikipedia.org/wiki/Q-learning)의 이해와 구현을 돕기 위해 만들어졌습니다. 보드 게임의 일종인, tic-tac-toe를 해결하는 solver를 구현할 수 있는 platform입니다. solver를 여러 개의 testcase로 평가한 결과를 보여드립니다.

## Getting Started

### Installing

#### CLI

repository를 clone 또는 다운로드 받고, command line에 다음 명령어들을 칩니다. 단, cmake와 c++17 컴파일러가 우선적으로 설치되어 있어야합니다.

```bash
git clone https://github.com/shhj1998/poscat-q-learning-lab.git
cd poscat-q-learning-lab
cmake .
make
./build/tester # execution
```

- make 명령어까지 입력이 완료되면, build 폴더 아래에 tester라는 executable file이 생긴 것을 확인하실 수 있습니다.
- 코드 수정 후, cmake .과 make 명령어를 차례대로 치시면 실행파일이 수정될 것입니다.

#### Visual Studio

- [링크](https://docs.microsoft.com/ko-kr/cpp/build/cmake-projects-in-visual-studio?view=vs-2019)를 참고하여, 프로젝트를 여시면 됩니다.
- 잘 안되시면 새 프로젝트를 만들고, includes/, src/ 아래에 있는 파일들을 새로 만든 프로젝트에 옮기시면 됩니다.

## Practice

처음 실행해보면 다음과 같이 결과가 나타날 것입니다.

```
***Start Testing!***

[TC #01] WRONG ANSWER

Total Result: 0 / 4492
```

- 이제 4492개의 testcase에 대해서 모두 정답을 맞는 것을 목표로 하시면 됩니다!
- 코드는 src/player.cpp의 train과 selectAction 함수를 구현하시면 됩니다. 
- **단, player.cpp와 player.h 이외의 코드는 수정하시면 안됩니다!**

## Built With

* [CMake](https://cmake.org/) - C++ Project Build Tool
