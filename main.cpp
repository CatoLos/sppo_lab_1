#include <QTextStream>
#include "CompanyRegister.h"
#include "TransportCompany.h"
#include "ResearchCompany.h"
#include "BuildingCompany.h"

int main(int argc, char *argv[])
{
    QTextStream cout(stdout);
    QTextStream cin(stdin);

    CompanyRegister& reg = CompanyRegister::getReg();

    TransportCompany* tr1 = new TransportCompany();

    tr1->setName("Karuha");
    tr1->setOwners(QList<QString>{"Kar", "Uha"});
    tr1->setEmployeesCount(15);
    tr1->setArea(300);
    tr1->setIncome(15000);

    reg.addCompany(tr1);

    TransportCompany* tr2 = new TransportCompany();

    tr2->setName("Katalka");
    tr2->setOwners({"Katya", "Alla"});
    tr2->setEmployeesCount(50);
    tr2->setArea(1000);
    tr2->setIncome(50000);

    reg.addCompany(tr2);

    ResearchCompany* rs1 = new ResearchCompany();

    rs1->setName("HimiaYadov");
    rs1->setOwners({"Yadov", "Alla"});
    rs1->setEmployeesCount(20);
    rs1->setArea(80);
    rs1->setIncome(2000);

    reg.addCompany(rs1);

    ResearchCompany* rs2 = new ResearchCompany();

    rs2->setName("FizInc");
    rs2->setOwners({"Yadov", "Gadov", "Zavodov"});
    rs2->setEmployeesCount(60);
    rs2->setArea(200);
    rs2->setIncome(5000);

    reg.addCompany(rs2);

    BuildingCompany* bl1 = new BuildingCompany();

    bl1->setName("DomishOK");
    bl1->setOwners({"Gadov", "Kadirov"});
    bl1->setEmployeesCount(350);
    bl1->setArea(1000);
    bl1->setIncome(20000);

    reg.addCompany(bl1);

    BuildingCompany* bl2 = new BuildingCompany();

    bl2->setName("DomGusya");
    bl2->setOwners({"Katya", "Kadirov", "Alla"});
    bl2->setEmployeesCount(500);
    bl2->setArea(1500);
    bl2->setIncome(40000);

    reg.addCompany(bl2);

    int compType = -1;

    cout << "Enter companys' type to print: " << endl
         << "0 - TRANSPORT" << endl
         << "1 - BUILDING" << endl
         << "2 - COMMERCIAL" << endl
         << "3 - RESEARCH_AND_PRODUCTION" << endl;

    cin >> compType;

    if(compType >= Company::TRANSPORT && compType < Company::RESEARCH_AND_PRODUCTION)
    {
        cout << endl << "Companies:" << endl;
        for(int i = 0; i < reg.getSize(); ++i)
        {
            Company* comp = reg.getCompany(i);

            if(comp->getType() == compType)
            {
                cout << comp->getName() << endl;
            }
        }
    }
    else
        cout << "Wrong type!" << endl;

    QString owner;

    cout << endl << "Enter the owner whose companies to print:" << endl;
    cin >> owner;
    cout << endl << "Companies:" << endl;
    int count = 0;


    for(int i = 0; i < reg.getSize(); ++i)
    {
        Company* comp = reg.getCompany(i);

        if(comp->getOwners().contains(owner))
        {
            ++count;
            cout << comp->getName() << endl;
        }
    }

    if(count == 0)
        cout << "Empty" << endl;

    cout << endl;

    for(int type = Company::TRANSPORT; type <= Company::RESEARCH_AND_PRODUCTION; ++type)
    {
        switch (type) {
        case Company::TRANSPORT:
            cout << "TRANSPORT statistics:" << endl;
            break;
        case Company::BUILDING:
            cout << "BUILDING statistics:" << endl;
            break;
        case Company::COMMERCIAL:
            cout << "COMMERCIAL statistics:" << endl;
            break;
        case Company::RESEARCH_AND_PRODUCTION:
            cout << "RESEARCH_AND_PRODUCTION statistics:" << endl;
            break;
        }

        cout << endl;

        int     totalCount       = 0.0;
        double  totalIncome   = 0.0;
        double  totalArea     = 0.0;
        double  totalEmpCount = 0.0;

        for(int i = 0; i < reg.getSize(); ++i)
        {
            Company* comp = reg.getCompany(i);

            if(comp->getType() == type)
            {
                ++totalCount;
                totalIncome += comp->getIncome();
                totalArea += comp->getArea();
                totalEmpCount += comp->getEmployeesCount();
            }
        }

        if(totalCount != 0){
            cout << "Average income: " << totalIncome / totalCount << endl;
            cout << "Average area: " << totalArea / totalCount << endl;
            cout << "Average employees count: " << totalEmpCount / totalCount << endl << endl;
        }
        else
            cout << "No companies of that type!" << endl << endl;
    }

    return 0;
}
