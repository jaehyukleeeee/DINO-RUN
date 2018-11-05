#pragma once
#pragma once
class Gameframework {
public:
	void Init();
	void Update();
	void Render();
	void Release();
private:
};

class Screen {
public:
	void Init();
	void Flipping();
	void Clear();
	void Release();
	void Print(int x, int y, char *string);
	void SetColor(unsigned short color);
protected:
	static int s_Index;
	static HANDLE s_Screen[2];
};

class Player {
public:
	void Left() {
		X--;
	}
	void Right() {
		X++;
	}
	void Jump() {
		Y--;
	}
	void Down() {
		Y++;
	}
	int X = 10; //36
	int Y = 20;
	int i = 0;
};

class Block {
public:
	int X = 65;
};

class Blockmove {
public:
	int X=80;
	int Y[3] = { 20,19,18 };
	void Left() {
		X--;
	}
	void Right() {
		X++;
	}
};