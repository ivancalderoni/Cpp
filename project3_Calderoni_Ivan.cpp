//DSA 5005 project 3

#include <iostream>
#include <fstream>
#include <stack>
#include <queue>

using namespace std;

class BitMatrixGraph {
protected:
	unsigned char** bitAdjacencyMatrix;
	int n; //number of nodes/vertices in the graph
public:
	BitMatrixGraph(); //empty constructor
	BitMatrixGraph(int numNodes); //parameterized constructor that creates bit matrix of size numNodes * numNodes
	BitMatrixGraph(const BitMatrixGraph& otherGraph); //copy constructor
	~BitMatrixGraph(); //destructor
	friend ostream& operator<<(std::ostream& stream, const BitMatrixGraph& graph); //ostream operator
	BitMatrixGraph& operator=(const BitMatrixGraph& otherGraph); //overloaded =operator
	void addEdge(int u, int v); //adds an edge
	bool isAnEdge(int u, int v) const; //checks to see if there is an edge between two nodes/vertices
	int getNumberOfNodes() const; //returns the size of the matrix aka the number of nodes/vertices
};


//empty constructor
BitMatrixGraph::BitMatrixGraph()
{
	BitMatrixGraph(1000);
}


//parameterized constructor that creates bit matrix of size numNodes * numNodes
BitMatrixGraph::BitMatrixGraph(int numNodes) : n(numNodes)
{
	//create the bit adjacency matrix structure
	int size;
	if (n % 8 == 0)
		size = (n / 8);
	else
		size = (n / 8) + 1;

	//allocate memory for the matrix
	bitAdjacencyMatrix = new unsigned char *[n];
	for (int i = 0; i < n; i++) {
		bitAdjacencyMatrix[i] = new unsigned char[size];
	}

	//initialize the bit adjacency matrix structure; set all of the bits to 0
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < size; j++) {
			bitAdjacencyMatrix[i][j] = 0x00 << 8;
		}
	}
}


//copy constructor
BitMatrixGraph::BitMatrixGraph(const BitMatrixGraph &otherGraph) : n(otherGraph.n)
{
	operator=(otherGraph); //calls the = operator and makes a copy of an object
}


//destructor
BitMatrixGraph::~BitMatrixGraph()
{
	for (int i = 0; i < n; i++) {
		delete[] bitAdjacencyMatrix[i];
	}
	delete[] bitAdjacencyMatrix;
}


//ostream operator that outputs the adjacency list
ostream& operator<< (std::ostream& stream, const BitMatrixGraph& graph)
{
	for (int i = 0; i < graph.n; i++) {
		for (int j = i + 1; j < graph.n; j++) {
			if (graph.isAnEdge(i, j)) {
				stream << i << " " << j << endl;
			}
		}
	}
	return stream;
}


//overloaded = operator for two matrices objects
BitMatrixGraph& BitMatrixGraph::operator=(const BitMatrixGraph& otherGraph)
{
	for (int i = 0; i < n; i++) {
		delete[] bitAdjacencyMatrix[i];
	}
	delete[] bitAdjacencyMatrix;

	n = otherGraph.n;

	int size;

	//create the bit adjacency matrix structure
	if (n % 8 == 0)
		size = (n / 8);
	else
		size = (n / 8) + 1;

	//allocate memory for the matrix
	bitAdjacencyMatrix = new unsigned char *[n];
	for (int i = 0; i < n; i++) {
		bitAdjacencyMatrix[i] = new unsigned char[size];
	}

	//copy the data from the matrix to the other one
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < size; j++) {
			bitAdjacencyMatrix[i][j] = otherGraph.bitAdjacencyMatrix[i][j];
		}
	}
	return *this;
}


//adds an edge
void BitMatrixGraph::addEdge(int u, int v)
{
	bitAdjacencyMatrix[u][v / 8] |= 0x01 << (7 - (v % 8));
	bitAdjacencyMatrix[v][u / 8] |= 0x01 << (7 - (u % 8));
}


//checks to see if there is an edge between two nodes/vertices
bool BitMatrixGraph::isAnEdge(int u, int v) const
{
	return (bitAdjacencyMatrix[u][v / 8] & (1 << (7 - (v % 8)))) != 0;
}


//returns the size of the matrix aka the number of nodes/vertices
int BitMatrixGraph::getNumberOfNodes() const
{
	return n;
}


//page 768
//[30 pts] breadth first search (bfs) and output the parent array representation of the bfs tree
void bfs(const BitMatrixGraph& graph, int start, int* parents)
{
	int n = graph.getNumberOfNodes(); //size of the matrix/number of nodes
	bool *used = new bool[n]; //to track all the used/visited nodes
	for (int i = 0; i < n; i++) {
		used[i] = false;
	}

	parents[start] = -1;
	used[start] = true;

	queue<int> bfsQueue; //queue to store the nodes/vertices to go through
	bfsQueue.push(start);

	while (!bfsQueue.empty()) {
		int v = bfsQueue.front(); //take the first node/vertex
		bfsQueue.pop();

		for (int i = 0; i < n; i++) {
			if (!used[i] && graph.isAnEdge(v, i)) {
				//if is not visited, add its children to the queue and mark its parent
				used[i] = true;
				parents[i] = v;
				bfsQueue.push(i);
			}
		}
	}
	delete[] used;
}


//page 757
//[20 pts bonus] perform depth first search (dfs) and output the parent array representation of the dfs tree
void dfs(const BitMatrixGraph& graph, int start, int* parents)
{
	int n = graph.getNumberOfNodes(); //size of the matrix/number of nodes
	bool *used = new bool[n]; //to track all used/visited nodes
	for (int i = 0; i < n; i++) {
		used[i] = false;
	}

	parents[start] = -1;
	used[start] = true;

	stack<int> dfsStack; //stack to store the nodes/vertices to go through
	dfsStack.push(start);

	while (!dfsStack.empty())
	{
		bool isTheEnd = true; //to check if a node has no unvisited children
		int v = dfsStack.top();
		for (int i = 0; i < n; i++)
		{
			if (!used[i] && graph.isAnEdge(v, i)) {
				//if is not used/visited, add its children to the stack and mark its parent
				isTheEnd = false;
				used[i] = true;
				parents[i] = v;
				dfsStack.push(i);
				break;
			}
		}
		if (isTheEnd) {
			dfsStack.pop();
		}
	}
	delete[] used;
}


int main() {

	int n;

	//ifstream fin("input.txt"); //this text file creates the graph from page 1 of the project 3 description .pdf file
	ifstream fin("sample input file.txt"); //this text file creates the graph for the sample input file provided to us in janux
	fin >> n;
	BitMatrixGraph graph(n);

	while (!fin.eof())
	{
		int u;
		int v;
		fin >> u >> v;
		graph.addEdge(u, v);
	}

	int userInput;

	cout << "DSA 5005 - Project 3:\n" << endl;
	cout << "We are working with the graph from the file: \"sample input file.txt\"\n" << endl;
	cout << "Do you want to print the graph in the edge list format? (type 1 for yes or 0 for no): ";

	cin >> userInput;
	if (userInput == 1) {
		cout << graph << endl;
	}

	else {
		cout << "\n" << endl;
	}

	int *parents = new int[n]; //array to store the parents

	cout << "Type the starting vertex whose array of parents you want outputted Breadth First Search (BFS) style: ";
	cin >> userInput;

	cout << "\nThe array of the parents of the BFS tree is: " << endl;

	bfs(graph, userInput, parents);
	for (int i = 0; i < n; i++) {
		cout << parents[i] << " ";
	}
	cout << endl << endl;

	cout << "Type the starting vertex whose array of parents you want outputted Depth First Search (DFS) style: ";
	cin >> userInput;

	cout << "\nThe array of the parents of the DFS tree is: " << endl;
	dfs(graph, userInput, parents);
	for (int i = 0; i < n; i++) {
		cout << parents[i] << " ";
	}
	cout << endl;

	system("PAUSE");
	return 0;
}