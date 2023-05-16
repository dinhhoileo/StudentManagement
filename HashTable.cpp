#include<iostream>
#include <string>
#include <cstring>
#include "List.cpp" 
class HashTable
{
private:
    ListStudent **Bucket; // mảng chứa các bộ nhớ
    int sizeTale;

public:
    HashTable(int sizeTable)
    {
        this->sizeTale = sizeTable;
        Bucket = new ListStudent *[sizeTable];
    }
    unsigned int hashFuction(std::string name)
    {
        int hashValue = 0;
        for (int i = 0; i < name.length(); i++)
        {
            hashValue += name[i];
        }
        return hashValue % sizeTale;
    }

    void addStudentInTable(Student *student)
    {
        unsigned int hashValue = hashFuction(student->GetFullName());
        int choice; // biến choice để tạo ra để sử dụng chọn thêm vào kiểu nào
        std::cout << "What do you want choice?:" << std::endl;
        std::cout << "1 - add to head student" << std::endl;
        std::cout << "2 - add to tail student" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            Bucket[hashValue]->addToHead(student);
            break;
        case 2:
            Bucket[hashValue]->addToTail(student);
            break;
        default:
            std::cout << "please enter right!!!" << std::endl;
            break;
        }
    }
    NodeStudent *findStudent(std::string name)
    {
        unsigned int hashValue = hashFuction(name);
        // Tìm kiếm học sinh trong danh sách liên kết tại ô có giá trị băm này
        return Bucket[hashValue]->findStudent(name);
    }
};
