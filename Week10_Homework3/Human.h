#pragma once
#include "Monster.h"
#include <conio.h>
enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };

class Human : public Monster {
public:
	Human(string n = "?̷???????", string i = "??", int px = 0, int py = 0)
		: Monster(n, i, px, py) {}

	int getDirKey() { return _getche() == 224 ? _getche() : 0; }
	void move(int** map, int maxx, int maxy) {
		if (_kbhit()) {
			char ch = getDirKey();
			if (ch == Left) x--;
			else if (ch == Right) x++;
			else if (ch == Up) y--;
			else if (ch == Down) y++;
			else return;
			clip(maxx, maxy);
			eat(map);
		}
	}
};

class Tuman : public Human {
public:
	Tuman(string n = "?̷??ǿ???", string i = "??", int px = 0, int py = 0)
		: Human(n, i, px, py) {}

	void move(int** map, int maxx, int maxy, char ch) {
		if (ch == Left || ch == 'a') x--;
		else if (ch == Right || ch == 'd') x++;
		else if (ch == Up || ch == 'w') y--;
		else if (ch == Down || ch == 's') y++;
		else return;
		clip(maxx, maxy);
		eat(map);
	}
};