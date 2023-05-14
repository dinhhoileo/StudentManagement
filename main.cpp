#include <iostream>
#include <string>
#include <cstring>
// HỌC SINH
class Student
{
private:
    std::string fullName;            // họ và tên
    std::string ID;                  // mã số sinh viên
    std::string dateOfBirth;         // ngày sinh
    std::string address;             // địa chỉ
    std::string email;               // thư điện tử email
    std::string phoneNumber;         // số điện thoại
    std::string *registeredSubjects; // danh sách môn học đã đăng ký
public:
    // constructor
    Student(std::string fullName, std::string ID, std::string dateOfBirth, std::string address, std::string email, std::string phoneNumber, std::string *registeredSubjects)
    {
        this->fullName = fullName;
        this->ID = ID;
        this->dateOfBirth = dateOfBirth;
        this->address = address;
        this->email = email;
        this->phoneNumber = phoneNumber;
        this->registeredSubjects = registeredSubjects;
    }
    std::string GetFullName() const
    {
        return this->fullName;
    }

    void SetFullName(std::string fullName)
    {
        fullName = fullName;
    }

    std::string GetID() const
    {
        return this->ID;
    }

    void SetID(std::string ID)
    {
        ID = ID;
    }

    std::string GetDateOfBirth() const
    {
        return this->dateOfBirth;
    }

    void SetDateOfBirth(std::string dateOfBirth)
    {
        dateOfBirth = dateOfBirth;
    }

    std::string GetAddress() const
    {
        return this->address;
    }

    void SetAddress(std::string address)
    {
        address = address;
    }

    std::string GetEmail() const
    {
        return this->email;
    }

    void SetEmail(std::string email)
    {
        email = email;
    }

    std::string GetPhoneNumber() const
    {
        return this->phoneNumber;
    }

    void SetPhoneNumber(std::string phoneNumber)
    {
        phoneNumber = phoneNumber;
    }

    std::string *GetRegisteredSubjects() const
    {
        return this->registeredSubjects;
    }

    void SetRegisteredSubjects(std::string *registeredSubjects)
    {
        registeredSubjects = registeredSubjects;
    }
};
// MÔN HỌC
class Subject
{
private:
    std::string nameSubject;           // tên môn học
    std::string IdSubject;             // mã môn học
    int numberOfCredits;               // số tín chỉ
    Student *registeredStudentSubject; // sinh viên đã đăng ký

public:
    // constructor
    Subject(std::string nameSubject, std::string IdSubject, int numberOfCredis, Student *registeredStudentSubject)
    {
        this->nameSubject = nameSubject;
        this->IdSubject = IdSubject;
        this->numberOfCredits = numberOfCredis;
        this->registeredStudentSubject = registeredStudentSubject;
    }
    std::string GetNameSubject() const
    {
        return this->nameSubject;
    }

    void SetNameSubject(std::string nameSubject)
    {
        nameSubject = nameSubject;
    }

    std::string GetIdSubject() const
    {
        return this->IdSubject;
    }

    void SetIdSubject(std::string IdSubject)
    {
        IdSubject = IdSubject;
    }

    int GetNumberOfCredits() const
    {
        return this->numberOfCredits;
    }

    void SetNumberOfCredits(int numberOfCredits)
    {
        numberOfCredits = numberOfCredits;
    }

    Student *GetRegisteredStudentSubject() const
    {
        return this->registeredStudentSubject;
    }

    void SetRegisteredStudentSubjects(Student *registeredStudentSubjects)
    {
        registeredStudentSubjects = registeredStudentSubjects;
    }
};

// LỚP
class Class
{
private:
    std::string idClass;           // mã lớp
    std::string nameClass;         // têm lớp
    Student *studentInClass;       // danh sách học sinh trong lớp
    Subject *subjectTaughtInClass; // danh sách môn học được dạy trong lớp

public:
    Class(std::string idClass, std::string nameClass, Student *studentInClass, Subject *subjectTaughtInClass)
    {
        this->idClass = idClass;
        this->nameClass = nameClass;
        this->studentInClass = studentInClass;
        this->subjectTaughtInClass = subjectTaughtInClass;
    }
    std::string GetIdClass() const
    {
        return idClass;
    }

    void SetIdClass(std::string idClass)
    {
        idClass = idClass;
    }

    std::string GetNameClass() const
    {
        return nameClass;
    }

    void SetNameClass(std::string nameClass)
    {
        nameClass = nameClass;
    }

    Student *GetStudentInClass() const
    {
        return studentInClass;
    }

    void SetStudentInClass(Student *studentInClass)
    {
        studentInClass = studentInClass;
    }

    Subject *GetSubjectTaughtInClass() const
    {
        return subjectTaughtInClass;
    }

    void SetSubjectTaughtInClass(Subject *subjectTaughtInClass)
    {
        subjectTaughtInClass = subjectTaughtInClass;
    }
};
// KHOA
class Faculty
{
private:
    std::string nameFaculty;   // têm khoa
    std::string idFaculty;     // mã khoa
    Class *listClassOfFaculty; // danh sách lớp thuộc khoa đó

public:
    Faculty(std::string nameFaculty, std::string idFaculty, Class *listClassOfFaculty)
    {
        this->nameFaculty = nameFaculty;
        this->idFaculty = idFaculty;
        this->listClassOfFaculty = listClassOfFaculty;
    }
    std::string GetNameFaculty() const
    {
        return nameFaculty;
    }

    void SetNameFaculty(std::string nameFaculty)
    {
        nameFaculty = nameFaculty;
    }

    std::string GetIdFaculty() const
    {
        return idFaculty;
    }

    void SetIdFaculty(std::string idFaculty)
    {
        idFaculty = idFaculty;
    }

    Class *GetListOfFaculty() const
    {
        return listClassOfFaculty;
    }

    void SetListOfFaculty(Class *listClassOfFaculty)
    {
        listClassOfFaculty = listClassOfFaculty;
    }
};

// HỌC KỲ
class Term
{
private:
    std::string idTerm;     // mã học kỳ
    std::string nameTerm;   // tên học kỳ
    Class *listClassInTerm; // danh sách các lớp học trong một học kỳ

public:
    // constructor
    Term(std::string idTerm, std::string nameTerm, Class *listClassInTerm)
    {
        this->idTerm = idTerm;
        this->nameTerm = nameTerm;
        this->listClassInTerm = listClassInTerm;
    }
    std::string GetIdTerm() const
    {
        return idTerm;
    }

    void SetIdTerm(std::string idTerm)
    {
        idTerm = idTerm;
    }

    std::string GetNameTerm() const
    {
        return nameTerm;
    }

    void SetNameTerm(std::string nameTerm)
    {
        nameTerm = nameTerm;
    }

    Class *GetListClassInTerm() const
    {
        return listClassInTerm;
    }

    void SetListClassInTerm(Class *listClassInTerm)
    {
        listClassInTerm = listClassInTerm;
    }
};

class NodeStudent
{
public:
    Student *student;
    NodeStudent *next;

public:
    NodeStudent(Student *student)
    {
        this->student = student;
        next = nullptr;
    }
};

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
    void addToHead(Student *data)
    {
        NodeStudent *newNode = new NodeStudent(data);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    void addToTail(Student *data)
    {
        NodeStudent *newNode = new NodeStudent(data);
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
            if (temp->student->GetFullName() == name)
            {
                return temp;
            }
        }
        return nullptr;
    }
};

class HashTable
{
private:
    ListStudent *listStudent;
    int sizeTale;

public:
    HashTable(ListStudent *listStudent, int sizeTable)
    {
        this->listStudent = listStudent;
        this->sizeTale = sizeTable;
    }
    ListStudent *getListStudent()
    {
        return this->listStudent;
    }
    void setListStudent(ListStudent *listStudent)
    {
        this->listStudent = listStudent;
    }

    int getSizeTale()
    {
        return this->sizeTale;
    }
    void setSizeTale(int sizeTale)
    {
        this->sizeTale = sizeTale;
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
            listStudent[hashValue].addToHead(student);
            break;
        case 2:
            listStudent[hashValue].addToTail(student);
            break;
        default:
            std::cout << "please enter right!!!" << std::endl;
            break;
        }
    }
    NodeStudent* findStudent(std::string name)
    {
        unsigned int hashValue=hashFuction(name);
        // Tìm kiếm học sinh trong danh sách liên kết tại ô có giá trị băm này
        return listStudent[hashValue].findStudent(name);
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
