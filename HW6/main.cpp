#include <iostream>
#include "Vector.hpp"

using namespace std;

int main()
{
	Vector<int> v1;
	Vector<float> v2(1);
	Vector<int> v3(v1);
	v1.push_back(11);
	v1.push_back(12);
	cout << v1[0] << " " << v1[1] << endl;
	cout << v1.at(10) << endl;
	cout << "v1.size()=" << v1.size() << endl;
	cout << "is v1 empty? " << (v1.empty() == 1 ? "flase" : "true") << endl;
	v1.clear();
	cout << "v1.size()=" << v1.size() << endl;
	cout << "is v1 empty? " << (v1.empty() == 1 ? "flase" : "true") << endl;
}