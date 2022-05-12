// polinom.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//



#include "Parser.h"
using namespace std;
int main()
{
    int n;
    std::cout << "1.work with polinoms\n";
    std::cout << "2.exit\n";
    std::cout << ">>"; std::cin >> n;
    while (n != 2) {


        std::cout << "input first polinom\n";
        string a = "";
        std::cin.clear();
        std::cin.ignore(std::cin.rdbuf()->in_avail());
        getline(std::cin, a);
        Polinom pol1 = Parser(a).getPolinom();
        



        std::cout << "input second polinom\n";
        a = "";
        std::cin.clear();
        std::cin.ignore(std::cin.rdbuf()->in_avail());
        getline(std::cin, a);
        Polinom pol2 = Parser(a).getPolinom();

        
        int d;
        std::cout << "1.multiply polinoms\n";
        std::cout << "2.add polinoms\n";
        std::cout << "3.substract polinoms\n";
        std::cout << "4.to menu\n";
        std::cout << ">>"; std::cin >> d;
        while (d != 4) {
            switch (d) {
            case 1:
                std::cout << pol1 * pol2 << endl;
                break;
            case 2:
                std::cout << pol1 + pol2 << endl;
                break;
            case 3:
                std::cout << pol1 - pol2 << endl;
                break;
            }



            std::cout << "1.multiply polinoms\n";
            std::cout << "2.add polinoms\n";
            std::cout << "3.substract polinoms\n";
            std::cout << "4.to menu\n";
            std::cout << ">>"; std::cin >> d;

        }



        std::cout << "1.work with polinoms\n";
        std::cout << "2.exit\n";
        std::cout << ">>"; std::cin >> n;
    }


    return 0;

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
