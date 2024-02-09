#pragma once
class Bullet
{
private:
	int x_;
	int y_;
	int r_;
	int speed_;
	bool isShot_;
public:
	void Intialize();
	void Update(char* keys, char* prekeys, int X_,int Y_);
	void Draw();
	int GetPosX() { return x_; }
	int GetPosY() { return y_; }
	int GetR() { return r_; }
};