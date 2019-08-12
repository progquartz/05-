#include <conio.h>
#include <iostream>

using namespace std;

int main() {
	int count = -1;
	while (1) {
		if (_getch()) {
			count = ++count % 10;
			switch (count)
			{

			case 0:
				cout << "H";
				break;
			case 1:
				cout << "e";
				break;
			case 2:
				cout << "l";
				break;
			case 3:
				cout << "l";
				break;
			case 4:
				cout << "o";
				break;
			case 5:
				cout << "W";
				break;
			case 6:
				cout << "o";
				break;
			case 7:
				cout << "r";
				break;
			case 8:
				cout << "l";
				break;
			case 9:
				cout << "d\n";
				break;
			}
			// cout << "Hello world" << "\n";
		}
	}
	return 0;
}