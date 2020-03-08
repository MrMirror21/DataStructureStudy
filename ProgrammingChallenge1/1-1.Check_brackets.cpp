#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;


void IsBalanced(string _string) {
	int num1 = -1;
	int num2 = -1;
	int num3 = -1;
	list<int> ary1{};
	list<int> ary2{};
	list<int> ary3{};
	list<int> prob{};
	list<int>::iterator iter;

	for (int i = 0; i < _string.size(); i++) {
		cout << _string[i] << endl;
		if (_string[i] == ')' || _string[i] == '}' || _string[i] == ']') {
			if (_string[i] == ')') {
				iter = prob.end();
				if (num1 != -1) {
					if (*iter != i) break;
					else {
					num1--;
					prob.remove(*ary1.begin());
					ary1.pop_back();
					}
				}
				else {
					num1--;
					prob.push_back(i);
				}
			}
			if (_string[i] == '}') {
				if (num2 != -1) {
					num2--;
					prob.remove(*ary2.begin());
					ary2.pop_back();
				}
				else {
					num2--;
					prob.push_back(i);
				}
			}
			if (_string[i] == ']') {
				if (num3 != -1) {
					num3--;
					prob.remove(*ary3.begin());
					ary3.pop_back();
				}
				else {
					num3--;
					prob.push_back(i);
				}
			}
		}
		if (_string[i] == '(' || _string[i] == '{' || _string[i] == '[') {
			if (_string[i] == '(') {
				num1++;
				prob.push_back(i);
				ary1.push_back(i);
			}
			if (_string[i] == '{') {
				num2++;
				prob.push_back(i);
				ary2.push_back(i);
			}
			if (_string[i] == '[') {
				num3++;
				prob.push_back(i);
				ary3.push_back(i);
				cout << num3 << endl;
			}
		}
		else continue;
	}
	cout << num1 << num2 << num3 << endl;
	if (num1 == -1 && num2 == -1 && num3 == -1) cout << "Success" << endl;
	else {
		try {
			iter = prob.end();
			iter--;
			cout << *iter + 1 << endl;
		}
		catch (exception&) {
			cout << *prob.begin() + 1 << endl;
		}
	}
}

int main() {
	string userinput;
	while (1) {
		cout << "Please input some string that include '(', ')', '[', ']', '{', '}' : ";
		cin >> userinput;
		if (userinput == "0") break;

		IsBalanced(userinput);
	}

	return 0;
}