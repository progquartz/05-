#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

void drawText(COORD &Position);
void clearText(COORD &Position);
void gotoxyf(int x, int y, char* s);

int main() {
	COORD m_Position = { 0,0 };
	CONSOLE_SCREEN_BUFFER_INFO m_csbi;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	system(" mode  con lines=50   cols=80 ");
	GetConsoleScreenBufferInfo(h, &m_csbi);

	while (1) {
		int m_KeyGotten = _getch();
		m_KeyGotten = _getch();
		// up = 22472 right = 22477 left = 22475 down = 22480
		if (m_KeyGotten % 2 == 0) {
			if (m_KeyGotten == 72 && m_Position.Y > 0) { // up
				clearText(m_Position);
				--m_Position.Y;
				drawText(m_Position);
			}
			else if (m_KeyGotten == 80 && m_Position.Y <= m_csbi.dwSize.Y - 2) { // down
				clearText(m_Position);
				++m_Position.Y;
				drawText(m_Position);
			}
		}
		else {
			if (m_KeyGotten == 75 && m_Position.X > 0) { // left
				clearText(m_Position);
				--m_Position.X;
				drawText(m_Position);
			}
			else if (m_KeyGotten == 77 && m_Position.X <= m_csbi.dwSize.X - 2) { // right
				clearText(m_Position);
				++m_Position.X;
				drawText(m_Position);
			}
		}
	}

}

void drawText(COORD &Position) {
	gotoxyf(Position.X, Position.Y, "T");
}

void clearText(COORD &Position) {
	gotoxyf(Position.X, Position.Y, " ");
}

void gotoxyf(int x, int y, char* s) { //x,y로 변경, 좌표값에 바로 문자열을 입력할 수 있도록 printf함수 삽입  
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("%s", s);
}
