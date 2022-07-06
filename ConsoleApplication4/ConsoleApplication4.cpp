#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int p, n, kp, kn, otv = 1;
    double cp, cn, itp, itn, itogo, skidka = 0, skidkan = 0, skidkap = 0;
    string namp, namn;
    do {

        cout << "Меню:\n";
        cout << "Пицца\n\n"
            << "1. Пеперони 10 руб.\n"
            << "2. Маргарита 20 руб. \n"
            << "3. Фирменная 30 руб. \n"
            << "4. Сырная 40 руб.\n\n"
            << "Для добавления в корзину введите номер пиццы, для перехода к напиткам нажмите 0\n";
        do {
            cin >> p;
            if (p < 5 && p != 0) {
                cout << "Введите количество \n";
                cin >> kp;
            }
            switch (p) {
            case 1:
                cp = 10;
                namp = "Пеперони ";
                break;
            case 2:
                cp = 20;
                namp = "Маргарита ";
                break;
            case 3:
                cp = 30;
                namp = "Фирменная ";
                break;
            case 4:
                cp = 40;
                namp = "Сырная ";
                break;
            case 0:
                cp = 0;
                kp = 0;
                break;
            default:
                cout << "Ошибка, введено недопустимое значение, поторите ввод номера заказа.\n";
                break;
            }
        } while (p >= 5);
        cout << "Напитки\n\n"
            << "1. Чай\n"
            << "2. Сок\n"
            << "3. Пиво\n\n"
            << "Для добавления в корзину введите номер напитка, "
            << "для перехода к следующему меню нажмите нажмите 0\n";
        do {
            cin >> n;
            if (n < 4 && n != 0) {
                cout << "Введите количество \n";
                cin >> kn;
            }
            switch (n) {
            case 1:
                cn = 10;
                namn = "Чай ";
                break;
            case 2:
                cn = 20;
                namn = "Сок ";
                break;
            case 3:
                cn = 30;
                namn = "Пиво ";
                break;
            case 0:
                cn = 0;
                kn = 0;
                break;
            default: cout << "Ошибка, введено недопустимое значение, поторите ввод номера заказа.\n";
            }
        } while (n >= 4);
        if (kp == 0 && kn == 0) {
            cout << "Вы не сделали заказ. Повторить меню? 1-да 2-нет\n";
            cin >> otv;
        }
        else otv = 2;
    } while (otv == 1);
    if (kp != 0 || kn != 0) {
        system("cls");
        cout << string(30, '*') << endl;
        cout << "      Чек\n\n";
        itp = cp * kp;
        itn = cn * kn;
        if (kp >= 5) {
            itp = (kp - (kp / 5)) * cp;
            skidkap = (kp / 5) * cp;
        }
        if (cn > 2 && kn > 3) {
            skidkan = 0.15 * itn;
            itn = itn * 0.85;
        }
        itogo = itp + itn;
        if (itogo > 20) {
            skidka = itogo * 0.2;
            itogo = itogo * 0.8;
        }
        if (kp != 0)
            cout << " " << namp << " " << kp << " шт. " << itp << " руб.\n";
        if (skidkap != 0) cout << " Скидка по акции \"Каждая пятая\" " << skidkap << " руб.\n\n";
        if (kn != 0)
            cout << " " << namn << " " << kn << " шт. " << itn << " руб.\n";
        if (skidkan != 0) cout << " Скидка по акции \"Бери дороже 2 руб. более 3 шт. получи скидку\" " << skidkan << " руб.\n\n";
        if (skidka > 0) { cout << " Скидка 20 % составила " << skidka << " руб.\n"; }
        cout << " К оплате: " << itogo << " руб.\n\n";
        cout << string(30, '*') << endl;
    }
}