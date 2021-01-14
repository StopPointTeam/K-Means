#ifndef UNIPOINT_H
#define UNIPOINT_H


//UniPoint 类。通用的点类，作为 Point 的基类
class UniPoint
{
public:
    UniPoint(double x, double y);
    double GetX(void);
    double GetY(void);
    void SetX(double x);
    void SetY(double y);

protected:
    double x; //点的 x 坐标
    double y; //点的 y 坐标
};


//Point 类。每个点对应一个对象
class Point : public UniPoint
{
public:
    Point(double x, double y);
    double GetClusterID(void);
    void SetClusterID(int cluster_id);

private:
    int cluster_id; //点所属的聚类的 id。从 0 开始
};


//Cluster 作为 UniPoint 的别名。即聚类实际上是用聚类均值点表示的
typedef UniPoint Cluster;


#endif //UNIPOINT_H