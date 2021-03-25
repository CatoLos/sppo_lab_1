#ifndef TRANSPORTCOMPANY_H
#define TRANSPORTCOMPANY_H
#include "Company.h"

class TransportCompany : public Company
{
public:
    TransportCompany();

    Type getType() override;
    double getTax() override;
};

#endif // TRANSPORTCOMPANY_H
