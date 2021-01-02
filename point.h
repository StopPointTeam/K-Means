#ifndef POINT_H
#define POINT_H


//Point 类。每个点对应一个对象
class Point
{
public:
    Point(double x, double y); //含参构造
    double GetX(void);
    double GetY(void);
    double GetClusterID(void);
    void SetClusterID(int cluster_id);

private:
    double x; //点的 x 坐标
    double y; //点的 y 坐标
    int cluster_id; //点所属的聚类的 id。从 0 开始
};


#endif //POINT_H