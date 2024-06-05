#ifndef GRAPH_H
#define GRAPH_H
#include <utility>
#include <vector>
#include <climits>
#include <tuple>
#include <stdexcept>

#include "DisjointSets.hpp"
#include "MinPriorityQueue.hpp"
#include "Quicksort.hpp"

using namespace std;

const int INFINIT_COST = INT_MAX;

template <typename T>
class Graph
{
private:
	// for you to decide
	class Edge
	{
	public:
		T from;
		T to;
		int weight;

		Edge() {};
		//~Edge() {};
		Edge(T from, T to, int weight) { this->from = from; this->to = to; this->weight = weight; };
		bool operator<(const Edge& other) { return weight < other.weight; }
		bool operator>(const Edge& other) { return weight > other.weight; }
		bool operator==(const Edge& other) { return from == other.from && to == other.to; }
		bool operator!=(const Edge& other) { return from != other.from || to != other.to; }

	};
	unordered_map<T, int> vertMap;
	vector<vector<Edge>> adjList;

	
public:
	Graph();
	virtual ~Graph();
	Graph(const Graph& other) = delete;
	Graph& operator=(const Graph& other) = delete;
	void addVertex(T vertex);
	void addEdge(T from, T to, int weight = 0);
	std::vector<T> getAllNeighboursTo(T vertex);
	int getNrOfVertices() const;
	int getNrOfEdges() const;
	void MST(std::vector<std::tuple<T, T, int>>& mst, int &totalCost);
};


#endif

template<typename T>
inline Graph<T>::Graph() //empty
{
}

template<typename T>
inline Graph<T>::~Graph() //empty
{
}

template<typename T>
inline void Graph<T>::addVertex(T vertex)
{
	// Adds a vertex
	if (vertMap.count(vertex) != 0)
	{
		throw exception("Vertex already exists");
	}
	vertMap[vertex] = vertMap.size(); // plus 1 everytime
	//declare space for adjList at this index
	adjList.push_back(vector<Edge>());//syntax good? !!!!!!!!!!!!!!! without vertMap[Vertex] maybe.
}

template<typename T>
inline void Graph<T>::addEdge(T from, T to, int weight)
{
	// Adds an edge
	if (vertMap.count(from) == 0)
	{
		addVertex(from);
	}
	if (vertMap.count(to) == 0)
	{
		addVertex(to);
	}
	adjList[vertMap[from]].push_back(Edge(from, to, weight));//oriktad
	//adjList[vertMap[to]].push_back(Edge(to, from, weight));//riktad (betty adds it both ways so i wont.)


	
}

template<typename T>
inline std::vector<T> Graph<T>::getAllNeighboursTo(T vertex)
{
	// Returns all neighbors to vertex in alphabetical order 
	if (vertMap.count(vertex) == 0)
	{
		throw exception("Vertex does not exist");
	}
	vector <T> neighbours;
	for (int i = 0; i < adjList[vertMap[vertex]].size(); i++)
	{
		neighbours.push_back(adjList[vertMap[vertex]][i].to);
	}
	sort(neighbours.begin(), neighbours.end()); // is it sorted alphabetically now? !!!!!!!!!!!!
	return neighbours;
}

template<typename T>
inline int Graph<T>::getNrOfVertices() const
{
	// Returns number of vertices
	return vertMap.size();
}

template<typename T>
inline int Graph<T>::getNrOfEdges() const
{
	int totalEdges = 0;
	for (int i = 0; i < adjList.size(); i++)
	{
		totalEdges += adjList[i].size();
	}
	return totalEdges;
}


template<typename T>
inline void Graph<T>::MST(std::vector<std::tuple<T, T, int>>& mst, int& totalCost)
{
	// Creates the MST of the graph
	// Should populate the vector mst with all included edges in format tuple(from, to, weight)
	// and store the total cost of the MST in totalCost.

	//so we can create it with Prims or Kruscals? ok cool.
	// can use MPQ and QuickSort for this if we want.
	//We making Prims with Disjunkta Mängder.
	DisjointSets <T> DS;
	MinPriorityQueue <Edge> PQ; // i dont think we need this. just sort when done.
	//vector <Edge> allEdges;
	//vector <bool> visited(vertMap.size(), false); //maybe no visited?
	//visited[0] = true;
	//PQ.enqueue(adjList[0]);
	for (int i = 0; i < adjList.size(); i++)
	{
		//DS.makeSet();
		for (int j = 0; j < adjList[i].size(); j++)
		{
			PQ.enqueue(adjList[i][j]);
			DS.makeSet(adjList[i][j].from);

		}
	}

	int totalVerticies = vertMap.size();
	int nrOfEdgesInMST = 0;
	while (nrOfEdgesInMST < totalVerticies - 1)
	{
		Edge currentEdge2 = PQ.dequeue();
		if (DS.findSet(currentEdge2.from) != DS.findSet(currentEdge2.to))
		{
			DS.unionSet(currentEdge2.from,currentEdge2.to); // unite
			totalCost += currentEdge2.weight;
			mst.push_back(make_tuple(currentEdge2.from, currentEdge2.to, currentEdge2.weight));
			nrOfEdgesInMST++;
		}
	}
						//for (int i = 0; i < vertMap.size(); i++)
						//{
						//	DS.makeSet(vertMap[i]);
						//}

				//PQ.enqueue(adjList[0]);
				//for (int i = 0; i < adjList[0].size(); i++)
				//{
				//	PQ.enqueue(adjList[0][i]);
				//}
	//firxed 0th index in queue. now fix rest.

			//while (PQ.size() != 0)
			//{
			//	vector <Edge> currentEdge = PQ.dequeue();
			//	//visited[vertMap[currentEdge]] = true;
			//	for (int i = 0; i < adjList[vertMap[currentEdge].size(); i++)
			//	{
			//		PQ.enqueue(adjList[vertMap[currentEdge][i]);

			//	}
			//}
			//sort(allEdges.begin(), allEdges.end());




	//int index = 0;
	//while (nrOfEdgesInMST < totalVerticies - 1)
	//{
	//	Edge currentEdge = allEdges[index++]; // something something [index++]
	//	if (DS.findSet(currentEdge.to) != DS.findSet(currentEdge.from))
	//	{
	//		DS.makeSet(currentedg)
	//	}
	//}



}