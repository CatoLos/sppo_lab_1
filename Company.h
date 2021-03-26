#ifndef COMPANY_H
#define COMPANY_H
#include <QString>
#include <QList>

class Company{

public:

    enum Type{
        TRANSPORT,
        BUILDING,
        COMMERCIAL,
        RESEARCH_AND_PRODUCTION
    };

    Company();
    virtual ~Company();

    QString getName();
    void setName(const QString& name);

    QList<QString> getOwners();
    void setOwners(const QList<QString>& owners);

    bool addOwner(const QString& owner);
    bool delOwner(const QString& owner);

    double getIncome();
    void setIncome(double income);

    double getArea();
    void setArea(double area);

    int getEmployeesCount();
    void setEmployeesCount(int count);

    virtual Type getType() = 0;
    virtual double getTax() = 0;

protected:

    QString         _name;
    QList<QString>  _owners;
    double          _income;
    double          _area;
    int             _employeesCount;
};

#endif // COMPANY_H
