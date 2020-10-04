#include <iostream>

#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include "Professor.h"
#include "Functionality.h"


using namespace std;

const int COUNT_OF_RECORDS = 1000;
int main()
{
    auto* table = new Professor[COUNT_OF_RECORDS];
    int count = 0;

    int command = 0;
    for(int i = 0; i < COUNT_OF_RECORDS; i++)
    {
        cout<<"Enter command number\n";
        cout<<"1 - add new Professor\n";
        cout<<"2 - search Professor by fio\n";
        cout<<"3 - filter by department\n";
        cout<<"4 - print table\n";
        cout<<"5 - sort by fio\n";
        cout<<"6 - quit\n";
        cin>>command;
        while(cin.fail() || command <= 0 || command > 6)
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            cout<<"Failed on entering command! Try again.\n";
            cin>>command;
        }
        switch(command)
        {
            case 1:
            {

                cout<<"Enter number of department\n";
                int department = 1;

                cin>>department;
                while(cin.fail() || department <= 0 || department > 4)
                {
                    std::cin.clear();
                    std::cin.ignore(32767,'\n');
                    cout<<"Failed on entering department! Try again.\n";
                    cin>>department;
                }
                cout<<"Enter fio. 10 symbols length.\n";
                char* fio = new char[4096];
                cin>>fio;
                while(cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(32767,'\n');
                    cout<<"Failed on entering name! Try again.\n";
                    cin>>fio;
                }
                cout<<"Enter status. 1 - Assistent, 2 - Docent, 3 - Professor\n";
                int status = 0;
                cin>>status;
                while(cin.fail() || status <= 0 || status > 4)
                {
                    std::cin.clear();
                    std::cin.ignore(32767,'\n');
                    cout<<"Failed on entering department! Try again.\n";
                    cin>>status;
                }
                add(table, count, department, fio, status);
                break;
            }
            case 2:
            {
                if(count < 1)
                {
                    cout<<"There is no records in database.\n";
                    break;
                }
                cout<<"Enter query.\n";
                char buf[4096];
                cin>>buf;
                while(cin.fail())
                {
                    std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
                    std::cin.ignore(32767,'\n');
                    cout<<"Failed on entering query! Try again.\n";
                    cin>>buf;
                }
                print_one(search(table, count, buf));
                break;
            }
            case 3:
            {
                if(count < 1)
                {
                    cout<<"There is no records in database.\n";
                    break;
                }
                int criteria_department = 0;
                cout<<"Enter department number to filter\n";
                cin >> criteria_department;
                while (cin.fail() || criteria_department < 0 || criteria_department > 4)
                {
                    std::cin.clear();
                    std::cin.ignore(32767,'\n');
                    cout<<"Failed on entering department number to filter! Try again.\n";
                    cin >> criteria_department;
                }
                print_many(filter(table, count, criteria_department));
                break;
            }
            case 4:
                if(count > 0)
                print_all(table, count);
                else cout<<"There is no records in database.\n";
                break;
            case 5:
                if(count > 1)
                sort(table, count);
                else cout<<"Too small amount of records to sort.\n";
                break;
            case 6:
                return 0;
        }
    }
    return 0;
}
