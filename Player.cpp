#include "Player.h"

Player::Player(string numPlayer) {
    ID=numPlayer;
    position=0;
}

string Player::getID() {
    return ID;
}
int Player::getPosition() {
    return position;
}
void Player::setPosition(int nPosition) {
    position=nPosition;
}
void Player::setID(string nID) {
    ID=nID;
}