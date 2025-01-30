#include <iostream>
#include <string>
using namespace std;

class Record
{
    public:
    string name;
    double grade;
};

/*Creates Dynamic Record Array*/
Record* ClassSize(int& size)
{
    while(true)
    {
        cout << "Enter Class Size: ";
        cin >> size;

        if(size > 0)
        {
            Record* records = new Record[size];
            return records;
        }
    }
}

void GetNames(Record* records,int size)
{
    for(int i = 0;i < size;i += 1)
    {
        cout << "Enter name of student " << (i + 1) << ": ";
        getline(cin,records[i].name);
    }
}

void GetGrades(Record* records,int size)
{
    for(int i = 0;i < size;i += 1)
    {
        while(true)
        {
            cout << "Enter grade for " << records[i].name << ": ";
            cin >> records[i].grade;

            if(records[i].grade >= 0 && records[i].grade)
            {
                break;
            }
        }
    }
}