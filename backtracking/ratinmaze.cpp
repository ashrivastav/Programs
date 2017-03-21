/*
 * ratinmaze.cpp
 *
 *  Created on: Mar 11, 2017
 *      Author: abhishek
 */

#include <vector>
#include <iostream>

using namespace std;
const int N = 4;


bool is_feasible(auto &maze, int x, int y)
{
	return (x >=0 &&  x < N && y >=0 && y < N && maze[x][y] == 1);
}


bool solvemazeutil(auto &maze, int x, int y, auto &solution)
{

	if(x == N-1 && y == N-1 && is_feasible(maze, x, y)){
		solution[x][y] = 1;
		return true;
	}

	if(is_feasible(maze, x, y))
	{
		solution[x][y] = 1;
		if(solvemazeutil(maze, x+1, y, solution))
			return true; // go left
		if(solvemazeutil(maze, x, y+1, solution))
			return true;// go down
		solution[x][y] =0;
		return false;
	}
	return false;
}

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

void solvemaze(auto maze)
{
	int solution[N][N] = {{0}};
	if(solvemazeutil(maze,0,0,solution))
		cout << "Solution exists" << endl;
	else
		cout << "Solution doesn't exists" << endl;

	printSolution(solution);

}


// driver program to test above function
int main()
{

	 int maze[N][N] = { {1, 0, 0, 0},
		{1, 1, 0, 1},
		{0, 1, 0, 0},
		{1, 1, 1, 1}
	};

	solvemaze(maze);
	return 0;
}
