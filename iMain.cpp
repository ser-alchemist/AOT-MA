/*
	*=================================================================
	* Title			:	Attack On Titan; Marley's Apocalypse
	* Author		:	Jerin Ahasan Kheya
	*					Mohammad Rafi
	*					**Our first project together**
	* Last Modified	:   Sep 24, 2020
	*=================================================================
*/


#include<iostream>
#include <string.h>
#include <sstream>
#include <cstring>
#include<fstream>
#include<cstdlib>
using namespace std;
#include "iGraphics.h"

#define screenWidth 1287
#define screenHight 700
#define JUMPLIMIT 150
#define BackGroundSpeed 13

int obstacleNumber = 0;

int pause_showFire;
int pause_showSpike;
int pause_showWood;
int pause_change;
int pause_tsChange;
int pause_bgChange;
int pause_eren1change;
int pause_eren1Jump;
int pause_fireChange;
bool isPause = false;
bool pauseIns = false;
bool gameover = false;
bool restart_level = false;

bool gameComp = false;
bool levelComp = false;


char eren1[8][60] = { "images\\1.bmp", "images\\2.bmp", "images\\3.bmp", "images\\4.bmp", "images\\5.bmp", "images\\6.bmp", "images\\7.bmp", "images\\8.bmp" };
char fire[6][40] = { "obstacles\\fire\\1.bmp", "obstacles\\fire\\2.bmp", "obstacles\\fire\\3.bmp", "obstacles\\fire\\4.bmp", "obstacles\\fire\\5.bmp", "obstacles\\fire\\6.bmp" };
char spike[6][60] = { "obstacles\\spike\\1.bmp", "obstacles\\spike\\2.bmp", "obstacles\\spike\\3.bmp", "obstacles\\spike\\4.bmp", "obstacles\\spike\\3.bmp", "obstacles\\spike\\2.bmp" };
char wood[6][60] = { "obstacles\\wood\\1.bmp", "obstacles\\wood\\2.bmp", "obstacles\\wood\\3.bmp", "obstacles\\wood\\4.bmp", "obstacles\\wood\\5.bmp", "obstacles\\wood\\5.bmp" };
char bTrap[5][40] = { "trap1.bmp", "trap2.bmp", "trap3.bmp", "trap4.bmp", "trap5.bmp" };
int bTrapX = 1100;
int bTrapX3 = 1100;
int bTrapX2 = 50;
int bTrapY = 0;
int bTrapIndex = 0;

int eren1Index = 0;
int fireIndex = 0;
int spikeIndex = 0;
int woodIndex = 0;

bool sFire = false;
bool sSpike = false;
bool sWood = false;

bool gFire = false;
bool gSpike = false;
bool gWood = false;

int fireX = 0;
int fireX2 = 10;
int dx = 10;
int dx2 = 5;
int dx3 = 5;
int dx4 = 5;
int spikeX = 200;
int woodX = 290;


char backGroundI[200][40] = { "background\\bg_1.bmp", "background\\bg_2.bmp", "background\\bg_3.bmp", "background\\bg_4.bmp", "background\\bg_5.bmp", "background\\bg_6.bmp", "background\\bg_7.bmp", "background\\bg_8.bmp", "background\\bg_9.bmp", "background\\bg_10.bmp", "background\\bg_11.bmp", "background\\bg_12.bmp", "background\\bg_13.bmp", "background\\bg_14.bmp", "background\\bg_15.bmp", "background\\bg_16.bmp", "background\\bg_17.bmp", "background\\bg_18.bmp", "background\\bg_19.bmp", "background\\bg_20.bmp", "background\\bg_21.bmp", "background\\bg_22.bmp", "background\\bg_23.bmp", "background\\bg_24.bmp", "background\\bg_25.bmp", "background\\bg_26.bmp", "background\\bg_27.bmp", "background\\bg_28.bmp", "background\\bg_29.bmp", "background\\bg_30.bmp", "background\\bg_31.bmp", "background\\bg_32.bmp", "background\\bg_33.bmp", "background\\bg_34.bmp", "background\\bg_35.bmp", "background\\bg_36.bmp", "background\\bg_37.bmp", "background\\bg_38.bmp", "background\\bg_39.bmp", "background\\bg_40.bmp", "background\\bg_41.bmp", "background\\bg_42.bmp", "background\\bg_43.bmp", "background\\bg_44.bmp", "background\\bg_45.bmp", "background\\bg_46.bmp", "background\\bg_47.bmp", "background\\bg_48.bmp", "background\\bg_49.bmp", "background\\bg_50.bmp", "background\\bg_51.bmp", "background\\bg_52.bmp", "background\\bg_53.bmp", "background\\bg_54.bmp", "background\\bg_55.bmp", "background\\bg_56.bmp", "background\\bg_57.bmp", "background\\bg_58.bmp", "background\\bg_59.bmp", "background\\bg_60.bmp", "background\\bg_61.bmp", "background\\bg_62.bmp", "background\\bg_63.bmp", "background\\bg_64.bmp", "background\\bg_65.bmp", "background\\bg_66.bmp", "background\\bg_67.bmp", "background\\bg_68.bmp", "background\\bg_69.bmp", "background\\bg_70.bmp", "background\\bg_71.bmp", "background\\bg_72.bmp", "background\\bg_73.bmp", "background\\bg_74.bmp", "background\\bg_75.bmp", "background\\bg_76.bmp", "background\\bg_77.bmp", "background\\bg_78.bmp", "background\\bg_79.bmp", "background\\bg_80.bmp", "background\\bg_81.bmp", "background\\bg_82.bmp", "background\\bg_83.bmp", "background\\bg_84.bmp", "background\\bg_85.bmp", "background\\bg_86.bmp", "background\\bg_87.bmp", "background\\bg_88.bmp", "background\\bg_89.bmp", "background\\bg_90.bmp", "background\\bg_91.bmp", "background\\bg_92.bmp", "background\\bg_93.bmp", "background\\bg_94.bmp", "background\\bg_95.bmp", "background\\bg_96.bmp", "background\\bg_97.bmp", "background\\bg_98.bmp", "background\\bg_99.bmp", "background\\bg_100.bmp", "background\\bg_101.bmp", "background\\bg_102.bmp", "background\\bg_103.bmp", "background\\bg_104.bmp", "background\\bg_105.bmp", "background\\bg_106.bmp", "background\\bg_107.bmp", "background\\bg_108.bmp", "background\\bg_109.bmp", "background\\bg_110.bmp", "background\\bg_111.bmp", "background\\bg_112.bmp", "background\\bg_113.bmp", "background\\bg_114.bmp", "background\\bg_115.bmp", "background\\bg_116.bmp", "background\\bg_117.bmp", "background\\bg_118.bmp", "background\\bg_119.bmp", "background\\bg_120.bmp", "background\\bg_121.bmp", "background\\bg_122.bmp", "background\\bg_123.bmp", "background\\bg_124.bmp", "background\\bg_125.bmp", "background\\bg_126.bmp", "background\\bg_127.bmp", "background\\bg_128.bmp", "background\\bg_129.bmp", "background\\bg_130.bmp", "background\\bg_131.bmp", "background\\bg_132.bmp", "background\\bg_133.bmp", "background\\bg_134.bmp", "background\\bg_135.bmp", "background\\bg_136.bmp", "background\\bg_137.bmp", "background\\bg_138.bmp", "background\\bg_139.bmp", "background\\bg_140.bmp", "background\\bg_141.bmp", "background\\bg_142.bmp", "background\\bg_143.bmp", "background\\bg_144.bmp", "background\\bg_145.bmp", "background\\bg_146.bmp", "background\\bg_147.bmp", "background\\bg_148.bmp", "background\\bg_149.bmp", "background\\bg_150.bmp", "background\\bg_151.bmp", "background\\bg_152.bmp", "background\\bg_153.bmp", "background\\bg_154.bmp", "background\\bg_155.bmp", "background\\bg_156.bmp", "background\\bg_157.bmp", "background\\bg_158.bmp", "background\\bg_159.bmp", "background\\bg_160.bmp", "background\\bg_161.bmp", "background\\bg_162.bmp", "background\\bg_163.bmp", "background\\bg_164.bmp", "background\\bg_165.bmp", "background\\bg_166.bmp", "background\\bg_167.bmp", "background\\bg_168.bmp", "background\\bg_169.bmp", "background\\bg_170.bmp", "background\\bg_171.bmp", "background\\bg_172.bmp", "background\\bg_173.bmp", "background\\bg_174.bmp", "background\\bg_175.bmp", "background\\bg_176.bmp", "background\\bg_177.bmp", "background\\bg_178.bmp", "background\\bg_179.bmp", "background\\bg_180.bmp", "background\\bg_181.bmp", "background\\bg_182.bmp", "background\\bg_183.bmp", "background\\bg_184.bmp", "background\\bg_185.bmp", "background\\bg_186.bmp", "background\\bg_187.bmp", "background\\bg_188.bmp", "background\\bg_189.bmp", "background\\bg_190.bmp", "background\\bg_191.bmp", "background\\bg_192.bmp", "background\\bg_193.bmp", "background\\bg_194.bmp", "background\\bg_195.bmp", "background\\bg_196.bmp", "background\\bg_197.bmp", "background\\bg_198.bmp", "background\\bg_199.bmp", "background\\bg_200.bmp" };
struct background{
	int x;
	int y;
};

background backGroundR[200];
struct buttonCordinate{
	int x;
	int y;
}bCordinate[4];

bool gExit = false;
bool gIns = false;
bool gScore = false;
bool gPlay = false;
bool gMusic = false;
bool gBack = false;
bool erenAttack = false;
bool titanBWalk = false;
bool gameBack = false;
bool titanDie = false;
bool titanDieL = false;

char eren[10][60] = { "1.bmp", "2.bmp", "3.bmp", "4.bmp", "5.bmp", "6.bmp", "7.bmp", "8.bmp", "9.bmp", "10.bmp" };
char titan[24][60] = { "t9.bmp", "t9.bmp", "t9.bmp", "t8.bmp", "t8.bmp", "t8.bmp", "t7.bmp", "t7.bmp", "t7.bmp", "t6.bmp", "t6.bmp", "t6.bmp", "t5.bmp", "t5.bmp", "t5.bmp", "t4.bmp", "t4.bmp", "t4.bmp", "t3.bmp", "t3.bmp", "t3.bmp", "t2.bmp", "t2.bmp", "t2.bmp" };
//char titanB[24][60] = { "tb2.bmp", "tb2.bmp", "tb2.bmp", "tb3.bmp", "tb3.bmp", "tb3.bmp", "tb4.bmp", "tb4.bmp", "tb4.bmp", "tb5.bmp", "tb5.bmp", "tb5.bmp", "tb6.bmp", "tb6.bmp", "tb6.bmp", "tb7.bmp", "tb7.bmp", "tb7.bmp", "tb8.bmp", "tb8.bmp", "tb8.bmp", "tb9.bmp", "tb9.bmp", "tb9.bmp", };
char titanB[24][60] = { "tb9.bmp", "tb9.bmp", "tb9.bmp", "tb8.bmp", "tb8.bmp", "tb8.bmp", "tb7.bmp", "tb7.bmp", "tb7.bmp", "tb6.bmp", "tb6.bmp", "tb6.bmp", "tb5.bmp", "tb5.bmp", "tb5.bmp", "tb4.bmp", "tb4.bmp", "tb4.bmp", "tb3.bmp", "tb3.bmp", "tb3.bmp", "tb2.bmp", "tb2.bmp", "tb2.bmp" };
char erenj[2][20] = { "jump1.bmp", "jump2.bmp" };
char erenbackj[2][20] = { "backj1.bmp", "backj2.bmp" };
char erenBack[10][60] = { "back1.bmp", "back2.bmp", "back3.bmp", "back4.bmp", "back5.bmp", "back6.bmp", "back7.bmp", "back8.bmp", "back9.bmp", "back10.bmp", };
char life[9][60] = { "life1.bmp", "life2.bmp", "life3.bmp", "life4.bmp", "life5.bmp", "life6.bmp", "life7.bmp", "life8.bmp", "life9.bmp" };
int lifeIndex = 0;

char TSR[10][60] = { "tSB.bmp", "tSR.bmp", "tSB.bmp", "tSR2.bmp", "tSB.bmp", "tSR.bmp", "tSB.bmp", "tSR2.bmp", "tSB.bmp", "tSR.bmp" };
char TSF[10][60] = { "tSB.bmp", "tSF.bmp", "tSB.bmp", "tSF2.bmp", "tSB.bmp", "tSF.bmp", "tSB.bmp", "tSF2.bmp", "tSB.bmp", "tSF.bmp" };
int tsrIndex = 0;
int tsfIndex = 0;



int erenCordinateX = 500;
int erenCordinateY = 0;
int erenIndex = 0;
int attackCounter = 0;
char erenStand[15] = "stand.bmp";
char erenBStand[15] = "backstand.bmp";
bool standPosition = true;
int standCounter = 0;
bool jump = false;
bool jumpUp = false;
bool jump1 = false;
bool jumpUp1 = false;
bool back = false;
bool titanWalk = true;
bool titanWalkL = true;
bool tFront = true;
bool tFrontL = true;

int erenCordinateJump = 0;

int titanX = screenWidth;
int titanY = 0;
int titanIndex = 0;

int titanXL = 0;
int titanYL = 0;

int titanNumber = 0;
int titanNumberL = 0;

bool front = true;
bool musicOn = true;

char button[4][60] = { "b1.bmp", "b2.bmp", "b3.bmp", "b4.bmp" };
char mainmenu[15] = "menu1.bmp";
//char play[15] = "";
char highscore[15] = "highscore1.bmp";
char ins[20] = "ins.bmp";

bool cut = false;
bool pressD = false;

int score = 0;
int score1 = 0;
int score2 = 0;
int score3 = 0;

int counter = 0;
int counterL = 0;
bool titanBlink = false;
int getTitanX;

bool titanBlinkL = false;
int getTitanXL;

bool lifeGuard = false;
int lifeGuardCounter = 0;




int gameState = -1;


void levelComplete()
{
	if (gameState == 7)
	{
		levelComp = true;
		iShowBMP2(350, 150, "pause_bck.bmp", 255);
		iShowBMP2(400, 300, "levelCom.bmp", 255);
		iPauseTimer(pause_showFire);
		iPauseTimer(pause_showSpike);
		iPauseTimer(pause_showWood);
		iPauseTimer(pause_change);
		iPauseTimer(pause_bgChange);
		iPauseTimer(pause_eren1change);
		iPauseTimer(pause_eren1Jump);
		iShowBMP2(550, 180, "next.bmp", 255);
	}

	else if (gameState == 0)
	{
		levelComp = true;
		iShowBMP2(350, 150, "pause_bck.bmp", 255);
		iShowBMP2(400, 300, "levelCom.bmp", 255);

		iPauseTimer(pause_showFire);
		iPauseTimer(pause_change);
		iPauseTimer(pause_tsChange);
		iPauseTimer(pause_fireChange);

		iShowBMP2(550, 180, "next.bmp", 255);
	}

}

void readScore()
{
	string myText;
	ifstream MyReadFile("score.txt");


	while (getline(MyReadFile, myText))
	{

		char* score_char1 = (char*)myText.c_str();
		iSetColor(250, 40, 96);

		iText(450, 600, "High score: ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(600, 600, score_char1, GLUT_BITMAP_TIMES_ROMAN_24);
	}

	MyReadFile.close();

}

void writeScore()
{
	int num = 0;
	string myText;
	ifstream MyReadFile("score.txt");
	while (getline(MyReadFile, myText))
	{
		num = stoi(myText);
		cout << num;
	}
	MyReadFile.close();


	if (score > num)
	{
		ofstream MyFile("score.txt");
		MyFile << score;
		MyFile.close();

	}



}

void gameComplete()
{
	gameComp = true;
	iShowBMP2(350, 150, "pause_bck.bmp", 255);
	iShowBMP2(500, 250, "win.bmp", 255);
	iPauseTimer(pause_change);
	iPauseTimer(pause_tsChange);
	iPauseTimer(pause_fireChange);
	iShowBMP2(550, 180, "exit2.bmp", 255);

}

void gameOver()
{


	if (gameState == 7)
	{
		if (lifeIndex >= 8)
		{
			gameover = true;
			lifeIndex = 8;
			iShowBMP2(50, 630, life[8], 255);
			iShowBMP2(350, 150, "pause_bck.bmp", 255);
			iShowBMP2(480, 320, "dead.bmp", 255);

			iPauseTimer(pause_showFire);
			iPauseTimer(pause_showSpike);
			iPauseTimer(pause_showWood);
			iPauseTimer(pause_change);
			iPauseTimer(pause_bgChange);
			iPauseTimer(pause_eren1change);
			iPauseTimer(pause_eren1Jump);

			iShowBMP2(550, 260, "restart_level.bmp", 255);
			iShowBMP2(550, 180, "exit2.bmp", 255);


			if (restart_level)
			{
				gameover = false;
				iResumeTimer(pause_showFire);
				iResumeTimer(pause_showSpike);
				iResumeTimer(pause_showWood);
				iResumeTimer(pause_change);
				iResumeTimer(pause_bgChange);
				iResumeTimer(pause_eren1change);
				iResumeTimer(pause_eren1Jump);

				lifeIndex = 0;
				score = 0;
				score1 = 0;
				score2 = 0;
				score3 = 0;

				fireX = 1300 + 0;
				spikeX = 1300 + 200;
				woodX = 1300 + 450;

				gameState = 7;
				restart_level = false;

			}
		}
	}

	if (gameState == 0)
	{
		if (lifeIndex >= 8)
		{
			gameover = true;
			lifeIndex = 8;
			iShowBMP2(50, 630, life[8], 255);
			iShowBMP2(350, 150, "pause_bck.bmp", 255);
			iShowBMP2(480, 320, "dead.bmp", 255);

			iPauseTimer(pause_showFire);
			iPauseTimer(pause_change);
			iPauseTimer(pause_tsChange);
			iPauseTimer(pause_fireChange);



			iShowBMP2(550, 260, "restart_level.bmp", 255);
			iShowBMP2(550, 180, "exit2.bmp", 255);


			if (restart_level)
			{
				gameover = false;

				iResumeTimer(pause_showFire);
				iResumeTimer(pause_change);
				iResumeTimer(pause_tsChange);
				iResumeTimer(pause_fireChange);


				lifeIndex = 0;

				score2 = 0;
				score3 = 0;

				erenCordinateX = 500;
				fireX2 = 15;
				bTrapX = 1100;
				titanX = 1300;
				titanNumber = 0;

				gameState = 0;
				restart_level = false;

			}
		}
	}

	if (gameState == 5)
	{
		if (lifeIndex >= 8)
		{
			gameover = true;
			lifeIndex = 8;
			iShowBMP2(50, 630, life[8], 255);
			iShowBMP2(350, 150, "pause_bck.bmp", 255);
			iShowBMP2(480, 320, "dead.bmp", 255);


			iPauseTimer(pause_change);
			iPauseTimer(pause_tsChange);
			iPauseTimer(pause_fireChange);



			iShowBMP2(550, 260, "restart_level.bmp", 255);
			iShowBMP2(550, 180, "exit2.bmp", 255);



			if (restart_level)
			{
				gameover = false;

				iResumeTimer(pause_showFire);
				iResumeTimer(pause_change);
				iResumeTimer(pause_tsChange);
				iResumeTimer(pause_fireChange);


				lifeIndex = 0;
				score3 = 0;

				erenCordinateX = 500;
				titanNumber = 0;
				titanNumberL = 0;
				titanXL = 0;
				titanX = 1300;

				gameState = 5;
				restart_level = false;

			}
		}
	}
}

void obsCollision()
{
	if (!gameover && !levelComp)
	{
		if (!lifeGuard)
		{
			if (((fireX < 320 && fireX > 300) && (erenCordinateY + erenCordinateJump < 50)) || ((spikeX < 330 && spikeX > 300) && (erenCordinateY + erenCordinateJump < 60)) || ((woodX < 330 && woodX > 300) && (erenCordinateY + erenCordinateJump < 60)))
			{
				cout << woodX << " ";
				lifeIndex++;
				lifeGuard = true;
			}
		}


		if (((fireX < 330 && fireX > 300) && (erenCordinateY + erenCordinateJump > 50)) || ((spikeX < 330 && spikeX > 300) && (erenCordinateY + erenCordinateJump > 60)) || ((woodX < 330 && woodX > 300) && (erenCordinateY + erenCordinateJump > 60)))
		{
			score1 += 5;
		}
	}

}

void obsMovement()
{

	if (sFire)
	{
		iShowBMP2(fireX, 0, fire[fireIndex], 255);
	}

	if (sSpike)
	{
		iShowBMP2(spikeX, 0, spike[spikeIndex], 0);
	}

	if (sWood)
	{
		iShowBMP2(woodX, 0, wood[woodIndex], 0);
	}

}

void obsMovementLevel2()
{

	iShowBMP2(fireX2, JUMPLIMIT, fire[fireIndex], 255);

	iShowBMP2(bTrapX, 0, bTrap[bTrapIndex], 0);

}

void obsMovementLevel3()
{

	iShowBMP2(bTrapX2, 0, bTrap[bTrapIndex], 0);
	iShowBMP2(bTrapX3, 0, bTrap[bTrapIndex], 0);


}

void enemyCollision()
{
	if (!gameover)
	{
		if ((erenCordinateX - titanX >= -10 && erenCordinateX - titanX <= 10) && jump && (((erenCordinateY + erenCordinateJump) >= 70) && ((erenCordinateY + erenCordinateJump) <= 100)))
		{
			titanWalk = false;
			titanDie = true;
			titanBlink = true;
			getTitanX = titanX;

			if (gameState == 0)
			{
				score2 += 500;
			}
			else if (gameState == 5)
			{
				score3 += 500;
			}
		}
	}


}

void enemyCollisionL()
{
	if (!gameover)
	{
		if ((erenCordinateX - titanXL <= 10 && erenCordinateX - titanXL >= -10) && jump && (((erenCordinateY + erenCordinateJump) >= 70) && ((erenCordinateY + erenCordinateJump) <= 100)))
		{
			titanWalkL = false;
			titanDieL = true;
			titanBlinkL = true;
			getTitanXL = titanXL;
			score3 += 500;
		}
	}

}

void titanFollow()
{
	if (erenCordinateX - titanX <= -100)
	{
		tFront = true;
	}
	else if (erenCordinateX - titanX >= 100)
	{
		tFront = false;
	}

}

void titanFollowL()
{
	if (erenCordinateX - titanXL >= 100)
	{
		tFrontL = true;
	}
	else if (erenCordinateX - titanXL <= -100)
	{
		tFrontL = false;
	}

}

void lifeCall()
{
	if (!gameover)
	{
		if (gameState == 5)
		{
			if (!lifeGuard)
			{
				if (jump)
				{
					if ((erenCordinateX - titanX <= 2 && erenCordinateX - titanX >= -2) && (((erenCordinateY + erenCordinateJump) >= 0) && ((erenCordinateY + erenCordinateJump) <= 60)))
					{

						lifeIndex++;
						lifeGuard = true;
					}
					else if ((erenCordinateX - titanXL <= 2 && erenCordinateX - titanXL >= -2) && (((erenCordinateY + erenCordinateJump) >= 0) && ((erenCordinateY + erenCordinateJump) <= 60)))
					{

						lifeIndex++;
						lifeGuard = true;
					}

				}

				else if (standPosition)
				{
					if (erenCordinateX - titanX <= 0 && erenCordinateX - titanX >= 0)
					{
						lifeIndex++;
						lifeGuard = true;
					}
					else if (erenCordinateX - titanXL <= 0 && erenCordinateX - titanXL >= 0)
					{

						lifeIndex++;
						lifeGuard = true;
					}
				}
				else
				{
					if ((erenCordinateX - bTrapX2 <= 2 && erenCordinateX - bTrapX2 >= -2))
					{
						lifeIndex++;
						lifeGuard = true;
					}

					if ((erenCordinateX - bTrapX3 <= 2 && erenCordinateX - bTrapX3 >= -2))
					{
						lifeIndex++;
						lifeGuard = true;
					}

					if (erenCordinateX - titanX <= 5 && erenCordinateX - titanX >= -5)
					{
						lifeIndex++;
						lifeGuard = true;
					}
					else if (erenCordinateX - titanXL <= 5 && erenCordinateX - titanXL >= -5)
					{
						lifeIndex++;
						lifeGuard = true;
					}
				}

			}


			iShowBMP2(50, 630, life[lifeIndex], 255);
		}

		else if (gameState == 0)
		{
			if (!lifeGuard && !levelComp && !gameover)
			{
				if (jump)
				{
					if (((erenCordinateX - fireX2 <= 5 && erenCordinateX - fireX2 >= -5) && (erenCordinateY + erenCordinateJump >= 130) && (erenCordinateY + erenCordinateJump <= 150)))
					{
						lifeIndex++;
						lifeGuard = true;
					}
					if ((erenCordinateX - titanX <= 2 && erenCordinateX - titanX >= -2) && (((erenCordinateY + erenCordinateJump) >= 0) && ((erenCordinateY + erenCordinateJump) <= 60)))
					{

						lifeIndex++;
						lifeGuard = true;
					}


				}

				else if (standPosition)
				{
					if ((erenCordinateX - titanX <= 0 && erenCordinateX - titanX >= 0) || (erenCordinateX - bTrapX <= 2 && erenCordinateX - bTrapX >= -2))
					{
						lifeIndex++;
						lifeGuard = true;
					}

				}

				else
				{
					if ((erenCordinateX - titanX <= 5 && erenCordinateX - titanX >= -5) || (erenCordinateX - bTrapX <= 2 && erenCordinateX - bTrapX >= -2))
					{
						lifeIndex++;
						lifeGuard = true;
					}

				}

			}


			iShowBMP2(50, 630, life[lifeIndex], 255);
		}

		if (gameState == 7)
		{

			iShowBMP2(50, 630, life[lifeIndex], 255);

		}
	}


}

void showScore()
{
	score = score1 + score2 + score3;


	string str = to_string(score);
	char* score_char = (char*)str.c_str();


	if (gameState == 7)
	{
		iSetColor(228, 218, 245);
	}


	else if (gameState == 0 || gameState == 5)
	{
		iSetColor(65, 46, 97);
	}


	iText(1000, 650, "Score : ", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1100, 650, score_char, GLUT_BITMAP_TIMES_ROMAN_24);


}

void level3()
{
	//titanNumber = 0;
	enemyCollision();
	enemyCollisionL();
	titanFollow();
	titanFollowL();
	iShowBMP(0, 0, "background3.2.bmp");
	iShowBMP2(1230, 640, "gameback.bmp", 255);
	obsMovementLevel3();
	lifeCall();
	showScore();


	if (titanBlink)
	{
		counter++;
		iShowBMP2(getTitanX, titanY, TSR[tsrIndex], 255);

		if (counter >= 40)
		{
			counter = 0;
			titanBlink = false;
		}
	}


	if (titanDie)
	{

		titanX = screenWidth;
		titanY = 0;
		iShowBMP2(titanX, titanY, titan[titanIndex], 255);
		titanWalk = true;
		titanDie = false;
		titanNumber++;

	}

	if (titanWalk && tFront)
	{
		iShowBMP2(titanX, titanY, titan[titanIndex], 255);
	}
	else if (titanWalk && !tFront)
	{
		iShowBMP2(titanX, titanY, titanB[titanIndex], 255);
	}




	if (titanWalkL && tFrontL)
	{
		iShowBMP2(titanXL, titanYL, titanB[titanIndex], 255);
	}
	else if (titanWalkL && !tFrontL)
	{
		iShowBMP2(titanXL, titanYL, titan[titanIndex], 255);
	}

	if (titanBlinkL)
	{
		counterL++;
		iShowBMP2(getTitanXL, titanY, TSR[tsrIndex], 255);

		if (counterL >= 40)
		{
			counterL = 0;
			titanBlinkL = false;
		}
	}

	if (titanDieL)
	{
		titanXL = 0;
		titanYL = 0;
		iShowBMP2(titanXL, titanYL, titanB[titanIndex], 255);
		titanWalkL = true;
		titanDieL = false;
		titanNumberL++;

	}
	if (titanNumber >= 6 && titanNumberL >= 5)  {

		gameComplete();


	}


	if (lifeIndex >= 8)
	{
		gameOver();
	}


	if (jump)
	{
		if (jumpUp)
		{
			if (!front)
			{

				iShowBMP2(erenCordinateX, erenCordinateY + erenCordinateJump, erenbackj[0], 255);

			}


			else
			{
				iShowBMP2(erenCordinateX, erenCordinateY + erenCordinateJump, erenj[0], 255);

			}
		}
		else
		{
			if (!front)
			{
				iShowBMP2(erenCordinateX, erenCordinateY + erenCordinateJump, erenbackj[1], 255);
			}
			else
			{
				iShowBMP2(erenCordinateX, erenCordinateY + erenCordinateJump, erenj[1], 255);
			}
		}
	}


	else
	{
		if (!standPosition)
		{
			if (!front)
			{
				iShowBMP2(erenCordinateX, erenCordinateY, erenBack[erenIndex], 255);
			}
			else
			{
				iShowBMP2(erenCordinateX, erenCordinateY, eren[erenIndex], 255);
			}

			standCounter++;

			if (standCounter >= 50)
			{
				standCounter = 0;
				erenIndex = 0;
				standPosition = true;
				pressD = false;
			}

		}


		else
		{
			if (!front)
			{
				iShowBMP2(erenCordinateX, erenCordinateY, erenBStand, 255);
			}
			else
			{
				iShowBMP2(erenCordinateX, erenCordinateY, erenStand, 255);
			}
		}

	}
}

void lifeGuardFunc()
{
	if (gameState == 7)
	{
		if (lifeGuard)
		{
			lifeGuardCounter++;

			if (lifeGuardCounter >= 25)
			{
				lifeGuard = false;
				lifeGuardCounter = 0;
			}
		}

	}

	else if (gameState == 0 || gameState == 5)
	{
		if (lifeGuard)
		{
			lifeGuardCounter++;

			if (lifeGuardCounter >= 25)
			{
				lifeGuard = false;
				lifeGuardCounter = 0;
			}
		}
	}


}

void menu()
{


	iShowBMP(0, 0, mainmenu);

	lifeIndex = 0;
	score = 0;
	score1 = 0;
	score2 = 0;
	score3 = 0;
	fireX = 0;
	spikeX = 200;
	woodX = 290;
	erenCordinateX = 500;
	fireX2 = 10;
	bTrapX = 1100;
	titanX = 1300;
	titanNumber = 0;
	titanNumberL = 0;
	titanXL = 0;
	obstacleNumber = 0;


	if (musicOn && !gMusic)
	{
		iShowBMP2(50, 0, "b5.bmp", 0);
	}

	else if (musicOn && gMusic)
	{
		iShowBMP2(50, 0, "gmb1.bmp", 0);
	}

	else if (!musicOn&&gMusic)
	{
		iShowBMP2(50, 0, "gmb2.bmp", 0);
	}

	else if (!musicOn&&!gMusic)
	{
		iShowBMP2(50, 0, "b6.bmp", 0);
	}


	for (int i = 0; i <= 3; i++)
	{
		iShowBMP2(bCordinate[i].x, bCordinate[i].y, button[i], 0);
	}
	//iShowBMP2(50, 0, "b5.bmp", 0);

	if (gExit)
	{
		iShowBMP2(50, 300, "gb4.bmp", 0);

	}

	else if (gIns)
	{
		iShowBMP2(50, 380, "gb3.bmp", 0);
	}

	else if (gScore)
	{
		iShowBMP2(50, 460, "gb2.bmp", 0);
	}

	else if (gPlay)
	{
		iShowBMP2(50, 540, "gb1.bmp", 0);
	}


}

void level2()
{

	enemyCollision();
	titanFollow();

	iShowBMP(0, 0, "disk2.bmp");
	iShowBMP2(1230, 640, "gameback.bmp", 255);
	obsMovementLevel2();
	lifeCall();
	showScore();


	if (titanBlink)
	{
		counter++;

		iShowBMP2(getTitanX, titanY, TSR[tsrIndex], 255);

		if (counter >= 40)
		{
			counter = 0;
			titanBlink = false;
		}
	}


	if (titanWalk && tFront)
	{
		iShowBMP2(titanX, titanY, titan[titanIndex], 255);
	}
	else if (titanWalk && !tFront)
	{
		iShowBMP2(titanX, titanY, titanB[titanIndex], 255);
	}

	if (titanDie)
	{

		titanX = screenWidth;
		titanY = 0;
		iShowBMP2(titanX, titanY, titan[titanIndex], 255);
		titanWalk = true;
		titanDie = false;
		titanNumber++;
	}

	if (titanNumber >= 8)
	{

		titanBlink = false;
		levelComplete();

		lifeIndex = 0;


		titanX = screenWidth;
		titanXL = 0;
		erenCordinateX = 500;

	}
	if (jump)
	{
		if (jumpUp)
		{
			if (!front)
			{

				iShowBMP2(erenCordinateX, erenCordinateY + erenCordinateJump, erenbackj[0], 255);


			}


			else
			{
				iShowBMP2(erenCordinateX, erenCordinateY + erenCordinateJump, erenj[0], 255);

			}
		}
		else
		{
			if (!front)
			{
				iShowBMP2(erenCordinateX, erenCordinateY + erenCordinateJump, erenbackj[1], 255);
			}
			else
			{
				iShowBMP2(erenCordinateX, erenCordinateY + erenCordinateJump, erenj[1], 255);
			}
		}
	}


	else
	{
		if (!standPosition)
		{
			if (!front)
			{
				iShowBMP2(erenCordinateX, erenCordinateY, erenBack[erenIndex], 255);
			}
			else
			{
				iShowBMP2(erenCordinateX, erenCordinateY, eren[erenIndex], 255);
			}

			standCounter++;

			if (standCounter >= 50)
			{
				standCounter = 0;
				erenIndex = 0;
				standPosition = true;
				pressD = false;
			}

		}


		else
		{
			if (!front)
			{
				iShowBMP2(erenCordinateX, erenCordinateY, erenBStand, 255);
			}
			else
			{
				iShowBMP2(erenCordinateX, erenCordinateY, erenStand, 255);
			}
		}

	}

	if (lifeIndex >= 8)
	{
		gameOver();
	}
	/*
	if (gameBack)
	{
	gameState = -1;
	//gameStop = true;
	}
	*/



}

void level1()
{


	for (int i = 0; i < 200; i++)
	{
		iShowBMP(backGroundR[i].x, backGroundR[i].y, backGroundI[i]);
	}

	iShowBMP2(1230, 640, "gameback.bmp", 255);
	lifeCall();
	showScore();
	obsCollision();
	obsMovement();

	if (!jump1)
	{
		iShowBMP2(300, 0, eren1[eren1Index], 255);
	}

	else if (jump1)
	{
		if (jumpUp1)
		{

			iShowBMP2(300, erenCordinateY + erenCordinateJump, "eren1jumpUp100.bmp", 255);

		}
		else
		{

			iShowBMP2(300, erenCordinateY + erenCordinateJump, "eren1jumpDown130.bmp", 255);

		}
	}

	if (lifeIndex >= 8)
	{
		gameOver();
	}


	if (obstacleNumber >= 15)
	{
		levelComplete();


	}
}

void pauseMenu()
{
	if (isPause)
	{
		iSetColor(137, 120, 120);
		iShowBMP2(350, 150, "pause_bck.bmp", 255);
		iSetColor(0, 0, 0);
		iText(570, 500, "PAUSE MENU", GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(460, 390, "resume.bmp", 255);
		iShowBMP2(460, 290, "instructions.bmp", 255);
		iShowBMP2(460, 190, "exit.bmp", 255);

		if (pauseIns)
		{
			iShowBMP2(350, 150, "ins_pause.bmp", 255);
			iText(530, 500, "---INSTRUCTIONS---", GLUT_BITMAP_TIMES_ROMAN_24);
			iSetColor(227, 218, 242);
			iText(400, 450, "Controls:", GLUT_BITMAP_HELVETICA_18);
			iText(400, 410, "w : Jump", GLUT_BITMAP_HELVETICA_18);
			iText(400, 370, "a : Move Left (works only level 2 & 3)", GLUT_BITMAP_HELVETICA_18);
			iText(400, 330, "d : Move Right (works only level 2 & 3)", GLUT_BITMAP_HELVETICA_18);
			iShowBMP2(826, 160, "backT.bmp", 255);
		}
	}
}




void iDraw()
{
	iClear();

	lifeGuardFunc();

	if (gameState == -1)
	{
		menu();
		//mainMenu();
	}


	if (gameState == 0)
	{
		level2();

	}



	if (gameState == 1)
	{
		iShowBMP(0, 0, highscore);

		readScore();

		if (back)
		{
			iShowBMP2(1000, 5, "back.bmp", 255);
		}

		if (gBack)
		{
			iShowBMP2(990, 0, "backb.bmp", 255);
		}

	}

	else if (gameState == 2)
	{
		iShowBMP(0, 0, ins);
		iSetColor(227, 218, 242);
		iText(80, 600, "Controls:", GLUT_BITMAP_HELVETICA_18);
		iText(80, 560, "w : Jump", GLUT_BITMAP_HELVETICA_18);
		iText(80, 510, "a : Move Left (works only level 2 & 3)", GLUT_BITMAP_HELVETICA_18);
		iText(80, 470, "d : Move Right (works only level 2 & 3)", GLUT_BITMAP_HELVETICA_18);
		iText(80, 410, "Instructions for level 1:", GLUT_BITMAP_HELVETICA_18);
		iText(80, 370, "Jump and avoid obstacles for score. Score vary on jump accuracy.", GLUT_BITMAP_HELVETICA_18);
		iText(80, 330, "Instructions for level 2:", GLUT_BITMAP_HELVETICA_18);
		iText(80, 290, "Jump and move to kill titan. Be aware of of fire and bear trap.", GLUT_BITMAP_HELVETICA_18);
		iText(80, 240, "Instructions for level 3:", GLUT_BITMAP_HELVETICA_18);
		iText(80, 200, "You have to kill titans generated from both left and right side of screen to complete the level.", GLUT_BITMAP_HELVETICA_18);
		iText(80, 180, "Killing the same titan won't complete the level but is a good chance to increase scores.", GLUT_BITMAP_HELVETICA_18);
		if (back)
		{
			iShowBMP2(1000, 5, "back.bmp", 255);
		}

		if (gBack)
		{
			iShowBMP2(990, 0, "backb.bmp", 255);
		}

	}

	else if (gameState == 5)
	{

		level3();

	}

	else if (gameState == 7)
	{

		level1();

	}


	if (isPause && !gameover)
	{
		pauseMenu();
	}

}

/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/

void iMouseMove(int mx, int my)
{

}

void iPassiveMouseMove(int mx, int my)
{
	if (gameState == -1)
	{

		if (mx >= 50 && mx <= 313 && my >= 300 && my <= 394)
		{
			gExit = true;

		}
		else
		{
			gExit = false;

		}

		if (mx >= 50 && mx <= 313 && my >= 380 && my <= 474)
		{
			gIns = true;
			//iShowBMP2(50, 474, "gb4.bmp", 0);
		}
		else
		{
			gIns = false;
		}

		if (mx >= 50 && mx <= 313 && my >= 460 && my <= 554)
		{
			gScore = true;
			//iShowBMP2(50, 474, "gb4.bmp", 0);
		}
		else
		{
			gScore = false;
		}

		if (mx >= 50 && mx <= 313 && my >= 540 && my <= 634)
		{
			gPlay = true;
			//iShowBMP2(50, 474, "gb4.bmp", 0);
		}
		else
		{
			gPlay = false;
		}

		if (mx >= 151 && mx <= 245 && my >= 31 && my <= 74)
		{
			gMusic = true;
		}
		else
		{
			gMusic = false;
		}

	}

	if (gameState == 1 || gameState == 2)
	{
		if (mx >= 1000 && mx <= 1250 && my >= 0 && my <= 80)
		{
			gBack = true;
		}
		else
		{
			gBack = false;
		}
	}

}

void iMouse(int button, int state, int mx, int my)
{


	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		cout << "X: " << mx << ", Y: " << my << "\n";

		if (levelComp && gameState == 7)
		{
			if (mx >= 550 && mx <= 740 && my >= 180 && my <= 230)
			{
				writeScore();
				gameState = 0;
				levelComp = false;
				iResumeTimer(pause_showFire);
				iResumeTimer(pause_showSpike);
				iResumeTimer(pause_showWood);
				iResumeTimer(pause_change);
				iResumeTimer(pause_tsChange);
				iResumeTimer(pause_bgChange);
				iResumeTimer(pause_eren1change);
				iResumeTimer(pause_eren1Jump);
				iResumeTimer(pause_fireChange);

			}
		}

		if (levelComp && gameState == 0)
		{
			if (mx >= 550 && mx <= 740 && my >= 180 && my <= 230)
			{
				writeScore();
				gameState = 5;
				levelComp = false;
				iResumeTimer(pause_showFire);
				iResumeTimer(pause_showSpike);
				iResumeTimer(pause_showWood);
				iResumeTimer(pause_change);
				iResumeTimer(pause_tsChange);
				iResumeTimer(pause_bgChange);
				iResumeTimer(pause_eren1change);
				iResumeTimer(pause_eren1Jump);
				iResumeTimer(pause_fireChange);

			}
		}

		if (gameComp)
		{
			if (mx >= 550 && mx <= 740 && my >= 180 && my <= 230)
			{
				writeScore();
				gameState = -1;
				gameComp = false;
				iResumeTimer(pause_showFire);
				iResumeTimer(pause_showSpike);
				iResumeTimer(pause_showWood);
				iResumeTimer(pause_change);
				iResumeTimer(pause_tsChange);
				iResumeTimer(pause_bgChange);
				iResumeTimer(pause_eren1change);
				iResumeTimer(pause_eren1Jump);
				iResumeTimer(pause_fireChange);

			}
		}

		if (gameover)
		{
			if (mx >= 550 && mx <= 740 && my >= 260 && my <= 310)
			{
				writeScore();
				restart_level = true;
			}

			if (mx >= 550 && mx <= 740 && my >= 180 && my <= 230)
			{
				writeScore();
				gameState = -1;
				gameover = false;
				iResumeTimer(pause_showFire);
				iResumeTimer(pause_showSpike);
				iResumeTimer(pause_showWood);
				iResumeTimer(pause_change);
				iResumeTimer(pause_tsChange);
				iResumeTimer(pause_bgChange);
				iResumeTimer(pause_eren1change);
				iResumeTimer(pause_eren1Jump);
				iResumeTimer(pause_fireChange);


				//mainMenu();

			}
		}

		if (isPause)
		{
			if (mx >= 450 && mx <= 720 && my >= 385 && my <= 455)
			{
				isPause = false;
				iResumeTimer(pause_showFire);
				iResumeTimer(pause_showSpike);
				iResumeTimer(pause_showWood);
				iResumeTimer(pause_change);
				iResumeTimer(pause_tsChange);
				iResumeTimer(pause_bgChange);
				iResumeTimer(pause_eren1change);
				iResumeTimer(pause_eren1Jump);
				iResumeTimer(pause_fireChange);
			}

			if (mx >= 450 && mx <= 720 && my >= 285 && my <= 355)
			{
				pauseIns = true;
			}
			if (mx >= 450 && mx <= 720 && my >= 185 && my <= 255)
			{
				isPause = false;
				gameState = -1;
				iResumeTimer(pause_showFire);
				iResumeTimer(pause_showSpike);
				iResumeTimer(pause_showWood);
				iResumeTimer(pause_change);
				iResumeTimer(pause_tsChange);
				iResumeTimer(pause_bgChange);
				iResumeTimer(pause_eren1change);
				iResumeTimer(pause_eren1Jump);
				iResumeTimer(pause_fireChange);
			}

			if (pauseIns)
			{
				if (mx >= 820 && mx <= 940 && my >= 155 && my <= 195)
				{
					pauseIns = false;
				}
			}
		}


		if (gameState == -1)
		{

			for (int i = 0; i <= 3; i++)
			{
				if (mx >= bCordinate[i].x && mx <= bCordinate[i].x + 260 && my >= bCordinate[i].y && my <= bCordinate[i].y + 90)
				{
					if (i == 0)
					{
						gameState = 7;
					}

					else
					{
						gameState = i;
					}

					if (gameState == 1 || gameState == 2)
					{
						back = true;
					}

					if (gameState == 3)
					{
						exit(0);
					}
				}
			}



			if (mx >= 151 && mx <= 245 && my >= 31 && my <= 74)
			{
				if (musicOn)
				{
					musicOn = false;
					PlaySound(0, 0, 0);
				}
				else
				{
					musicOn = true;
					PlaySound("bck2.wav", NULL, SND_LOOP | SND_ASYNC);
				}

			}
		}
		if (gameState == 1 || gameState == 2)

		{
			if (mx >= 1000 && mx <= 1300 && my >= 0 && my <= 200)
			{

				gameState = -1;
			}

		}

		if (gameState == 0 || gameState == 5 || gameState == 7)
		{
			if (mx >= 1250 && mx <= 1300 && my >= 650 && my <= 700)
			{
				//gameBack = true;

				if (!isPause)
				{
					iPauseTimer(pause_showFire);
					iPauseTimer(pause_showSpike);
					iPauseTimer(pause_showWood);
					iPauseTimer(pause_change);
					iPauseTimer(pause_tsChange);
					iPauseTimer(pause_bgChange);
					iPauseTimer(pause_eren1change);
					iPauseTimer(pause_eren1Jump);
					iPauseTimer(pause_fireChange);
					isPause = true;
				}

				/*
				//gameState = -1;
				lifeIndex = 0;
				score = 0;
				titanX = screenWidth;
				erenCordinateX = 500;
				*/
			}

			else
			{
				gameBack = false;
			}
		}

	}


	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/

void iKeyboard(unsigned char key)
{


	if ((gameState == 0 || gameState == 5) && !gameover &&!gameComp && !levelComp)
	{
		if (key == 'w')
		{
			if (!jump)
			{
				jump = true;
				jumpUp = true;

			}
		}

		if (key == 'd')
		{
			front = true;
			if (erenCordinateX <= 1170)
			{
				erenCordinateX += 10;
			}

			erenIndex++;
			if (erenIndex >= 9)
			{
				erenIndex = 0;
			}
			standPosition = false;
			pressD = true;
		}

		else if (key == 'a')
		{
			front = false;

			if (erenCordinateX >= 10)
			{
				erenCordinateX -= 10;
			}

			erenIndex--;
			if (erenIndex < 0)
			{
				erenIndex = 9;
			}
			standPosition = false;
			pressD = true;
		}

	}

	else if (gameState == 7)
	{
		if (key == 'w')
		{
			if (!jump1)
			{
				jump1 = true;
				jumpUp1 = true;

			}
		}
	}

	if (key == 'm')
	{
		if (musicOn)
		{
			musicOn = false;
			PlaySound(0, 0, 0);
		}
		else
		{
			musicOn = true;
			PlaySound("bck2.wav", NULL, SND_LOOP | SND_ASYNC);
		}
	}


}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/

void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{

	}

	if (key == GLUT_KEY_RIGHT)
	{

	}

	else if (key == GLUT_KEY_LEFT)
	{

	}
	else if (key == GLUT_KEY_END)
	{
		gameState = -1;
	}

}

void backGroundSet()
{
	int sum = 0;
	for (int i = 0; i < 200; i++)
	{
		backGroundR[i].y = 0;
		backGroundR[i].x = sum;
		sum += BackGroundSpeed;
	}
}

void eren1change()
{
	eren1Index++;
	if (eren1Index >= 7)
	{
		eren1Index = 0;
	}

}

void change()
{
	if (jump)
	{
		if (jumpUp)
		{

			erenCordinateJump += 5;
			if (erenCordinateJump >= JUMPLIMIT)
			{
				jumpUp = false;
			}
		}
		else
		{
			erenCordinateJump -= 5;
			if (erenCordinateJump < 0)
			{
				jump = false;
				erenCordinateJump = 0;
			}
		}
	}

	if (gameState == 0)
	{

		if (titanWalk)
		{
			if (tFront)
			{
				titanX -= 1;
			}

			else if (!tFront)
			{
				titanX += 1;
			}


			titanIndex++;

			if (titanIndex >= 24)
			{
				titanIndex = 0;
			}
		}
	}

	if (gameState == 5)
	{
		if (titanWalk)
		{
			if (tFront)
			{
				titanX -= 1;
			}

			else if (!tFront)
			{
				titanX += 1;
			}


			titanIndex++;

			if (titanIndex >= 24)
			{
				titanIndex = 0;
			}
		}

		if (titanWalkL)
		{
			if (tFrontL)
			{
				titanXL += 1;
			}

			else if (!tFrontL)
			{
				titanXL -= 1;
			}


			titanIndex++;

			if (titanIndex >= 24)
			{
				titanIndex = 0;
			}
		}
	}

}

void bgChange()
{

	for (int i = 0; i < 200; i++)
	{
		backGroundR[i].x -= BackGroundSpeed;

	}

	for (int i = 0; i < 200; i++)
	{

		if (i >= 0 && i <= 99)
		{
			if (backGroundR[i].x <= 0)
			{
				backGroundR[i].x = screenWidth;
			}
		}

		if (i >= 99 && i <= 199)
		{
			if (backGroundR[i].x <= 0)
			{
				backGroundR[i].x = 2 * screenWidth;
			}
		}

	}
}

void tsChange()
{
	tsrIndex++;
	if (tsrIndex >= 10)
	{
		tsrIndex = 0;
	}

}

void eren1Jump()
{
	if (jump1)
	{
		if (jumpUp1)
		{

			erenCordinateJump += 20;
			if (erenCordinateJump >= JUMPLIMIT)
			{
				jumpUp1 = false;
			}
		}
		else
		{
			erenCordinateJump -= 15;
			if (erenCordinateJump < 0)
			{
				jump1 = false;
				erenCordinateJump = 0;
			}
		}
	}
}

void showFire()
{

	fireIndex++;

	if (fireIndex >= 6)
	{
		fireIndex = 0;
	}

	fireX -= 13;

	int randObs = 0;

	if (fireX <= 0)
	{
		do{

			randObs = rand() % 420 + 50;
			fireX = screenWidth + randObs;
			cout << "fire" << "\n";

		} while ((fireX - spikeX > -200 && fireX - spikeX < 200) || (fireX - woodX > -200 && fireX - woodX < 200));

		obstacleNumber++;
		fireX = screenWidth + randObs;
		gFire = true;
		sFire = true;
	}

}

void showSpike()
{

	spikeIndex++;

	if (spikeIndex >= 6)
	{
		spikeIndex = 0;
	}

	spikeX -= 13;

	int randObs = 0;

	if (spikeX <= 0)
	{
		do{

			randObs = rand() % 480 + 75;

			spikeX = screenWidth + randObs;
			cout << "spike" << "\n";
		} while ((spikeX - fireX > -200 && spikeX - fireX < 200) || (spikeX - woodX > -200 && spikeX - woodX < 200));
		cout << "spike";
		obstacleNumber++;
		spikeX = screenWidth + randObs;
		gSpike = true;
		sSpike = true;
	}

}

void showWood()
{

	woodIndex++;

	if (woodIndex >= 6)
	{
		woodIndex = 0;
	}

	woodX -= 13;

	int randObs = 0;

	if (woodX <= 0)
	{
		do{

			randObs = rand() % 650 + 60;

			woodX = screenWidth + randObs;
			cout << "wood" << "\n";
		} while ((woodX - fireX > -200 && woodX - fireX < 200) || (woodX - spikeX > -200 && woodX - spikeX < 200));

		obstacleNumber++;
		woodX = screenWidth + randObs;
		gWood = true;
		sWood = true;
	}

}

void fireChange()
{
	fireX2 += dx;

	if ((fireX2 >= (screenWidth - 50)) || fireX2 <= 10)
	{
		dx = dx*(-1);
	}

	bTrapX += dx2;
	bTrapX2 += dx3;
	bTrapX3 += dx4;

	if ((bTrapX >= 1150) || bTrapX <= 400)
	{
		dx2 = dx2*(-1);
	}

	if ((bTrapX2 <= 50) || bTrapX2 >= 700)
	{
		dx3 = dx3*(-1);
	}

	if ((bTrapX3 >= 1150) || bTrapX3 <= 550)
	{
		dx4 = dx4*(-1);
	}

	if (bTrapIndex >= 4)
	{
		bTrapIndex = 0;
	}

	bTrapIndex++;
}


int main()
{
	///srand((unsigned)time(NULL));

	pause_showFire = iSetTimer(20, showFire);
	pause_showSpike = iSetTimer(20, showSpike);
	pause_showWood = iSetTimer(20, showWood);
	pause_change = iSetTimer(20, change);
	pause_tsChange = iSetTimer(200, tsChange);
	pause_bgChange = iSetTimer(2, bgChange);
	pause_eren1change = iSetTimer(25, eren1change);
	pause_eren1Jump = iSetTimer(2, eren1Jump);
	pause_fireChange = iSetTimer(25, fireChange);

	backGroundSet();

	iInitialize(screenWidth, screenHight, "Project1");

	if (musicOn)
	{
		PlaySound("bck2.wav", NULL, SND_LOOP | SND_ASYNC);
	}

	//setenemyVariables();
	int sum = 300;
	for (int i = 3; i >= 0; i--)
	{
		bCordinate[i].x = 50;
		bCordinate[i].y = sum;
		sum += 80;
	}

	//titanMovements();
	iStart();
	///updated see the documentations
	return 0;
}