#pragma once
class Enemy {
private:
	int x_;
	int y_;
	int speed_;
	int r_;
	int isAlive_;
public:
	void Intialize();
	void Update();
	void Draw();
	int GetPosX() { return x_; }
	int GetPosY() { return y_; }
	int GetR() { return r_; }
	
};