#include <iostream>
using namespace std;
int front[3][3],back[3][3],le[3][3],ri[3][3],up[3][3],down[3][3];
int temp[3];
void init ()
{
	cout <<"请输入初始魔方状态"<<endl;
	cout <<"----------------"<<endl;
	cout <<"数字0，1，2，3，4，5分别代表。。。"<<endl;
	cout <<"请输入正面魔方图~"<<endl;
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			cin >>front[i][j];
		}
	}
	cout <<"请输入顶面魔方图~"<<endl;
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			cin >>up[i][j];
		}
	}
	cout <<"请输入左面魔方图~"<<endl;
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			cin >>le[i][j];
		}
	}
	cout <<"请输入底面魔方图~"<<endl;
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			cin >>down[i][j];
		}
	}
	cout <<"请输入右面魔方图~"<<endl;
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			cin >>ri[i][j];
		}
	}
	cout <<"请输入背面魔方图~"<<endl;
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			cin >>back[i][j];
		}
	}

}


void print1(int a[3][3])
{
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
			cout <<a[i][j]<<' ';
		cout <<endl;
	}
	cout <<endl;
}
void print ()
{
	print1(front);
	print1(up);
	print1(down);
	print1(le);
	print1(ri);
	print1(back);

}
int main()
{
	init();
	U();
	print();
	return 0;
}