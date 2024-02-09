#include "Bullet.h"
#include"Novice.h"

//void Bullet() {
//	x_ = 1000;
//	y_ = 1000;
//	r_ = 32;
//	speed_ = 8;
//}

void Bullet::Intialize()
{
	x_ = 1000;
	y_ = 1000;
	r_ = 32;
	speed_ = 8;
	isShot_ = false;
}

void Bullet::Update(char*keys,char*prekeys, int X_,int Y_) {
	if (!prekeys[DIK_SPACE] && keys[DIK_SPACE] && isShot_ == false) {//弾の発射制御

		isShot_ = true;//弾が打たれているとき//はい

		x_ = X_;
		y_ = Y_;

	}
	if (isShot_ == true) {

		y_ = y_ - 20;

		if (y_ < -30) {

			isShot_ = false;
		}
	}
}

void Bullet::Draw() {
	Novice::DrawEllipse(x_, y_, r_, r_, 0.0f, RED, kFillModeSolid);
}