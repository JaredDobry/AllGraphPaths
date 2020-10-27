#pragma once
#include "Vertex.h"
#include <assert.h>
#include <iostream>
#include <string>
class Graph
{
public:
	Graph(int N)
	{
		m_size = N;
		for (int i = 0; i < N; i++)
		{
			Vertex v = Vertex(i);
			m_vertices.push_back(v);
		}
	}
	~Graph();

	void AddEdge(int parent, int child)
	{
		assert(parent >= 0 && parent <= m_vertices.size() - 1);
		assert(child >= 0 && child <= m_vertices.size() - 1);
		m_vertices[parent].m_directedLinks.push_back(m_vertices[child].ID);
	}

	void Print()
	{
		std::cout << "Graph of size " << std::to_string(m_size) << ":" << std::endl;
		for (int i = 0; i < m_vertices.size(); i++)
			m_vertices[i].Print();
	}

	int m_size;
	std::vector<Vertex> m_vertices;
};

