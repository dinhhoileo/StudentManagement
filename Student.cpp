#include <string>

class Student
{
private:
    std::string fullName;    // họ và tên
    std::string ID;          // mã số sinh viên
    std::string dateOfBirth; // ngày sinh
    std::string address;     // địa chỉ
    std::string email;       // thư điện tử email
    std::string phoneNumber; // số điện thoại
    std::string *registeredSubjects;
    // danh sách môn học đã đăng ký

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
