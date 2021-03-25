#include "Company.h"

Company::Company():
    _income(0.0),
    _area(0.0),
    _employeesCount(0)
{}

Company::~Company()
{}

QString Company::getName()
{
    return _name;
}

void Company::setName(const QString &name)
{
    _name = name;
}

QList<QString> Company::getOwners()
{
    return _owners;
}

void Company::setOwners(const QList<QString> &owners)
{
    _owners = owners;
}

bool Company::addOwner(const QString &owner)
{
    if(_owners.count(owner) == 0)
    {
        _owners.append(owner);
        return true;
    }

    return false;
}


bool Company::delOwner(const QString &owner)
{
    return _owners.removeOne(owner);
}

double Company::getIncome()
{
    return _income;
}

void Company::setIncome(double income)
{
    _income = income;
}

double Company::getArea()
{
    return _area;
}

void Company::setArea(double area)
{
    _area = area;
}

int Company::getEmployeesCount()
{
    return _employeesCount;
}

void Company::setEmployeesCount(int count)
{
    _employeesCount = count;
}
