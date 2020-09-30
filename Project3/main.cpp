#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>
using namespace std;
using namespace sf;

Text text, text1, text2, text3,boardfont,returnfont;
Text num1, num2, num3, num4, num5, num6,R;
Text s1, s2, s3, s4, s5, s6, s7, s8, s9, s10,S1,S2,S3,Sc,Sp;
Text P1name, p2name, p3name,p1id,p2id,p3id,playername,playerid,playerscore;
Texture background, snake,red,black,green,rightbackground,gray,white,dice150,menubackground,board,back;
Font font,font2,f1,f2,f3,f4,f5;
Sprite background1, snake1,red1,blue1,green1, rightbackground1,player,gray1,white1,dice1, menubackground1,board1,back1;
int dice, position = 0, a, save, counter = 0, newd, position1 = 0, position2 = 0,position3=0,position4=0,num=0;
bool y = true, x = true, x1 = true, win = false , boardshow = false;
sf::Event event;
Music lose_ad, win_ad, snake_ad, ladder_ad, dice_ad, main_ad;
struct players
{
	
	int id;
	int score;

}p1,p2,p3;
void lose_audio()
{
	lose_ad.openFromFile("laylay.wav");
	lose_ad.setVolume(100);
	lose_ad.play();
}
void main_audio()
{
	main_ad.openFromFile("main.wav");
	main_ad.setVolume(20);
	main_ad.play();
}
void win_audio()
{
	win_ad.openFromFile("winner.wav");
	win_ad.setVolume(100);
	win_ad.play();
}
void dice_effect()
{
	dice_ad.openFromFile("dice.wav");
	dice_ad.setVolume(100);
	dice_ad.play();
}
void ladder_effect()
{
	ladder_ad.openFromFile("ladder.wav");
	ladder_ad.setVolume(100);
	ladder_ad.play();
}
void snake_effect()
{
	snake_ad.openFromFile("snake.wav");
	snake_ad.setVolume(100);
	snake_ad.play();
}
void you_win()
{
	if (win == true)
	{
		main_ad.stop();
		win_audio();
	}
}
void you_lose()
{
	if (win == true)
	{
		lose_audio();
	}
}
int Dice()
{
	srand(time(0));
	int x = (rand() % 6) + 1;
	return x;
}
void menu()
{
	menubackground.loadFromFile("menuBackground.jpg");
	menubackground1.setTexture(menubackground);
	f1.loadFromFile("SHOWG.ttf");
	f2.loadFromFile("FORTE.ttf");
	f3.loadFromFile("MAGNETOB.ttf");
	f4.loadFromFile("SHOWG.ttf");
	f5.loadFromFile("SHOWG.ttf");
	text.setFont(f3);
	text1.setFont(f2);
	text2.setFont(f2);
	text3.setFont(f2);
	text1.setFillColor(Color::Red);
	text2.setFillColor(Color::Blue);
	text3.setFillColor(Color::Yellow);

	text.setString(" snake      and      ladder ");
	text.setCharacterSize(90);
	text.setPosition(100, 20);
	text1.setString(" Two    players  ");
	text1.setCharacterSize(50);
	text1.setPosition(100, 200);
	text2.setString(" three   players ");
	text2.setCharacterSize(50);
	text2.setPosition(96, 300);
	text3.setString("END GAME LEVEL");
	text3.setCharacterSize(35);
	text3.setPosition(110, 400);
	
}
void show()
{
	background.loadFromFile("Untitled.png");
	rightbackground.loadFromFile("rightbackground.png");
	red.loadFromFile("red.png");
	snake.loadFromFile("snake.jpg");
	black.loadFromFile("blue.png");
	green.loadFromFile("green.png");
	gray.loadFromFile("gray.png");
	dice150.loadFromFile("dice150.png");
	white.loadFromFile("white.png");
	background1.setTexture(background);
	background1.setPosition(Vector2f(0, 0));
	red1.setTexture(red);
	red1.setPosition(Vector2f(60, 720));
	blue1.setTexture(black);
	blue1.setPosition(Vector2f(60, 720));
	green1.setTexture(green);
	green1.setPosition(Vector2f(60, 720));
	gray1.setTexture(gray);
	gray1.setPosition(Vector2f(60, 720));
	snake1.setTexture(snake);
	snake1.setPosition(Vector2f(150, 0));
	rightbackground1.setPosition(Vector2f(0, 0));
	rightbackground1.setTexture(rightbackground);
	white1.setTexture(white);
	white1.setPosition(1260,60);
	dice1.setTexture(dice150);
	dice1.setPosition(1260, 350);
}
void diceShow()
{
	
	ladder_ad.stop();
	snake_ad.stop();

	font2.loadFromFile("BERNHC.ttf");
	R.setPosition(0, 0);
	num1.setFont(font2);
	num2.setFont(font2);
	num3.setFont(font2);
	num4.setFont(font2);
	num5.setFont(font2);
	num6.setFont(font2);

	num1.setCharacterSize(70);
	num2.setCharacterSize(70);
	num3.setCharacterSize(70);
	num4.setCharacterSize(70);
	num5.setCharacterSize(70);
	num6.setCharacterSize(70);

	num1.setString("1");
	num2.setString("2");
	num3.setString("3");
	num4.setString("4");
	num5.setString("5");
	num6.setString("6");
	if (dice == 1)
	{
		R = num1;
		R.setPosition(1320, 90);
	}
	 if (dice == 2)
	{
		 R = num2;
		R.setPosition(1320, 90);
	}
	 if (dice == 3)
	{
		 R = num3;
		R.setPosition(1320, 90);
	}
	 if (dice == 4)
	{
		 R = num4;
		R.setPosition(1320, 90);
	}
	 if (dice == 5)
	{
		 R = num5;
		R.setPosition(1320, 90);
	}
	 if (dice == 6)
	{
		 R = num6;
		R.setPosition(1320, 90);
	}

	 dice_effect();

}
void change2()
{
	if (dice == 6)
	{
		dice--;
		position--;
	}

	else
	{
		dice++;
		position++;
	}
}
void AI2()
{
	if (position == 1)
	{
		change2();

	}
	else if (position == 4)
	{
		change2();
	}
	else if (position == 9)
	{
		change2();
	}
	else if (position == 28)
	{
		change2();
	}
	else if (position == 80)
	{
		change2();
	}
	else if (position == 21)
	{
		change2();
	}
	else if (position == 51)
	{
		change2();
	}
	else if (position == 72)
	{
		change2();
	}
}
void move()
{
	dice = Dice();
	position = position + dice;
	if (num==1)
	{
		AI2();
	}
	
	diceShow();

	system("cls");
	cout << dice << endl;
	//line 1
	if (position < 10)
	{
		for (int i = 0; i < dice; ++i)
		{

			player.move(100, 0);


		}
	}
	else if (position > 10 && position - dice <= 10)
	{
		save = position;
		save = save - dice;
		a = 10 - save;

		for (int i = 0; i < a; ++i)
		{
			player.move(100, 0);
		}
		player.move(0, -85);
		newd = dice - a;
		newd--;
		for (int i = 0; i < newd; ++i)
		{
			player.move(-100, 0);
		}

	}
	else if (position == 10) {
		for (int i = 0; i < dice; ++i)
		{
			player.move(100, 0);
		}
	}

	//line 2

	if (position < 20 && position - dice > 10)
	{
		for (int i = 0; i < dice; ++i)
		{
			player.move(-100, 0);
		}
	}
	else if (position > 20 && position - dice <= 20)
	{
		save = position;
		save = save - dice;
		a = 20 - save;

		for (int i = 0; i < a; ++i)
		{
			player.move(-100, 0);
		}
		player.move(0, -75);
		newd = dice - a;
		newd--;
		for (int i = 0; i < newd; ++i)
		{
			player.move(100, 0);
		}

	}
	else if (position == 20) {
		for (int i = 0; i < dice; ++i)
		{
			player.move(-100, 0);
		}
	}
	//line 3
	if (position < 30 && position - dice > 20)
	{
		for (int i = 0; i < dice; ++i)
		{
			player.move(100, 0);
		}
	}
	else if (position > 30 && position - dice <= 30)
	{
		save = position;
		save = save - dice;
		a = 30 - save;

		for (int i = 0; i < a; ++i)
		{
			player.move(100, 0);
		}
		player.move(0, -80);
		newd = dice - a;
		newd--;
		for (int i = 0; i < newd; ++i)
		{
			player.move(-100, 0);
		}

	}
	else if (position == 30) {
		for (int i = 0; i < dice; ++i)
		{
			player.move(100, 0);
		}
	}
	//line 4
	if (position <= 40 && position - dice > 30)
	{
		for (int i = 0; i < dice; ++i)
		{
			player.move(-100, 0);
		}
	}
	else if (position > 40 && position - dice <= 40)
	{
		save = position;
		save = save - dice;
		a = 40 - save;

		for (int i = 0; i < a; ++i)
		{
			player.move(-100, 0);
		}
		player.move(0, -80);
		newd = dice - a;
		newd--;
		for (int i = 0; i < newd; ++i)
		{
			player.move(100, 0);
		}

	}
	else if (position == 40) {
		for (int i = 0; i < dice; ++i)
		{
			player.move(-100, 0);
		}
	}
	//line 5
	if (position <= 50 && position - dice > 40)
	{
		for (int i = 0; i < dice; ++i)
		{
			player.move(100, 0);
		}
	}
	else if (position > 50 && position - dice <= 50)
	{
		save = position;
		save = save - dice;
		a = 50 - save;

		for (int i = 0; i < a; ++i)
		{
			player.move(100, 0);
		}
		player.move(0, -80);
		newd = dice - a;
		newd--;
		for (int i = 0; i < newd; ++i)
		{
			player.move(-100, 0);
		}

	}
	else if (position == 50) {
		for (int i = 0; i < dice; ++i)
		{
			player.move(100, 0);
		}
	}
	//line 6
	if (position <= 60 && position - dice > 50)
	{
		for (int i = 0; i < dice; ++i)
		{
			player.move(-100, 0);
		}
	}
	else if (position > 60 && position - dice <= 60)
	{
		save = position;
		save = save - dice;
		a = 60 - save;

		for (int i = 0; i < a; ++i)
		{
			player.move(-100, 0);
		}
		player.move(0, -80);
		newd = dice - a;
		newd--;
		for (int i = 0; i < newd; ++i)
		{
			player.move(100, 0);
		}

	}
	else if (position == 60) {
		for (int i = 0; i < dice; ++i)
		{
			player.move(-100, 0);
		}
	}
	//line 7
	if (position <= 70 && position - dice > 60)
	{
		for (int i = 0; i < dice; ++i)
		{
			player.move(100, 0);
		}
	}
	else if (position > 70 && position - dice <= 70)
	{
		save = position;
		save = save - dice;
		a = 70 - save;

		for (int i = 0; i < a; ++i)
		{
			player.move(100, 0);
		}
		player.move(0, -80);
		newd = dice - a;
		newd--;
		for (int i = 0; i < newd; ++i)
		{
			player.move(-100, 0);
		}

	}
	else if (position == 70) {
		for (int i = 0; i < dice; ++i)
		{
			player.move(100, 0);
		}
	}
	//line 8
	if (position <= 80 && position - dice > 70)
	{
		for (int i = 0; i < dice; ++i)
		{
			player.move(-100, 0);
		}
	}
	else if (position > 80 && position - dice <= 80)
	{
		save = position;
		save = save - dice;
		a = 80 - save;

		for (int i = 0; i < a; ++i)
		{
			player.move(-100, 0);
		}
		player.move(0, -80);
		newd = dice - a;
		newd--;
		for (int i = 0; i < newd; ++i)
		{
			player.move(100, 0);
		}

	}
	else if (position == 80) {
		for (int i = 0; i < dice; ++i)
		{
			player.move(-100, 0);
		}
	}
	//line 9
	if (position <= 90 && position - dice > 80)
	{
		for (int i = 0; i < dice; ++i)
		{
			player.move(100, 0);
		}
	}
	else if (position > 90 && position - dice <= 90)
	{
		save = position;
		save = save - dice;
		a = 90 - save;

		for (int i = 0; i < a; ++i)
		{
			player.move(100, 0);
		}
		player.move(0, -80);
		newd = dice - a;
		newd--;
		for (int i = 0; i < newd; ++i)
		{
			player.move(-100, 0);
		}

	}
	else if (position == 90) {
		for (int i = 0; i < dice; ++i)
		{
			player.move(100, 0);
		}
	}
	//line 10
	if (position <= 100 && position - dice > 90)
	{
		for (int i = 0; i < dice; ++i)
		{
			player.move(-100, 0);
		}
	}
	else if (position > 100)
	{

		position = position - dice;


	}
	else if (position == 100) {
		for (int i = 0; i < dice; ++i)
		{
			player.move(-100, 0);
		}
	
	}
	if (position == 100)
	{
		win = true;
		you_win();
	}

}
void change()
{
	if (dice == 6)
	{
		dice--;
		position--;
	}
	
	else 
	{
		dice++;
		position++;
	}
}
void AI()
{
	if (position == 17)
	{
		change();
	}
	else if (position == 62)
	{
		change();
	}
	else if (position == 64)
	{
		change();
	}
	else if (position == 93)
	{
		change();
	}
	else if (position == 87)
	{
		change();
	}
	else if (position == 95)
	{
		change();
	}
	else if (position == 98)
	{ 
		change();
	}
	else if (position == 54)
	{
		change();
	}
	
	
	
}
void AiMove()
{
	dice = Dice();
	system("cls");
	cout << dice << endl;
	position = position + dice;

	AI();
	diceShow();
	cout << dice << endl;
	
	
	//line 1
	if (position < 10)
	{
		for (int i = 0; i < dice; ++i)
		{

			player.move(100, 0);


		}
	}
	else if (position > 10 && position - dice <= 10)
	{
		save = position;
		save = save - dice;
		a = 10 - save;

		for (int i = 0; i < a; ++i)
		{
			player.move(100, 0);
		}
		player.move(0, -85);
		newd = dice - a;
		newd--;
		for (int i = 0; i < newd; ++i)
		{
			player.move(-100, 0);
		}

	}
	else if (position == 10) {
		for (int i = 0; i < dice; ++i)
		{
			player.move(100, 0);
		}
	}

	//line 2

	if (position < 20 && position - dice > 10)
	{
		for (int i = 0; i < dice; ++i)
		{
			player.move(-100, 0);
		}
	}
	else if (position > 20 && position - dice <= 20)
	{
		save = position;
		save = save - dice;
		a = 20 - save;

		for (int i = 0; i < a; ++i)
		{
			player.move(-100, 0);
		}
		player.move(0, -75);
		newd = dice - a;
		newd--;
		for (int i = 0; i < newd; ++i)
		{
			player.move(100, 0);
		}

	}
	else if (position == 20) {
		for (int i = 0; i < dice; ++i)
		{
			player.move(-100, 0);
		}
	}
	//line 3
	if (position < 30 && position - dice > 20)
	{
		for (int i = 0; i < dice; ++i)
		{
			player.move(100, 0);
		}
	}
	else if (position > 30 && position - dice <= 30)
	{
		save = position;
		save = save - dice;
		a = 30 - save;

		for (int i = 0; i < a; ++i)
		{
			player.move(100, 0);
		}
		player.move(0, -80);
		newd = dice - a;
		newd--;
		for (int i = 0; i < newd; ++i)
		{
			player.move(-100, 0);
		}

	}
	else if (position == 30) {
		for (int i = 0; i < dice; ++i)
		{
			player.move(100, 0);
		}
	}
	//line 4
	if (position <= 40 && position - dice > 30)
	{
		for (int i = 0; i < dice; ++i)
		{
			player.move(-100, 0);
		}
	}
	else if (position > 40 && position - dice <= 40)
	{
		save = position;
		save = save - dice;
		a = 40 - save;

		for (int i = 0; i < a; ++i)
		{
			player.move(-100, 0);
		}
		player.move(0, -80);
		newd = dice - a;
		newd--;
		for (int i = 0; i < newd; ++i)
		{
			player.move(100, 0);
		}

	}
	else if (position == 40) {
		for (int i = 0; i < dice; ++i)
		{
			player.move(-100, 0);
		}
	}
	//line 5
	if (position <= 50 && position - dice > 40)
	{
		for (int i = 0; i < dice; ++i)
		{
			player.move(100, 0);
		}
	}
	else if (position > 50 && position - dice <= 50)
	{
		save = position;
		save = save - dice;
		a = 50 - save;

		for (int i = 0; i < a; ++i)
		{
			player.move(100, 0);
		}
		player.move(0, -80);
		newd = dice - a;
		newd--;
		for (int i = 0; i < newd; ++i)
		{
			player.move(-100, 0);
		}

	}
	else if (position == 50) {
		for (int i = 0; i < dice; ++i)
		{
			player.move(100, 0);
		}
	}
	//line 6
	if (position <= 60 && position - dice > 50)
	{
		for (int i = 0; i < dice; ++i)
		{
			player.move(-100, 0);
		}
	}
	else if (position > 60 && position - dice <= 60)
	{
		save = position;
		save = save - dice;
		a = 60 - save;

		for (int i = 0; i < a; ++i)
		{
			player.move(-100, 0);
		}
		player.move(0, -80);
		newd = dice - a;
		newd--;
		for (int i = 0; i < newd; ++i)
		{
			player.move(100, 0);
		}

	}
	else if (position == 60) {
		for (int i = 0; i < dice; ++i)
		{
			player.move(-100, 0);
		}
	}
	//line 7
	if (position <= 70 && position - dice > 60)
	{
		for (int i = 0; i < dice; ++i)
		{
			player.move(100, 0);
		}
	}
	else if (position > 70 && position - dice <= 70)
	{
		save = position;
		save = save - dice;
		a = 70 - save;

		for (int i = 0; i < a; ++i)
		{
			player.move(100, 0);
		}
		player.move(0, -80);
		newd = dice - a;
		newd--;
		for (int i = 0; i < newd; ++i)
		{
			player.move(-100, 0);
		}

	}
	else if (position == 70) {
		for (int i = 0; i < dice; ++i)
		{
			player.move(100, 0);
		}
	}
	//line 8
	if (position <= 80 && position - dice > 70)
	{
		for (int i = 0; i < dice; ++i)
		{
			player.move(-100, 0);
		}
	}
	else if (position > 80 && position - dice <= 80)
	{
		save = position;
		save = save - dice;
		a = 80 - save;

		for (int i = 0; i < a; ++i)
		{
			player.move(-100, 0);
		}
		player.move(0, -80);
		newd = dice - a;
		newd--;
		for (int i = 0; i < newd; ++i)
		{
			player.move(100, 0);
		}

	}
	else if (position == 80) {
		for (int i = 0; i < dice; ++i)
		{
			player.move(-100, 0);
		}
	}
	//line 9
	if (position <= 90 && position - dice > 80)
	{
		for (int i = 0; i < dice; ++i)
		{
			player.move(100, 0);
		}
	}
	else if (position > 90 && position - dice <= 90)
	{
		save = position;
		save = save - dice;
		a = 90 - save;

		for (int i = 0; i < a; ++i)
		{
			player.move(100, 0);
		}
		player.move(0, -80);
		newd = dice - a;
		newd--;
		for (int i = 0; i < newd; ++i)
		{
			player.move(-100, 0);
		}

	}
	else if (position == 90) {
		for (int i = 0; i < dice; ++i)
		{
			player.move(100, 0);
		}
	}
	//line 10
	if (position <= 100 && position - dice > 90)
	{
		for (int i = 0; i < dice; ++i)
		{
			player.move(-100, 0);
		}
	}
	else if (position > 100)
	{

		position = position - dice;


	}
	else if (position == 100) {
		for (int i = 0; i < dice; ++i)
		{
			player.move(-100, 0);
		}
	}
	if (position == 100)
	{
		win = true;
		main_ad.stop();
		you_lose();
		lose_audio();
	}
}
void ladder()
{

	if (position == 1)
	{
		ladder_effect();
		position = 38;
		player.setPosition(360, 480);

	}
	else if (position == 4)
	{
		ladder_effect();
		position = 14;
		player.setPosition(760, 640);
	}
	else if (position == 9)
	{
		ladder_effect();
		position = 31;
		player.setPosition(1060, 480);
	}
	else if (position == 28)
	{
		ladder_effect();
		position = 84;
		player.setPosition(460, 80);
	}
    else if (position == 80)
	{
		ladder_effect();
	   position = 99;
	   player.setPosition(260, 0);
	}
	else if (position == 21)
	{
		ladder_effect();
		position = 42;
		player.setPosition(260, 400);
	}
	else if (position == 51)
	{
		ladder_effect();
		position = 67;
		player.setPosition(760, 240);
	}
	else if (position == 72)
	{
		ladder_effect();
		position = 91;
		player.setPosition(1060, 0);
	}
}
void snakes()
{
	if (position == 17)
	{
		snake_effect();
		position = 7;
		player.setPosition(760, 720);

	}
	else if (position ==62)
	{
		snake_effect();
		position = 19;
		player.setPosition(260, 635);
	}
	else if (position == 64)
	{
		snake_effect();
		position = 60;
		player.setPosition(160, 320);
	}
	else if (position == 98)
	{
		snake_effect();
		position = 79;
		player.setPosition(260, 160);
	}
	else if (position == 95)
	{
		snake_effect();
		position = 75;
		player.setPosition(660, 160);
	}
	else if (position == 93)
	{
		snake_effect();
		position = 73;
		player.setPosition(860, 160);
	}
	else if (position == 87)
	{
		snake_effect();
		position = 36;
		player.setPosition(560, 480);
	}
	else if (position == 54)
	{
		snake_effect();
		position = 34;
		player.setPosition(760, 480);
	}
}
void player1()
{
	
	player = red1;
	position = position1;
	move();
	R.setFillColor(Color::Red);
	ladder();
	snakes();
	position1 =position;
	red1= player;
	x = false;
	x1 = false;
	if (position1 == 100)
		p1.score = p1.score + 1;

	

}
void player2()
{
	
	player = green1;
	position = position2;
	move();
	R.setFillColor(Color::Green);
	ladder();
	snakes();
	position2 =position;
	green1 = player;
	y = false;
	x1 = true;
	if (position2 == 100)
		p2.score = p2.score + 1;
}
void player3()
{
	
	player = blue1;
	position = position3;
	move();
	R.setFillColor(Color::Blue);
	ladder();
	snakes();
	position3 = position;
	blue1 = player;
	x = true;
	y = true;
	if (position3 == 100)
		p3.score = p3.score + 1;
}
void computer()
{
	player = gray1;
	position = position4;
	AiMove();
	R.setFillColor(Color::Black);
	ladder();
	snakes();
	position4 = position;
	gray1 = player;
	y = false;
	x1 = true;
}
void solo()
{
	
	if (x1 == true)
		player1();
	else { computer(); }
}
void two_players()
{
	if (x1 == true)
		player1();
	else { player2(); }
}
void three_players()
{
	if (x == true && y == true)
	{
		player1();
	}
	else if (y == true && x == false)
	{
		player2();
	}
	else { player3(); }
}
void playAgain()
{
	lose_ad.stop();
	win_ad.stop();
	main_audio();
	position = 0;
	position1 = 0;
	position2 = 0;
	position3 = 0;
	position4 = 0;
	player.setPosition(60, 720);
	red1.setPosition(60, 720);
	blue1.setPosition(60, 720);
	green1.setPosition(60, 720);
	gray1.setPosition(60, 720);
	R.setPosition(0, 0);
	num1.setPosition(0, 0);
	num2.setPosition(0, 0);
	num3.setPosition(0, 0);
	num4.setPosition(0, 0);
	num5.setPosition(0, 0);
	num6.setPosition(0, 0);
	win = false;

}
void randchoose()
{
	int x = event.mouseButton.x;
	int y = event.mouseButton.y;
	if (x >= 1260 && x <= 1410)
	{
		if (y >= 350 && y <= 500)
		{
			if (num == 1)
			{

				solo();
			}
			else if (num == 2)
			{
				two_players();
			}
			else
			{
				three_players();
			}
		}
	}
}
void choose()
{
	int x = event.mouseButton.x;
	int y = event.mouseButton.y;
	if (x>=100 && x<=400)
	{
		if (y >200 &&y <260 )
		{
			show();
			num = 2;
		}
	}
	 if (x >= 95 && x <= 390)
	{
		if (y > 300 && y < 360)
		{
			show();
			num = 3;
		}
	}
	 if (x >= 120 && x <= 350)
	 {
		 if (y > 400 && y < 460)
		 {
			 show();
			 num = 1;
		 }
	 }
	

	 
}
void rechoose()
{
	int x = event.mouseButton.x;
	int y = event.mouseButton.y;
	if (x >= 1200 && x <= 1400)
	{
		if (y > 600 && y < 650)
		{
			boardshow = true;
		}
	}
	if (x >= 1200 && x <= 1400)
	{
		if (y > 700 && y < 750)
		{
			playAgain();
		}
	}
	if (x >= 1400 && x <= 1500)
	{
		if (y > 0 && y < 50)
		{
			boardshow = false;
		}
	}
}
void score()
{
	
		S1.setString("0");
		S2.setString("0");
		S3.setString("0");

	if (p1.score == 1)
		S1 = s1;
	if (p2.score == 1)
		S2 = s1;
	if (p3.score == 1)
		S3 = s1;
	
	//
	if (p1.score == 2)
		S1 = s2;
	 if (p2.score == 2)
		S2 = s2;
	if (p3.score == 2)
		S3 = s2;
	//
	if (p1.score == 3)
		S1 = s3;
	 if (p2.score == 3)
		S2 = s3;
	 if (p3.score == 3)
		S3 = s3;
	//
	if (p1.score == 4)
		S1 = s4;
    if (p2.score == 4)
		S2 = s4;
	if (p3.score == 4)
		S3 = s4;
	//
	if (p1.score == 5)
		S1 = s5;
	 if (p2.score == 5)
		S2 = s5;
	if (p3.score == 5)
		S3 = s5;
	//
	if (p1.score == 6)
		S1 = s6;
	if (p2.score == 6)
		S2 = s6;
	if (p3.score == 6)
		S3 = s6;
	//
	if (p1.score == 7)
		S1 = s7;
	 if (p2.score == 7)
		S2 = s7;
	if (p3.score == 7)
		S3 = s7;
	//
	if (p1.score == 8)
		S1 = s8;
	 if (p2.score == 8)
		S2 = s8;
	 if (p3.score == 8)
		S3 = s8;
	//
	if (p1.score == 9)
		S1 = s9;
	 if (p2.score == 9)
		S2 = s9;
	if (p3.score == 9)
		S3 = s9;
	//
	if (p1.score == 10)
		S1 = s10;
	 if (p2.score == 10)
		S2 = s10;
	 if (p3.score == 10)
		S3 = s10;
}
void scoreArrange()
{
	//1
	if (p1.score > p2.score )
	{
		if (p2.score > p3.score) {
			P1name.setPosition(30, 220);
			p1id.setPosition(450, 220);
			S1.setPosition(900, 220);

			p2name.setPosition(30, 370);
			p2id.setPosition(450, 370);
			S2.setPosition(900, 370);

			p3name.setPosition(30, 520);
			p3id.setPosition(450, 520);
			S3.setPosition(900, 520);
		}
		else {

			P1name.setPosition(30, 220);
			p1id.setPosition(450, 220);
			S1.setPosition(900, 220);

			p3name.setPosition(30, 370);
			p3id.setPosition(450, 370);
			S3.setPosition(900, 370);

			p2name.setPosition(30, 520);
			p2id.setPosition(450, 520);
			S2.setPosition(900, 520);

		}
	}

	
	//3
	if (p2.score > p1.score)
	{
		if (p1.score > p3.score)
		{
			p2name.setPosition(30, 220);
			p2id.setPosition(450, 220);
			S2.setPosition(900, 220);

			P1name.setPosition(30, 370);
			p1id.setPosition(450, 370);
			S1.setPosition(900, 370);

			p3name.setPosition(30, 520);
			p3id.setPosition(450, 520);
			S3.setPosition(900, 520);
		}
		else {

			p2name.setPosition(30, 220);
			p2id.setPosition(450, 220);
			S2.setPosition(900, 220);

			p3name.setPosition(30, 370);
			p3id.setPosition(450, 370);
			S3.setPosition(900, 370);

			P1name.setPosition(30, 520);
			p1id.setPosition(450, 520);
			S1.setPosition(900, 520);
		}
	}
	
	
	//5
	if (p3.score > p1.score)
	{
		if (p1.score > p2.score)
		{
			p3name.setPosition(30, 220);
			p3id.setPosition(450, 220);
			S3.setPosition(900, 220);

			P1name.setPosition(30, 370);
			p1id.setPosition(450, 370);
			S1.setPosition(900, 370);

			p2name.setPosition(30, 520);
			p2id.setPosition(450, 520);
			S2.setPosition(900, 520);
		}
		else
		{
			p3name.setPosition(30, 220);
			p3id.setPosition(450, 220);
			S3.setPosition(900, 220);

			p2name.setPosition(30, 370);
			p2id.setPosition(450, 370);
			S2.setPosition(900, 370);

			P1name.setPosition(30, 520);
			p1id.setPosition(450, 520);
			S1.setPosition(900, 520);
		}
	}
	



}
void boardShow()
{
	back.loadFromFile("back.png");
	back1.setTexture(back);
	back1.setPosition(1450, 0);
	boardfont.setString("score board");
	boardfont.setFont(f2);
	boardfont.setCharacterSize(50);
	boardfont.setPosition(1200, 600);
	boardfont.setFillColor(Color::Red);
	returnfont.setString("play again");
	returnfont.setFont(f2);
	returnfont.setCharacterSize(50);
	returnfont.setPosition(1200, 700);
	returnfont.setFillColor(Color::Red);
	board.loadFromFile("board.jpg");
	board1.setTexture(board);
	s1.setString("1");
	s2.setString("2");
	s3.setString("3");
	s4.setString("4");
	s5.setString("5");
	s6.setString("6");
	s7.setString("7");
	s8.setString("8");
	s9.setString("9");
	s10.setString("10");
	score();
	
	//board
	playername.setString("plarer name ");
	playername.setFont(f2);
	playername.setCharacterSize(40);
	playername.setPosition(30, 60);
	playername.setFillColor(Color::Black);
	//
	playerid.setString("Color");
	playerid.setFont(f2);
	playerid.setCharacterSize(40);
	playerid.setPosition(450, 60);
	playerid.setFillColor(Color::Black);
	//
	playerscore.setString("plarer score ");
	playerscore.setFont(f2);
	playerscore.setCharacterSize(40);
	playerscore.setPosition(800, 60);
	playerscore.setFillColor(Color::Black);
	//player 1
	P1name.setString("player 1 ");
	p1id.setString("Red");
	P1name.setFont(f2);
	P1name.setCharacterSize(40);
	p1id.setFont(f2);
	p1id.setCharacterSize(40);
	P1name.setFillColor(Color::Red);
	p1id.setFillColor(Color::Red);
	P1name.setPosition(70, 220);
	p1id.setPosition(680, 220);
	S1.setFont(f2);
	S1.setCharacterSize(40);
	S1.setFillColor(Color::Red);
	S1.setPosition(1200, 220);
	//player 2
	p2name.setString("player 2 ");
	p2id.setString("Green");
	p2name.setFont(f2);
	p2name.setCharacterSize(40);
	p2id.setFont(f2);
	p2id.setCharacterSize(40);
	p2name.setFillColor(Color::Green);
	p2id.setFillColor(Color::Green);
	p2name.setPosition(70, 370);
	p2id.setPosition(680, 370);
	S2.setFont(f2);
	S2.setCharacterSize(40);
	S2.setFillColor(Color::Green);
	S2.setPosition(1200, 370);
	//player 3
	p3name.setString("player 3 ");
	p3id.setString("Blue");
	p3name.setFont(f2);
	p3name.setCharacterSize(40);
	p3id.setFont(f2);
	p3id.setCharacterSize(40);
	p3name.setFillColor(Color::Blue);
	p3id.setFillColor(Color::Blue);
	p3name.setPosition(70, 520);
	p3id.setPosition(680, 520);
	S3.setFont(f2);
	S3.setCharacterSize(40);
	S3.setFillColor(Color::Blue);
	S3.setPosition(1200, 520);
	


	scoreArrange();
	
}


int main()
{
	sf::RenderWindow window(sf::VideoMode(1500, 800), "ladder and snake");
	
	main_audio();
	you_win();

	menu();
	
	while (window.isOpen())
	{
		
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::MouseButtonPressed:
				if (win==false)
				{
					choose();
					randchoose();
				}
				else {
					
					rechoose();
				}
				
				

				break;
			}
			




		}
	
		
		boardShow();
		window.clear();
		window.draw(menubackground1);
		window.draw(text);
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(background1);
		window.draw(snake1);
		window.draw(red1);
		window.draw(green1);
		window.draw(blue1);
		window.draw(gray1);
		window.draw(player);
		window.draw(white1);
		window.draw(R);
		window.draw(dice1);
		window.draw(rightbackground1);
		if (win == true)
		{
			window.draw(boardfont);
			window.draw(returnfont);
		}
		if (boardshow == true)
		{
			window.draw(board1);
			window.draw(playername);
			window.draw(playerid);
			window.draw(playerscore);
			window.draw(P1name);
			window.draw(p2name);
			window.draw(p3name);
			window.draw(back1);
			window.draw(p1id);
			window.draw(p2id);
			window.draw(p3id);
			window.draw(S1);
			window.draw(S2);
			window.draw(S3);

		}
		window.display();
	}
	return 0;
}