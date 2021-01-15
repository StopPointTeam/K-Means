#include "unipoint.h"


UniPoint::UniPoint(double x, double y)
{
    this->x = x;
    this->y = y;
}


double UniPoint::GetX(void)
{
    return x;
}


double UniPoint::GetY(void)
{
    return y;
}


void UniPoint::SetX(double x)
{
    this->x = x;
}


void UniPoint::SetY(double y)
{
    this->y = y;
}


Point::Point(double x, double y) : UniPoint(x, y)
{
    cluster_id = -1;
}


int Point::GetClusterID(void)
{
    return cluster_id;
}


void Point::SetClusterID(int cluster_id)
{
    this->cluster_id = cluster_id;
}