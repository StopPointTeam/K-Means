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