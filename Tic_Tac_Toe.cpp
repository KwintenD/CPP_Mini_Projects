#include <iostream>

class Board {
private:
	unsigned char m_values[9];
	bool m_isNotAvailable[9];

public:
	Board();
	~Board();

	void Set(int index, unsigned char value);
	bool Get(int index) const;
	void Draw();
	bool IsWin() const;
	bool IsFull() const;
};

Board* g_pBoard{ new Board() };
bool g_isPlayerOne{ true };

void ProcessInput();

int main() {
	std::cout << "Let's play tic tac toe!\n\n";

	while (true) {
		g_pBoard->Draw();
		ProcessInput();
		std::cout << "\n\n\n";

		if (g_pBoard->IsWin()) {
			g_pBoard->Draw();
			g_isPlayerOne = !g_isPlayerOne;
			std::cout << (g_isPlayerOne ? "Player 1 won!" : "Player 2 won!");
			break;
		}

		if (g_pBoard->IsFull()) {
			g_pBoard->Draw();
			std::cout << "Non of the players won.";
			break;
		}
	}

	std::cin.get();

	return 0;
}

void ProcessInput() {
	std::cout << (g_isPlayerOne ? "Player 1\n" : "Player 2\n");

	int input;
	std::cout << "Choose a cell: ";
	std::cin >> input;

	if (!g_pBoard->Get(input - 1)) {
		g_pBoard->Set(input - 1, g_isPlayerOne ? 'X' : 'O');
		g_isPlayerOne = !g_isPlayerOne;
	}
	else ProcessInput();
}

Board::Board() : m_values{ '1', '2', '3', '4' ,'5' ,'6' ,'7' ,'8' ,'9' }, m_isNotAvailable{ } { }
Board::~Board() {
	delete[] &m_values;
	delete[] &m_isNotAvailable;
}
void Board::Set(int index, unsigned char value) {
	m_values[index] = value;
	m_isNotAvailable[index] = true;
}
bool Board::Get(int index) const {
	return m_isNotAvailable[index];
}
void Board::Draw(){
	std::cout << "Board: \n";

	unsigned char size = unsigned char(sqrt(sizeof(m_values) / sizeof(unsigned char)));
	for (unsigned char y{}; y < size; y++) {
		std::cout << " ";
		for (unsigned char x{}; x < size; x++) {
			std::cout << m_values[3 * y + x] << (x == 2 ? "" : " | ");
		}
		std::cout << '\n';
		std::cout << (y == 2 ? "\n" : " ---------\n");
	}
}
bool Board::IsWin() const {
	bool a{}, b{};

	int size = int(sqrt(sizeof(m_values) / sizeof(unsigned char)));

	for (int i{}; i < size; i++) {
		a = m_values[i] == m_values[3 + i];
		b = m_values[i] == m_values[6 + i];
		if (a && b) return true;
	}

	for (int i{}; i < size; i++) {
		a = m_values[i * size] == m_values[1 + i * size];
		b = m_values[i * size] == m_values[2 + i * size];
		if (a && b) return true;
	}

	a = m_values[0] == m_values[4];
	b = m_values[0] == m_values[8];
	if (b && a) return true;

	a = m_values[2] == m_values[4];
	b = m_values[2] == m_values[6];
	if (b && a) return true;

	return false;
}
bool Board::IsFull() const {
	bool isFull = true;
	for (unsigned char i{}; i < sizeof(m_isNotAvailable) / sizeof(bool); i++) {
		if (!m_isNotAvailable[i]) {
			isFull = false;
			break;
		}
	}
	return isFull;
}
