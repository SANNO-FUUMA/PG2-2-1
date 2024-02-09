#include"Enemy.h"
#include"Novice.h"
void Enemy::Intialize() {
	x_ = 300;
	y_ = 100;
	r_ = 32;
	speed_ = 9;
	isAlive_ = 1;

}
void Enemy::Update() 
{
	if (isAlive_ == 1) 
	{
		x_ += speed_;
		if (x_ <= r_ || x_ >= 1200 +r_)
		{
			speed_ *= -1;
		}
	}
}

void Enemy::Draw() {
	if (isAlive_ == 1) {
		Novice::DrawEllipse(x_,y_,r_,r_,0.0f,WHITE,kFillModeSolid);
	}
}