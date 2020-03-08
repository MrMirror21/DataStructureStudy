#include <iostream>
#include <vector>
using namespace std;

int* MakeAry(int NumOfNodes) {
	int* ary = new int[NumOfNodes];
	for (int i = 0; i < NumOfNodes; i++) cin >> ary[i];
	return ary;
}

void loop(int* ary, int length) {
	int Max_depth = 0;
	for (int i = 0; i < length; i++) {
		int Gen_count = 1;
		while (ary[i] != -1) {
			ary[i] = ary[ary[i]];
			Gen_count++;
		}
		if (Gen_count > Max_depth) Max_depth = Gen_count;
	}
	cout << Max_depth;
}



int main() {
	int NumOfNodes = 0;
	cin >> NumOfNodes;
	loop(MakeAry(NumOfNodes), NumOfNodes);

	return 0;
}