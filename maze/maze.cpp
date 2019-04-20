#include <iostream>
#include <vector>
using namespace std;

int M = 0;
int N = 0;
vector<vector<int>> maze;
vector<vector<int>> maze_path;
vector<vector<int>> maze_best;

void Mazetrak(int i, int j)
{
	maze[i][j] = 1;
	maze_path.push_back({ i, j });
	if (i == M - 1 && j == N - 1)
	{
		if (maze_best.empty() || maze_best.size() > maze_path.size())
		{
			maze_best = maze_path;
		}
	}
	if (i<M - 1 && maze[i + 1][j] == 0)
	{
		Mazetrak(i + 1, j);
	}
	if (i >0 && maze[i - 1][j] == 0)
	{
		Mazetrak(i - 1, j);
	}
	if (j >0 && maze[i][j - 1] == 0)
	{
		Mazetrak(i, j - 1);
	}
	if (j<N - 1 && maze[i][j + 1] == 0)
	{
		Mazetrak(i, j + 1);

	}
	maze[i][j] = 0;
	maze_path.pop_back();
}


int main()
{
	while (cin >> M >> N)
	{
		maze.resize(M);
		int tmp = 0;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> tmp;
				maze[i].push_back(tmp);
			}
		}
		maze_best.clear();
		maze_path.clear();
		Mazetrak(0, 0);
		for (int i = 0; i < maze_best.size(); ++i)
		{
			cout << "(" << maze_best[i][0] << "," << maze_best[i][1] << ")" << endl;
		}
	}
	return 0;
}