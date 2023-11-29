#include <iostream>
#include <iomanip>
using namespace std;

class Material {
protected:
    string name;
    int amount;

public:
    Material(string _name, int _amount) : name(_name), amount(_amount) {}

    string getName() const {
        return name;
    }

    int getAmount() const {
        return amount;
    }

    void setAmount(int _amount) {
        amount = _amount;
    }

    bool subAmount(int _amount) {
        return (amount < _amount) ? false : (amount -= _amount, true);
    }
};

class Coffee : public Material {
public:
    Coffee() : Material("Coffee", 3) {}
};

class Sugar : public Material {
public:
    Sugar() : Material("Sugar", 3) {}
};

class Cream : public Material {
public:
    Cream() : Material("Cream", 3) {}
};

class Water : public Material {
public:
    Water() : Material("Water", 3) {}
};

class Cup : public Material {
public:
    Cup() : Material("Cup", 3) {}
};

class CoffeeMachine {
    Material* mat[5];

public:
    CoffeeMachine() {
        cout << "-----명품 커피 자판기 켭니다.-----\n";
        mat[0] = new Coffee(); mat[1] = new Sugar(); mat[2] = new Cream(); mat[3] = new Water(); mat[4] = new Cup();
        showCoffeeMachineState();
        cout << endl;
    }

    ~CoffeeMachine() {
        for (int i = 0; i < 5; ++i) delete mat[i];
    }

    void showCoffeeMachineState() {
        for (int i = 0; i < 5; i++) cout << setw(10) << mat[i]->getName() << string(mat[i]->getAmount(), '*') << endl;
    }

    void start() {
        int num;
        while (true) {
            showMenu();
            num = selectMenu();
            if (num == 3) {
                for (int i = 0; i < 5; i++) mat[i]->setAmount(3);
                cout << "모든 통을 채웁니다~~\n";
                showCoffeeMachineState();
                cout << endl;
                continue;
            }
            else if (num == 4) {
                cout << "프로그램을 종료합니다...\n";
                break;
            }

            if (!mat[0]->subAmount(1) || !mat[3]->subAmount(1) || !mat[4]->subAmount(1)) {
                cout << "재료가 부족합니다.\n";
                showCoffeeMachineState();
                continue;
            }

            switch (num) {
            case 0: if (!mat[2]->subAmount(1)) break;
                cout << "맛있는 보통 커피 나왔습니다~~\n"; break;
            case 1: if (!mat[1]->subAmount(1)) break;
                cout << "맛있는 설탕 커피 나왔습니다~~\n"; break;
            case 2: cout << "맛있는 블랙 커피 나왔습니다~~\n"; break;
            default: cout << "잘못 입력 하셨습니다.\n"; break;
            }
            showCoffeeMachineState();
            cout << endl;
        }
    }

    void showMenu() {
        cout << "보통 커피:0, 설탕 커피:1, 블랙 커피:2, 채우기:3, 종료:4>> ";
    }

    int selectMenu() {
        int num;
        cin >> num;
        return num;
    }
};

int main() {
    cout.setf(ios::left);
    CoffeeMachine c;
    c.start();

    return 0;
}
