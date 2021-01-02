#include "cluster.h"


Cluster::Cluster(double x, double y)
{
    this->x = x;
    this->y = y;
}


double Cluster::GetX(void)
{
    return x;
}


double Cluster::GetY(void)
{
    return y;
}


void Cluster::SetX(double x)
{
    this->x = x;
}


void Cluster::SetY(double y)
{
    this->y = y;
}