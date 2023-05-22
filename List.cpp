#include <iostream>
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
    NodeStudent();
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
    NodeSubject();
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
    NodeClass();
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
    NodeFaculty();
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
    NodeTerm();
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
                temp->dataOfStudent->outputInformation();
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
    void editChosseStudent(NodeStudent *foundStudent)
    {
        while (true)
        {
            char choice;
            std::cout << "1 - Edit Name" << std::endl;
            std::cout << "2 - Edit ID" << std::endl;
            std::cout << "3 - Edit Date Of Birth" << std::endl;
            std::cout << "4 - Edit Address" << std::endl;
            std::cout << "5 - Edit Email" << std::endl;
            std::cout << "6 - Edit Phone Number:" << std::endl;
            std::cout << "Do you want to exit (y/Y): ";
            std::cin.get(choice);
            std::cin.ignore(); // Xóa bộ đệm đệm đầu dòng
            if (choice == '1')
            {
                std::string editName;
                std::cout << "Edit Name:";
                std::getline(std::cin, editName);
                foundStudent->dataOfStudent->SetFullName(editName);
            }
            else if (choice == '2')
            {
                std::string editId;
                std::cout << "Edit Id:";
                std::getline(std::cin, editId);
                foundStudent->dataOfStudent->SetID(editId);
            }
            else if (choice == '3')
            {
                std::string editBirth;
                std::cout << "Edit Birth:";
                std::getline(std::cin, editBirth);
                foundStudent->dataOfStudent->SetDateOfBirth(editBirth);
            }
            else if (choice == '4')
            {
                std::string editAddress;
                std::cout << "Edit Address:";
                std::getline(std::cin, editAddress);
                foundStudent->dataOfStudent->SetAddress(editAddress);
            }
            else if (choice == '5')
            {
                std::string editEmail;
                std::cout << "Edit Email:";
                std::getline(std::cin, editEmail);
                foundStudent->dataOfStudent->SetEmail(editEmail);
            }
            else if (choice == 'y' || choice == 'Y')
            {
                break; // Thoát khỏi vòng lặp while
            }
        }
    }

    // sửa Học sinh theo tên
    void editStudent(std::string name, Student *newDataOfStudent)
    {
        NodeStudent *studentNode = findStudent(name);
        if (studentNode != nullptr)
        {
            editChosseStudent(studentNode);
        }
    }
    void displayStudent()
    {
        NodeStudent *temp = head;
        while (temp != nullptr)
        {
            temp->dataOfStudent->outputInformation();
            temp = temp->next;
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
    void editChosse()
    {
        while (true)
        {
            // std::cout << "" char chosse;
        }
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
    void displaySubject()
    {
        NodeSubject *temp = head;
        while (temp != nullptr)
        {
            temp->dataOfSubject->outputInformation();
            temp = temp->next;
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
    void displayClass()
    {
        NodeClass *temp = head;
        while (temp != nullptr)
        {
            temp->dataOfClass->outputInformation();
            temp = temp->next;
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
    void displayFaculty()
    {
        NodeFaculty *temp = head;
        while (temp != nullptr)
        {
            temp->dataOfFaculty->outputInformation();
            temp = temp->next;
        }
    }
};

class ListTerm
{
private:
    NodeTerm *head;

public:
    ListTerm()
    {
        head = nullptr;
    }

    void addToHead(Term *dataOfTerm)
    {
        NodeTerm *newNode = new NodeTerm(dataOfTerm);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void addToTail(Term *dataOfTerm)
    {
        NodeTerm *newNode = new NodeTerm(dataOfTerm);
        if (head == nullptr)
        {
            addToHead(dataOfTerm);
            return;
        }
        NodeTerm *temp = head;
        while (temp != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    // tìm kiếm môn học
    NodeTerm *findTerm(std::string nameTerm)
    {
        NodeTerm *temp = head;
        while (temp != nullptr)
        {
            if (temp->dataOfTerm->GetIdTerm() == nameTerm)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
    // sửa thông tin một lớp môn học
    void editTerm(std::string nameTerm, Term *newDataOfTerm)
    {
        NodeTerm *newNodeTerm = findTerm(nameTerm);
        if (newNodeTerm != nullptr)
        {
            newNodeTerm->dataOfTerm = newDataOfTerm;
        }
    }
    void displayTerm()
    {
        NodeTerm *temp = head;
        while (temp != nullptr)
        {
            temp->dataOfTerm->outputInformation();
            temp = temp->next;
        }
    }
};
int main()
{
    // Một ví dụ sử dụng các chức năng trong lớp ListStudent
    ListStudent studentList;
    Student *student1 = new Student();
    student1->putInformationStudent();
    studentList.addToHead(student1);

    Student *student2 = new Student();
    student2->putInformationStudent();
    studentList.addToTail(student2);

    std::string searchName;
    std::cout << "Search Name:";
    std::getline(std::cin, searchName);
    NodeStudent *foundStudent = studentList.findStudent(searchName);
    if (foundStudent != nullptr)
    {
        foundStudent->dataOfStudent->outputInformation();
        std::cin.ignore();
    }
    else
    {
        std::cout << "Student not found." << std::endl;
    }

    Student *newStudentData = new Student();
    std::string editName;
    std::cout << "Edit Name: ";
    std::getline(std::cin, editName);
    studentList.editStudent(editName, newStudentData);



    studentList.displayStudent();

    return 0;
}
