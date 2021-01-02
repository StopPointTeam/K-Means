#ifndef CLUSTER_H
#define CLUSTER_H


//Cluster 类。每个聚类对应一个对象
class Cluster
{
public:
    Cluster(double x, double y); //含参构造
    double GetX(void);
    double GetY(void);
    void SetX(double x);
    void SetY(double y);

private:
    double x; //聚类均值点的 x 坐标
    double y; //聚类均值点的 y 坐标
};


#endif //CLUSTER_H