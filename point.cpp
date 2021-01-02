#include "point.h"


Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;

    cluster_id = -1;
}


double Point::GetX(void)
{
    return x;
}


double Point::GetY(void)
{
    return y;
}


double Point::GetClusterID(void)
{
    return cluster_id;
}


void Point::SetClusterID(int cluster_id)
{
    this->cluster_id = cluster_id;
}