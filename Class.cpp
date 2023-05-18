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

        // Calculate the size of the registeredSubjects array
        int numSubjects = registeredSubjects->length();

        // Allocate memory for the registeredSubjects array
        this->registeredSubjects = new std::string[numSubjects];

        // Copy the subjects to the registeredSubjects array
        for (int i = 0; i < numSubjects; i++)
        {
            this->registeredSubjects[i] = registeredSubjects[i];
        }
    }
    ~Student()
    {
        delete[] registeredSubjects;
    }
    std::string GetFullName() const { return this->fullName; }
    void SetFullName(std::string fullName) { this->fullName = fullName; }

    std::string GetID() const { return this->ID; }
    void SetID(std::string ID) { this->ID = ID; }

    std::string GetDateOfBirth() const { return this->dateOfBirth; }
    void SetDateOfBirth(std::string dateOfBirth) { this->dateOfBirth = dateOfBirth; }

    std::string GetAddress() const { return this->address; }
    void SetAddress(std::string address) { this->address = address; }

    std::string GetEmail() const { return this->email; }
    void SetEmail(std::string email) { this->email = email; }

    std::string GetPhoneNumber() const { return this->phoneNumber; }
    void SetPhoneNumber(std::string phoneNumber) { this->phoneNumber = phoneNumber; }

    std::string *GetRegisteredSubjects() const { return this->registeredSubjects; }
    void SetRegisteredSubjects(std::string *registeredSubjects) { this->registeredSubjects = registeredSubjects; }

    // nhập thông tin
    void putInformationStudent()
    {
        std::cout << "Full Name: ";
        std::getline(std::cin, fullName);
        std::cout << "Student ID: ";
        std::getline(std::cin, ID);
        std::cout << "Date of Birth: ";
        std::getline(std::cin, dateOfBirth);
        std::cout << "Address: ";
        std::getline(std::cin, address);
        std::cout << "Email: ";
        std::getline(std::cin, email);
        std::cout << "Phone Number: ";
        std::getline(std::cin, phoneNumber);

        int numberOfSubjects;
        std::cout << "Number of Registered Subjects: ";
        std::cin >> numberOfSubjects;
        std::cin.ignore();

        registeredSubjects = new std::string[numberOfSubjects];
        for (int i = 0; i < numberOfSubjects; i++)
        {
            std::cout << "Subject " << i + 1 << ": ";
            std::getline(std::cin, registeredSubjects[i]);
        }
    }
};
// MÔN HỌC
class Subject
{
private:
    std::string nameSubject;               // tên môn học
    std::string IdSubject;                 // mã môn học
    int numberOfCredits;                   // số tín chỉ
    std::string *registeredStudentSubject; // sinh viên đã đăng ký

public:
    // constructor
    Subject(std::string nameSubject, std::string IdSubject, int numberOfCredis, std::string *registeredStudentSubject)
    {
        this->nameSubject = nameSubject;
        this->IdSubject = IdSubject;
        this->numberOfCredits = numberOfCredis;
        int lenghtRegisteredStudentSubject = registeredStudentSubject->length();
        for (int i = 0; i < lenghtRegisteredStudentSubject; i++)
        {
            this->registeredStudentSubject[i] = registeredStudentSubject[i];
        }
    }
    std::string GetNameSubject() const { return this->nameSubject; }
    void SetNameSubject(std::string nameSubject) { this->nameSubject = nameSubject; }

    std::string GetIdSubject() const { return this->IdSubject; }
    void SetIdSubject(std::string IdSubject) { this->IdSubject = IdSubject; }

    int GetNumberOfCredits() const { return this->numberOfCredits; }
    void SetNumberOfCredits(int numberOfCredits) { this->numberOfCredits = numberOfCredits; }

    std::string *GetRegisteredStudentSubject() const { return this->registeredStudentSubject; }
    void SetRegisteredStudentSubjects(std::string *registeredStudentSubjects) { this->registeredStudentSubject = registeredStudentSubjects; }

    void putInformationSubject()
    {
        std::cout << "Enter the name of the subject: ";
        std::getline(std::cin, nameSubject);

        std::cout << "Enter the ID of the subject: ";
        std::getline(std::cin, IdSubject);

        std::cout << "Enter the number of credits: ";
        std::cin >> numberOfCredits;
        std::cin.ignore(); // Ignore the newline character

        int numStudents;
        std::cout << "Enter the number of registered students: ";
        std::cin >> numStudents;
        std::cin.ignore(); // Ignore the newline character

        this->registeredStudentSubject = new std::string[numStudents];
        for (int i = 0; i < numStudents; ++i)
        {
            std::cout << "Enter the name of student " << i + 1 << ": ";
            std::getline(std::cin, registeredStudentSubject[i]);
        }
    }
};

// LỚP
class Class
{
private:
    std::string idClass;               // mã lớp
    std::string nameClass;             // têm lớp
    std::string *studentInClass;       // danh sách học sinh trong lớp
    std::string *subjectTaughtInClass; // danh sách môn học được dạy trong lớp

public:
    Class(std::string idClass, std::string nameClass, std::string *studentInClass, std::string *subjectTaughtInClass)
    {
        this->idClass = idClass;
        this->nameClass = nameClass;
        int numberStudentInClass = studentInClass->length(); // lấy số lượng học sinh trong một lớp
        this->studentInClass = new std::string[numberStudentInClass];
        for (int i = 0; i < numberStudentInClass; i++)
        {
            this->studentInClass[i] = studentInClass[i];
        }

        int numberSubjectTaughtInClass = subjectTaughtInClass->length(); // lấy số lượng các môn học trong một kỳ
        this->subjectTaughtInClass = new std::string[numberSubjectTaughtInClass];
        for (int i = 0; i < numberStudentInClass; i++)
        {
            this->subjectTaughtInClass[i] = subjectTaughtInClass[i];
        }
    }
    ~Class()
    {
        delete[] subjectTaughtInClass;
        delete[] studentInClass;
    }
    std::string GetIdClass() const { return idClass; }
    void SetIdClass(std::string idClass) { this->idClass = idClass; }

    std::string GetNameClass() const { return nameClass; }
    void SetNameClass(std::string nameClass) { this->nameClass = nameClass; }

    std::string *GetStudentInClass() const { return studentInClass; }
    void SetStudentInClass(std::string *studentInClass) { this->studentInClass = studentInClass; }

    std::string *GetSubjectTaughtInClass() const { return subjectTaughtInClass; }
    void SetSubjectTaughtInClass(std::string *subjectTaughtInClass) { this->subjectTaughtInClass = subjectTaughtInClass; }
    void putInformationClass()
    {
        std::cout << "Enter the ID of the class: ";
        std::getline(std::cin, idClass);

        std::cout << "Enter the name of the class: ";
        std::getline(std::cin, nameClass);

        int numStudents;
        std::cout << "Enter the number of students in the class: ";
        std::cin >> numStudents;
        std::cin.ignore(); // Ignore the newline character

        studentInClass = new std::string[numStudents];
        for (int i = 0; i < numStudents; ++i)
        {
            std::cout << "Enter the name of student " << i + 1 << ": ";
            std::getline(std::cin, studentInClass[i]);
        }

        int numSubjects;
        std::cout << "Enter the number of subjects taught in the class: ";
        std::cin >> numSubjects;
        std::cin.ignore(); // Ignore the newline character

        subjectTaughtInClass = new std::string[numSubjects];
        for (int i = 0; i < numSubjects; ++i)
        {
            std::cout << "Enter the name of subject " << i + 1 << ": ";
            std::getline(std::cin, subjectTaughtInClass[i]);
        }
    }
};
// KHOA
class Faculty
{
private:
    std::string nameFaculty;         // têm khoa
    std::string idFaculty;           // mã khoa
    std::string *listClassOfFaculty; // danh sách lớp thuộc khoa đó

public:
    Faculty(std::string nameFaculty, std::string idFaculty, std::string *listClassOfFaculty)
    {
        this->nameFaculty = nameFaculty;
        this->idFaculty = idFaculty;
        int numberListClassOfFaculty = listClassOfFaculty->length();
        this->listClassOfFaculty = new std::string[numberListClassOfFaculty];
        for (int i = 0; i < numberListClassOfFaculty; i++)
        {
            this->listClassOfFaculty[i] = listClassOfFaculty[i];
        }
    }
    ~Faculty()
    {
        delete[] listClassOfFaculty;
    }
    std::string GetNameFaculty() const { return nameFaculty; }
    void SetNameFaculty(std::string nameFaculty) { this->nameFaculty = nameFaculty; }

    std::string GetIdFaculty() const { return idFaculty; }
    void SetIdFaculty(std::string idFaculty) { this->idFaculty = idFaculty; }

    std::string *GetListOfFaculty() const { return listClassOfFaculty; }
    void SetListOfFaculty(std::string *listClassOfFaculty) { this->listClassOfFaculty = listClassOfFaculty; }

    void putInformationFaculty()
    {
        std::cout << "Enter the name of the faculty: ";
        std::getline(std::cin, nameFaculty);

        std::cout << "Enter the ID of the faculty: ";
        std::getline(std::cin, idFaculty);
        int numberListClassOfFaculty;
        std::cout << "Enter the number of classes in the faculty: ";
        std::cin >> numberListClassOfFaculty;
        std::cin.ignore(); // Ignore the newline character

        listClassOfFaculty = new std::string[numberListClassOfFaculty];
        for (int i = 0; i < numberListClassOfFaculty; ++i)
        {
            std::cout << "Enter the name of class " << i + 1 << ": ";
            std::getline(std::cin, listClassOfFaculty[i]);
        }

        delete[] listClassOfFaculty;
    }
};

// HỌC KỲ
class Term
{
private:
    std::string idTerm;           // mã học kỳ
    std::string nameTerm;         // tên học kỳ
    std::string *listClassInTerm; // danh sách các lớp học trong một học kỳ

public:
    // constructor
    Term(std::string idTerm, std::string nameTerm, std::string *listClassInTerm)
    {
        this->idTerm = idTerm;
        this->nameTerm = nameTerm;
        int numberListClassInTerm = listClassInTerm->length();
        this->listClassInTerm = new std::string[numberListClassInTerm];
        for (int i = 0; i < numberListClassInTerm; i++)
        {
            this->listClassInTerm[i] = listClassInTerm[i];
        }
    }
    ~Term()
    {
        delete[] listClassInTerm;
    }

    std::string GetIdTerm() const
    {
        return idTerm;
    }

    void SetIdTerm(std::string idTerm)
    {
        this->idTerm = idTerm;
    }

    std::string GetNameTerm() const
    {
        return nameTerm;
    }

    void SetNameTerm(std::string nameTerm)
    {
        this->nameTerm = nameTerm;
    }

    std::string *GetListClassInTerm() const
    {
        return listClassInTerm;
    }

    void SetListClassInTerm(std::string *listClassInTerm)
    {
        this->listClassInTerm = listClassInTerm;
    }

    void putInformationTerm()
    {
        std::cout << "Enter the ID of the term: ";
        std::getline(std::cin, idTerm);

        std::cout << "Enter the name of the term: ";
        std::getline(std::cin, nameTerm);
        int numberListClassInTerm;
        std::cout << "Enter the number of classes in the term: ";
        std::cin >> numberListClassInTerm;
        std::cin.ignore(); // Ignore the newline character

        listClassInTerm = new std::string[numberListClassInTerm];
        for (int i = 0; i < numberListClassInTerm; i++)
        {
            std::cout << "Enter the name of class " << i + 1 << ": ";
            std::getline(std::cin, listClassInTerm[i]);
        }
    }
};
