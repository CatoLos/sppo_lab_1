#include "TransportCompany.h"

TransportCompany::TransportCompany():
    Company()
{}

Company::Type TransportCompany::getType()
{
    return Type::TRANSPORT;
}

double TransportCompany::getTax()
{
    double fromIncome   = 0.0;
    double fromEmp      = 0.0;
    double fromArea     = 0.0;

    if(_employeesCount < 20)
        fromEmp = _income * 0.05;
    else if(_employeesCount < 50)
        fromEmp = _income * 0.065;
    else if(_employeesCount < 200)
        fromEmp = _income * 0.07;
    else
        fromEmp = _income * 0.08;

    if(_income < 1000.0)
        fromIncome = _income * 0.02;
    else
        fromIncome = _income * 0.04;

    if(_area < 500.0)
        fromArea = _income * 0.01;
    else
        fromArea = _income * 0.03;

    return fromIncome + fromArea + fromEmp;
}


