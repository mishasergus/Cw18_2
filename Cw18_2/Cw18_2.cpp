#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <filesystem>
#include <fstream>
#include <Stack>

using namespace std;
namespace fs = filesystem;

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
	
	
}
