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

//ȭ�� ��� �Լ�
////
//	scr.Print(0, 0, "��������������������������������������������");
//	scr.Print(0, 1, "�� ��           ��			  ��           ��");
//	scr.Print(0, 2, "��                                        ��");
//	scr.Print(0, 3, "��                                        ��");
//	scr.Print(0, 4, "��                                        ��");
//	scr.Print(0, 5, "��                                        ��");
//	scr.Print(0, 6, "��                                        ��");
//	scr.Print(0, 7, "��                                        ��");
//	scr.Print(0, 8, "��                                        ��");
//	scr.Print(0, 9, "��	                                       ��");
//	scr.Print(0, 10, "��                                        ��");
//	scr.Print(0, 11, "��                                       ��");
//	scr.Print(0, 12, "��                                        ��");
//	scr.Print(0, 13, "��                                        ��");
//	scr.Print(0, 14, "��                                        ��");
//	scr.Print(0, 15, "��                  ��                    ��");
//	scr.Print(0, 16, "��                  ��                    ��");
//	scr.Print(0, 17, "��                  ��                    ��");
//	scr.Print(0, 18, "��     ����������������������������       ��");
//	scr.Print(0, 19, "��     ��        Space Bar       ��       ��");
//	scr.Print(0, 20, "��     ����������������������������       ��");
//	scr.Print(0, 21, "��     �����̽��ٸ� ������ ���ӽ��� !     ��");
//	scr.Print(0, 22, "��                                        ��");
//	scr.Print(0, 23, "��������������������������������������������");
//
//
//} �ϴٰ�����


// �ʱ�ȭ
void Gameframework::Init() {

}

// ����
void Gameframework::Update() {
	////////////////////����///////////////////////
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


		////////////////////����///////////////////////

		////////////////////��///////////////////////
		/*
		�����Լ��� ����ؼ� 1�̸� ��1�� 2�̸� ��2�� 3�̸� ��3�� ��ȯ
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


	////////////////////��///////////////////////




// ������
void Gameframework::Render() {
	scr.Clear();
	scr.Print(70, 4, "\\��/"); // �¾�
	scr.Print(69, 5, "���ݦ�"); // �¾�
	scr.Print(70, 6, "/��\\"); // �¾�
	scr.Print(35, 5, "��");
	scr.Print(45, 5, "��");
	scr.Print(55, 5, "��");
	scr.Print(3,14,"    �� _ ��\n");
	scr.Print(4, 15, "   ( ' ��')  �������� >.<b\n");
	scr.Print(5, 16   , "   (  * * )\n");
	scr.Print(6, 17, "   *    *   ");
	scr.Print(40, 15,"    ^  -- ^   \n");
	scr.Print(37, 16, "     (  !  . ! )  ȭ���� >.< \n ");
	scr.Print(34, 17, "         ( ��  �� )  \n");
	scr.Print(35, 18, "         *    * \n,");
	
	sprintf_s(string, "High Score : %d", highscore);
	scr.Print(5, 4, string);
	sprintf_s(string, "Score : %d", score);
	scr.Print(5, 5, string);
	if(Char.Y == 10){

		scr.Print(20,8,"�� �����");

	}

	scr.Print(Char.X, Char.Y-1, "��"); //�÷��̾�
	scr.Print(Char.X, Char.Y, "��");  //�÷��̾�
	scr.Print(0, 21, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"); // ��

	
	if (highscore >= score)
	{
		highscore = highscore;
	}
	else
	{
		highscore = score;
	}



	// ��°� �浹ó��
	if (RenderBlock == 0)
	{
		scr.Print(Bm.X, Bm.Y[0], "��");
		/////////////////////////////////////////
		if (Bm.X == 10)   //�浹
		{
			if (Char.Y == Bm.Y[0])
			{
				Sleep(1000);
				score = 0;
			}
			else
			{
				scr.Print(25, 25, "����");
			}
		}                 //�浹
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
		scr.Print(Bm.X, Bm.Y[1], "��");
		scr.Print(Bm.X, Bm.Y[0], "��");

		/////////////////////////////////////////
		if (Bm.X == 10)   //�浹
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
				scr.Print(25, 25, "����");
			}
		}                 //�浹
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
		scr.Print(Bm.X, Bm.Y[2], "��");
		scr.Print(Bm.X, Bm.Y[1], "��");
		scr.Print(Bm.X, Bm.Y[0], "��");

		/////////////////////////////////////////
		if (Bm.X == 10)   //�浹
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
				scr.Print(25, 25, "����");
			}
		}                 //�浹
		else
		{
			score++;
		}
		////////////////////////////////////////////////
		// �浹ó�� ��


		if (Bm.X == 0)
		{
			Bm.X = 80;
		}
	}

	scr.Flipping();
}

// ����
void Gameframework::Release() {

}

int main(void) {
	scr.Init(); // ȭ�� �ʱ�ȭ
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
	scr.Release(); // ȭ�� ����
	return 0;
}