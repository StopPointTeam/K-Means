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