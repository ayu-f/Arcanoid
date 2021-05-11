#include "GameController.h"
#pragma warning(disable:4996)

int main() {
	GameController game;
	game.SetBlocksToDefualt();

	while (game.window.isOpen()) {
		sf::Event event;

		game.window.pollEvent(event);
		if (event.type == sf::Event::Closed)
			game.window.close();

		game.window.clear();

		switch (game.GAMESTATE) {
		case GAMEPLAY:
			game.RunGame();
			game.DrawField();
			break;

		case GAME_OVER:
			game.SetBlocksToDefualt();

			if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) {
				game.GAMESTATE = STATES::GAMEPLAY;
				sleep(milliseconds(150));
			}
			game.DrawGameOver();
			sleep(seconds(0.8f));
			game.GAMESTATE = STATES::GAMEPLAY;
			game.score--;
			break;

		case WINNER:
			game.SetBlocksToDefualt();

			if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) {
				game.GAMESTATE = STATES::GAMEPLAY;
			}
			game.score = 0;
			game.DrawField();
			break;
		}
	}
	return 0;
}