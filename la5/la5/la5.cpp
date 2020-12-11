// la4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#define _CRT_SECURE_NO_WARNINGS
#include "windows.h"
#include "stdio.h"
#include "time.h"
#include "conio.h"
#include <queue>
#include <locale.h>
//#define SIZE 5
using namespace std;



void rand_Zap(int** mat, int n)
{
	srand(time(NULL));
	printf("G\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				mat[i][j] = 0;
			}
			if (i < j) {
				mat[i][j] = rand() % 2;
				mat[j][i] = mat[i][j];
			}
		}
}

void print_G(int** mat, int n)
{
	printf("  ");
	for (int i = 0; i < n; i++)
		printf("%3d", i + 1);
	printf("\n\n");
	for (int i = 0; i < n; i++)
	{
		printf("%2d", i + 1);
		for (int j = 0; j < n; j++)
		{
			printf("%3d", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void BFS(int s, int** G, int n, int* vis)
{
	queue <int> Q;
	Q.push(s);
	vis[s] = 1;
	while (!Q.empty()) {
		s = Q.front();
		printf("%d ", s + 1);
		Q.pop();
		for (int i = 0; i < 5; i++) {
			if ((G[s][i] == 1) && !vis[i]) {
				Q.push(i);
				vis[i] = 1;
			}
		}
	}
}



int main()
{
	setlocale(LC_ALL, "Rus");

	int N = 1;
	scanf("%d", &N);

	int** G = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++) {
		G[i] = (int*)malloc(N * sizeof(int));
	}

	int* vis;
	vis = (int*)malloc(N * sizeof(int));

	int s, i = 0;
	rand_Zap(G, N);

	printf("\n");

	print_G(G, N);

	for (int i = 0; i < N; i++)
	{
		vis[i] = 0;
	}
	printf("Введите вершину для начала обхода\n");
	scanf("%d", &s);
	while ((s < 1) || (s > N))
	{
		printf("Ошибка.\n");
		scanf("%d", &s);
	}
	printf("\n");
	s--;
	printf("Результат:\n");
	BFS(s, G, N, &vis[0]);
	getchar();
	getchar();
}


