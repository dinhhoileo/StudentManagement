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
    ListTerm **memoryTerm;       // mảng chứa danh sách học kỳ
    int sizeTable;

public:
    HashTable(int sizeTable)
    {
        this->sizeTable = sizeTable;
        memoryStudent = new ListStudent *[sizeTable]();
        memorySubject = new ListSubject *[sizeTable]();
        memoryClass = new ListClass *[sizeTable]();
        memoryFaculty = new ListFaculty *[sizeTable]();
        memoryTerm = new ListTerm *[sizeTable]();
    }

    unsigned int hashFunction(const std::string &name)
    {
        unsigned int hashValue = 0;
        for (char i : name)
        {
            hashValue += i;
        }
        return hashValue % sizeTable;
    }

    // thực hiện xây dựng với danh sách học sinh
    void addToStudentTable(NodeStudent *student)
    {
        unsigned int hashValue = hashFunction(student->dataOfStudent->GetFullName());
        int choice;
        std::cout << "1 - Add To Head" << std::endl;
        std::cout << "2 - Add To Tail" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            if (memoryStudent[hashValue] == nullptr)
            {
                memoryStudent[hashValue] = new ListStudent();
            }
            memoryStudent[hashValue]->addToHead(student->dataOfStudent);
            break;
        case 2:
            if (memoryStudent[hashValue] == nullptr)
            {
                memoryStudent[hashValue] = new ListStudent();
            }
            memoryStudent[hashValue]->addToTail(student->dataOfStudent);
            break;
        default:
            break;
        }
    }

    NodeStudent *findStudent(const std::string &name)
    {
        unsigned int hashValue = hashFunction(name);
        if (memoryStudent[hashValue] != nullptr)
        {
            return memoryStudent[hashValue]->findStudent(name);
        }
        return nullptr;
    }

    // thực hiện các chức năng với Môn học
    void addToSubjectToTable(NodeSubject *subject)
    {
        unsigned int hashValue = hashFunction(subject->dataOfSubject->GetIdSubject());
        int choice;
        std::cout << "1 - Add To Head" << std::endl;
        std::cout << "2 - Add To Tail" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            if (memorySubject[hashValue] == nullptr)
            {
                memorySubject[hashValue] = new ListSubject();
            }
            memorySubject[hashValue]->addToHead(subject->dataOfSubject);
            break;
        case 2:
            if (memorySubject[hashValue] == nullptr)
            {
                memorySubject[hashValue] = new ListSubject();
            }
            memorySubject[hashValue]->addToTail(subject->dataOfSubject);
            break;
        default:
            break;
        }
    }

    NodeSubject *findIdSubject(const std::string &IdSubject)
    {
        unsigned int hashValue = hashFunction(IdSubject);
        if (memorySubject[hashValue] != nullptr)
        {
            return memorySubject[hashValue]->findSubject(IdSubject);
        }
        return nullptr;
    }

    // thực hiện với các chức năng với lớp Class
    void addToClassToTable(NodeClass *classs)
    {
        unsigned int hashValue = hashFunction(classs->dataOfClass->GetNameClass());
        int choice;
        std::cout << "1 - Add To Head" << std::endl;
        std::cout << "2 - Add To Tail" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            if (memoryClass[hashValue] == nullptr)
            {
                memoryClass[hashValue] = new ListClass();
            }
            memoryClass[hashValue]->addToHead(classs->dataOfClass);
            break;
        case 2:
            if (memoryClass[hashValue] == nullptr)
            {
                memoryClass[hashValue] = new ListClass();
            }
            memoryClass[hashValue]->addToTail(classs->dataOfClass);
            break;
        default:
            break;
        }
    }

    NodeClass *findNameClass(const std::string &nameClass)
    {
        unsigned int hashValue = hashFunction(nameClass);
        if (memoryClass[hashValue] != nullptr)
        {
            return memoryClass[hashValue]->findClass(nameClass);
        }
        return nullptr;
    }

    // thực hiện với khóa
    void addToFacultyToTable(NodeFaculty *faculty)
    {
        unsigned int hashValue = hashFunction(faculty->dataOfFaculty->GetNameFaculty());
        int choice;
        std::cout << "1 - Add To Head" << std::endl;
        std::cout << "2 - Add To Tail" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            if (memoryFaculty[hashValue] == nullptr)
            {
                memoryFaculty[hashValue] = new ListFaculty();
            }
            memoryFaculty[hashValue]->addToHead(faculty->dataOfFaculty);
            break;
        case 2:
            if (memoryFaculty[hashValue] == nullptr)
            {
                memoryFaculty[hashValue] = new ListFaculty();
            }
            memoryFaculty[hashValue]->addToTail(faculty->dataOfFaculty);
            break;
        default:
            break;
        }
    }

    NodeFaculty *findNameFaculty(const std::string &nameFaculty)
    {
        unsigned int hashValue = hashFunction(nameFaculty);
        if (memoryFaculty[hashValue] != nullptr)
        {
            return memoryFaculty[hashValue]->findFaculty(nameFaculty);
        }
        return nullptr;
    }

    // thực hiện với học kỳ
    void addToTermToTable(NodeTerm *Term)
    {
        unsigned int hashValue = hashFunction(Term->dataOfTerm->GetNameTerm());
        int choice;
        std::cout << "1 - Add To Head" << std::endl;
        std::cout << "2 - Add To Tail" << std::endl;
        std::cin >> choice;
        std::cin.ignore();
        switch (choice)
        {
        case 1:
            if (memoryTerm[hashValue] == nullptr)
            {
                memoryTerm[hashValue] = new ListTerm();
            }
            memoryTerm[hashValue]->addToHead(Term->dataOfTerm);
            break;
        case 2:
            if (memoryTerm[hashValue] == nullptr)
            {
                memoryTerm[hashValue] = new ListTerm();
            }
            memoryTerm[hashValue]->addToTail(Term->dataOfTerm);
            break;
        default:
            break;
        }
    }

    NodeTerm *findNameTerm(const std::string &nameTerm)
    {
        unsigned int hashValue = hashFunction(nameTerm);
        if (memoryTerm[hashValue] != nullptr)
        {
            return memoryTerm[hashValue]->findTerm(nameTerm);
        }
        return nullptr;
    }
};

