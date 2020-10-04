//
// Created by strukovsky on 20.09.2020.
//

#ifndef LAB1_FUNCTIONALITY_H
#define LAB1_FUNCTIONALITY_H


#include "Professor.h"
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

void add(Professor* table, int& count, int department, char* fio, int status)
{
    table[count].department = department;
    table[count].status = status;
    table[count].fio = fio;
    count++;
}

void print_one(const Professor& p)
{
    cout<<p.fio<<"   "<<p.status<<"    "<<p.department<<endl;
}

void print_all(Professor* table, int count)
{

    cout<<"FIO       department      status\n";
    for(int i = 0; i < count; i++)
    {
        cout<<table[i].fio<<"   "<<table[i].department<<"   "<<table[i].status<<endl;
    }
}

void print_many(vector<Professor>* vec)
{
    for(Professor p : *vec)
        cout<<p.fio<<"   "<<p.department<<"   "<<p.status<<endl;
}
Professor search(Professor* table, int count, const char* query)
{
    Professor current;
    for(int i = 0; i < count; i++)
    {
        current = table[i];
        if(strcmp(current.fio,query) == 0)
            break;
    }
    return current;
}
vector<Professor>* filter(Professor* table, int count, int status)
{
    auto* result = new vector<Professor>;
    for(int i = 0; i < count; i++)
    {
        Professor current = table[i];
        if(current.status == status)
            result->push_back(table[i]);
    }
    return result;
}

void sort(Professor* table, int count)
{

    for (int i = count-1; i>=0;i--) {
        for (int j = 0; j < i; ++j) {
            if(strcmp(table[i].fio, table[j].fio) < 0)
            {
                Professor tmp = table[i];
                table[i] = table[j];
                table[j] = tmp;
            }
        }
    }
   
}

void also_sort(Professor **table, int count)
{
    Professor *tmp;
    for (int i = count-1; i>=0;i--) {
        for (int j = 0; j < i; ++j) {
            if(strcmp(table[j]->fio, table[i]->fio) > 0)
            {
                if(tmp->fio != nullptr)
                    delete tmp->fio;
                tmp->fio = new char[strlen(table[j]->fio)];

                strcpy(tmp->fio , table[j]->fio);
                tmp->status = table[j]->status;
                tmp->department = table[j]->department;

                table[j]->department = table[i]->department;
                table[j]->status = table[i]->status;
                strcpy(table[j]->fio, table[i]->fio);

                table[i]->department  = tmp->department;
                table[i]->status = tmp->status;
                strcpy(table[i]->fio, tmp->fio);


            }
        }
    }
    delete tmp;
}

#endif //LAB1_FUNCTIONALITY_H
