/*#include <SFML\Graphics.hpp>
#include <vector>
#define keyVal_playerX 1
#define keyVal_playerO 2
#define keyVal_playerEmpty 0
#define keyVal_gameEnded_Draw 3

typedef std::vector<std::vector<unsigned>> Matrix;


const int win_x = 1000, win_y = 1000;
sf::RenderWindow window(sf::VideoMode(win_x, win_y), "Tic-Tac-Toe (Winner Takes All)");

class Board {
private:
	Matrix boardValues;
	unsigned turn;
public:
	Board() {
		clearBoard();
	}
	void clearBoard() {
		boardValues = { {keyVal_playerEmpty, keyVal_playerEmpty, keyVal_playerEmpty},
				{keyVal_playerEmpty, keyVal_playerEmpty, keyVal_playerEmpty},
				{keyVal_playerEmpty, keyVal_playerEmpty, keyVal_playerEmpty} };
		turn = keyVal_playerX;
	}
	void setBoardValue(unsigned x_pos, unsigned y_pos) {
		boardValues.at(y_pos).at(x_pos) = turn;
		turn = (turn == keyVal_playerX) ? keyVal_playerO : keyVal_playerX; //this part makes the players switch turns
	}
	bool isDraw() { //this function checks if the board has no more keyValue_playerEmpty
		for (std::vector<unsigned>& y : boardValues) {
			for (unsigned& x : y) if (x == keyVal_playerEmpty) return true;
		}
		return false;
	}
	unsigned checkWinner() { //this method checks the board if there's any winner, if the game cannot be continued, it returns draw
		if (!isDraw()) return keyVal_gameEnded_Draw;
		/////This part checks all possible 3 same symbols, and if there are 3 pairs, it returns the symbol of which pair
		//checks diagonals
		if (boardValues[0][0] == boardValues[1][1] && boardValues[1][1] == boardValues[2][2]) return boardValues[1][1];
		if (boardValues[0][2] == boardValues[1][1] && boardValues[1][1] == boardValues[2][0]) return boardValues[1][1];
		//checks Horizontally
		for (int y = 0; y < 2; y++) if (boardValues[y][0] == boardValues[y][1] && boardValues[y][1] == boardValues[y][2]) return boardValues[y][1];
		//checks Vertically
		for (int x = 0; x < 2; x++) if (boardValues[0][x] == boardValues[1][x] && boardValues[1][x] == boardValues[2][x]) return boardValues[1][x];

		return keyVal_playerEmpty;
	}
	unsigned whosTurn() { //just returns if which turns (probably might not be used but i'm just gonna put it here)
		return turn;
	}
	Matrix getBoardValues() { //just returns the value of each of the boxes.
		return boardValues;
	}
};

class symbolHandler{
private:
	sf::RectangleShape LPlayer1_rect;
	sf::RectangleShape RPlayer1_rect;					
	sf::CircleShape Player2_circ;			
public:
	symbolHandler(int windowX, int windowY, float position_x, float position_y, float size):
	LPlayer1_rect(sf::Vector2f(200.0f * size, 50.0f * size)),  // Initialize with size
    RPlayer1_rect(sf::Vector2f(200.0f * size, 50.0f * size)),  // Initialize with size
    Player2_circ(100.0f * size)
	{
		int win_x = windowX;
		int win_y = windowY;
		// Set properties for LPlayer1_rect
        LPlayer1_rect.setFillColor(sf::Color::White);
        LPlayer1_rect.setPosition(position_x, position_y);
        LPlayer1_rect.setOrigin(100, 25);
        LPlayer1_rect.setRotation(45);

        // Set properties for RPlayer1_rect
        RPlayer1_rect.setFillColor(sf::Color::Red);
        RPlayer1_rect.setPosition(position_x, position_y);
        RPlayer1_rect.setOrigin(100, 25);
        RPlayer1_rect.setRotation(135);

        // Set properties for Player2_circ
        Player2_circ.setFillColor(sf::Color::White);
        Player2_circ.setOutlineColor(sf::Color::Red);
        Player2_circ.setOutlineThickness(-10);
        Player2_circ.setOrigin(100.0f, 100.0f);
        Player2_circ.setPosition(position_x, position_y);
	}
	void show(int symbol){
		switch(symbol){
			case keyVal_playerX:
				//hide player2_circle
				window.draw(LPlayer1_rect);
				window.draw(RPlayer1_rect);
			case keyVal_playerO:
				//hide left and right player1_ri
				window.draw(Player2_circ);
			
		}
	}
};


int main()
{
	symbolHandler Box1(win_x, win_y, 10, 10, 0.25);

	Board mainboardValues;
	mainboardValues.setBoardValue(0, 0);

	while (window.isOpen())
	{
		//stuffs to make event work
		sf::Event event;
		while (window.pollEvent(event))
		{
			//Close the Window
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			//WASD Movement
			if (event.key.code == sf::Keyboard::W)
			{

			}
			if (event.key.code == sf::Keyboard::A)
			{

			}
			if (event.key.code == sf::Keyboard::S)
			{

			}
			if (event.key.code == sf::Keyboard::D)
			{

			}
		}

		window.clear();
		window.draw(Box1);
		window.display();
	}
}
*/