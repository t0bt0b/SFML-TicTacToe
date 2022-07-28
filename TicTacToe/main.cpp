#include "ttt.h"

int main() {
	TTT normalGame;
	int mouseX = 0, mouseY = 0, ss = 0;
	sf::RenderWindow menu(sf::VideoMode(700, 800), "Hauptmenü", sf::Style::Close);
	mainMenu mM(menu.getSize().x, menu.getSize().y);
	sf::Image icon;
	icon.loadFromFile("img/icon.png");
	menu.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	mM.selectSound.setBuffer(mM.buffer);

	if (!normalGame.loadGameFiles()) {
		std::cout << "Fehler game.loadGameFiles()" << std::endl;
		return EXIT_FAILURE;
	}
	if (!normalGame.loadFontFile()) {
		std::cout << "Fehler game.loadFontFile()" << std::endl;
		return EXIT_FAILURE;
	}
	if (!normalGame.loadSoundFile()) {
		std::cout << "Fehler game.loadSoundFile()" << std::endl;
		return EXIT_FAILURE;
	}
	if (!normalGame.loadIconFile()) {
		std::cout << "Fehler game.loadIconFile()" << std::endl;
		return EXIT_FAILURE;
	}

	while (menu.isOpen()) {
		sf::Event event;
		while (menu.pollEvent(event)) {
			if (event.type == sf::Event::Closed)menu.close();
			mouseX = sf::Mouse::getPosition(menu).x;
			mouseY = sf::Mouse::getPosition(menu).y;
			if (mouseX >= 255 && mouseX <= 425 && mouseY >= 270 && mouseY <= 310) {
				if (ss != 1) {
					ss = 1;
					mM.selectSound.play();
				}
				mM.menuText[0].setFillColor(sf::Color::Red);
				mM.menuText[1].setFillColor(sf::Color::Black);
				mM.menuText[2].setFillColor(sf::Color::Black);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					mM.selectSound.play();
					normalGame.loadGameWindow();
					normalGame.setGameFiles();
					normalGame.gameLoop();
				}
			}
			if (mouseX >= 312 && mouseX <= 365 && mouseY >= 372 && mouseY <= 410) {
				if (ss != 2) {
					ss = 2;
					mM.selectSound.play();
				}
				mM.menuText[1].setFillColor(sf::Color::Red);
				mM.menuText[0].setFillColor(sf::Color::Black);
				mM.menuText[2].setFillColor(sf::Color::Black);
			}

			if (mouseX >= 204 && mouseX <= 468 && mouseY >= 471 && mouseY <= 510) {
				if (ss != 3) {
					ss = 3;
					mM.selectSound.play();
				}
				mM.menuText[2].setFillColor(sf::Color::Red);
				mM.menuText[1].setFillColor(sf::Color::Black);
				mM.menuText[0].setFillColor(sf::Color::Black);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					mM.selectSound.play();
					menu.close();
					break;
				}
			}
			//std::cout << "X: " << mouseX << std::endl;
			//std::cout << "Y: " << mouseY << std::endl;
			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::Up) {
					mM.moveUp();
					break;
				}
				if (event.key.code == sf::Keyboard::Down) {
					mM.moveDown();
					break;
				}
				
				if (event.key.code == sf::Keyboard::Return) {
					//sf::RenderWindow normal(sf::VideoMode(700, 800), "game");
					//sf::RenderWindow _3D(sf::VideoMode(700, 800), "3d");
					
					int x = mM.mainMenuPressed();
					if (x == 0) {
						normalGame.loadGameWindow();
						normalGame.setGameFiles();
						normalGame.gameLoop();
					}
					
					if (x == 1) {
						//3D
					}

					if (x == 2) {
						menu.close();
						break;
					}

				}
			}
		}
		menu.clear(sf::Color(255, 255, 255, 255));
		mM.draw(menu);
		menu.display();
	}

}


//int main() {
//    TTT game;
//    //TTT3D dd;
//    //dd.loadGameWindow();
//    game.loadGameWindow();
//    
//    //Menu
//    //mainMenu menu;
//    //menu.loadGameWindow();
//
//    if (!game.loadGameFiles()) {
//        std::cout << "Fehler game.loadGameFiles()" << std::endl;
//        return EXIT_FAILURE;
//    }
//    game.setGameFiles();
//
//    if (!game.loadFontFile()) {
//        std::cout << "Fehler game.loadFontFile()" << std::endl;
//        return EXIT_FAILURE;
//    }
//
//    if (!game.loadSoundFile()) {
//        std::cout << "Fehler game.loadSoundFile()" << std::endl;
//        return EXIT_FAILURE;
//    }
//
//    if (!game.loadIconFile()) {
//        std::cout << "Fehler game.loadIconFile()" << std::endl;
//        return EXIT_FAILURE;
//    }
//
//
//    //Menu
//    //if (!menu.loadFiles()) {
//    //    std::cout << "Error loadFiles()" << std::endl;
//    //}
//    //menu.mainMenuLoop();
//
//    game.gameLoop();
//    //dd.gameLoop();
//    return EXIT_SUCCESS;
//}