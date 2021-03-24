#ifndef COMPANYREGISTER_H
#define COMPANYREGISTER_H
#include "Company.h"

class CompanyRegister{

public:

    CompanyRegister(const CompanyRegister&) = delete;

    void addCompany(Company* company);
    void delCompany(int index);
    Company* getCompany(int index);
    int getSize();

    static CompanyRegister& getReg();

private:

    CompanyRegister();

    QList<Company*> _companies;
};

#endif // COMPANYREGISTER_H
