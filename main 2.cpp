#include <iostream>
#include <fstream>
using namespace std;
char cube[6][3][3];//面的编号：前右后左 0123 上4下5
int temp[3];
ifstream fin("cube.txt");
void init ()//输入魔方初始状态
{
    cout <<"请输入初始魔方状态"<<endl;
    cout <<"----------------"<<endl;
    cout <<"数字0，1，2，3，4，5分别代表。。。"<<endl;
    cout <<"请输入正面魔方图~"<<endl;
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            fin >>cube[0][i][j];
        }
    }
    cout <<"请输入顶面魔方图~"<<endl;
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            fin >>cube[4][i][j];
        }
    }
    cout <<"请输入左面魔方图~"<<endl;
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            fin >>cube[3][i][j];
        }
    }
    cout <<"请输入底面魔方图~"<<endl;
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            fin >>cube[5][i][j];
        }
    }
    cout <<"请输入右面魔方图~"<<endl;
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            fin >>cube[1][i][j];
        }
    }
    cout <<"请输入背面魔方图~"<<endl;
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            fin >>cube[2][i][j];
        }
    }

}
void spint(int n)//将整个编号为N的面顺时针旋转90
{
    char tempp[3][3];
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
            tempp[i][j]=cube[n][i][j];
    }
    cube[n][0][2]=tempp[0][0];
    cube[n][2][2]=tempp[0][2];
    cube[n][2][0]=tempp[2][2];
    cube[n][0][0]=tempp[2][0];
    cube[n][0][1]=tempp[1][0];
    cube[n][1][2]=tempp[0][1];
    cube[n][2][1]=tempp[1][2];
    cube[n][1][0]=tempp[2][1];
}
void spinut(int n)//将编号为N的面逆时针旋转90.
{
    char tempp[3][3];
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
            tempp[i][j]=cube[n][i][j];
    }
    cube[n][0][0]=tempp[0][2];
    cube[n][0][2]=tempp[2][2];
    cube[n][2][2]=tempp[2][0];
    cube[n][2][0]=tempp[0][0];
    cube[n][1][0]=tempp[0][1];
    cube[n][0][1]=tempp[1][2];
    cube[n][1][2]=tempp[2][1];
    cube[n][2][1]=tempp[1][0];
}
void cpr(char a[3],char b[3])//复制整条块a=b
{
    for (int i=0;i<3;i++)
    {
        a[i]=b[i];
    }
}
void cpm(char a[3][3],char b[3][3])//复制整个面a=b
{
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            a[i][j]=b[i][j];
        }
    }
}
void U()//上面顺时针转动
{
    char temp[3];
    cpr(temp,cube[0][0]);
    for (int i=0;i<3;i++)
    {
        cpr(cube[i][0],cube[i+1][0]);
    }
    cpr(cube[3][0],temp);
    spint(4);
    cout <<"U"<<' ';
}
void UI()//上面逆时针转动
{
    char temp[3];
    cpr(temp,cube[3][0]);
    for (int i=2;i>=0;i--)
    {
        cpr(cube[i+1][0],cube[i][0]);
    }
    cpr(cube[0][0],temp);
    spinut(4);
    cout <<"UI"<<" ";
}
void D()//底面逆时针转动
{
    char temp[3];
    cpr(temp,cube[3][2]);
    for (int i=2;i>=0;i--)
    {
        cpr(cube[i+1][2],cube[i][2]);
    }
    cpr(cube[0][2],temp);
    spint(5);
    cout <<"D"<<' ';
}
void DI()//底面顺时针转动
{
    char temp[3];
    cpr(temp,cube[0][2]);
    for (int i=0;i<3;i++)
    {
        cpr(cube[i][0],cube[i+1][0]);
    }
    cpr(cube[3][2],temp);
    spinut(5);
    cout <<"DI"<<' ';
}
void R()//右面向上
{
    char temp[3];
    for (int i=0;i<3;i++)
        temp[i]=cube[0][i][2];
    for (int i=0;i<3;i++)
    {
        cube[0][i][2]=cube[5][i][2];
        cube[5][i][2]=cube[2][2-i][0];
        cube[2][2-i][0]=cube[4][i][2];
        cube[4][i][2]=temp[i];
    }
    spint(1);
    cout <<"R"<<' ';
}
void RI()//右面向下转
{
    char temp[3];
    for (int i=0;i<3;i++)
        temp[i]=cube[5][i][2];
    for (int i=0;i<3;i++)
    {
        cube[5][i][2]=cube[0][i][2];
        cube[0][i][2]=cube[4][i][2];
        cube[4][i][2]=cube[2][2-i][0];
        cube[2][2-i][0]=temp[i];


    }
    spinut(1);
    cout <<"RI"<<" ";
}
void L()//左面向上转
{
    char temp[3];
    for (int i=0;i<3;i++)
        temp[i]=cube[0][i][2];
    for (int i=0;i<3;i++)
    {
        cube[0][i][0]=cube[5][i][0];
        cube[5][i][0]=cube[2][2-i][2];
        cube[2][2-i][2]=cube[4][i][0];
        cube[4][i][0]=temp[i];
    }
    spinut(3);
    cout <<"L"<<" ";
}
void LI()//左面向下转
{
    char temp[3];
    for (int i=0;i<3;i++)
        temp[i]=cube[5][i][2];
    for (int i=0;i<3;i++)
    {
        cube[5][i][0]=cube[0][i][0];
        cube[0][i][0]=cube[4][i][0];
        cube[4][i][0]=cube[2][2-i][2];
        cube[2][2-i][2]=temp[i];


    }
    spint(3);
    cout <<"LI"<<" ";
}
void F()
{
    char temp1[3],temp2[3];
    cpr(temp1,cube[4][2]);
    cpr(temp2,cube[5][0]);
    for (int i=0;i<3;i++)
    {
        cube[4][2][i]=cube[1][i][0];
        cube[5][0][i]=cube[3][i][2];
        cube[1][i][0]=temp1[i];
        cube[3][i][2]=temp2[i];
    }
    spint(0);
}
void FI()
{
    char temp1[3],temp2[3];
    cpr(temp1,cube[4][2]);
    cpr(temp2,cube[5][0]);
    for (int i=0;i<3;i++)
    {
        cube[4][2][i]=cube[3][i][2];
        cube[5][0][i]=cube[1][i][0];
        cube[1][i][0]=temp2[i];
        cube[3][i][2]=temp1[i];
    }
    spinut(0);
}
void B()
{
    char temp1[3],temp2[3];
    cpr(temp1,cube[4][0]);
    cpr(temp2,cube[5][2]);
    for (int i=0;i<3;i++)
    {
        cube[4][0][i]=cube[1][i][2];
        cube[5][2][i]=cube[3][i][0];
        cube[1][i][2]=temp2[i];
        cube[3][i][0]=temp1[i];
    }
    spint(2);
}
void BI()
{
    char temp1[3],temp2[3];
    cpr(temp1,cube[4][0]);
    cpr(temp2,cube[5][2]);
    for (int i=0;i<3;i++)
    {
        cube[4][0][i]=cube[3][i][0];
        cube[5][2][i]=cube[1][i][2];
        cube[1][i][2]=temp1[i];
        cube[3][i][0]=temp2[i];
    }
    spinut(2);
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
    for (int i=0;i<6;i++)
    {
        for (int j=0;j<3;j++)
        {
            for (int k=0;k<3;k++)
                cout <<cube[i][j][k]<<' ';
            cout<<endl;
        }
        cout <<endl;
    }

}
int main()
{
    init();
    BI();
    print();
    return 0;
}