#include <ctime>
#include <cmath>

#include "kmeans.h"


//含参构造。参数分别为：点数、坐标最大值、聚类数、最大迭代次数
KMeans::KMeans(int point_num, double max_point_crood, int cluster_num, int max_interation_times)
{
    this->point_num = point_num;
    this->max_point_crood = max_point_crood;
    this->cluster_num = cluster_num;
    this->max_interation_times = max_interation_times;

    srand((unsigned int)time(NULL)); //设置随机种子
}


//初始化点
void KMeans::InitPoints(void)
{
    for (int i = 0; i < point_num; i++)
    {
        Point point((double)rand() / (double)RAND_MAX * max_point_crood, 
                    (double)rand() / (double)RAND_MAX * max_point_crood);
    
        points.push_back(point);
    }
}


//初始化聚类（均值点）
void KMeans::InitClusters(void)
{
    for (int i = 0; i < cluster_num; i++)
    {
        Cluster cluster((double)rand() / (double)RAND_MAX * max_point_crood,
                        (double)rand() / (double)RAND_MAX * max_point_crood);
        
        clusters.push_back(cluster);

        next_clusters_point_num.push_back(0); //设置 next_clusters_point_num 初始值为 0
        
        next_clusters_x_sum.push_back(0.0); //设置 next_clusters_x_sum 初始值为 0.0
        next_clusters_y_sum.push_back(0.0); //设置 next_clusters_y_sum 初始值为 0.0
    }
}


//计算 point 和 cluster 的距离
inline double CalcDistance(Point& point, Cluster& cluster)
{
    return sqrt(pow(point.GetX() - cluster.GetX(), 2.0) +
                pow(point.GetY() - cluster.GetY(), 2.0));
}


//分配点
void KMeans::AssignPoints(void)
{
    int min_cluster_id;
    double min_distance;

    for (int i = 0; i < point_num; i++) //遍历点
    {
        min_cluster_id = 0; //假定 0 号聚类为与 points[i] 最近的聚类
        min_distance = CalcDistance(points[i], clusters[0]); //假定 0 号聚类为与 points[i] 最近的聚类

        for (int j = 1; j < cluster_num; j++) //遍历聚类
        {
            double distance = CalcDistance(points[i], clusters[j]); //计算距离

            if (distance < min_distance) //比较
            {
                min_distance = distance;
                min_cluster_id = j;
            }
        }

        points[i].SetClusterID(min_cluster_id); //更新点所属的聚类 id
        next_clusters_point_num[min_cluster_id]++; //增加对应聚类中点的数量
        next_clusters_x_sum[min_cluster_id] += points[i].GetX(); //增加对应聚类中点的 x 坐标和
        next_clusters_y_sum[min_cluster_id] += points[i].GetY(); //增加对应聚类中点的 y 坐标和
    }
}


//更新聚类。若所有聚类均值点均不移动，返回 false
bool KMeans::UpdateClusters(void)
{
    bool is_cluster_move = false; //假定所有聚类均值点都不移动

    double next_x;
    double next_y;
    
    for (int i = 0; i < cluster_num; i++)
    {
        next_x = next_clusters_x_sum[i] / (double)next_clusters_point_num[i]; //更新后的均值点 x 坐标
        next_y = next_clusters_y_sum[i] / (double)next_clusters_point_num[i]; //更新后的均值点 y 坐标
        
        if (clusters[i].GetX() != next_x || clusters[i].GetY() != next_y)
        {
            is_cluster_move = true; //若发生移动，则 is_cluster_move 改为 true
            clusters[i].SetX(next_x); //更新均值点 x 坐标
            clusters[i].SetY(next_y); //更新均值点 y 坐标
        }

        next_clusters_point_num[i] = 0; //设置 next_clusters_point_num 值为 0
        next_clusters_x_sum[i] = 0.0; //设置 next_clusters_x_sum 值为 0.0
        next_clusters_y_sum[i] = 0.0; //设置 next_clusters_y_sum 值为 0.0
    }

    return is_cluster_move;
}