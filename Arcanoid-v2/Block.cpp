#include "Block.h"

//Block::Block(int x, int y, float blockWidth, float blockHeight) : Rectangle(x,y, blockWidth, blockHeight) {
//
//}

void Block::SetColor(int type) {
    this->type = type;
    switch (type)
    {
    case NOT_DESTROYED:
        shape.setFillColor(Color(105, 105, 105)); // gray
        break;
    case ORDINARY:
        shape.setFillColor(Color::Yellow);
        break;
    case WITH_BONUS:
        shape.setFillColor(Color(255, 105, 180)); // pink
        break;
    case INCREASE_SPEED:
        shape.setFillColor(Color(0, 255, 255)); // cyan
        break;
    case WITH_HEALTH: // orange
        shape.setFillColor(withHealth.color[withHealth.lvl]);
        break;
    default:
        break;
    }
}
