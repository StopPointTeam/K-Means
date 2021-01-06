#ifndef KMEANS_H
#define KMEANS_H

//取消此处注释，则输出每轮迭代的结果
//#define OUTPUT_EVERY_INTERATION


#include <vector>

#include "point.h"
#include "cluster.h"


//KMeans类。一次 K-Means 计算对应一个对象
class KMeans
{
public:
    //含参构造。参数分别为：点数、坐标最大值、聚类数、最大迭代次数
    KMeans(int point_num, double max_point_crood, int cluster_num, int max_interation_times);
    std::vector<Point> Result(void); //返回结果

private:
    int point_num; //点数
    double max_point_crood; //坐标最大值
    std::vector<Point> points; //存放点的向量

    int cluster_num; //聚类数
    std::vector<Cluster> clusters; //存放聚类的向量
    std::vector<int> next_clusters_point_num; //存放此轮迭代结束后对应聚类中点的数量。用于计算下一轮中对应聚类的均值点
    std::vector<double> next_clusters_x_sum; //存放此轮迭代结束后对应聚类中点的 x 坐标和。用于计算下一轮中对应聚类的均值点
    std::vector<double> next_clusters_y_sum; //存放此轮迭代结束后对应聚类中点的 y 坐标和。用于计算下一轮中对应聚类的均值点

    int max_interation_times; //最大迭代次数

    void InitPoints(void); //初始化点
    void InitClusters(void); //初始化聚类（均值点）
    void AssignPoints(void); //分配点
    bool UpdateClusters(void); //更新聚类。若所有聚类均值点均不移动，返回 false
};


#endif //KMEANS_H