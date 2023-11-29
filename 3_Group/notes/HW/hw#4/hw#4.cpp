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
        cout << "-----��ǰ Ŀ�� ���Ǳ� �մϴ�.-----\n";
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
                cout << "��� ���� ä��ϴ�~~\n";
                showCoffeeMachineState();
                cout << endl;
                continue;
            }
            else if (num == 4) {
                cout << "���α׷��� �����մϴ�...\n";
                break;
            }

            if (!mat[0]->subAmount(1) || !mat[3]->subAmount(1) || !mat[4]->subAmount(1)) {
                cout << "��ᰡ �����մϴ�.\n";
                showCoffeeMachineState();
                continue;
            }

            switch (num) {
            case 0: if (!mat[2]->subAmount(1)) break;
                cout << "���ִ� ���� Ŀ�� ���Խ��ϴ�~~\n"; break;
            case 1: if (!mat[1]->subAmount(1)) break;
                cout << "���ִ� ���� Ŀ�� ���Խ��ϴ�~~\n"; break;
            case 2: cout << "���ִ� �� Ŀ�� ���Խ��ϴ�~~\n"; break;
            default: cout << "�߸� �Է� �ϼ̽��ϴ�.\n"; break;
            }
            showCoffeeMachineState();
            cout << endl;
        }
    }

    void showMenu() {
        cout << "���� Ŀ��:0, ���� Ŀ��:1, �� Ŀ��:2, ä���:3, ����:4>> ";
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
