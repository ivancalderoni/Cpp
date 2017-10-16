//DSA 5005 project 2

#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <class T>
class HashingTable {
	vector<list<T> > V;
	int h(const string& x) const
	{
		return x[0] - 'A'; //hashing function
	}
public:
	HashingTable(); //empty constructor
	HashingTable(int size = 0); //parameterized constructor
	HashingTable(const HashingTable& other); //copy constructor
	void operator=(const HashingTable<T>& x); //assignment operator
	virtual ~HashingTable(); //destructor
	void insert(const T& item); //insert new item to the hash table
	void remove(const T& item); //remove
	bool find(const T& item); //find item in the hash table
	void split(int index, int p); //split

	friend ostream& operator <<(ostream& s, const HashingTable<T>& object)
	{
		cout << "\nTable:\n " << endl;
		for (size_t i = 0; i < object.V.size(); i++)
		{
			s << "[" << i << "] " << "= ";
			list<T>::const_iterator cIterator;
			for (cIterator = object.V[i].cbegin(); cIterator != object.V[i].cend(); cIterator++)
			{
				s << *cIterator;
				list<T>::const_iterator cIterator2(cIterator);
				cIterator2++;
				if (cIterator2 != object.V[i].end())
				{
					s << ", ";
				}
			}
			s << endl;
		}
		return s;
	}

};

//empty constructor
template <class T>
HashingTable<T>::HashingTable()
{

}

//parameterized constructor
template <class T>
HashingTable<T>::HashingTable(int size = 0)
{
	V.resize(size);
}

//copy constructor
template <class T>
HashingTable<T>::HashingTable(const HashingTable& other) {
	V.resize(other.V.size());
	for (size_t i = 0; i < other.V.size(); i++) {
		list<T>::const_iterator cIterator;
		for (cIterator = other.V[i].cbegin(); cIterator != other.V[i].cend(); cIterator++) {
			V[i].push_back(*cIterator);
		}
	 }
}

//assignment operator
template <class T>
void HashingTable<T>::operator=(const HashingTable<T>& x)
{
		if (this != &x) {
			//create temporary copy
			HashingTable temp(x);
			//swap fields with curent object
			swap(temp.V, this->V);
		}

		return this;
}

//destructor
template <class T>
HashingTable<T>::~HashingTable()
{
	for (size_t i = 0; i < V.size(); i++) {
		V[i].clear();
	}
}

//append new item to the hash table
template <class T>
void HashingTable<T>::insert(const T& item)
{

		if (item == NULL) return;

		//calculate hash
		int i = h(item);

		//expand V bucket if necessary
		if (i >= V.size())
			V.resize(i + 1);
			//add new item
			V[i].push_back(item);
}

//remove
template <class T>
void HashingTable<T>::remove(const T& item)
{

}

//find item in hash table
template <class T>
bool HashingTable<T>::find(const T& item)
{
	if (item == NULL) return false;
	//calculate hash
	int hash = h(item);

	while (hash > 0) {
		//search list with index
		list<T>::const_iterator cIterator;
		for (cIterator = V[hash].cbegin(); cIterator != V[hash].cend(); ++cIterator) {
			if (*cIterator == item) return true;
		}

		hash = hash - 1;
	}

	return false;
}

//split
template <class T>
void HashingTable<T>::split(int index, int p)
{
	int n = V[index].size() - 1;
	int below = index - 1;
	if (V[index].size() > p) {
		n = V[index].size() - p;
	}


	list<T>::reverse_iterator rIterator = V[index].rbegin();
	if (below < 0) {
		V.resize(V.size() + 1);
		below = V.size() - 1;
	}

	//move items
	for (int i = 0; i < n; /* i++ */) {
		if (V[below].size() < p) {
			V[below].push_back(*rIterator);
			V[index].pop_back();
			rIterator = V[index].rbegin();
			i++;
		}
		else {
			below = below - 1;
			if (below < 0) {
				V.resize(V.size() + 1);
				below = V.size() - 1;
			}
		}
	}
}


void main() /* A sample main program */
{
	HashingTable<char*>* myHashTable;
	char* Names[25] = { "Andy B", "Amy Dean", "Antonio G", "Andy Roberts",
		"Brian W","Bob Macy", "Brent James", "Buck Muck",
		"Cannon James", "Cart Wright", "Catherine Zeta", "Carl Lewis",
		"David Johnson", "Dowd Peter", "Daniel Fauchier", "Dawn Smith",
		"Yarda Varda", "Yami Jacob", "Yester Louis", "Yukon Oklahoma",
		"Zandi Rich", "Zea John", "Zelby Leon", "Ziert Paul", "Zanola Helen" };

	int i;

	myHashTable = new HashingTable<char*>(25);
	for (i = 0; i < 25; i++)
		(*myHashTable).insert(Names[i]);

	cout << "Printing the hash table after inserting...." << endl;
	cout << *myHashTable << endl;

	if ((*myHashTable).find("Zandi Rich"))
		cout << "Zandi Rich is in the list" << endl;
	else
		cout << "Zandi Rich is not in the list" << endl;
	(*myHashTable).remove("Zea John");
	if ((*myHashTable).find("Zea John"))
		cout << "Zea John is in the list" << endl;
	else
		cout << "Zea John is not in the list" << endl;

	for (i = 0; i <= 25; i++)
		(*myHashTable).split(i, 2);

	//for (i = 0; i <= 25; i++)
	//	(*myHashTable).split(i, 1);

	cout << "Printing the hash table after splitting...." << endl;
	cout << *myHashTable << endl;

	if ((*myHashTable).find("Ziert Paul"))
		cout << "Ziert Paul is in the list" << endl;
	else
		cout << "Ziert Paul is not in the list" << endl;

	(*myHashTable).insert("Zea John");
	if ((*myHashTable).find("Zea John"))
		cout << "Zea John is in the list" << endl;
	else
		cout << "Zea John is not in the list" << endl;

	delete myHashTable;

	system("PAUSE");
	
}
