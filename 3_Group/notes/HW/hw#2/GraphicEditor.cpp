#include <iostream>
using namespace std;
#include "Shape.h"
#include "Circle.h"
#include "Line.h"
#include "Rect.h"
#include "UI.h"
#include "GraphicEditor.h"

GraphicEditor::GraphicEditor() {  //포인터 초기화
	pStart = NULL;
	pLast = NULL;
}
GraphicEditor::~GraphicEditor() {  //현재 생성된 모든 객체 삭제
	Shape* p = pStart;
	while (p != pStart) {
		Shape* q = p->getNext();  //다음객체 위치로 저장
		delete p;  //현재객체 삭제
		p = q;  //다음객체로 이동
	}
}

void GraphicEditor::paint() {  //현재 생성된 모든 객체 그리기
	Shape* p = pStart;
	int i = 0;
	while (p != NULL) {
		UI::print(i);
		UI::print(": ");
		p->paint();  //도형 그려버리기
		p = p->getNext();
		i++;
	}
}

void GraphicEditor::edit() {   //도형선택과 생성
	int shapetype = UI::getShapeMenu();
	switch (shapetype) {
	case LINE:
		add(new Line()); break;
	case CIRCLE:
		add(new Circle()); break;
	case RECT:
		add(new Rect()); break;
	default:
		UI::printIn("도형 선택 오류");
	}
}

void GraphicEditor::remove(int shapeIndex) {  //shapeIndex의 원소를 삭제
	if (pLast == NULL) {
		UI::printIn("도형이 없음");
	}
	int i = 0;
	Shape* p = pStart;
	Shape* beforeP = pStart;
	if (shapeIndex == 0) {
		pStart = p->getNext();
		delete p;
		return;
	}
	while (i < shapeIndex) {
		i++;
		beforeP = p;
		p = p->getNext();
	}
	beforeP->add(p->getNext());
	delete p;
}

void GraphicEditor::remove() {  //도형삭제
	int shapeIndex = UI::getShapedelete();
	remove(shapeIndex);
}

void GraphicEditor::run() {  //그래픽에디터의 메인함수에 호출
	UI::printIn("그래픽 에디터입니다.");
	while (true) {
		int menu = UI::getMenu();
		switch (menu) {
		case EDIT:
			edit(); break;
		case REMOVE:
			remove(); break;
		case PAINT:
			paint(); break;
		case EXIT:
			return;
		}
	}
}

void GraphicEditor::add(Shape* p) {  //도형추가시 포인터 위치 추가 지정
	if (pStart == NULL) {  //도형이 없을때
		pStart = p;
		pLast = p;
	}
	else {  //도형이 있을때
		pLast->add(p);  //도형p를 마지막에 단다.
		pLast = p;
	}
}