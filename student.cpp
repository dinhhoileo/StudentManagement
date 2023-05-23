#include <iostream>
#include <string>
#include <cstring>

// Khai báo lớp Student để đại diện cho một học sinh
class Student
{
private:
    std::string name;
    std::string id;
    std::string className;
    float gpa;

public:
    Student(std::string name, std::string id, std::string className, float gpa)
    {
        this->name = name;
        this->id = id;
        this->className = className;
        this->gpa = gpa;
    }

    // Phương thức để in thông tin của một học sinh
    void printInfo()
    {
        std::cout << "Name: " << this->name << std::endl;
        std::cout << "ID: " << this->id << std::endl;
        std::cout << "Class: " << this->className << std::endl;
        std::cout << "GPA: " << this->gpa << std::endl;
    }

    // Phương thức để lấy mã sinh viên của học sinh
    std::string getName()
    {
        return this->name;
    }
    void setName(std::string name)
    {
        this->name = name;
    }

    std::string getId()
    {
        return this->id;
    }
    void setId(std::string id)
    {
        this->id = id;
    }

    std::string getClassName()
    {
        return this->className;
    }
    void setClassName(std::string className)
    {
        this->className = className;
    }

    float getGpa()
    {
        return this->gpa;
    }
    void setGpa(float gpa)
    {
        this->gpa = gpa;
    }
};

class Subject
{
private:
    std::string nameSubject; // tên môn học
    std::string IdSubject;   // mã môn học
    int numberOfCredits;     // số tín chỉ
public:
    Subject(std::string nameSubject, std::string IdSubject, int numberOfCredits)
    {
        this->nameSubject = nameSubject;
        this->IdSubject = IdSubject;
        this->numberOfCredits = numberOfCredits;
    }
    std::string getNameSubject()
    {
        return this->nameSubject;
    }
    void setNameSubject(std::string nameSubject)
    {
        this->nameSubject = nameSubject;
    }

    std::string getIdSubject()
    {
        return this->IdSubject;
    }
    void setIdSubject(std::string IdSubject)
    {
        this->IdSubject = IdSubject;
    }

    int getNumberOfCredits()
    {
        return this->numberOfCredits;
    }
    void setNumberOfCredits(int numberOfCredits)
    {
        this->numberOfCredits = numberOfCredits;
    }
    void printInforSubject()
    {
        std::cout << "Name Subject: " << this->nameSubject << std::endl;
        std::cout << "Id Subject: " << this->IdSubject << std::endl;
        std::cout << "Number of Credits: " << this->numberOfCredits << std::endl;
    }
};

class Class
{
private:
    std::string idClass;   // mã lớp
    std::string nameClass; // têm lớp
public:
    Class(std::string idClass, std::string nameClass)
    {
        this->idClass = idClass;
        this->nameClass = nameClass;
    }
    std::string getIdClass()
    {
        return this->idClass;
    }
    void setIdClass(std::string idClass)
    {
        this->idClass = idClass;
    }

    std::string getNameClass()
    {
        return this->nameClass;
    }
    void setNameClass(std::string nameClass)
    {
        this->nameClass = nameClass;
    }

    void printInforClass()
    {
        std::cout << "Id Class:" << this->idClass << std::endl;
        std::cout << "Name Class:" << this->nameClass << std::endl;
    }
};

class Faculty
{
private:
    std::string nameFaculty; // têm khoa
    std::string idFaculty;   // mã khoa
public:
    Faculty(std::string nameFaculty, std::string idFaculty)
    {
        this->nameFaculty = nameFaculty;
        this->idFaculty = idFaculty;
    }
    std::string getNameFaculty()
    {
        return this->nameFaculty;
    }
    void setNameFaculty(std::string nameFaculty)
    {
        this->nameFaculty = nameFaculty;
    }

    std::string getIdFaculty()
    {
        return this->idFaculty;
    }
    void setIdFaculty(std::string idFaculty)
    {
        this->idFaculty = idFaculty;
    }
    void printInforFaculty()
    {
        std::cout << "Name Faculty:" << this->nameFaculty << std::endl;
        std::cout << "Id Facylty:" << this->idFaculty << std::endl;
    }
};

class Term
{
private:
    std::string idTerm;   // mã học kỳ
    std::string nameTerm; // tên học kỳ
public:
    Term(std::string idTerm, std::string nameTerm)
    {
        this->idTerm = idTerm;
        this->nameTerm = nameTerm;
    }
    std::string getIdTerm()
    {
        return this->idTerm;
    }
    void setIdTerm(std::string idTerm)
    {
        this->idTerm = idTerm;
    }

    std::string getNameTerm()
    {
        return this->nameTerm;
    }
    void setNameTerm(std::string nameTerm)
    {
        this->nameTerm = nameTerm;
    }
    void printInforTerm()
    {
        std::cout << "Id Term:" << this->idTerm << std::endl;
        std::cout << "Name Term:" << this->nameTerm << std::endl;
    }
};

// Khai báo lớp StudentNode để đại diện cho một nút trong danh sách liên kết các học sinh
class StudentNode
{
public:
    Student *student;
    StudentNode *next;

    // constructor
    StudentNode(Student *student)
    {
        this->student = student;
        next = nullptr;
    }
};

class StudentList
{
private:
    StudentNode *head;

public:
    StudentList()
    {
        head = nullptr;
    }
    void addToHead(Student *student)
    {
        StudentNode *newNode = new StudentNode(student);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    void addToTail(Student *student)
    {
        if (head == nullptr)
        {
            addToHead(student);
            return;
        }
        StudentNode *newNode = new StudentNode(student);
        StudentNode *temp = head;
        while (temp != nullptr)
        {
            temp = temp->next;
        }
        newNode->next = temp;
        temp = newNode;
    }
    StudentNode *findStudent(std::string id)
    {
        StudentNode *temp = head;
        while (temp != nullptr)
        {
            if (temp->student->getId() == id)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};

class SubjectNode
{
public:
    Subject *subject;
    SubjectNode *next;

    // constructor
    SubjectNode(Subject *subject)
    {
        this->subject = subject;
        next = nullptr;
    }
};

class SubjectList
{
private:
    SubjectNode *head;

public:
    SubjectList()
    {
        head = nullptr;
    }
    void addToHead(Subject *subject)
    {
        SubjectNode *newNode = new SubjectNode(subject);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    void addToTail(Subject *subject)
    {
        if (head == nullptr)
        {
            addToHead(subject);
        }
        SubjectNode *newNode = new SubjectNode(subject);
        SubjectNode *temp = head;
        while (temp != nullptr)
        {
            temp = temp->next;
        }
        newNode->next = temp;
        temp = newNode;
    }
    SubjectNode *findSubject(std::string idSubject)
    {
        SubjectNode *temp = head;
        while (temp != nullptr)
        {
            if (temp->subject->getIdSubject() == idSubject)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};
class ClassNode
{
public:
    Class *dataClass;
    ClassNode *next;

    ClassNode(Class *dataClass)
    {
        this->dataClass = dataClass;
        next = nullptr;
    }
};
class ClassList
{
private:
    ClassNode *head;

public:
    ClassList()
    {
        head = nullptr;
    }
    void addToHeadClass(Class *dataClass)
    {
        ClassNode *newNode = new ClassNode(dataClass);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    void addToTailClass(Class *dataClass)
    {
        if (head == nullptr)
        {
            addToHeadClass(dataClass);
            return;
        }
        ClassNode *temp = head;
        ClassNode *newNode = new ClassNode(dataClass);
        while (temp != nullptr)
        {
            temp = temp->next;
        }
        newNode->next = newNode;
        temp = newNode;
    }

    ClassNode *findClass(std::string idClass)
    {
        ClassNode *temp = head;
        while (temp != nullptr)
        {
            if (temp->dataClass->getIdClass() == idClass)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};

class TermNode
{
public:
    Term *term;
    TermNode *next;
    TermNode(Term *term)
    {
        this->term = term;
        next = nullptr;
    }
};

class TermList
{
private:
    TermNode *head;

public:
    TermList()
    {
        head = nullptr;
    }
    void addToHead(Term *term)
    {
        TermNode *newNode = new TermNode(term);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    void addToTail(Term *term)
    {
        if (head == nullptr)
        {
            addToHead(term);
            return;
        }
        TermNode *temp = head;
        TermNode *newNode = new TermNode(term);
        while (temp != nullptr)
        {
            temp = temp->next;
        }
        newNode->next = temp;
        temp = newNode;
    }
    TermNode *findTerm(std::string idTerm)
    {
        TermNode *temp = head;
        while (temp != nullptr)
        {
            if (temp->term->getIdTerm() == idTerm)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};

class HashTable
{
private:
    StudentList **tableStudent;
    SubjectList **tableSubject;
    ClassList **tableClass;
    TermList **tableTerm;
    int Table_Size;

public:
    HashTable(int Table_Size)
    {
        this->Table_Size = Table_Size;
        tableStudent = new StudentList *[Table_Size];
        tableSubject = new SubjectList *[Table_Size];
        tableClass = new ClassList *[Table_Size];
        tableTerm = new TermList *[Table_Size];

        // Khởi tạo danh sách liên kết cho mỗi phần tử trong bảng băm
        for (int i = 0; i < Table_Size; i++)
        {
            tableStudent[i] = new StudentList();
            tableSubject[i] = new SubjectList();
            tableClass[i] = new ClassList();
            tableTerm[i] = new TermList();
        }
    }

    // Hash Fucntion
    unsigned int hash(std::string id)
    {
        unsigned int hashValue = 0;
        for (auto &&i : id)
        {
            hashValue += i;
        }
        return hashValue % Table_Size;
    }

    // Phương thức để thêm một học sinh vào bảng băm
    void addStudent(Student *student)
    {
        int hashValue = hash(student->getId());

        tableStudent[hashValue]->addToTail(student);
    }

    // Phương thức để tìm kiếm một học sinh trong bảng băm
    StudentNode *findStudent(std::string id)
    {
        // Tính giá trị băm của mã sinh viên
        int hashValue = hash(id);
        return tableStudent[hashValue]->findStudent(id);
    }

    void addSubject(Subject *subject)
    {
        unsigned int hashValue = hash(subject->getIdSubject());
        tableSubject[hashValue]->addToTail(subject);
    }

    SubjectNode *findSubject(std::string idSubject)
    {
        unsigned int hashValue = hash(idSubject);
        return tableSubject[hashValue]->findSubject(idSubject);
    }
    void addClass(Class *dataClass)
    {
        unsigned int hashValue = hash(dataClass->getIdClass());
        tableClass[hashValue]->addToTailClass(dataClass);
    }
    ClassNode *findClass(std::string idClass)
    {
        unsigned int hashValue = hash(idClass);
        return tableClass[hashValue]->findClass(idClass);
    }
    void addTerm(Term *term)
    {
        unsigned int hashValue = hash(term->getIdTerm());
        tableTerm[hashValue]->addToTail(term);
    }
    TermNode *findTerm(std::string idTerm)
    {
        unsigned int hashValue = hash(idTerm);
        return tableTerm[hashValue]->findTerm(idTerm);
    }
};
int main()
{
    // Tạo một bảng băm với kích thước là 100
    HashTable hashTable(100);
    StudentList *head;
    // Thêm một số học sinh vào bảng băm
    Student student1("John Smith", "1001", "Math", 3.8);
    Student student2("Emily Johnson", "1002", "History", 3.5);
    Student student3("David Lee", "1003", "Chemistry", 3.2);
    Student student4("Amy Chen", "1004", "English", 3.9);

    hashTable.addStudent(&student1);
    hashTable.addStudent(&student2);
    hashTable.addStudent(&student3);
    hashTable.addStudent(&student4);

    // Tìm kiếm học sinh có mã sinh viên là "1002" và in thông tin của học sinh này
    StudentNode *studentNode = hashTable.findStudent("1002");
    if (studentNode != nullptr)
    {
        studentNode->student->printInfo();
        std::cout<<std::endl;
    }
    else
    {
        std::cout << "Student not found" << std::endl;
    }

    // Thêm một số môn học vào bảng băm
    Subject subject1("Mathematics", "MATH101", 3);
    Subject subject2("Physics", "PHYS101", 4);
    Subject subject3("Computer Science", "CS101", 3);

    hashTable.addSubject(&subject1);
    hashTable.addSubject(&subject2);
    hashTable.addSubject(&subject3);

    // Tìm kiếm môn học có mã môn "CS101" và in thông tin của môn học này
    SubjectNode *subjectNode = hashTable.findSubject("CS101");
    if (subjectNode != nullptr)
    {
        subjectNode->subject->printInforSubject();
        std::cout<<std::endl;
    }
    else
    {
        std::cout << "Subject not found" << std::endl;
    }

    // Thêm một số lớp học vào bảng băm
    Class class1("C01", "Class A");
    Class class2("C02", "Class B");
    Class class3("C03", "Class C");

    hashTable.addClass(&class1);
    hashTable.addClass(&class2);
    hashTable.addClass(&class3);

    // Tìm kiếm lớp học có mã lớp "C02" và in thông tin của lớp học này
    ClassNode *classNode = hashTable.findClass("C02");
    if (classNode != nullptr)
    {
        classNode->dataClass->printInforClass();
        std::cout<<std::endl;
    }
    else
    {
        std::cout << "Class not found" << std::endl;
    }

    // Thêm một số học kỳ vào bảng băm
    Term term1("T01", "Term 1");
    Term term2("T02", "Term 2");
    Term term3("T03", "Term 3");

    hashTable.addTerm(&term1);
    hashTable.addTerm(&term2);
    hashTable.addTerm(&term3);

    // Tìm kiếm học kỳ có mã học kỳ "T02" và in thông tin của học kỳ này
    TermNode *termNode = hashTable.findTerm("T02");
    if (termNode != nullptr)
    {
        termNode->term->printInforTerm();
        std::cout<<std::endl;
    }
    else
    {
        std::cout << "Term not found" << std::endl;
    }

    return 0;
}
