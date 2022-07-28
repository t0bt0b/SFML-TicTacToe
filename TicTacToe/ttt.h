#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>


class TTT {
private:
    sf::RenderWindow window;
    sf::Texture playfield, symbolX, symbolO, res, white, goBack;
    sf::Sprite addPlayfield, addX, addO, pieces[9], addRes, addWhite, addGoBack;
    sf::Font font;
    sf::Text playerTurnMsg, playerWinMsg;
    sf::Event event;
    sf::IntRect squareFields[9], restartBtn;
    sf::Vector2i position[9];
    sf::SoundBuffer buffer, buffer1;
    sf::Sound placeSound, restartSound;
    char* placementList = (char*)malloc(sizeof(char) * 9);
    bool teste = false;
    sf::Image icon;

public:
    void loadGameWindow();
    bool loadGameFiles();
    bool loadFontFile();
    bool loadSoundFile();
    bool loadIconFile();
    void setGameFiles();
    void whoseTurn();
    void updateWhoseTurn(int round);
    void rectCoord();
    void setRectCoord(sf::IntRect& fields, int left, int top, int width, int height);
    bool takeRound(int turn);
    bool isClicked(int fPos);
    void posPieces();
    void setPosPieces(sf::Vector2i& pos, int left, int top);
    void gameLoop();
    char winFunction(int round);
    void restart(int* round, sf::Mouse mouse, bool* winnerFound);
    void initResetBtn();
    bool back(sf::Mouse mouse);
};


class TTT3D {
private:
    sf::RenderWindow window;
    sf::Texture playfield3D;
    sf::Sprite addPlayfield3D;
    sf::Event event;

public:
    void loadGameWindow();
    bool loadGameFiles();
    void setGameFiles();
    void gameLoop();
};


class mainMenu {
public:
    mainMenu(float width, float height);

    void draw(sf::RenderWindow& window);
    void moveUp();
    void moveDown();
    bool loadFontFile();
    bool loadSoundFile();
    void setMenuText();
    int mainMenuPressed() {
        return mainMenuSelected;
    }
    sf::Text menuText[3], menuLogo;
    sf::SoundBuffer buffer;
    sf::Sound selectSound;

private:
    int mainMenuSelected;
    sf::Font menuFont;
};


