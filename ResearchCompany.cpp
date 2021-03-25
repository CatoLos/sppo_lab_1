#include "ResearchCompany.h"

ResearchCompany::ResearchCompany():
    Company()
{}

Company::Type ResearchCompany::getType()
{
    return Type::RESEARCH_AND_PRODUCTION;
}

double ResearchCompany::getTax()
{
    double fromIncome   = 0.0;
    double fromEmp      = 0.0;
    double fromArea     = 0.0;

    if(_employeesCount < 15)
        fromEmp = _income * 0.06;
    else
        fromEmp = _income * 0.01;

    fromIncome = _income * 0.05;

    if(_area < 50.0)
        fromArea = _income * 0.01;
    else
        fromArea = _income * 0.02;

    return fromEmp + fromArea + fromIncome;
}
