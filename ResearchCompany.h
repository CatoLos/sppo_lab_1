#ifndef RESEARCHCOMPANY_H
#define RESEARCHCOMPANY_H
#include "Company.h"

class ResearchCompany : public Company
{
public:
    ResearchCompany();

    Type getType() override;
    double getTax() override;
};

#endif // RESEARCHCOMPANY_H
