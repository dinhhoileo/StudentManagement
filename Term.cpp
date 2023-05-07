#include <string>

class Term
{
private:
    std::string idTerm; // mã học kỳ
    std::string nameTerm;// tên học kỳ
    std::string *listClassInTerm;// danh sách các lớp học trong một học kỳ

public:
    // constructor
    Term(std::string idTerm, std::string nameTerm, std::string *listClassInTerm)
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

    std::string *GetListClassInTerm() const
    {
        return listClassInTerm;
    }

    void SetListClassInTerm(std::string *listClassInTerm)
    {
        listClassInTerm = listClassInTerm;
    }
};