#include "player.h"
#include "Novice.h"

void Player::Intialize()
{
	x_ = 660;
	y_ = 600;
	r_ = 32;
	//isShot_ = true;
	isAlive_ = 0;
	X_ = 1000;
	Y_ = 1000;
	R_ = 8;
	speed_ = 8;
}

void Player::Update()
{
	if (Novice::CheckHitKey(DIK_W)) {
		speed_ = -20;
		y_ = y_ + speed_;
	}


	if (Novice::CheckHitKey(DIK_A)) {
		speed_ = -20;
		x_ = x_ + speed_;


	}

	if (Novice::CheckHitKey(DIK_S)) {
		speed_ = 20;
		y_ = y_ + speed_;



	}

	if (Novice::CheckHitKey(DIK_D)) {
		speed_ = 20;
		x_ = x_ + speed_;


	}
}
	

void Player::Draw()
{
	Novice::DrawEllipse(x_, y_, r_, r_, 0.0f, BLACK, kFillModeSolid);
}
