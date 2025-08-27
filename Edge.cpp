/**
 * Tatiana Gasparre
 * CPSC350-01
 * A6 - Spanning the Gamut
 */
#include "Edge.h"
using namespace std;
/**
 * Edge.cpp / Edge.h creates An edge item that stores a weight and the two vertexes that it is connected to
 */

/**
* Edge - the constructor
*/
Edge::Edge()
{
    weight = 0;
    vertex1 = 0;
    vertex2 = 0;
}

/**
* Edge - the overloaded constructor
* @param w - the weight of the edge
* @param v1 - the first vertex of the edge
* @param v2 - the second vertex of the edge
*/
Edge::Edge(double w, int v1, int v2)
{
    weight = w;
    vertex1 = v1;
    vertex2 = v2;
}

/**
* ~Edge - the destructor
*/
Edge::~Edge()
{

}

/**
* operator> - the overloaded comparison operator >
* @param edgeToCompare - the edge to compare 
* @return true if the edge's weight is greater than the edge to compare's weight and false otherwise
*/
bool Edge::operator>(const Edge& edgeToCompare)
{
    return this->weight > edgeToCompare.weight;
}

/**
* operator< - the overloaded comparison operator <
* @param edgeToCompare - the edge to compare 
* @return true if the edge's weight is smaller than the edge to compare's weight and false otherwise
*/
bool Edge::operator<(const Edge& edgeToCompare)
{
    return this->weight < edgeToCompare.weight;
}

/**
* operator= - the overloaded assignment operator =
* assigns the edge's weight and vertexes to the weight and vertexes of edgeToCompare
* @param edgeToCompare - the edge to compare
*/
void Edge::operator=(const Edge& edgeToCompare)
{
    this->weight = edgeToCompare.weight;
    this->vertex1 = edgeToCompare.vertex1;
    this->vertex2 = edgeToCompare.vertex2;
}
