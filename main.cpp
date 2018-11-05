#include<cstdio>
#include<cstdlib>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include"Screen.h"

Screen scr;
Gameframework gfw;
Player Char;
Block Bo;
Blockmove Bm;


int button = 0;
int RenderBlock = 0;
int score = 0;
int highscore = 0;
int temp;
char string[100];

//화면 출력 함수
////
//	scr.Print(0, 0, "┏━━━━━━━━━━━━━━━━━━━━┓");
//	scr.Print(0, 1, "┃ 공           룡			  런           ┃");
//	scr.Print(0, 2, "┃                                        ┃");
//	scr.Print(0, 3, "┃                                        ┃");
//	scr.Print(0, 4, "┃                                        ┃");
//	scr.Print(0, 5, "┃                                        ┃");
//	scr.Print(0, 6, "┃                                        ┃");
//	scr.Print(0, 7, "┃                                        ┃");
//	scr.Print(0, 8, "┃                                        ┃");
//	scr.Print(0, 9, "┃	                                       ┃");
//	scr.Print(0, 10, "┃                                        ┃");
//	scr.Print(0, 11, "┃                                       ┃");
//	scr.Print(0, 12, "┃                                        ┃");
//	scr.Print(0, 13, "┃                                        ┃");
//	scr.Print(0, 14, "┃                                        ┃");
//	scr.Print(0, 15, "┃                  ■                    ┃");
//	scr.Print(0, 16, "┃                  ■                    ┃");
//	scr.Print(0, 17, "┃                  ▼                    ┃");
//	scr.Print(0, 18, "┃     ┌────────────┐       ┃");
//	scr.Print(0, 19, "┃     │        Space Bar       │       ┃");
//	scr.Print(0, 20, "┃     └────────────┘       ┃");
//	scr.Print(0, 21, "┃     스페이스바를 눌러서 게임시작 !     ┃");
//	scr.Print(0, 22, "┃                                        ┃");
//	scr.Print(0, 23, "┗━━━━━━━━━━━━━━━━━━━━┛");
//
//
//} 하다가망함


// 초기화
void Gameframework::Init() {

}

// 갱신
void Gameframework::Update() {
	////////////////////점프///////////////////////
	if (button == 1) {
		Char.Jump();
		if (Char.Y <= 8)
			button = 2;
	}
	if (button == 2)
	{
		Char.Down();
		if (Char.Y == 20)
		{
			button = 0;
		}


	}


		////////////////////점프///////////////////////

		////////////////////블럭///////////////////////
		/*
		랜덤함수를 사용해서 1이면 블럭1개 2이면 블럭2개 3이면 블럭3개 소환
		*/

		int block = 0;
		int blmv = 0;

		srand(time(NULL));
		int a = rand() % 3;

		block = a;

		if (block == 0)
		{
			RenderBlock = 0;
			Bm.Left();
		}
		else if (block == 1)
		{
			RenderBlock = 1;
			Bm.Left();
		}
		else if (block == 2)
		{
			RenderBlock = 2;
			Bm.Left();
		}
	}


	////////////////////블럭///////////////////////




// 렌더링
void Gameframework::Render() {
	scr.Clear();
	scr.Print(70, 4, "\\│/"); // 태양
	scr.Print(69, 5, "─◎─"); // 태양
	scr.Print(70, 6, "/│\\"); // 태양
	scr.Print(35, 5, "공");
	scr.Print(45, 5, "룡");
	scr.Print(55, 5, "런");
	scr.Print(3,14,"    △ _ △\n");
	scr.Print(4, 15, "   ( ' ㅅ')  힘을내양 >.<b\n");
	scr.Print(5, 16   , "   (  * * )\n");
	scr.Print(6, 17, "   *    *   ");
	scr.Print(40, 15,"    ^  -- ^   \n");
	scr.Print(37, 16, "     (  !  . ! )  화이팅 >.< \n ");
	scr.Print(34, 17, "         ( ♥  ♥ )  \n");
	scr.Print(35, 18, "         *    * \n,");
	
	sprintf_s(string, "High Score : %d", highscore);
	scr.Print(5, 4, string);
	sprintf_s(string, "Score : %d", score);
	scr.Print(5, 5, string);
	if(Char.Y == 10){

		scr.Print(20,8,"앙 공룡띠");

	}

	scr.Print(Char.X, Char.Y-1, "▶"); //플레이어
	scr.Print(Char.X, Char.Y, "■");  //플레이어
	scr.Print(0, 21, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"); // 땅

	
	if (highscore >= score)
	{
		highscore = highscore;
	}
	else
	{
		highscore = score;
	}



	// 출력과 충돌처리
	if (RenderBlock == 0)
	{
		scr.Print(Bm.X, Bm.Y[0], "■");
		/////////////////////////////////////////
		if (Bm.X == 10)   //충돌
		{
			if (Char.Y == Bm.Y[0])
			{
				Sleep(1000);
				score = 0;
			}
			else
			{
				scr.Print(25, 25, "정상");
			}
		}                 //충돌
		else
		{
			score++;
		}
		////////////////////////////////////////////////

		if (Bm.X == 0) //x
		{
			Bm.X = 80;
		}
	}
	else if (RenderBlock == 1)
	{
		scr.Print(Bm.X, Bm.Y[1], "■");
		scr.Print(Bm.X, Bm.Y[0], "■");

		/////////////////////////////////////////
		if (Bm.X == 10)   //충돌
		{
			if (Char.Y == Bm.Y[0])
			{
				Sleep(1000);
				score = 0;
			}
			else if (Char.Y == Bm.Y[1])
			{
				Sleep(1000);
				score = 0;
			}
			else
			{
				scr.Print(25, 25, "정상");
			}
		}                 //충돌
		else
		{
			score++;
		}
		////////////////////////////////////////////////

		if (Bm.X == 0) // x
		{
			Bm.X = 80;
		}
	}
	else if (RenderBlock == 2)
	{
		scr.Print(Bm.X, Bm.Y[2], "■");
		scr.Print(Bm.X, Bm.Y[1], "■");
		scr.Print(Bm.X, Bm.Y[0], "■");

		/////////////////////////////////////////
		if (Bm.X == 10)   //충돌
		{
			if (Char.Y == Bm.Y[0])
			{
				Sleep(1000);
				score = 0;
			}
			else if (Char.Y == Bm.Y[1])
			{
				Sleep(1000);
				score = 0;
			}
			else if (Char.Y == Bm.Y[2])
			{
				Sleep(1000);
				score = 0;
			}
			else
			{
				scr.Print(25, 25, "정상");
			}
		}                 //충돌
		else
		{
			score++;
		}
		////////////////////////////////////////////////
		// 충돌처리 끝


		if (Bm.X == 0)
		{
			Bm.X = 80;
		}
	}

	scr.Flipping();
}

// 해제
void Gameframework::Release() {

}

int main(void) {
	scr.Init(); // 화면 초기화
	gfw.Init();
	while (true)
	{
		gfw.Update();

		if (_kbhit())
		{
			int nKey = _getch();
			switch (nKey)
			{
			//case 'a':
			//	Char.Left();
			//	break;
			//case 'd':
			//	Char.Right();
			//	break;
			case ' ':
				if (Char.Y == 20)
				{
					button = 1;
				}
				break;
			}
		}

		gfw.Render();
	}
	gfw.Release();
	scr.Release(); // 화면 해제
	return 0;
}