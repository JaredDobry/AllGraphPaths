#include "Vertex.h"
#include "Graph.h"
#include <assert.h>
#include <iostream>
#include <string>

Graph CreateGraph(const std::vector<std::vector<int>>& adjacencyMatrix);
std::vector<std::vector<int>> GetPaths(const Graph& g);
void GetPath(int root, std::vector<std::vector<int>>& map, std::vector<int> path, const Graph& g);

int main()
{
	std::vector<std::vector<int>> adj;
	std::vector<int> row1 = { 1, 0, 1, 1 };
	std::vector<int> row2 = { 0, 1, 1, 0 };
	std::vector<int> row3 = { 1, 0, 0, 0 };
	std::vector<int> row4 = { 1, 1, 1, 1 };
	adj.push_back(row1);
	adj.push_back(row2);
	adj.push_back(row3);
	adj.push_back(row4);
	Graph g = CreateGraph(adj);
	g.Print();

	std::vector<std::vector<int>> paths = GetPaths(g);

	//output
	for (int i = 0; i < paths.size(); i++)
	{
		std::cout << "Path " << std::to_string(i) << ": ";
		for (int j = 0; j < paths[i].size(); j++)
		{
			std::cout << std::to_string(paths[i][j]) << " ";
		}
		std::cout << std::endl;
	}

	while (true)
	{
		//Hang to see the output
	}
	return 0;
}

Graph CreateGraph(const std::vector<std::vector<int>>& adjacencyMatrix)
{
	assert(!adjacencyMatrix.empty());
	assert(adjacencyMatrix.size() == adjacencyMatrix[0].size());
	Graph g = Graph(adjacencyMatrix.size());
	for (int i = 0; i < adjacencyMatrix.size(); i++)
	{
		for (int j = 0; j < adjacencyMatrix.size(); j++)
		{
			if (adjacencyMatrix[i][j] == 1)
			{
				g.AddEdge(i, j);
			}
		}
	}
	return g;
}

std::vector<std::vector<int>> GetPaths(const Graph& g)
{
	std::vector<std::vector<int>> map = std::vector<std::vector<int>>();
	for (int i = 0; i < g.m_size; i++)
	{
		std::vector<int> path = { i };
		for (int j : g.m_vertices[i].m_directedLinks)
			GetPath(j, map, path, g);
	}
	return map;
}

void GetPath(int root, std::vector<std::vector<int>>& map, std::vector<int> path, const Graph& g)
{
	//Check if the current node we are looking at already exists in the path
	for (int i : path)
	{
		if (i == root)
		{
			//If this is a self-cycle then that's ok
			if (path.size() == 1)
			{
				path.push_back(root); //Do this if you want a self-cycle to be 0->0 instead of just 0.
				//Add this path to the map if it's already not there
				auto findItr = std::find(map.begin(), map.end(), path);
				if (findItr == map.end())
					map.push_back(path);
			}
			return;
		}
	}
	//Node not in the path, add it on
	path.push_back(root);
	
	//Check if we add to the map
	auto findItr = std::find(map.begin(), map.end(), path);
	if (findItr == map.end())
		map.push_back(path);

	//Look through all of our children
	for (int i : g.m_vertices[root].m_directedLinks)
		GetPath(i, map, path, g);
}