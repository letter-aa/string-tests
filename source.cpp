#include <iostream>
#include <vector>
using namespace std;
vector<int> getcpos(string var) {
	vector<int> cpos;
	for (int i = 0; i < var.size() - 1; i++) {
		if (var[i] == '\\') {
			i++;
			continue;
		}
		else {
			if (var[i] == '\'') {
				cpos.push_back(i);
			}
			if (var[i] == '\"') {
				cpos.push_back(i);
			}
		}
	}
	return cpos;
}
vector<string> stoc(string str, vector<int> cpos) {
	vector<string> cvcpstr; //converted cpos to str
	for (int i = 0; i < cpos.size(); i++) {
		if (i == cpos.size() - 1) {
			cvcpstr.push_back(str.substr(cpos[i]));
		}
		else {
			cvcpstr.push_back(str.substr(cpos[i], cpos[i + 1] - cpos[i] + 1));
			i++;
		}
	}
	return cvcpstr;
}
int main()
{
	string var = "dsa'hi'asd";
	string test = var.substr(var.find("'"), var.find_last_of("'") - var.find("'") + 1);
	string test1 = var.substr(var.find(test) + test.size());
	string test2 = var.substr(0, var.find(test));
	cout << "var: " << var << endl << "test: " << test << endl << "test1: " << test1 << endl << "test2: " << test2 << endl;
	cout << "-------------------------------------------------" << endl;
	string bruh = "\"hiii\"";
	vector<int> hi = getcpos(bruh);
	vector<string> strs = stoc(bruh, hi);
	for (string data : strs) {
		cout << data << endl;
	}
}
