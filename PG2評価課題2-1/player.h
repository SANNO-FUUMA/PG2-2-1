#pragma once
class Player {
private:
	int x_;
	int y_;
	int r_;
	//bool isShot_;
	bool isAlive_;
	int X_;
	int Y_;
	int R_;
	int speed_;
public:
	void Intialize();
	void Update();
	void Draw();
	int GetPosX() { return x_; }
	int GetPosY() { return y_; }
	int GetR() { return r_; }
};

