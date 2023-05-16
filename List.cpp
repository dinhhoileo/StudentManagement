#include <string>
#include <cstring>
#include "Class.cpp"

// DỮ LIỆU LỚP HỌC SINH
class NodeStudent
{
public:
    Student *dataOfStudent;
    NodeStudent *next;
    // constructor
    NodeStudent(Student *dataOfStudent)
    {
        this->dataOfStudent = dataOfStudent;
        next = nullptr;
    }
};
// DỮ LIỆU LỚP MÔN HỌC
class NodeSubject
{
public:
    Subject *dataOfSubject;
    NodeSubject *next;
    // constructor
    NodeSubject(Subject *dataOfSubject)
    {
        this->dataOfSubject = dataOfSubject;
        next = nullptr;
    }
};

// DỮ LIỆU CỦA LỚP CLASS
class NodeClass
{
public:
    Class *dataOfClass;
    NodeClass *next;
    // constructor
    NodeClass(Class *dataOfClass)
    {
        this->dataOfClass = dataOfClass;
        next = nullptr;
    }
};

// DỮ LIỆU CỦA LỚP KHOA
class NodeFaculty
{
public:
    Faculty *dataOfFaculty;
    NodeFaculty *next;
    // constructor
    NodeFaculty(Faculty *dataOfFaculty)
    {
        this->dataOfFaculty = dataOfFaculty;
        NodeFaculty *next;
    }
};
// DỮ LIỆU CỦA LỚP HỌC KỲ
class NodeTerm
{
public:
    Term *dataOfTerm;
    NodeTerm *next;
    // constructor
    NodeTerm(Term *dataOfTerm)
    {
        this->dataOfTerm = dataOfTerm;
        next = nullptr;
    }
};
// danh sách lưa trữ học sinh
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
    // thêm vào cuối danh sách một node
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
    // sửa Học sinh theo tên
    void editStudent(std::string name, Student *newDataOfStudent)
    {
        NodeStudent *studentNode = findStudent(name);
        if (studentNode != nullptr)
        {
            studentNode->dataOfStudent = newDataOfStudent;
        }
    }
};
// danh sách lưa trữ các môn học
class ListSubject
{
private:
    NodeSubject *head;

public:
    ListSubject()
    {
        head = nullptr;
    }

    void addToHead(Subject *dataOfSubject)
    {
        NodeSubject *newNode = new NodeSubject(dataOfSubject);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void addToTail(Subject *dataOfSubject)
    {
        NodeSubject *newNode = new NodeSubject(dataOfSubject);
        if (head == nullptr)
        {
            addToHead(dataOfSubject);
            return;
        }
        NodeSubject *temp = head;
        while (temp != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    // tìm kiếm môn học
    NodeSubject *findSubject(std::string nameSubject)
    {
        NodeSubject *temp = head;
        while (temp != nullptr)
        {
            if (temp->dataOfSubject->GetIdSubject() == nameSubject)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
    // sửa thông tin một lớp môn học
    void editSubject(std::string nameSubject, Subject *newDataOfSubject)
    {
        NodeSubject *newNodeSubject = findSubject(nameSubject);
        if (newNodeSubject != nullptr)
        {
            newNodeSubject->dataOfSubject = newDataOfSubject;
        }
    }
};

class ListClass
{
private:
    NodeClass *head;

public:
    ListClass()
    {
        head = nullptr;
    }

    void addToHead(Class *dataOfClass)
    {
        NodeClass *newNode = new NodeClass(dataOfClass);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void addToTail(Class *dataOfClass)
    {
        NodeClass *newNode = new NodeClass(dataOfClass);
        if (head == nullptr)
        {
            addToHead(dataOfClass);
            return;
        }
        NodeClass *temp = head;
        while (temp != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    // tìm kiếm môn học
    NodeClass *findClass(std::string nameClass)
    {
        NodeClass *temp = head;
        while (temp != nullptr)
        {
            if (temp->dataOfClass->GetIdClass() == nameClass)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
    // sửa thông tin một lớp môn học
    void editClass(std::string nameClass, Class *newDataOfClass)
    {
        NodeClass *newNodeClass = findClass(nameClass);
        if (newNodeClass != nullptr)
        {
            newNodeClass->dataOfClass = newDataOfClass;
        }
    }
};

class ListFaculty
{
private:
    NodeFaculty *head;

public:
    ListFaculty()
    {
        head = nullptr;
    }

    void addToHead(Faculty *dataOfFaculty)
    {
        NodeFaculty *newNode = new NodeFaculty(dataOfFaculty);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void addToTail(Faculty *dataOfFaculty)
    {
        NodeFaculty *newNode = new NodeFaculty(dataOfFaculty);
        if (head == nullptr)
        {
            addToHead(dataOfFaculty);
            return;
        }
        NodeFaculty *temp = head;
        while (temp != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    // tìm kiếm môn học
    NodeFaculty *findFaculty(std::string nameFaculty)
    {
        NodeFaculty *temp = head;
        while (temp != nullptr)
        {
            if (temp->dataOfFaculty->GetIdFaculty() == nameFaculty)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
    // sửa thông tin một lớp môn học
    void editFaculty(std::string nameFaculty, Faculty *newDataOfFaculty)
    {
        NodeFaculty *newNodeFaculty = findFaculty(nameFaculty);
        if (newNodeFaculty != nullptr)
        {
            newNodeFaculty->dataOfFaculty = newDataOfFaculty;
        }
    }
};
