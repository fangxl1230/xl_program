#ifndef TEST_H
#define TEST_H
#include <stdlib.h>
#include <iostream>
#include <fstream>

struct PID {
    PID (double value) {

        double P = pid[0], I= pid[1], D = pid[2];

        //位置式PID
        error  = taret_value - value;
        P_OUT  = P * error;
        I_OUT += I * error;
        D_OUT  = D * (last_error - error);

        OUT = P_OUT + I_OUT + D_OUT;
        last_error = error;

        //增量式PID
        error  = taret_value - value;
        P_OUT  = P * (error - last_error);
        I_OUT += I * error;
        D_OUT  = D * (error - 2 * last_error + last_error2);

        OUT = P_OUT + I_OUT + D_OUT + last_OUT;
        last_error = error;

    }
    double pid[3];
    double taret_value;//目标值

    double OUT;        //总输出

    double P_OUT;      //P输出
    double I_OUT;      //I输出
    double D_OUT;      //D输出
    double error;      //本次误差
    double last_error; //上次误差
    double last_error2;//上上次误差
    double last_OUT;   //上次总输出
};






class test
{
public:
    test();
};






//直接复制到cpp文件中就可以直接使用
//在这里插入代码片
void gauss_solve(int n, double A[], double x[], double b[]);

/*polyfit(n,x,y,poly_n,a)=/
/=拟合y=a0+a1x+a2x2+……+apoly_n*xpoly_n==/
/=n是数据个数 xy是数据值 poly_n是多项式的项数==/
/=返回a0,a1,a2,……a[poly_n]，系数比项数多一（常数项）===*/
void polyfit(int n, double x[], double y[], int poly_n, double p[]) {
    int i, j;
    double *tempx, *tempy, *sumxx, *sumxy, *ata;
    tempx = (double *)calloc(n, sizeof(double));
    sumxx = (double *)calloc((poly_n * 2 + 1), sizeof(double));
    tempy = (double *)calloc(n, sizeof(double));
    sumxy = (double *)calloc((poly_n + 1), sizeof(double));
    ata = (double *)calloc((poly_n + 1)*(poly_n + 1), sizeof(double));
    for (i = 0; i<n; i++) {
        tempx[i] = 1;
        tempy[i] = y[i];
    }
    for (i = 0; i<2 * poly_n + 1; i++) {
        for (sumxx[i] = 0, j = 0; j<n; j++) {
            sumxx[i] += tempx[j];
            tempx[j] *= x[j];
        }
    }
    for (i = 0; i<poly_n + 1; i++) {
        for (sumxy[i] = 0, j = 0; j<n; j++)
        {
            sumxy[i] += tempy[j];
            tempy[j] *= x[j];
        }
    }
    for (i = 0; i<poly_n + 1; i++) {
        for (j = 0; j<poly_n + 1; j++) {
            ata[i*(poly_n + 1) + j] = sumxx[i + j];
        }
    }
    gauss_solve(poly_n + 1, ata, p, sumxy);

    free(tempx);
    free(sumxx);
    free(tempy);
    free(sumxy);
    free(ata);
}
/*============================================================
高斯消元法计算得到n次多项式的系数
n : 系数的个数
    ata : 线性矩阵
    sumxy : 线性方程组的Y值
    p : 返回拟合的结果
    ============================================================*/
void gauss_solve(int n, double A[], double x[], double b[]) {
    int i, j, k, r;
    double max;
    for (k = 0; k < n - 1; k++) {
//        max = fabs(A[kn + k]); // find maxmum
        r = k;
        for (i = k + 1; i<n - 1; i++) {
//            if (max<fabs(A[in + i])) {
//                max = fabs(A[in + i]);
//                r = i;
//            }
        }
        if (r != k) {
            for (i = 0; i<n; i++) { //change array:A[k]&A[r]
//                max = A[kn + i];
//                A[kn + i] = A[rn + i];
//                A[r*n + i] = max;
            }
            max = b[k]; //change array:b[k]&b[r]
            b[k] = b[r];
            b[r] = max;
        }
    }
}
//曲线拟合结果以及特征点计算并保存到txt文档
//注意：拟合计算出来的结果是double，需要强制类型转换利用四舍五入算法对特征点所在的行数进行处理
//void Computational_feature_points(const Mat &src) {
//    int num = getSample(src); //获得样本个数
//    int FeatureCol = Get_FeatureCol(src); //获得特征点所在的列数
//    int row_result;//特征点所在的行

//    double P[3];
//    int dimension = 2;	//5次多项式拟合

//    //此方法定义数组可以使得数组的长度为变量
//    double* xx = new double[num];//样本的x坐标
//    double* yy = new double[num];//样本的y坐标

//    for (int j = 0, i = 0; i <num; i++, j++){//	要拟合的数据
//        xx[j] = e_col[i];
//        yy[j] = d_row[i];
//    }

//    polyfit(num, xx, yy, dimension, P);

//    //printf("拟合系数, 按升序排列如下:\n");
//    for (int i = 0; i < dimension + 1; i++)	{ //这里是升序排列，Matlab是降序排列

//        printf("P[%d]=%lf\n", i, P[i]);
//    }

//    row_result = P[0] + P[1] * FeatureCol + P[2] * FeatureCol*FeatureCol;
//    std::cout << "所在的行数" << row_result << "   " << "所在的列数" << FeatureCol << std::endl;


////将特征点从像素坐标系下转移至相机坐标系下
///*相机的内外参使用的是a平面标定的结果：内参矩阵如下所示：
//[6026.7679813        0         1295.5
//0          6026.7679813   971.5
//0               0           1    ]
//*/
//    double Xc, Yc, Zc;
//    double  mid_result;
//    mid_result = α1 + 0.004005*(FeatureCol - 1295.5) + 6.654*(row_result - 971.5);
//    Zc = 220.15 * α1 / mid_result;
//    Xc = (FeatureCol - 1295.5)*Zc / α1;
//    Yc = (row_result - 971.5)*Zc / α1;


//    //将计算出来的特征点写入到txt文档中
//    std::fstream f;
//    //追加写入,在原来基础上加了ios::app
//    /*f.open("data.txt", ios::out | ios::app);*/
//    f.open("data.txt", ios::out | ios::app);
//    //输入你想写入的内容
//    f <<"Xc:"<< Xc << "   " << "Yc:" << Yc << "   " << "Zc:" << Zc << std::endl;
//    f << std::endl;
//    f.close();
//}

#endif // TEST_H
