#include "CompanyRegister.h"

CompanyRegister::CompanyRegister(){}

CompanyRegister::~CompanyRegister()
{
    while(!_companies.empty())
    {
        delete _companies.takeFirst();
    }
}

void CompanyRegister::addCompany(Company* company)
{
    _companies.push_back(company);
}

void CompanyRegister::delCompany(int index)
{
    if(index >= 0 && index < _companies.size())
        _companies.removeAt(index);
}

Company* CompanyRegister::getCompany(int index)
{
    if(index >= 0 && index < _companies.size())
        return _companies[index];

    return nullptr;
}

int CompanyRegister::getSize()
{
    return _companies.size();
}

CompanyRegister &CompanyRegister::getReg()
{
    static CompanyRegister reg;
    return reg;
}


