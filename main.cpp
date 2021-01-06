#include <vector>
#include <iostream>
#include <fstream>

#include "kmeans.h"
#include "point.h"


using namespace std;


int main()
{
	cout << "点数：500000" << endl;
	cout << "坐标最大值：1000.0" << endl;
	cout << "聚类数：20" << endl;
	cout << "最大迭代次数：20" << endl;

	KMeans km(500000, 1000.0, 20, 20);

	vector<Point> points = km.Result(); //将计算结果存入 points

	ofstream fileout("data.csv"); //将结果写入 data.csv
	
	for (int i = 0; i < (int)points.size(); i++)
		fileout << points[i].GetX() << "," << points[i].GetY() << "," << points[i].GetClusterID() << endl; //采用逗号分隔符

	fileout.close();

	return 0;
}