#include <Novice.h>
#include"Player.h"
#include"Enemy.h"
#include"Bullet.h"
#include<math.h>
const char kWindowTitle[] = "GC1D_06_サンノウ_フウマ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char prekeys[256] = { 0 };

	//float prekeyes = 0;

	bool Collision(float obj1_x, float obj1_y, float obj1_r, float obj2_x, float obj2_y, float obj2_r) {
		float a = obj2_x - obj1_x;
		float b = obj2_y - obj1_y;
		float distance = sqrtf(a * a + b * b);

		if (distance <= obj1_r + obj2_r) {
			return = true;
		}
		else {
			return = false;
		}
	};

	Player* d1 = new Player;
	d1->Intialize();

	Enemy* d2 = new Enemy;
	d2->Intialize();

	Bullet* d3 = new Bullet;
	d3->Intialize();

	int shot_posX = 0;//弾の
	int shot_posY = 0;//弾の
	bool isBulletshot = false;//弾はでてるか？//いいえ
	//int timer = 0;//リス時間

	enum scene {
		TITLE,
		GAME,
		CLEAR,
		OVER,
	};

	int scene = TITLE;
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(prekeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		///
		/// ↓更新処理ここから
		switch (scene)
		{
		case TITLE:
			

			break;
		case GAME:
			Collision(d1->GetPosX(), d1->GetPosY(), d1->GetR(), d2->GetPosX(), d2->GetPosY(), d2->GetR());
			d1->Update();
			d2->Update();
			d3->Update(keys, prekeys, d1->GetPosX(), d1->GetPosY());

			
			break;
		case CLEAR:
			break;
		case OVER:
			break;
		default:
			break;
		}
		

		/// ↑更新処理ここまで
		//
		switch (scene)
		{
		case TITLE:


			break;
		case GAME:
		
			d1->Draw();
			d2->Draw();
			d3->Draw();

			break;
		case CLEAR:
			break;
		case OVER:
			break;
		default:
			break;
		}
		

		///
		/// ↑更新処理ここまで


		///
		/// ↓描画処理ここから
		///
		
			//座標↓
		//Novice::ScreenPrintf(0, 50, "PlayerPosX=%d", posX);
		//Novice::ScreenPrintf(200, 50, "PlayerPosY=%d", posY);
		Novice::ScreenPrintf(0, 0, "W:up");
		Novice::ScreenPrintf(40, 0, "A:left");
		Novice::ScreenPrintf(100, 0, "D:right");
		Novice::ScreenPrintf(0, 20, "S:down");
		Novice::ScreenPrintf(400, 70, "isBulletshot=%d", isBulletshot);
		Novice::ScreenPrintf(0, 75, "bullet=%d", shot_posX);
		Novice::ScreenPrintf(200, 75, "bullet=%d", shot_posY);
		//Novice::ScreenPrintf(0, 95, "tekiki=%d", posx);


		/*if (isBulletshot == true) {
			Novice::DrawEllipse(shot_posX, shot_posY, 15, 15, 0, WHITE, kFillModeSolid);
			Novice::DrawEllipse(shot_posX, shot_posY, 10, 10, 0, RED, kFillModeSolid);

		}*/

		///
		/// ↑描画処理ここまで


		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (prekeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	delete d1;
	delete d2;
	delete d3;
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}