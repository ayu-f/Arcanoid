#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <ctime>
#include "Ball.h"
#include "Paddle.h"
#include "Block.h"
#include "Bonus.h"

using namespace std;
using namespace sf;

enum STATES {
	GAMEPLAY,
	WINNER,
	GAME_OVER
};

class GameController {
private:
	int blocksX = 10, blocksY = 7, blockWidth = 80, blockHeight = 20;
	int windowWidth = 1024, windowHeight = 768, frameLimit = 60;
	Clock Clock;
	Sprite gamePlayBackground, gameOverBackground;
	Texture gamePlayBackgroundTexture, gameOverBackgroundTexture;
	Font font;
	Text tScore;
	string printLose = "Lose : ";

	bool IsCollisionBlock(Block& block, Ball& ball);
	bool IsCollisionPaddle(GameObject& paddle, Ball& ball);
	bool IsIntersecting(GameObject& obj1, GameObject& obj2);
	void HandleCollisionBlock(Block& block, Ball& ball);
	int health = 0;
public:
	int score = 0;
	int GAMESTATE = STATES::GAMEPLAY;
	RenderWindow window{ VideoMode(windowWidth, windowHeight), "Arcanoid", Style::Titlebar | Style::Close };
	Bonus bonus{ 400, 300 };
	vector<Ball> balls;
	Paddle paddle{ windowWidth / 2.f, windowHeight - 20.f };
	vector<Block> blocks;

	GameController();

	void RunGame();
	void SetBlocksToDefualt();
	void DrawField();
	void LoadImages();
	void DrawGameOver();
	void StartBonus(int it);
};