#include <iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	cv::Mat dstMat;
	cv::Mat srcMat = cv::imread("D:\\Files\\lena.jpg");//读取图像
	if (srcMat.empty())//检测图像是否读取成功
	{
		return -1;
	}
	//变换前三点坐标
	const cv::Point2f src_pt[] = {
									cv::Point2f(200,200),
									cv::Point2f(250,200),
									cv::Point2f(200,100) };
	//变换后三点坐标
	const cv::Point2f dst_pt[] = {
									cv::Point2f(300,100),
									cv::Point2f(300,50),
									cv::Point2f(200,100) };
	//计算仿射矩阵
	const cv::Mat affine_matrix = cv::getAffineTransform(src_pt, dst_pt);
	cv::warpAffine(srcMat, dstMat, affine_matrix, srcMat.size());//进行仿射变换
	cv::imshow("src", srcMat);//输出原图像
	cv::imshow("dst", dstMat);//输出仿射变换后图像
	waitKey(0);
}