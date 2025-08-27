/**
 * Tatiana Gasparre
 * CPSC350-01
 */
#ifndef WGraph_H
#define WGraph_H
/**
 * An implementation of an undirected, weighted graph that also includes Minimum Spanning Tree creation
 */
#include "PQueue.h"
#include "Edge.h"
#include <iostream>
#include <stdexcept>
#include <limits>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <set>

//a weighted, undirected WGraph implemented with adjacency matrix
//fixed size

typedef unsigned int VertexID;

class WGraph{
public: 
  /**
   * WGraph - the constructor 
   */
  WGraph();
  /**
   * WGraph - the overloaded constructor
   * @param sz - the amount of nodes in the graph
   */
  WGraph(unsigned int sz);
  /**
   * ~WGraph - the destructor
   */
  ~WGraph();
  /**
   * readGraphFromFile - takes in a file that contains a size and a grid and adds the values to a weighted graph
   * populates the adjacency matrix with the values in the file
   * @param fileName - the file path of the input file
   */
  void readGraphFromFile(std::string fileName);
  /**
   * addEdge - adds an edge to the adjacency matrix of the graph
   * @param i - the first vertex of the edge
   * @param j - the second vertex of the edge
   * @param w - the weight of the edge
   */
  void addEdge(VertexID i, VertexID j, double w);
  /**
   * removeEdge - removes an edge from the adjacency matrix of the graph
   * @param i - the first vertex of the edge
   * @param j - the second vertex of the edge
   */
  void removeEdge(VertexID i, VertexID j);
  /**
   * areAdjacent - returns wether or not two vertexes are adjacent
   * @param i - the first vertex of the edge
   * @param j - the second vertex of the edge
   * @return true if they are adjacent and false otherwise
   */
  bool areAdjacent(VertexID i, VertexID j);
  /**
   * cheapestCost - returns the cheapest cost to get from the first vertex to the second
   * @param i - the first vertex
   * @param j - the destination vertex
   */
  double cheapestCost(VertexID i, VertexID j);
  /**
   * calcFW - uses the Floyd Warshall algorithm to calculate the shortest paths between all nodes
   */
  void calcFW();
  /**
   * computeMST - uses Kruskal's algorithm to caculate the minimum spanning tree and its cost
   */
  void computeMST();

private:
  /**
   * displayMST - displays the MST to the terminal
   */
  void displayMST(DblList<double> weightsInMST);
  double** m_adj; //is there an edge between two vertices and what's the weight of the edge
  double** m_conn; //more general, is there a path between a start and a finish and what's the cost (all parts summed)
  unsigned int m_size; //nodes in WGraph (fixed)

};

#endif
