#include <vector>
#include <iostream>
#include <chrono>
#include <fstream>
#include <cstring>

#include "kmeans.h"
#include "unipoint.h"


using namespace std;


int main(int argc, char* argv[])
{		
	cout << "K-Means 并行计算" << endl;
	cout << "By StopPointTeam" << endl;

	int point_num = 500000; //点数
	double max_point_crood = 1000.0; //坐标最大值
	int cluster_num = 20; //聚类数
	int max_interation_times = 20; //最大迭代次数

	if (argc == 1 || strcmp(argv[1], "-default")) //加 -default 参数运行时自动使用默认计算参数
	{	
		int menu_choice;
		cout << endl << "[1] 手动输入参数" << endl;
		cout << "[2] 使用默认参数" << endl;
		cout << "请选择：";
		cin >> menu_choice;
		if (menu_choice == 1)
		{
			cout << "点数：";
			cin >> point_num;
			cout << "坐标最大值：";
			cin >> max_point_crood;
			cout << "聚类数：";
			cin >> cluster_num;
			cout << "最大迭代次数：";
			cin >> max_interation_times;
		}
	}

	cout << endl << "本次计算参数：" << endl;
	cout << "点数：" << point_num << endl;
	cout << "坐标最大值：" << max_point_crood << endl;
	cout << "聚类数：" << cluster_num << endl;
	cout << "最大迭代次数：" << max_interation_times << endl;

	KMeans km(point_num, max_point_crood, cluster_num, max_interation_times);

	cout << endl << "开始计时..." << endl;
	chrono::time_point<chrono::system_clock> time_start = chrono::system_clock::now(); //获取计算开始时的时间

	vector<Point> points = km.Result(); //进行计算并将计算结果存入 points

	chrono::time_point<chrono::system_clock> time_stop = chrono::system_clock::now(); //获取计算结束时的时间
	chrono::duration<double> calc_time = time_stop - time_start; //时间差
	cout << "计算结束，用时：" << calc_time.count() << "s" << endl;

	cout << endl << "正在将结果写入 data.csv" << endl;
	ofstream fileout("data.csv"); //将结果写入 data.csv
	
	for (int i = 0; i < (int)points.size(); i++)
		fileout << points[i].GetX() << "," << points[i].GetY() << "," << points[i].GetClusterID() << endl; //采用逗号分隔符

	fileout.close();
	cout << "写入完成" << endl;

	return 0;
}