// polinom.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//



#include "Parser.h"
using namespace std;
int main()
{
    /*TList<string> l;
    cout << l.empty() << endl;
    l.push_back("3");
    l.push_back("123");
    l.push_back("8");
    cout << l << endl;
    cout << l.empty() << endl;
    //l.remove("123");
    cout << l << endl;
    l.push_back("1234");
    l.remove_first();
    cout << l << endl;
    l.remove_last();
    cout << l << endl;


    TList<string> plist(l);
    cout << plist << endl << endl << endl;

    for (auto it = plist.begin(); it != plist.end(); it++) {
        cout << (*it) << " ";
    }
    */

    /*Polinom fg,cg;
    fg.add(Monom(5,128));
    fg.add(Monom(6,178));
    fg.add(Monom(8,81));
    cg.add(Monom(8, 561));
    cg.add(Monom(8, 1));
    cg.add(Monom(251, 131));
    cg.add(Monom(200, 81));
    cg.add(Monom(251, 61));
    cg.add(Monom(251, 51));
    cg.add(Monom(-5, 128));
    */


    /*fg.add(Monom(5, 665));
    fg.add(Monom(-4, 564));
    fg.add(Monom(10, 231));



    cg.add(Monom(-2, 334));
    cg.add(Monom(-5, 1));

    Polinom t = fg * cg;*/

    //cout << fg << endl << -fg << endl;
    //cout << endl << fg+cg;
    //cout << endl <<fg*cg;
    /*string a="";
    getline(std::cin, a);
    Parser b(a);
    //b.lexical_analys();
    b.SyntaxisAnalis();
    std::cout << b.pol;*/


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
