#include<iostream>
#include<stdlib.h>﻿
#include<ctime>
#include <windows.h>
#include<conio.h>//Помогает отслеживать, что нажал пользователь без закрытия термнала 
using namespace std;

bool gameOver;//Переменная, обозначающая конец игры
const int width = 70;//Ширина поля
const int height = 40;//Высота поля
int x, y;
int life[100][100];
int life1[100][100];
int pop = 0;
int time1 = 1;
int kol = 0;//Колличество живых клеток рядом с проверяемой клеткой

int random() {
	int i = rand() % 7;
	if (i== 0) return 1;
	else return 0;
}

int check(int x, int y){
	int i = 0;
	int k = 0;
	while (i < 8) {
		switch (i)
		{
		case 0: {
			if (life[x - 1][y + 1] == 1)
				k++;
			break;
		}
		case 1: {
			if (life[x][y + 1] == 1)
				k++;
			break;
		}
		case 2: {
			if (life[x + 1][y + 1] == 1)
				k++;
			break;
		}
		case 3: {
			if (life[x - 1][y] == 1)
				k++;
			break;
		}
		case 4: {
			if (life[x + 1][y] == 1)
				k++;
			break;
		}
		case 5: {
			if (life[x-1][y-1] == 1)
				k++;
			break;
		}
		case 6: {
			if (life[x][y-1] == 1)
				k++;
			break;
		}
		case 7: {
			if (life[x+1][y-1] == 1)
				k++;
			break;
		}
		default:
			break;
		}
		i++;
	}
	if (life[x][y] == 0) {
		if (k == 3) {
			return 1;
		}
		else return 0;
	}
	if (life[x][y] == 1) {
		if (k < 2 || k > 3) {
			return 0;
		}
		else if (k==2||k==3) return 1;
	}
}

void Setup() {   //Настройка параметров
	gameOver = false;//так ткак мы не проиграли сначала
	srand(time(NULL)); // автоматическая рандомизация. time(NULL) передает время с 1 янваяря n-ого года
	for (int i = 0; i < height; i++) {		//Задание первоначального значения
		for (int j = 0; j < width; j++) {
			life[i][j] = 0;
		}
	}

	for (int i = 0; i < height; i++) {		//Задание первоначального значения
		for (int j = 0; j < width; j++) {
			life[i][j] = random();
			life1[i][j] = life[i][j];
		}
	}
}

void Draw() {    //Рисование карты

	system("cls");//Очищает терминал каждый раз когда мы вызываем функцию draw
	for (int i = 0; i < width+2; i++) {   //Нарисуем верхнюю границу
		cout << "#";
	}
	cout << endl;

	for (int i = 0; i < height; i++) {//Создание боковой границы
		for (int j = 0; j < (width+1); j++) {
			if (j == 0){// width-1 так как стартовали с 0 
				cout << "#";
			}
			if (life[i][j]==1 ){ //проверка на живую клетку
				cout << "X";//Обозначение живой клетки
				pop++;
			}
			else if (j == (width)) {// width-1 так как стартовали с 0 
				cout << "#";
			}
			else  {
				cout << " ";
			}
		}
		cout << endl;//Чтобы перекинуло на новую строчку
	}
	for (int i = 0; i < width + 2; i++) {   //Нарисуем нижнюю границу
		cout << "#";
	}
	cout << endl;
	cout << "Time: " << time1 << endl;
	cout << "Population: " << pop << endl;
	pop = 0;
	time1++;
}

void Logic()
{
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			life1[i][j] = check(i, j);
		}
	}
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			life[i][j] = life1[i][j];
		}
	}
}


int main() {
	setlocale(LC_ALL, "ru");
	int n = 0; 
	int time = 0;

	int k;
	Setup();//Вызов функции
	while (!gameOver) {
		while (!gameOver) {//Пока не проиграли
			Draw();
			Sleep(time);
			Logic();
		}
		cout << "Игра окончена" << endl;
	}
	return 0;
}