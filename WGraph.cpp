/**
 * Tatiana Gasparre
 * CPSC350-01
 */
#include "WGraph.h"
using namespace std;
/**
 * An implementation of an undirected, weighted graph that also includes Minimum Spanning Tree creation
 */

/**
* WGraph - the constructor 
*/
WGraph::WGraph(){
  m_size = 0;
  m_adj = NULL;
  m_conn = NULL;
}

/**
* WGraph - the overloaded constructor
* @param sz - the amount of nodes in the graph
*/
WGraph::WGraph(unsigned int sz){
  m_size = sz;
  //allocate sz * sz adj matrix
  m_adj = new double*[sz];
  m_conn = new double*[sz];
  for(int i = 0; i < m_size; ++i){
    m_adj[i] = new double[sz];
    m_conn[i] = new double[sz];
  }
  //start with edges
  for(int i = 0; i < m_size; ++i){
    for(int j = 0; j < m_size; ++j){
      m_adj[i][j] = std::numeric_limits<double>::max(); //essentially infinity
      m_conn[i][j] = std::numeric_limits<double>::max();
    }
  }
}

/**
* ~WGraph - the destructor
*/
WGraph::~WGraph(){
  for (int i = 0; i < m_size; ++i)
  {
    delete[] m_adj[i];
    delete[] m_conn[i];
  }
  delete[] m_adj;
  delete[] m_conn;
}

/**
* readGraphFromFile - takes in a file that contains a size and a grid and adds the values to a weighted graph
* populates the adjacency matrix with the values in the file
* @param fileName - the file path of the input file
*/
void WGraph::readGraphFromFile(string fileName)
{
  ifstream in(fileName);
  if (in.fail())
  {
    throw runtime_error("The file you provided either does not exist or couldn't be opened. Please run the program again with a different file");
  }

  int i = 0;
  int j = 0;
  double edgeWeight;
  int size;
  //read in the first integer to skip it, since it represents the size we don't need it for this function
  in >> size;

  while (in >> edgeWeight)
  {
    if (m_adj[i][j] == std::numeric_limits<double>::max())  
    {
      addEdge(i, j, edgeWeight);
      m_conn[i][j] = m_adj[i][j];
      m_conn[j][i] = m_adj[j][i];

    }
    ++i;
    if (i >= m_size) // reached end of row
    {
      i = 0;
      ++j;
    }
  }
  in.close();
}

/**
* addEdge - adds an edge to the adjacency matrix of the graph
* @param i - the first vertex of the edge
* @param j - the second vertex of the edge
* @param w - the weight of the edge
*/
void WGraph::addEdge(VertexID i, VertexID j, double w){
  if(i < m_size && j < m_size){
    m_adj[i][j] = w;
    m_adj[j][i] = w;
  }
}

/**
* removeEdge - removes an edge from the adjacency matrix of the graph
* @param i - the first vertex of the edge
* @param j - the second vertex of the edge
*/
void WGraph::removeEdge(VertexID i, VertexID j){
  if(i < m_size && j < m_size){
    m_adj[i][j] = std::numeric_limits<double>::max();
    m_adj[j][i] = std::numeric_limits<double>::max();
  }
}

/**
* areAdjacent - returns wether or not two vertexes are adjacent
* @param i - the first vertex of the edge
* @param j - the second vertex of the edge
* @return true if they are adjacent and false otherwise
*/
bool WGraph::areAdjacent(VertexID i, VertexID j){
  return (m_adj[i][j] < std::numeric_limits<double>::max());
}

/**
* calcFW - uses the Floyd Warshall algorithm to calculate the shortest paths between all nodes
*/
void WGraph::calcFW(){ //runtime complexity O(v^3)
  for(int i = 0; i < m_size; ++i){
    for(int j = 0; j < m_size; ++j){
      m_conn[i][j] = m_adj[i][j]; //start with conn == adj matrix
    }
  }
  for(int im = 0; im < m_size; ++ im){ //intermediate points --> transitive closure
    for(int source = 0; source < m_size; ++source){ //source = starting point
      for(int sink = 0; sink <m_size; ++sink){ //sink = ending point
        if(source == sink){
          continue;
        }else if(m_conn[source][im] != std::numeric_limits<double>::max() &&
          m_conn[im][sink] != std::numeric_limits<double>::max() &&
          m_conn[source][sink] > m_conn[source][im] + m_conn[im][sink]){
           m_conn[source][sink] = m_conn[source][im] + m_conn[im][sink];
        }
      }
    }
  }
}

/**
* cheapestCost - returns the cheapest cost to get from the first vertex to the second
* @param i - the first vertex
* @param j - the destination vertex
*/
double WGraph::cheapestCost(VertexID i, VertexID j){
  return m_conn[i][j]; //constant
}

/**
* computeMST - uses Kruskal's algorithm to caculate the minimum spanning tree and its cost
*/
void WGraph::computeMST()
{
  PQueue<Edge> edgeQueue(true);
  //a linked list to be filled with all the edge weights inside the MST
  DblList<double> MSTResult = DblList<double>();
  //a set that contains each vertex in the graph represented as a set
  set<set<int>> allVertexes;
  for (int i = 0; i < m_size; ++i)
  {
    allVertexes.insert({i});
    for (int j = 0; j < m_size; ++j)
    {
      if (m_adj[i][j] != 0)
      {
        Edge newEdge(m_adj[i][j], i, j);
        edgeQueue.add(newEdge);
      }
    }
  }

  while (allVertexes.size() > 1 && edgeQueue.size() > 0)
  {
    Edge currentEdge = edgeQueue.peek();
    edgeQueue.remove();

    set<int> leftVertexSet;
    set<int> rightVertexSet;

    for (set<int> vSet : allVertexes)
    {
      if (vSet.find(currentEdge.vertex1) != vSet.end())
      {
        leftVertexSet = vSet;
      }
      if (vSet.find(currentEdge.vertex2) != vSet.end())
      {
        rightVertexSet = vSet;
      }
    }

    // if the two vertexes are in separate sets, that means one or both has not been visited yet 
    // their weight should be added to the MST
    if (leftVertexSet != rightVertexSet)
    {
      MSTResult.addBack(currentEdge.weight);
      allVertexes.erase(leftVertexSet);
      allVertexes.erase(rightVertexSet);

      for (int num : leftVertexSet)
      {
        rightVertexSet.insert(num);
      }
      //union set, merged the sets containing the left and right vertexes of the current edge
      allVertexes.insert(rightVertexSet);
    }
  }
  displayMST(MSTResult);
}

/**
* displayMST - displays the MST to the terminal
*/
void WGraph::displayMST(DblList<double> weightsInMST)
{
  double totalWeight = 0;
  for (int i = 0; i < weightsInMST.getSize(); ++i)
  {
    totalWeight += weightsInMST.get(i);
  }

  cout << "The MST Cost is: " << totalWeight << endl;

  for (int i = 0; i < m_size; ++i)
  {
    for (int j = 0; j < m_size; ++j)
    {
      bool isInMST = false;
      for (int pos = 0; pos < weightsInMST.getSize(); ++pos)
      {
        if (m_conn[i][j] == weightsInMST.get(pos))
        {
          isInMST = true;
        }
      }
      if (!isInMST)
      {
        m_conn[i][j] = 0;
      }
      
      if (j == 0)
      {
        cout << m_conn[i][j];
      }
      else
      {
        cout << " "  << m_conn[i][j];
      }
    }
    cout << endl;
  }

}
