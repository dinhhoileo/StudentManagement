#include <iostream>
#include <string>
#include <cstring>
#include "List.cpp"
class HashTable
{
private:
    ListStudent **memoryStudent; // mảng chứa danh sách học sinh
    ListSubject **memorySubject; // mảng chứa danh sách môn học
    ListClass **memoryClass;     // mảng chứa danh sách lớp học
    ListFaculty **memoryFaculty; // mảng chứa danh sách khoa
    int sizeTable;

public:
    HashTable(int sizeTable)
    {
        this->sizeTable = sizeTable;
        memoryStudent = new ListStudent *[sizeTable];
        memorySubject = new ListSubject *[sizeTable];
        memoryClass = new ListClass *[sizeTable];
        memoryFaculty = new ListFaculty *[sizeTable];
    }

    unsigned int hashFunction(std::string name)
    {
        unsigned int hashValue = 0;
        for (auto i : name)
        {
            hashValue += i;
        }
        return hashValue % sizeTable;
    }

    // thực hiện xây dựng với danh sách học sinh
    void addToStudentTable(NodeStudent* student)
    {
        unsigned int hashValue=hashFunction(student->dataOfStudent->GetFullName());
        int choice;
        std::cout<<"1 -Add To Head"<<std::endl;
        std::cout<<"2 -Add To Tail"<<std::endl;
        std::cin>>choice;
        switch (choice)
        {
        case 1:
            memoryStudent[hashValue]->addToHead(student->dataOfStudent);
            break;
        case 2:
            memoryStudent[hashValue]->addToTail(student->dataOfStudent);
            break;
        default:
            break;
        }
    } 

    NodeStudent* findStudent(std::string name)
    {
        unsigned int hashValue= hashFunction(name);
        return memoryStudent[hashValue]->findStudent(name);
    }

};
