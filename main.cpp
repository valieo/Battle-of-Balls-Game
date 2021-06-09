
#include"Player.h"
#include"Background.h"
#include <time.h>

#define CANDY_NUM 100
#define ENEMY_NUM 8
#define SPRITE_NUM 20


Candy* candy[CANDY_NUM];
Sprite* sprite[SPRITE_NUM];
Enemy* enemy[ENEMY_NUM];
Player* player;
Background* background;
ACL_Sound bkMusic;
bool gameOver = false;
bool pause = false;
bool music = true;


void InitGame();
void GameOver();
void Display();
void Update();
void FreeMemory();
void Refresh(int id);
void MouseControl(int x, int y, int button, int event);
void KeyControl(int key, int event);




int Setup() {

	initWindow("Battle of balls", DEFAULT, DEFAULT,WIDTH,HEIGTH);
	loadSound("bkMusic.mp3", &bkMusic);

	InitGame();
	registerTimerEvent(Refresh);
	registerKeyboardEvent(KeyControl);
	registerMouseEvent(MouseControl);
	startTimer(0, 50);		//20帧

	//FreeMemory();
	return 0;
}


void InitGame() {
	gameOver = false;
	pause = false;
	srand((unsigned)time(NULL));
	player = new Player(25);
	background = new Background();
	for (int i = 0; i < CANDY_NUM; ++i) {
		candy[i] = Candy::CreateRandomly();
	}
	for (int i = 0; i < SPRITE_NUM; ++i) {
		sprite[i] = Sprite::CreateRandomly();
	}
	for (int i = 0; i < ENEMY_NUM; ++i) {
		enemy[i] = Enemy::CreateRandomly();
	}
	
	
	if(music)
		playSound(bkMusic, 1);
}

void GameOver() {
	setTextBkColor(EMPTY);
	setTextSize(40);
	char tip[30];
	if (player->IsDead()) {
		setTextColor(RED);
		strcpy_s(tip, 30, "GAME OVER, YOU LOSE!!!");
	}
	else {
		setTextColor(BLUE);
		strcpy_s(tip, 30, "GAME OVER, YOU WIN!!!");
	}
	paintText(WIDTH / 2 - 220, HEIGTH / 2 - 20, tip);
	if (music) {
		stopSound(bkMusic);
	}
}


void Display() {
	
	clearDevice();
	background->Display();
	for (int i = 0; i < CANDY_NUM; ++i) {
		candy[i]->Display();
	}
	for (int i = 0; i < SPRITE_NUM; ++i) {
		sprite[i]->Display();
	}
	for (int i = 0; i < ENEMY_NUM; ++i) {
		
		enemy[i]->Display();
	}
	player->Display();
	
	Enemy::ShowNum();
	player->ShowImmuneTime();
	//music button
	char buttonOn[] = "Music: ON";
	char buttonOff[] = "Music: OFF";
	paintText(WIDTH - 120, 5, music ? buttonOn : buttonOff);
}

//数据处理(更新位置坐标……)
void Update() {
	if (!player->IsDead())
	{
		player->Move();
		for (int i = 0; i < CANDY_NUM; ++i) {
			player->Eat(*candy[i]);
			candy[i]->Reborn();
		}
		for (int i = 0; i < SPRITE_NUM; ++i) {
			sprite[i]->Move();
			player->Eat(*sprite[i]);
		}
		for (int i = 0; i < ENEMY_NUM; ++i) {
			enemy[i]->Move();
			//如果玩家在enemy的视野内，则enemy会追击玩家或逃离玩家
			if (!player->Immune() && enemy[i]->InScope(player->GetWorldPosition())) {
				if (enemy[i]->GetRadius() > player->GetRadius() + 2) {
					enemy[i]->Attack(player->GetWorldPosition());
				}
				else {
					enemy[i]->Flee(player->GetWorldPosition());
				}
			}
			player->Eat(*enemy[i]);
		}

		//玩家吃掉了所有的enmey
		if (Enemy::EnemyNum() <= 0) {
			gameOver = true;
			player->SetSpeedZero();	//速度置零，不再移动
		}
	}
	else {		//玩家被吃掉
		gameOver = true;
	}
}

void FreeMemory() {
	for (int i = 0; i < CANDY_NUM; ++i) {
		delete candy[i];
	}
	for (int i = 0; i < SPRITE_NUM; ++i) {
		delete sprite[i];
	}
	for (int i = 0; i < ENEMY_NUM; ++i) {
		delete enemy[i];
	}
	Enemy::SetNum(0);
	delete player;
	delete background;
}

//鼠标控制player移动
void MouseControl(int x, int y, int button, int event) {
	if (event == BUTTON_DOWN) {
		if (!gameOver && !pause) {
			//music button
			if (x > WIDTH - 120 && y < 25) {
				if (music) {
					stopSound(bkMusic);
					music = false;
				}
				else {
					playSound(bkMusic, 1);
					music = true;
				}
			}
			else {//控制移动
				Vector point(x, y);
				player->SetDestination(point + Object::GetRelativePos());
			}
		}
	}
}


void Refresh(int id) {
	if (id == 0) {

		beginPaint();
		Display();		//刷新界面
		if (gameOver) {	//游戏结束界面
			GameOver();
		}
		endPaint();

		Update();
	}
}

void KeyControl(int key, int event) {
	if (event == KEY_UP) {
		switch (key) {
		case 0x52:			//R键重新开始游戏
			cancelTimer(0);
			FreeMemory();

			InitGame();
			startTimer(0, 50);		//20帧
			break;
		case 0x50:			//P键暂停/继续
			if (pause) {
				pause = false;
				startTimer(0, 50);
				if (music) {
					playSound(bkMusic, 1);
				}
			}
			else {
				pause = true;
				cancelTimer(0);
				if (music) {
					stopSound(bkMusic);
				}
			}
			break;
		case 0x4D:			//M键开启或关闭静音
			if (music) {
				music = false;
				stopSound(bkMusic);
			}
			else {
				music = true;
				playSound(bkMusic, 1);
			}
			break;
		default:
			break;
		}
	}
}