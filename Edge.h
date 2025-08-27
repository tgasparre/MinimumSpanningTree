/**
 * Tatiana Gasparre
 * 2429174
 * gasparre@chapman.edu
 * CPSC350-01
 * A6 - Spanning the Gamut
 */
#ifndef EDGE_H
#define EDGE_H
/**
 * Edge.cpp / Edge.h creates An edge item that stores a weight and the two vertexes that it is connected to
 */

class Edge {
    public:
        /**
         * Edge - the constructor
         */
        Edge();
        /**
         * Edge - the overloaded constructor
         * @param w - the weight of the edge
         * @param v1 - the first vertex of the edge
         * @param v2 - the second vertex of the edge
         */
        Edge(double w, int v1, int v2);
        /**
         * ~Edge - the destructor
         */
        ~Edge();
        /**
         * operator> - the overloaded comparison operator >
         * @param edgeToCompare - the edge to compare 
         * @return true if the edge's weight is greater than the edge to compare's weight and false otherwise
         */
        bool operator>(const Edge& edgeToCompare);
        /**
         * operator< - the overloaded comparison operator <
         * @param edgeToCompare - the edge to compare 
         * @return true if the edge's weight is smaller than the edge to compare's weight and false otherwise
         */
        bool operator<(const Edge& edgeToCompare);
        /**
         * operator= - the overloaded assignment operator =
         * assigns the edge's weight and vertexes to the weight and vertexes of edgeToCompare
         * @param edgeToCompare - the edge to compare
         */
        void operator=(const Edge& edgeToCompare);
        /**
         * weight - the weight of the edge 
         */
        double weight;
        /**
         * vertex1 - the first vertex of the edge
         */
        int vertex1;
        /**
         * the second vertex of the edge 
         */
        int vertex2;
};


#endif 

