# K-Means

通过 C++ 和 OpenMP 实现的并行 K-Means 算法。

## Usage

运行程序，可选择手动输入参数或使用默认参数。程序会记录 K-Means 计算的耗时。计算完成后，结果将写入 data.csv。

使用命令行参数 -default，程序会自动使用默认参数计算，便于进行批量运行测试。

默认参数如下：

+ 点数：500000
+ 坐标最大值：1000
+ 聚类数：20
+ 最大迭代次数：20

## Description

程序运行后，在 0 < x < max_point_crood && 0 < y < max_point_crood 区域内随机生成指定数量的点作为数据。通过以下步骤进行 K-Means 运算：

1. 在区域内随机选取指定数量的初始聚类均值点。
2. 计算每个点与每个聚类均值点的距离，从而将点分配到聚类。
3. 更新聚类均值点。
4. 重复 2 3 过程，直到所有聚类均值点不再移动或超过最大迭代次数为止。

代码文件介绍：

+ main.cpp

+ unipoint.h
  + UniPoint 类、Point 类的声明。
  + UniPoint 类为通用的点类，Point 类继承 UniPoint 类，具有 cluster_id 成员变量，指明该点属于的聚类。
  + Cluster 是 UniPoint 的别名，即聚类实际上是用聚类均值点表示的。
  + 每个点对应一个 Point 类对象。每个聚类对应一个 Cluster 类对象。

+ unipoint.cpp
  + UniPoint 类、Point 类的实现。

+ kmeans.h
  + KMeans 类的声明。
  + 一次 K-Means 计算对应一个 KMeans 类对象。

+ kmeans.cpp
  + KMeans 类的实现。

## Build

使用 Visual Studio 2019 构建。

将 kmeans.h 中 #define OUTPUT_EVERY_INTERATION 的注释取消，程序将输出每一轮迭代后的结果，总运行时长则大大增加。

请在 Release 配置下开启 OpenMP 支持编译。否则编译将退化为串行。

## Copyright

Stop Point Team