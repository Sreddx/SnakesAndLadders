#include "MyGame.h"

void MyGame::start() {
    //Pre ajustes de jugadores
        Player player1("1"), player2("2");
        char interaction;
        dado dado1;

        cout
                << " _____                _                                  _   _             _      _                   \n"
                   "/  ___|              | |                                | | | |           | |    | |                  \n"
                   "\\ `--.  _ __    __ _ | | __ ___  ___    __ _  _ __    __| | | |  __ _   __| |  __| |  ___  _ __  ___  \n"
                   " `--. \\| '_ \\  / _` || |/ // _ \\/ __|  / _` || '_ \\  / _` | | | / _` | / _` | / _` | / _ \\| '__|/ __| \n"
                   "/\\__/ /| | | || (_| ||   <|  __/\\__ \\ | (_| || | | || (_| | | || (_| || (_| || (_| ||  __/| |   \\__ \\ \n"
                   "\\____/ |_| |_| \\__,_||_|\\_\\\\___||___/  \\__,_||_| |_| \\__,_| |_| \\__,_| \\__,_| \\__,_| \\___||_|   |___/ \n"
                   "                                                                                                      \n"
                   "                                                                                                      "
                << endl;
        cout << "Please type the following parameters for the game to be configured" << endl;
        int numberTurns, intentosError=0;

        int C, L, S, R, P;
        cout << "For how many turns do you want the game to last?" << endl;
        cin >> numberTurns;
        setTurnMAX(numberTurns);

            cout << "Board size: ";
            cin >> C;
            MyException errorTamano, errorValido;
            if (errorTamano.InvalidConfigurationException(C, "tiles",C)== false)return;
            cout << endl;
            cout << "Total number of ladders: ";
            cin >> L;
            if (errorTamano.InvalidConfigurationException(L, "ladders",C)== false)return;
            cout << endl;
            cout << "Total number of snakes: ";
            cin >> S;
            if (errorTamano.InvalidConfigurationException(S, "snake",C)== false)return;
            cout << endl;
            cout << "Reward for landing on a ladder: ";
            cin >> R;
            if (errorTamano.InvalidConfigurationException(R, "reward",C)== false)return;
            cout << endl;
            cout << "Penalty for landing on a snake: ";
            cin >> P;//Aqui puse R en lugar de P asi que no tenia valor para P abajo
            if (errorTamano.InvalidConfigurationException(P, "penalty",C)== false)return;
            cout << endl;

        char gameMode;

        Board Board1(C, L, S, R, P);
        Board1.printBoard();
        cout << endl;
        cout << "Choose the game mode( m for manual, a for automatic:" << endl;
        cin >> gameMode;
        if (gameMode == 'm') {
            cout << "Press C to continue next turn, or E to end the game:" << endl;

            while (turn != maxTurns + 1 && interaction != 'e') {
                cin >> interaction;

                if (interaction == 'c' || interaction == 'e') {
                    cout << endl;
                    //Se tira el dado
                    int diceV = dado1.GetValorDado();

                    if (turn % 2 == 0) {
                        //Turno de jugador 2
                        int posI2 = player2.getPosition();
                        int move2 = posI2 + diceV;
                        //imprimimos datos del turno del jugador
                        cout << "Turn: " << turn << " || " << "Player: " << player2.getID() << " || " << "Position: "
                             << posI2 + 1 << " || "
                             << "Dice: " << diceV << " || " << "Case type: " << Board1.getCaseType(move2) << endl;
                        cout << "New position is: ";

                        //Validamos movimiento con tipo de casilla destino
                        if (Board1.getCaseType(move2) == 'S') {
                            move2 = move2 - P;
                        } else if (Board1.getCaseType(move2) == 'L') {
                            move2 = move2 + R;
                        }

                        //Establecemos posicion y verificamos que no se pase
                        player2.setPosition(move2);
                        int newPos2 = player2.getPosition() + 1;
                        if (newPos2 < C) {
                            cout << newPos2 << endl;
                        } else {
                            cout << C << endl;
                        }

                        //Si llega a la meta declaramos ganador y acaba el juego
                        if (newPos2 >= C) {
                            cout << "Player " << player2.getID() << " is the winner!!!" << endl;
                            break;
                        }
                    } else {
                        //Turno de jugador 1
                        int posI = player1.getPosition();
                        int move = posI + diceV;
                        //imprimimos datos del turno del jugador
                        cout << "Turn: " << turn << " || " << "Player: " << player1.getID() << " || " << "Position: "
                             << posI + 1
                             << " || "
                             << "Dice: " << diceV << " || " << "Case type: " << Board1.getCaseType(move) << endl;
                        cout << "New position is: ";

                        //Validamos movimiento con tipo de casilla destino
                        if (Board1.getCaseType(move) == 'S') {
                            move = move - P;
                        } else if (Board1.getCaseType(move) == 'L') {
                            move = move + R;
                        }
                        //Establecemos posicion y verificamos que no se pase
                        player1.setPosition(move);
                        int newPos = player1.getPosition() + 1;
                        if (newPos < C) {
                            cout << newPos << endl;
                        } else {
                            cout << C << endl;
                        }
                        //Si llega a la meta declaramos ganador y acaba el juego
                        if (newPos >= C) {
                            cout << "Player " << player1.getID() << " is the winner!!!" << endl;
                            break;
                        }
                    }
                    turn = turn + 1;
                } else {
                    cout << "Invalid option, please press C to continue next turn or E to end the game" << endl;
                    intentosError+=1;
                    if (intentosError==5){
                        break;
                    }
                    continue;
                }
            }
            //Mensajes de despedida
            if (turn >= maxTurns) {
                cout << "The maximum number of turns has been reached..." << endl;
            }
            if(intentosError==5){
                cout<<"Invalid menu choice exceeded"<<endl;
            }else {
                cout << "--GAME OVER--" << endl;
                cout << "Thanks for playing!!!" << endl;
            }
//Modo de juego AUTOMATICO
        } else if (gameMode == 'a') {
            while (turn != maxTurns + 1) {
                //Se tira el dado
                int diceV = dado1.GetValorDado();

                if (turn % 2 == 0) {
                    //Turno de jugador 2
                    int posI2 = player2.getPosition();
                    int move2 = posI2 + diceV;
                    //imprimimos datos del turno del jugador
                    cout << "Turn: " << turn << " || " << "Player: " << player2.getID() << " || " << "Position: "
                         << posI2 + 1 << " || "
                         << "Dice: " << diceV << " || " << "Case type: " << Board1.getCaseType(move2) << endl;
                    cout << "New position is: ";

                    //Validamos movimiento con tipo de casilla destino
                    if (Board1.getCaseType(move2) == 'S') {
                        move2 = move2 - P;
                    } else if (Board1.getCaseType(move2) == 'L') {
                        move2 = move2 + R;
                    }
                    //Establecemos posicion y verificamos que no se pase
                    player2.setPosition(move2);
                    int newPos2 = player2.getPosition() + 1;
                    if (newPos2 < C) {
                        cout << newPos2 << endl;
                    } else {
                        cout << C << endl;
                    }

                    //Si llega a la meta declaramos ganador y acaba el juego
                    if (newPos2 >= C) {
                        cout << "Player " << player2.getID() << " is the winner!!!" << endl;
                        break;
                    }
                } else {
                    //Turno de jugador 1
                    int posI = player1.getPosition();
                    int move = posI + diceV;
                    //imprimimos datos del turno del jugador
                    cout << "Turn: " << turn << " || " << "Player: " << player1.getID() << " || " << "Position: "
                         << posI + 1
                         << " || "
                         << "Dice: " << diceV << " || " << "Case type: " << Board1.getCaseType(move) << endl;
                    cout << "New position is: ";

                    //Validamos movimiento con tipo de casilla destino
                    if (Board1.getCaseType(move) == 'S') {
                        move = move + P;
                    } else if (Board1.getCaseType(move) == 'L') {
                        move = move + R;
                    }
                    //Establecemos posicion y verificamos que no se pase
                    player1.setPosition(move);
                    int newPos = player1.getPosition() + 1;
                    if (newPos < C) {
                        cout << newPos << endl;
                    } else {
                        cout << C << endl;
                    }
                    //Si llega a la meta declaramos ganador y acaba el juego
                    if (newPos >= C) {
                        cout << "Player " << player1.getID() << " is the winner!!!" << endl;
                        break;
                    }
                }
                turn = turn + 1;
                //Mensajes de despedida
                if (turn >= maxTurns) {
                    cout << "The maximum number of turns has been reached..." << endl;
                }
            }

            cout << "--GAME OVER--" << endl;
            cout << "Thanks for playing!!!" << endl;
        }
        }


//Metodos de turnos
void MyGame::setTurn(int changeTurn){
    turn=changeTurn;
}
int MyGame::getTurn(){
    return turn;
}

void MyGame::setTurnMAX(int newMax){
    maxTurns=newMax;
}
int MyGame::getTurnMAX(){
    return maxTurns;
}