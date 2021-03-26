#ifndef BUILDINGCOMPANY_H
#define BUILDINGCOMPANY_H
#include "Company.h"

class BuildingCompany : public Company
{
public:
    BuildingCompany();

    Type getType() override;
    double getTax() override;
};

#endif // BUILDINGCOMPANY_H
