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
    ListTerm **memoryTerm ;     //man
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

    // thực hiện các chức năng với Môn học
    void addToSubjectToTable(NodeSubject *subject)
    {
        unsigned int hashValue=hashFunction(subject->dataOfSubject->GetIdSubject());
        int choice;
        std::cout<<"1 -Add To Head"<<std::endl;
        std::cout<<"2 -Add To Tail"<<std::endl;
        std::cin>>choice;
        switch (choice)
        {
        case 1:
            memorySubject[hashValue]->addToHead(subject->dataOfSubject);
            break;
        case 2:
            memorySubject[hashValue]->addToTail(subject->dataOfSubject);
            break;
        default:
            break;
        }
    }
    NodeSubject* findIdSubject(std::string IdSubject)    
    {
        unsigned int hashValue=hashFunction(IdSubject);
        return memorySubject[hashValue]->findSubject(IdSubject);
    }

    // thực hiện với các chức năng với lớp Class
    void addToClassToTable(NodeClass* claxx)
    {
        unsigned int hashValue=hashFunction(claxx->dataOfClass->GetNameClass());
        int choice;
        std::cout<<"1 -Add To Head"<<std::endl;
        std::cout<<"2 -Add To Tail"<<std::endl;
        std::cin>>choice;
        switch (choice)
        {
        case 1:
            memoryClass[hashValue]->addToHead(claxx->dataOfClass);
            break;
        case 2:
            memoryClass[hashValue]->addToTail(claxx->dataOfClass);
            break;
        default:
            break;
        }
    }
    NodeClass* findNameClass(std::string nameClass)
    {
        unsigned int hashValue=hashFunction(nameClass);
        return memoryClass[hashValue]->findClass(nameClass);
    }

    // thực hiện với khóa
    void addToFacultyToTable(NodeFaculty* faculty)
    {
        unsigned int hashValue=hashFunction(faculty->dataOfFaculty->GetNameFaculty());
        int choice;
        std::cout<<"1 -Add To Head"<<std::endl;
        std::cout<<"2 -Add To Tail"<<std::endl;
        std::cin>>choice;
        switch (choice)
        {
        case 1:
            memoryFaculty[hashValue]->addToHead(faculty->dataOfFaculty);
            break;
        case 2:
            memoryFaculty[hashValue]->addToTail(faculty->dataOfFaculty);
            break;
        default:
            break;
        }
    }
    NodeFaculty* findNameFaculty(std::string nameFaculty)
    {
        unsigned int hashValue=hashFunction(nameFaculty);
        return memoryFaculty[hashValue]->findFaculty(nameFaculty);
    }
    // thực hiện với học kỳ
    void addToTermToTable(NodeTerm* Term)
    {
        unsigned int hashValue=hashFunction(Term->dataOfTerm->GetNameTerm());
        int choice;
        std::cout<<"1 -Add To Head"<<std::endl;
        std::cout<<"2 -Add To Tail"<<std::endl;
        std::cin>>choice;
        switch (choice)
        {
        case 1:
            memoryTerm[hashValue]->addToHead(Term->dataOfTerm);
            break;
        case 2:
            memoryTerm[hashValue]->addToTail(Term->dataOfTerm);
            break;
        default:
            break;
        }
    }
    NodeTerm* findNameTerm(std::string nameTerm)
    {
        unsigned int hashValue=hashFunction(nameTerm);
        return memoryTerm[hashValue]->findTerm(nameTerm);
    }
};
