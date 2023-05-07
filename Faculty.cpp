#include <string>

class Faculty
{
private:
    std::string nameFaculty; // têm khoa
    std::string idFaculty; // mã khoa
    std::string *listClassOfFaculty; // danh sách lớp thuộc khoa đó

public:
    Faculty(std::string nameFaculty, std::string idFaculty, std::string *listClassOfFaculty)
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

    std::string *GetListOfFaculty() const
    {
        return listClassOfFaculty;
    }

    void SetListOfFaculty(std::string *listClassOfFaculty)
    {
        listClassOfFaculty = listClassOfFaculty;
    }
};
