#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

void clearScreen();
void drawText(COORD &Position);
void gotoxyf(int x, int y, char* s);

int main() {
	COORD m_Position = { 0,0 };
	CONSOLE_SCREEN_BUFFER_INFO m_csbi;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	system(" mode  con lines=50   cols=80 ");
	GetConsoleScreenBufferInfo(h, &m_csbi);

	clearScreen();
	while (1) {
		int m_KeyGotten = _getch();
		m_KeyGotten = _getch();
		// up = 22472 right = 22477 left = 22475 down = 22480
		if (m_KeyGotten % 2 == 0) {
			if (m_KeyGotten == 72 && m_Position.Y > 0) { // up
				--m_Position.Y;
				drawText(m_Position);
			}
			else if (m_KeyGotten == 80 && m_Position.Y <= m_csbi.dwSize.Y-2) { // down
				++m_Position.Y;
				drawText(m_Position);
			}
		}
		else {
			if (m_KeyGotten == 75 && m_Position.X > 0) { // left
				--m_Position.X;
				drawText(m_Position);
			}
			else if (m_KeyGotten == 77 && m_Position.X <= m_csbi.dwSize.X-2) { // right
				++m_Position.X;
				drawText(m_Position);
			}
		}
	}

}

void drawText(COORD &Position) {
		clearScreen();
		gotoxyf(Position.X, Position.Y, "T");
}

void clearScreen()
{
	DWORD
		n,
		size;
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(h, &csbi);


	size = csbi.dwSize.X * csbi.dwSize.Y; 
	// csbi.dwSize�� �ش� ���� �ܼ�â�� ũ�⸦ �ǹ�.
	// dwCursorPosition�� ���� ���� �κ��� ��ǥ�� �������� �˷���.

	FillConsoleOutputCharacter(h, TEXT(' '), size, coord, &n);
	GetConsoleScreenBufferInfo(h, &csbi);
	FillConsoleOutputAttribute(h, csbi.wAttributes, size, coord, &n);

	SetConsoleCursorPosition(h, coord);
}

void gotoxyf(int x, int y, char* s) { //x,y�� ����, ��ǥ���� �ٷ� ���ڿ��� �Է��� �� �ֵ��� printf�Լ� ����  
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("%s", s);
}
