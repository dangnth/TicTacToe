#include "AIwithMinMax.h"

AIwithMinMax::AIwithMinMax()
{
}


AIwithMinMax::~AIwithMinMax()
{
}

int AIwithMinMax::CheckStateMatch(int broad[3][3]) {
	//kiem tra win
	for (int i=0; i<3; ++i)
		for (int j=0; j<3; ++j)
			if (broad[i][j] != 0) {
				// ngang
				int v = j + 1;
				int count = 1;
				while (v < 3 && broad[i][v] == broad[i][j]) {
					++v; ++count;
				}
				v = j - 1;
				while (v >= 0 && broad[i][v] == broad[i][j]) {
					--v; ++count;
				}
				if (count == 3) return 1;
				// doc
				int u = i + 1;
				count = 1;
				while (u < 3 && broad[u][j] == broad[i][j]) {
					++u; ++count;
				}
				u = i - 1;
				while (u >= 0 && broad[u][j] == broad[i][j]) {
					--u; ++count;
				}
				if (count == 3) return 1;
				// cheo chinh 
				u = i + 1; v =j + 1; count = 1;
				while (u < 3 && v < 3 && broad[u][v] == broad[i][j]) {
					++u; ++v; ++count;
				}
				u = i - 1; v = j - 1; 
				while (u >= 0 && v >= 0 && broad[u][v] == broad[i][j]) {
					--u; --v; ++count;
				}
				if (count == 3) return 1;
				// cheo phu
				u = i + 1; v = j - 1; count = 1;
				while (u < 3 && v >= 0 && broad[u][v] == broad[i][j]) {
					++u; --v; ++count;
				}
				u = i - 1; v = j + 1;
				while (u >= 0 && v < 3 && broad[u][v] == broad[i][j]) {
					--u; ++v; ++count;
				}
				if (count == 3) return 1;
			}
	// kiem tra hoa/thua
	int count = 0;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (broad[i][j] != 0) count++;
			else return 0;
	if (count == 9) return -1;
	return 1;
}

edge AIwithMinMax::FindBestWay(int broad[3][3]) {
	edge bestWay;
	value = 0;
	bestWay.x = -1; bestWay.y = -1;
	long valuebestWay = -100000000;
	//
	for (int i=0; i<3; ++i)
		for (int j = 0; j < 3; ++j) {
			if (broad[i][j] == 0) {
				broad[i][j] = 1; value = 0;
				MinMax(broad, true);
				if (valuebestWay < value) {
					valuebestWay = value;
					bestWay.x = i; bestWay.y = j;
				}
				broad[i][j] = 0;
			}
		}
	return bestWay;
}

void AIwithMinMax::MinMax(int broad[3][3], bool isMinMax) {
	/* std::cout << value << std::endl;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j)
			std::cout << broad[i][j];
		std::cout << std::endl;
	}
	*/

	if (isMinMax) {
		for (int i=0; i < 3; i++) 
			for (int j = 0; j < 3; j++) {
				if (broad[i][j] == 0) {
					broad[i][j] = 1;
					value--;
					if (CheckStateMatch(broad) == 1) {
						value += 10;
						broad[i][j] = 0;
					}
					else MinMax(broad, false);
					
					broad[i][j] = 0;
				}
			}
	}
	else {
		for (int i=0; i<3; i++)
			for (int j = 0; j < 3; j++) {
				if (broad[i][j] == 0) {
					broad[i][j] = 2;
					value--;
					if (CheckStateMatch(broad) == 1) {
						value -= 10;
						broad[i][j] = 0;
					}
					else MinMax(broad, true);
					
					broad[i][j] = 0;
				}
			}
	}
}
