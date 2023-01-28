

// 17.01.23.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
#pragma warning(disable:4996)
struct Human {
    char* name;
    int height;
    int old;
    int weight;
};
void add(int& size, Human*& pup) {
    size += 1;
    char nam[255];
    if (size == 1) {
        pup = new Human[size];
        cout << "введите имя\n";
        cin.getline(nam, 255);
        nam[0] = toupper(nam[0]);
        cout << strlen(nam) + 1;
        pup[size - 1].name = new char[strlen(nam) + 1];
        strcpy_s(pup[size - 1].name, strlen(nam) + 1, nam);
        cout << "сколько лет\n";
        cin >> pup[size - 1].old;
        cout << "высота\n";
        cin >> pup[size - 1].height;
        cout << "вес\n";
        cin >> pup[size - 1].weight;
    }
    if (size > 1) {
        cin.ignore();
        Human* pup2 = new Human[size];

        for (int i = 0; i < size - 1; i++) {
            pup2[i].weight = pup[i].weight;
            pup2[i].height = pup[i].height;
       
            pup2[i].old = pup[i].old;
    
            for (int i = 0; i < size - 1; i++) {
                pup2[i].name = new char[strlen(pup[i].name) + 1];
                for (int j = 0; j < strlen(pup[i].name) + 1; j++) {
                    if (pup2[i].name[j] == '\0')
                        break;
                    pup2[i].name[j] = pup[i].name[j];
                }
            }
        }
        for (int i = 0; i < size - 1; i++)
            delete[]pup[i].name;
        delete[]pup;
        pup = new Human[size];
        for (int i = 0; i < size - 1; i++) {
            pup[i].weight = pup2[i].weight;
            pup[i].height = pup2[i].height;
            pup[i].old = pup2[i].old;
            for (int i = 0; i < size - 1; i++) {
                pup[i].name = new char[strlen(pup2[i].name) + 1];
                for (int j = 0; j < strlen(pup2[i].name) + 1; j++) {
                    if (pup[i].name[j] == '\0')
                        break;
                    pup[i].name[j] = pup2[i].name[j];
                }
            }
        }

        cout << "введите имя\n";
        cin.getline(nam, 255);
        nam[0] = toupper(nam[0]);
        pup[size - 1].name = new char[strlen(nam) + 1];
        strcpy_s(pup[size - 1].name, strlen(nam) + 1, nam);
        cout << "сколько лет\n";
        cin >> pup[size - 1].old;
   
        cout << "высота\n";
        cin >> pup[size - 1].height;
        cout << "вес\n";
        cin >> pup[size - 1].weight;
        for (int i = 0; i < size - 1; i++)
            delete[]pup2[i].name;
        delete[]pup2;

    }
}
void prin(Human* h, int size) {
    for (int i = 0; i < size; i++) {
        cout << "высота ";
        cout << h[i].height << endl;
        cout << "вес ";
        cout << h[i].weight << endl;
        cout << "сколько лет ";
        cout << h[i].old << endl;
        cout << "имя ";
        cout << h[i].name << endl;
    }
}
void sort(Human*& h, int size) {
    for (int i = 0; i < size; i++) {
        int namindex = 0;
        if (i + 1 != size) {
            for (int i = 0; i < size; i++) {
                for (int j = i + 1; j < size; j++) {
                    if ((int)h[i].name[0] > (int)h[j].name[0]) {
                        swap(h[i], h[j]);
                    }
                
                }
            }
        }
    }

}
int main()
{
    int size = 0;
    Human* h;
    add(size, h);
    sort(h, size);
    prin(h, size);
    add(size, h);
    sort(h, size);
    prin(h, size);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

