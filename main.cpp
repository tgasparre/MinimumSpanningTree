/**
 * Tatiana Gasparre
 * CPSC350-01
 */
#include "WGraph.h"
/**
 * main creates a graph, reads in the adjacency matrix from a file (provided as a command line argument)
 * and then creates the Minimum spanning tree and outputs the results to the terminal
 */
int main(int argc, char* argv[])
{
    ifstream in(argv[1]);
    if (in.fail())
    {
        throw runtime_error("The file you provided either does not exist or couldn't be opened. Please run the program again with a different file");
    }
    int size;
    in >> size;
    in.close();

    WGraph inputGraph(size);
    inputGraph.readGraphFromFile(argv[1]);
    inputGraph.computeMST();
}
