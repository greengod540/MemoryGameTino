#include "Board.h"
#include "Presenter.h"
#include "InputManager.h"
#include "SoundManager.h"
#include <random>
bool changed = false;
int firstClick = NULL;
int secondClick = NULL;
int clickCounter = 1;
SoundManager soundMan;
Board::Board()
{

}

Board::~Board()
{

}

void Board::init()
{
	string configFile = "boardInit.txt";

	fstream stream;

	string backgorundImg, player1ConfigFile, player2ConfigFile, tmp, card1Config, card2, card3, card4, card5,
	card6, card7, card8, card9, card10;

	stream.open(CONFIG_FOLDER + configFile);

    stream >> tmp >> backgorundImg;
	stream >> tmp >> player1ConfigFile >> player2ConfigFile;
	stream >> tmp >> card1Config;
	stream >> tmp >> card2;
	stream >> tmp >> card3;
	stream >> tmp >> card4;
	stream >> tmp >> card5;
	stream >> tmp >> card6;
	stream >> tmp >> card7;
	stream >> tmp >> card8;
	stream >> tmp >> card9;
	stream >> tmp >> card10;


	stream.close();

	m_background = loadTexture(backgorundImg);

	m_player1.init(player1ConfigFile);
	m_player2.init(player2ConfigFile);

	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_int_distribution<int> posXDist(300, 800);
	std::uniform_int_distribution<int> posYDist(0, 700);

	m_card1.init(card1Config);
	m_card2.init(card2);
	m_card3.init(card3);
	m_card4.init(card4);
	m_card5.init(card5);
	m_card6.init(card6);
	m_card7.init(card7);
	m_card8.init(card8);
	m_card9.init(card9);
	m_card10.init(card10);
	cards = { m_card1, m_card2, m_card3, m_card4, m_card5 , m_card6 , m_card7, m_card8 , m_card9 , m_card10 };
	ids[0] = 9;
	ids[1] = 8;
	ids[2] = 7;
	ids[3] = 6;
	ids[4] = 5;
	
	for (int i = 0; i < cards.size(); i++) {
		bool overlap;

		do {
			overlap = false;
			int randomPosX = posXDist(eng);
			int randomPosY = posYDist(eng);

			SDL_Rect currentCardRect = { randomPosX, randomPosY, 100, 200 };

			for (int j = 0; j < i; j++) {
				if (SDL_HasIntersection(&currentCardRect, &cards[j].m_card.rect)) {
					overlap = true;
					break;
				}
			}

			if (!overlap) {
				cards[i].m_card.rect = { randomPosX, randomPosY, 100, 100 };
			}
		} while (overlap);
	}

	
	soundMan.init();
	


}

void Board::update()
{
	

	for (int i = 0; i < cards.size(); i++) {

		if (isMouseInRect(InputManager::m_mouseCoor, cards[i].m_card.rect) && InputManager::isMousePressed()) {
			cards[i].changeTexture();
			
			soundMan.playSound(CARD_FLIP);
			clickCounter++;
			if (clickCounter == 1) {
				firstClick = i;
			}
			else if (clickCounter == 2) {
				secondClick = i;
			}
			else if (clickCounter >= 3) {
				soundMan.playSound(CARDS_NOT_SAME);
				firstClick = NULL;
				secondClick = NULL;
				clickCounter = 0;
			}
		}

	}
	for (const auto& entry : ids) {
		if ((entry.first == firstClick && entry.second == secondClick) ||
			(entry.first == secondClick && entry.second == firstClick)) {
			soundMan.playSound(CARDS_SAME);
			cards[firstClick].destroy();
			cards[secondClick].destroy();
			
			
			
		}
		
		
		
	}
	if (ids.empty()) {
		exit(1);
	}
	
		
	
		
}

void Board::draw()
{
	drawObject(m_background);

	for (int i = 0; i < cards.size(); i++) {
		cards[i].draw();
	}


	//m_player1.draw();
	//m_player2.draw();
}

void Board::destroy()
{
	SDL_DestroyTexture(m_background);

	m_card1.destroy();
	m_card2.destroy();
	m_card3.destroy();
	m_card4.destroy();
	m_card5.destroy();
	m_card6.destroy();
	m_card7.destroy();
	m_card8.destroy();
	m_card9.destroy();
	m_card10.destroy();

	//m_player1.destroy();
	//m_player2.destroy();
}