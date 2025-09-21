#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <filesystem>
#include <fstream>
#include <Stack>

using namespace std;
namespace fs = filesystem;


template <class T>
class Vect {
private:
	int size;
	T* arr;
public:
	explicit Vect() {
		size = 0;
		arr = new T[size];
	}
	void push_back(T value) {
		try {
			T* newArr = new T[size + 1];
			for (int i = 0; i < size; i++) {
				newArr[i] = arr[i];
			}
			newArr[size] = value;
			size++;
			delete[] arr;
			arr = newArr;
		}
		catch (...) {
			cout << "Error\n";
		}
	}
	void pop_back() {
		try {
			if (size == 0) {
				throw "Error";
			}
			T* newArr = new T[size - 1];
			for (int i = 0; i < size - 1; i++) {
				newArr[i] = arr[i];
			}
			size--;
			delete[] arr;
			arr = newArr;
		}
		catch (char* f) {
			cout << f;
		}
	}
	void swap(int a, int b) {
		try {
			if (a < 0 || b < 0 || a >= size || b >= size) {
				throw "Error";
			}
			T temp = arr[a];
			arr[a] = arr[b];
			arr[b] = temp;
		}
		catch (char* f) {
			cout << f;
		}
	}
	T begin() {
		try {
			if (size == 0) {
				throw "Error";
			}
			return arr[0];
		}
		catch (char* f) {
			cout << f;
			return T();
		}
	}
	T back() {
		try {
			if (size == 0) {
				throw "Error";
			}
			return arr[size - 1];
		}
		catch (char* f) {
			cout << f;
			return T();
		}
	}
	void insert(int index, T value) {
		try {
			if (index < 0 || index >= size) {
				throw "Error";
			}
			T* newArr = new T[size + 1];
			for (int i = 0; i < index; i++) {
				newArr[i] = arr[i];
			}
			newArr[index] = value;
			for (int i = index; i < size; i++) {
				newArr[i + 1] = arr[i];
			}
			size++;
			delete[] arr;
			arr = newArr;
		}
		catch (char* f) {
			cout << f;
		}
	}
	void show() {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	~Vect() {
		delete[] arr;
	}
};

string readFile(string path) {
	fstream obj1(path, ios::in);
	string txt;
	string txt2 = "";
	bool next = false;
	if (obj1.is_open()) {
		while (getline(obj1, txt)) {
			txt += "\n";
			txt2 += txt;
		}
	}
	obj1.close();
	return txt2;
}
float operation(string text, int chastka) {
	stack<string> st;
	string temp = "";
	bool nextIsMinus = false;
	for (char simv : text) {
		if (int(simv) >= 48 && int(simv) <= 57 && !nextIsMinus) {
			temp += simv;
		}
		if(int(simv) < 48 || int(simv) > 57){
			nextIsMinus = false;
			if (temp != "") {
				st.push(temp);
			}
			temp = "";
		}
		if (simv == '-') {
			nextIsMinus = true;
		}
	}
	int sum = 0;
	while (!st.empty()) {
		sum += stoi(st.top());
		cout << st.top() << "\n";
		st.pop();
	}
	return float(sum/ chastka);
}
int main()
{
	srand(time(0));
	string tex = "";
	tex = readFile("D:/Token/token.txt");
	cout << tex;
	float c = operation(tex, 3);
	cout << "Result: " << c << '\n';
	
	Vect<int> v;
	v.push_back(5);
	v.push_back(10);
	v.push_back(15);
	v.show();
	v.pop_back();
	v.show();
	v.insert(1, 20);
	v.show();
	
}
