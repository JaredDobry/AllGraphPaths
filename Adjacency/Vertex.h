#pragma once
#include <vector>
#include <iostream>
#include <string>
class Vertex
{
public:
	Vertex(int I)
	{
		ID = I;
	}
	~Vertex();

	void Print()
	{
		std::cout << "Node " << std::to_string(ID) << ", Connected to: ";
		for (int i : m_directedLinks)
		{
			std::cout << std::to_string(i) << " ";
		}
		std::cout << std::endl;
	}

	int ID;
	std::vector<int> m_directedLinks;
};

