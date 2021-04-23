#include <iostream>
#include <cmath>
#include <locale.h>
#include <Windows.h>

using namespace std;

class Triangle {
private:
    double a, b, c;
public:
    Triangle() {
        a = 0;
        b = 0;
        c = 0;
    }

    Triangle(double x, double y, double z) {
        a = x;
        b = y;
        c = z;
        cout << "Конструктор успешно сработал" << "(" << this << ")" << endl << endl;
    }

    ~Triangle() {
        cout << "Деструктор успешно сработал" << "(" << this << ")" << endl << endl;
    }

    Triangle(const Triangle& other) {
        this->a = other.a;
        this->b = other.b;
        this->c = other.c;
        cout << "Конструктор копирования успешно сработал" << "(" << this << ")" << endl << endl;
    }

    double getA() { return a; }
    double getB() { return b; }
    double getC() { return c; }

    void setA(double x) {
        while (x == 0 || x < 0) {
            cout << "Сторона не может равняться нулю" << endl << "Введите сторону А: ";
            cin >> x;
        }
        a = x;
    }

    void setB(double x) {
        while ((x == 0) || (x < 0)) {
            cout << "Сторона не может равняться нулю" << endl << "Введите сторону B: ";
            cin >> x;
        }
        b = x;
    }

    void setC(double x) {
        while ((x == 0) || (x < 0)) {
            cout << "Сторона не может равняться нулю" << endl << "Введите сторону C: ";
            cin >> x;
        }
        c = x;
    }


    void vvod()
    {
        cout << " a = ? " << endl;
        cin >> a;
        cout << " b = ? " << endl;
        cin >> b;
        cout << " c = ? " << endl;
        cin >> c;
    }

    double polup()
    {
        double p = (a + b + c) / 2;
        return p;
    }

    double square()
    {
        double p;
        p = polup();
        // double p = (a + b + c) / 2;
        double s = sqrt(p * (p - a) * (p - b) * (p - c));
        cout << "Площадь s = " << s << endl << endl;
        return s;
    }

    double opradius()
    {
        double p, s;
        p = polup();
        s = square();
        double rop = (a * b * c) / (4 * s);
        cout << "Описанный радиус = " << rop << endl << endl;
        return rop;
    }
    double vpradius()
    {
        double p, s;
        p = polup();
        s = square();
        double rv = s / p;
        cout << "Вписанный радиус = " << rv << endl << endl;
        return rv;
    }

    void tip()
    {
        while (a < b || b < c || a < c)
        {
            if (c > b)
            {
                double count = b;
                b = c;
                c = count;
            }
            if (b > a)
            {
                double count = a;
                a = b;
                b = count;
            }
            if (c > a)
            {
                double count = a;
                a = c;
                c = count;
            }
        }
        if ((b * b + c * c) == a * a)
            cout << "Прямоугольный" << endl << endl;
        else if ((b * b + c * c) > a * a)
            cout << "Остроугольный" << endl << endl;
        else if ((b * b + c * c) < a * a)
            cout << "Тупоугольный" << endl << endl;

    }

    void print()
    {
        cout << "Сторона a = " << a << "\nСторона b = " << b << "\nСторона c = " << c << endl << endl;
    }

    bool operator == (Triangle& abc)
    {

        return ((a == abc.a) && (b == abc.b) && (c == abc.c)) || ((a == abc.b) && (b == abc.c) && (c == abc.a)) || ((a == abc.c) && (b == abc.a) && (c == abc.b)) || ((a == abc.a) && (b == abc.c) && (c == abc.b)) || ((a == abc.c) && (b == abc.b) && (c == abc.a)) || ((a == abc.c) && (b == abc.b) && (c == abc.a)) || ((a == abc.b) && (b == abc.a) && (c == abc.c));
    }
};


int main()
{

    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Triangle first;
    int a = 1, i;
    system("cls");

    while (a) {
        system("cls");
        cout << "\tМеню" << endl;
        cout << "1. Ввод" << endl;
        cout << "2. Площадь" << endl;
        cout << "3. Описанный Радиус" << endl;
        cout << "4. Вписанный Радиус" << endl;
        cout << "5. Тип триугольника" << endl;
        cout << "6. Вывести значения сторон" << endl;
        cout << "7. Ввести сторну А через сеттер" << endl;
        cout << "8. Ввести сторну B через сеттер" << endl;
        cout << "9. Ввести сторну C через сеттер" << endl;
        cout << "10. Выход" << endl;
        cout << ">";
        cin >> a;
        cout << endl;

        switch (a) {
        case 1: system("cls"); first.vvod(); break;
        case 2: system("cls"); first.square(); system("pause"); break;
        case 3: system("cls"); first.opradius(); system("pause"); break;
        case 4: system("cls"); first.vpradius(); system("pause"); break;
        case 5: system("cls"); first.tip(); system("pause"); break;
        case 6: system("cls"); first.print(); system("pause"); break;
        case 7: system("cls"); cout << "Сторона А - "; cin >> i; first.setA(i); system("pause"); break;
        case 8: system("cls"); cout << "Сторона B - "; cin >> i; first.setB(i); system("pause"); break;
        case 9: system("cls"); cout << "Сторона C - "; cin >> i; first.setC(i); system("pause"); break;
        case 10: cout << "Работа завершена" << endl; return 0;
        }
    }
    return 0;
}
