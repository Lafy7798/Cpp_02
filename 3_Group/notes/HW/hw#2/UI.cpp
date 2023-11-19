#include <iostream>
using namespace std;
#include "UI.h"

int UI::getMenu() {
	int menu;
	cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
	cin >> menu;
	return menu;
}

int UI::getShapeMenu() {
	int shapetype;
	cout << "선:1, 원:2, 사각형:3 >> ";
	cin >> shapetype;
	return shapetype;
}

int UI::getShapedelete() {
	int shapeIn;
	cout << "삭제하고자 하는 도형의 인덱스 >> ";
	cin >> shapeIn;
	return shapeIn;
}

void UI::printIn(string msg) {
	cout << msg << endl;
}

void UI::print(string msg) {
	cout << msg;
}

void UI::print(int msg) {
	cout << msg;
}