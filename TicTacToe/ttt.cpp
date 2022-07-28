#include "ttt.h"

void TTT::loadGameWindow() {
    window.create(sf::VideoMode(700, 800), "TicTacToe", sf::Style::Close);
}

bool TTT::loadGameFiles() {
    return (playfield.loadFromFile("img/playfield.png") && symbolX.loadFromFile("img/X.png") && symbolO.loadFromFile("img/O.png") &&
        res.loadFromFile("img/restart-2.png") && white.loadFromFile("img/white-screen.png") && goBack.loadFromFile("img/goBack.png"));
}

bool TTT::loadFontFile() {
    return font.loadFromFile("fonts/data-latin.ttf");
}

bool TTT::loadSoundFile() {
    return (buffer.loadFromFile("sounds/placeSound.wav") && buffer1.loadFromFile("sounds/restart.wav"));
}

bool TTT::loadIconFile() {
    return icon.loadFromFile("img/icon.png");
}

void TTT::setGameFiles() {
    addPlayfield.setTexture(playfield);
    addPlayfield.scale(1.f, 1.f);
    addPlayfield.setPosition(140.f, 240.f); //X Y

    addX.setTexture(symbolX);
    addO.setTexture(symbolO);
    addWhite.setTexture(white);

    addGoBack.setTexture(goBack);
    addGoBack.scale(1.f, 1.f);
    addGoBack.setPosition(20, 24);

    addRes.setTexture(res);
    addRes.setPosition(328.f, 700.f);
}

void TTT::whoseTurn() {
    playerTurnMsg.setString("Spieler 1");
    playerTurnMsg.setFont(font);
    playerTurnMsg.setCharacterSize(60);
    playerTurnMsg.setFillColor(sf::Color::Black);
    playerTurnMsg.setPosition(225, 50);

    playerWinMsg.setFont(font);
    playerWinMsg.setCharacterSize(60);
    playerWinMsg.setFillColor(sf::Color::Black);
    playerWinMsg.setPosition(165, 50);
}

void TTT::updateWhoseTurn(int round) {
    std::string message;
    message = round % 2 == 0 ? "Spieler 1" : "Spieler 2";
    playerTurnMsg.setString(message);
}

void TTT::setRectCoord(sf::IntRect& fields, int left, int top, int width, int height) {
    fields.left = left;
    fields.top = top;
    fields.width = width;
    fields.height = height;
}

void TTT::rectCoord() {
    setRectCoord(squareFields[0], 145, 245, 275, 375);
    setRectCoord(squareFields[1], 280, 245, 410, 375);
    setRectCoord(squareFields[2], 415, 245, 545, 375);

    setRectCoord(squareFields[3], 145, 380, 275, 510);
    setRectCoord(squareFields[4], 280, 380, 410, 510);
    setRectCoord(squareFields[5], 415, 380, 545, 510);

    setRectCoord(squareFields[6], 145, 515, 275, 645);
    setRectCoord(squareFields[7], 280, 515, 410, 645);
    setRectCoord(squareFields[8], 415, 515, 545, 645);
}

void TTT::setPosPieces(sf::Vector2i& pos, int left, int top) {
    pos.x = left;
    pos.y = top;
}

void TTT::posPieces() {
    setPosPieces(position[0], 145, 245);
    setPosPieces(position[1], 280, 245);
    setPosPieces(position[2], 415, 245);

    setPosPieces(position[3], 145, 380);
    setPosPieces(position[4], 280, 380);
    setPosPieces(position[5], 415, 380);

    setPosPieces(position[6], 145, 515);
    setPosPieces(position[7], 280, 515);
    setPosPieces(position[8], 415, 515);

}

bool TTT::isClicked(int fPos) {
    return (event.mouseButton.x >= squareFields[fPos].left
        && event.mouseButton.x <= squareFields[fPos].width
        && event.mouseButton.y >= squareFields[fPos].top
        && event.mouseButton.y <= squareFields[fPos].height);

}

void TTT::restart(int* round, sf::Mouse mouse, bool* winnerFound) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (event.mouseButton.x >= restartBtn.left && event.mouseButton.x <= restartBtn.width && event.mouseButton.y >= restartBtn.top && event.mouseButton.y <= restartBtn.height) {
            restartSound.play();
            *round = 0;
            *winnerFound = true;
            whoseTurn();
            //playerTurnMsg.setString("Spieler 1");
            //playerTurnMsg.(0, 0);
            rectCoord();
            posPieces();
            setGameFiles();
            for (int i = 0; i < 9; i++) {
                pieces[i] = addWhite;
                placementList[i] = 'A';
            }
            window.clear(sf::Color(255, 255, 255, 255));
            window.display();
        }
    }
}

void TTT::initResetBtn() {
    restartBtn.left = 328;
    restartBtn.top = 700;
    restartBtn.width = 360;
    restartBtn.height = 732;
}

char TTT::winFunction(int round) {
    short xCount = 0, oCount = 0;

    //first row
    for (int i = 0; i <= 2; i++) {
        if (placementList[i] == 'X') {
            xCount++;
            oCount = 0;
        }
        else if (placementList[i] == 'O') {
            oCount++;
            xCount = 0;
        }
        if (xCount == 3) return 'X';
        else if (oCount == 3)return 'O';
    }
    xCount = 0, oCount = 0;
    //second row
    for (int i = 3; i <= 5; i++) {
        if (placementList[i] == 'X') {
            xCount++;
            oCount = 0;
        }
        else if (placementList[i] == 'O') {
            oCount++;
            xCount = 0;
        }
        if (xCount == 3) return 'X';
        else if (oCount == 3)return 'O';
    }
    xCount = 0, oCount = 0;
    //third row
    for (int i = 6; i <= 8; i++) {
        if (placementList[i] == 'X') {
            xCount++;
            oCount = 0;
        }
        else if (placementList[i] == 'O') {
            oCount++;
            xCount = 0;
        }
        if (xCount == 3) return 'X';
        else if (oCount == 3)return 'O';
    }
    xCount = 0, oCount = 0;

    //first column
    for (int i = 0; i <= 6; i += 3) {
        if (placementList[i] == 'X') {
            xCount++;
            oCount = 0;
        }
        else if (placementList[i] == 'O') {
            oCount++;
            xCount = 0;
        }
        if (xCount == 3) return 'X';
        else if (oCount == 3)return 'O';
    }
    xCount = 0, oCount = 0;
    //second column
    for (int i = 1; i <= 7; i += 3) {
        if (placementList[i] == 'X') {
            xCount++;
            oCount = 0;
        }
        else if (placementList[i] == 'O') {
            oCount++;
            xCount = 0;
        }
        if (xCount == 3) return 'X';
        else if (oCount == 3)return 'O';
    }
    xCount = 0, oCount = 0;
    //third column
    for (int i = 2; i <= 8; i += 3) {
        if (placementList[i] == 'X') {
            xCount++;
            oCount = 0;
        }
        else if (placementList[i] == 'O') {
            oCount++;
            xCount = 0;
        }
        if (xCount == 3) return 'X';
        else if (oCount == 3)return 'O';
    }
    xCount = 0, oCount = 0;

    //diagonal \ 
    for (int i = 0; i <= 8; i += 4) {
        if (placementList[i] == 'X') {
            xCount++;
            oCount = 0;
        }
        else if (placementList[i] == 'O') {
            oCount++;
            xCount = 0;
        }
        if (xCount == 3) return 'X';
        else if (oCount == 3)return 'O';
    }
    xCount = 0, oCount = 0;
    //diagonal /
    for (int i = 2; i <= 6; i += 2) {
        if (placementList[i] == 'X') {
            xCount++;
            oCount = 0;
        }
        else if (placementList[i] == 'O') {
            oCount++;
            xCount = 0;
        }
        if (xCount == 3) return 'X';
        else if (oCount == 3)return 'O';
    }
    xCount = 0, oCount = 0;
    return 'A';
}

bool TTT::takeRound(int round) {
    for (int fPos = 0; fPos < 9; fPos++) {
        if (isClicked(fPos)) {
            if (squareFields[fPos].left != -500) {
                placeSound.play();
                pieces[round] = round % 2 == 0 ? addX : addO;
                pieces[round].move((float)position[fPos].x, (float)position[fPos].y);
                squareFields[fPos].left = -500;
                placementList[fPos] = round % 2 == 0 ? 'X' : 'O';
                std::cout << "placementList pos: " << fPos << " " << placementList[fPos] << std::endl;
                updateWhoseTurn(round);
                return true;
            }
            else {
                updateWhoseTurn(round);
                return false;
            }
        }
    }
    return false;
}

bool TTT::back(sf::Mouse mouse) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (event.mouseButton.x >= 11 && event.mouseButton.x <= 43 && event.mouseButton.y >= 10 && event.mouseButton.y <= 42) {
            restartSound.play();
            return true;
        }
    }
    return false;
}

void TTT::gameLoop() {
    int round = 0;
    char proof;
    bool winnerFound = true;
    whoseTurn();
    rectCoord();
    posPieces();
    initResetBtn();
    placeSound.setBuffer(buffer);
    restartSound.setBuffer(buffer1);
    sf::Mouse mouse;

    for (int i = 0; i < 9; i++) {
        pieces[i] = addWhite;
        placementList[i] = 'A';
    }

    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                restart(&round, mouse, &winnerFound);
                window.close();
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && round < 9 && winnerFound) {
            if (takeRound(round)) {
                proof = winFunction(round);
                if (proof == 'X' || proof == 'O')winnerFound = false;
                else round++;
            }
        }
        if (winnerFound == false) {
            round % 2 == 0 ? playerWinMsg.setString("  Spieler 1\n   gewinnt") : playerWinMsg.setString("  Spieler 2\n   gewinnt");
            restart(&round, mouse, &winnerFound);
        }
        else if (round >= 9) {
            playerWinMsg.setString("Unentschieden");
            round++;
            restart(&round, mouse, &winnerFound);
            window.close();
        }
        if (back(mouse)) {
            restart(&round, mouse, &winnerFound);
            window.close();
        }
        window.clear(sf::Color(255, 255, 255, 255));
        if (winnerFound == false || round >= 9)window.draw(addRes);
        window.draw(addPlayfield);
        window.draw(addGoBack);
        winnerFound == true && round < 9 ? window.draw(playerTurnMsg) : window.draw(playerWinMsg);
        for (int i = 0; i < 9; i++) {
            window.draw(pieces[i]);
        }
        window.display();
    }
}

//-----------------3DTicTacToe

void TTT3D::loadGameWindow() {
    window.create(sf::VideoMode(700, 800), "3D-TicTacToe", sf::Style::Close);
}

bool TTT3D::loadGameFiles() {
    return (playfield3D.loadFromFile("img/3Dplayfield.png"));
}

void TTT3D::setGameFiles() {
    addPlayfield3D.setTexture(playfield3D);
    addPlayfield3D.setPosition(160, 150);
}

void TTT3D::gameLoop() {
    loadGameFiles();
    setGameFiles();
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)window.close();
        }


        window.clear(sf::Color(255, 255, 255, 255));
        window.draw(addPlayfield3D);
        window.display();
    }
}



//-----------------MAIN_MENU


void mainMenu::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 3;i++) {
        window.draw(menuText[i]);
    }
    window.draw(menuLogo);
}
void mainMenu::moveUp() {
    if (mainMenuSelected - 1 >= 0) {
        selectSound.play();
        menuText[mainMenuSelected].setFillColor(sf::Color::Black);
        mainMenuSelected--;
        if (mainMenuSelected == -1)mainMenuSelected = 0;
        menuText[mainMenuSelected].setFillColor(sf::Color::Red);
    }

}
void mainMenu::moveDown() {
    if (mainMenuSelected + 1 <= 3) {
        selectSound.play();
        menuText[mainMenuSelected].setFillColor(sf::Color::Black);
        mainMenuSelected++;
        if (mainMenuSelected == 3)mainMenuSelected = 0;
        menuText[mainMenuSelected].setFillColor(sf::Color::Red);
    }
}

bool mainMenu::loadSoundFile() {
    return (buffer.loadFromFile("sounds/selectSound.wav"));
}

bool mainMenu::loadFontFile() {
    return (menuFont.loadFromFile("fonts/data-latin.ttf"));
}

void mainMenu::setMenuText() {
    menuLogo.setString("TicTacToe");
    menuLogo.setFillColor(sf::Color::Black);
    menuLogo.setFont(menuFont);
    menuLogo.setCharacterSize(120);
    menuLogo.setPosition(80.f, 50.f);
    
    menuText[0].setString("NORMAL");
    menuText[0].setFillColor(sf::Color::Red);
    menuText[0].setFont(menuFont);
    menuText[0].setCharacterSize(60);
    menuText[0].setPosition(250.f, 250.f);

    menuText[1].setString("3D");
    menuText[1].setFillColor(sf::Color::Black);
    menuText[1].setFont(menuFont);
    menuText[1].setCharacterSize(60);
    menuText[1].setPosition(305.f, 350.f);

    menuText[2].setString("Verlassen");
    menuText[2].setFillColor(sf::Color::Black);
    menuText[2].setFont(menuFont);
    menuText[2].setCharacterSize(60);
    menuText[2].setPosition(200.f, 450.f);

    mainMenuSelected = 0;
}

mainMenu::mainMenu(float width, float height) {
    if (!loadSoundFile()) {
        std::cout << "ERROR loadSoundFile()" << std::endl;
    }
    if (!loadFontFile()) {
        std::cout << "ERROR loadFontFile()" << std::endl;
    }
    setMenuText();
}