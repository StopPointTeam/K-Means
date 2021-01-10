#include <vector>
#include <iostream>
#include <chrono>
#include <fstream>

#include "kmeans.h"
#include "unipoint.h"


using namespace std;
using namespace std::chrono;


int main()
{
	cout << "点数：500000" << endl;
	cout << "坐标最大值：1000.0" << endl;
	cout << "聚类数：20" << endl;
	cout << "最大迭代次数：20" << endl;

	KMeans km(500000, 1000.0, 20, 20);

	cout << "开始计时..." << endl;
	time_point<system_clock> time_start = system_clock::now(); //获取计算开始时的时间

	vector<Point> points = km.Result(); //将计算结果存入 points

	time_point<system_clock> time_stop = system_clock::now(); //获取计算结束时的时间
	cout << "计算结束" << endl;
	duration<double> calc_time = time_stop - time_start; //时间差
	cout << "time: " << calc_time.count() << "s" << endl;

	ofstream fileout("data.csv"); //将结果写入 data.csv
	
	for (int i = 0; i < (int)points.size(); i++)
		fileout << points[i].GetX() << "," << points[i].GetY() << "," << points[i].GetClusterID() << endl; //采用逗号分隔符

	fileout.close();

	return 0;
}