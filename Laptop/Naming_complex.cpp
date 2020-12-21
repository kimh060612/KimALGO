#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string.h>
#define MAX 30

using namespace std;

ifstream fin;
ofstream fout;

int N;
int MAP[MAX][MAX],check[MAX][MAX];
int New_MAP[MAX][MAX];
int max_room = -987654321;
int dx[7] = {1,-1,0,0};
int dy[7] = {0,0,1,-1};
vector<int> Room;


void Input()
{
	cin >> N;
	char tmp[30];
	for (int i = 1; i <= N; i++)
	{
		cin >> tmp;
		for (int j = 0; j < strlen(tmp); j++)
		{
			MAP[i][j + 1] = tmp[j] - 48;
		}
	}
}

int house;

void Search(int x, int y)
{
	check[y][x] = 1;
	house++;
	New_MAP[y][x] = house;
	max_room = max_room < house ? house : max_room;

	if (x < 0 || y < 0 || x > N || y > N)return;

	for (int i = 0; i < 4; i++)
	{
		if (x + dx[i] > 0 && y + dy[i] > 0 && x + dx[i] <= N && y + dy[i] <= N)
		{
			if (MAP[y + dy[i]][x + dx[i]] && !check[y + dy[i]][x + dx[i]])
			{
				Search(x + dx[i], y + dy[i]);
			}
		}
	}
}

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	Input();
	
	int num_complex = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (MAP[i][j] != 0 && !check[i][j])
			{
				max_room = -987654321;
				num_complex++;
				house = 0;
				Search(j, i);
				Room.push_back(max_room);
			}
		}
	}

	sort(Room.begin(), Room.end());

	cout << num_complex << endl;
	for (int i = 0; i < Room.size(); i++)
	{
		cout << Room[i] << endl;
	}

	fin.close();
	fout.close();
	return 0;
}