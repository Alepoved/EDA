/* C/C++ program to solve Rat in a Maze problem using
backtracking */
#include<stdio.h>
#include <iostream>
using namespace std;

// Maze size
#define N 4 

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);

/* A utility function to print solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf(" %d ", sol[i][j]);
		printf("\n");
	}
}

/* A utility function to check if x,y is valid index for N*N maze */
bool isSafe(int maze[N][N], int x, int y)
{
	return (x < N  && y <= N && maze[x][y] == 1);
}

/* This function solves the Maze problem using Backtracking.  It mainly
uses solveMazeUtil() to solve the problem. It returns false if no
path is possible, otherwise return true and prints the path in the
form of 1s. Please note that there may be more than one solutions,
this function prints one of the feasible solutions.*/
bool solveMaze(int maze[N][N])
{
	int sol[N][N] = { { 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 }
	};

	if (solveMazeUtil(maze, 0, 0, sol) == false)
	{
		printf("Solution doesn't exist");
		return false;
	}

	printSolution(sol);
	return true;
}

/* A recursive utility function to solve Maze problem */
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
	if (x == N - 1 && y == N - 1) {
		sol[x][y] = 1;
		return true;
	}

	if (isSafe(maze ,x, y)) {
		sol[x][y] = 1;
		if (solveMazeUtil(maze, x + 1, y, sol))return true;
		if (solveMazeUtil(maze, x, y + 1, sol))return true;
		sol[x][y] = 0;
		return false;
	}

	return false;
}

// driver program to test above function
int main()
{
	int maze[N][N] = { { 1, 0, 0, 0 },
	{ 1, 1, 0, 1 },
	{ 0, 1, 0, 0 },
	{ 1, 1, 1, 1 }
	};

	solveMaze(maze);
	system("pause");
	return 0;
}