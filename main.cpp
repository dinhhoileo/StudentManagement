#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "Build.cpp"

class ListStudent
{
private:
    NodeStudent *head;

public:
    ListStudent()
    {
        head = nullptr;
    }
    // thêm vào đầu danh sách 1 node student
    void addToHead(Student *dataOfStudent)
    {
        NodeStudent *newNode = new NodeStudent(dataOfStudent);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    void addToTail(Student *dataOfStudent)
    {
        NodeStudent *newNode = new NodeStudent(dataOfStudent);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        NodeStudent *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = nullptr;
    }
    // tìm học sinh theo tên theo từng Node
    NodeStudent *findStudent(std::string name)
    {
        NodeStudent *temp = head;
        while (temp != nullptr)
        {
            if (temp->dataOfStudent->GetFullName() == name)
            {
                return temp;
            }
        }
        return nullptr;
    }
};

class ListSubject
{

};

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

int main(int argc, char const *argv[])
{
    // khởi tạo một listStudent
    ListStudent listStudent;

    // Tạo một bảng băm với kích thước là 10
    HashTable hashTable(10);

    // Thêm sinh viên vào bảng băm
    hashTable.addStudentInTable(new Student("Nguyen Van A", "SV001", "01/01/2000", "Ha Noi", "nguyenvana@gmail.com", "0123456789", nullptr));
    hashTable.addStudentInTable(new Student("Tran Thi B", "SV002", "02/02/2001", "Ho Chi Minh", "tranthib@gmail.com", "0123456789", nullptr));
    hashTable.addStudentInTable(new Student("Pham Van C", "SV003", "03/03/2002", "Da Nang", "phamvanc@gmail.com", "0123456789", nullptr));

    return 0;
}
