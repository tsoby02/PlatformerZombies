#include "Game.h"

int main() {
    Game game;

    game.initStateMachine();

    while(game.getCurrentState() != game.getExitState()) {
        game.handleEvents();
        game.update();
        game.changeState();
        game.render();
    }

    return 0;
}
