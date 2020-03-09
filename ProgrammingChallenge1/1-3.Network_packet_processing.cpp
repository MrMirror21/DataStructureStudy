#include <iostream>

using namespace std;

int main() {
	int Size_buffer = 0;
	int numOfPacket = 0;
	cin >> Size_buffer >> numOfPacket;
	int** buffer = new int* [numOfPacket];
	for (int i = 0; i < numOfPacket; i++)
		buffer[i] = new int[2];

	for (int i = 0; i < numOfPacket; i++) {
		int _ArriveTime;
		int _ProcessingTime;
		cin >> _ArriveTime >> _ProcessingTime;
		buffer[i][0] = _ArriveTime;
		buffer[i][1] = _ProcessingTime;
	}

	int TimeNow = 0;
	for (int i = 0; i < numOfPacket; i++) {
		if (TimeNow > buffer[i][0]) {
			cout << -1 << endl;
			continue;
		}
		while (TimeNow != buffer[i][0]) {
			TimeNow++;
		}
		cout << TimeNow << endl;
		TimeNow += buffer[i][1];
	}
	

	return 0;
}