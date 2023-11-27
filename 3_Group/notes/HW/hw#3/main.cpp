#include <iostream>
#include <string>
#include <vector>
#include "Shape.h"
#include "Circle.h"
#include "Line.h"
#include "Rect.h"
using namespace std;

int main() {

	vector<Shape*> v;
	vector<Shape*>::iterator it;
	int num;
	int num2;
	cout << "그래픽 에디터입니다" << endl;
	while (true) {
        cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
        cin >> num;
        if (num == 4)
            break;
        if (num == 1)
        {
            cout << "선:1, 원:2, 사각형:3 >> ";
            cin >> num2;
            if (num2 == 1)
            {
                v.push_back(new Line);
            }
            if (num2 == 2)
            {
                v.push_back(new Circle);
            }
            if (num2 == 3)
            {
                v.push_back(new Rect);
            }
        }
        if (num == 2)
        {
            cout << "삭제하고자 하는 도형의 인덱스 >> ";
            cin >> num2;
            it = v.begin();
            int i = 0;
            while (it != v.end())
            {
                if (i == num2)
                {
                    it = v.erase(it);
                    break;
                }
                else
                {
                    it++;
                    i++;
                }
            }
        }
        if (num == 3)
        {
            int i;
            for (it = v.begin(), i = 0; it != v.end(); it++, i++)
            {
                Shape* temp = *it;
                cout << i << ": ";
                temp->paint();
            }
        }
    }
}

	
	


