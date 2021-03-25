#include "BuildingCompany.h"

BuildingCompany::BuildingCompany():
    Company()
{}

Company::Type BuildingCompany::getType()
{
    return Type::BUILDING;
}

double BuildingCompany::getTax()
{
    double fromIncome   = 0.0;
    double fromEmp      = 0.0;
    double fromArea     = 0.0;

    if(_employeesCount < 30)
        fromEmp = _income * 0.03;
    else if (_employeesCount < 100)
        fromEmp = _income * 0.04;
    else
        fromEmp = (_employeesCount / 10000.0) * _income;

    if(_area < 300.0)
        fromArea = _income * 0.02;
    else
        fromArea = _income * 0.03;

    if(_income < 1500.0)
        fromIncome = _income * 0.02;
    else if (_income < 5000.0)
        fromIncome = _income * 0.03;
    else
        fromIncome = _income * 0.05;

    return fromArea + fromEmp + fromIncome;
}

