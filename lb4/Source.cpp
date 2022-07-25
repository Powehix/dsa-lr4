#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  
using namespace std;

vector<int> mem;
vector<vector<int>> matrix = {
	{0,1,0,0,1,1,0,0,0,0,0,0},//0
	{1,0,0,0,0,0,1,0,0,0,0,0},//1
	{0,0,0,1,0,1,0,0,0,0,0,0},//2
	{0,0,1,0,0,0,0,1,0,0,0,0},//3
	{1,0,0,0,0,0,0,0,0,1,0,0},//4
	{1,0,1,0,0,0,0,0,0,0,0,0},//5
	{0,1,0,0,0,0,0,1,0,1,0,1},//6
	{0,0,0,1,0,0,1,0,0,0,1,1},//7
	{0,0,0,0,0,0,0,0,0,1,0,0},//8
	{0,0,0,0,1,0,1,0,1,0,0,0},//9
	{0,0,0,0,0,0,0,1,0,0,0,0},//10
	{0,0,0,0,0,0,1,1,0,0,0,0}//11
};

vector<int> getRelatedVertices(int v) {
	vector<int> related;
	for (int i = 0; i < matrix[v].size(); i++) {
		if (matrix[v][i] == 1)
			related.push_back(i);
	}
	return related;
}

void traverse(int v) {
	mem.push_back(v);
	vector<int> related_vertices = getRelatedVertices(v);
	for (int i = 0; i < related_vertices.size(); i++) {
		if (find(mem.begin(), mem.end(), related_vertices[i]) != mem.end())
			continue;
		traverse(related_vertices[i]);
	}
}

int main()
{
	traverse(0);
	for (int i : mem) {
		cout << i << " ";
	}
	cout << endl;
	system("pause");
}