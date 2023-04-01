#ifndef CAMERA_H
#define CAMERA_H

#include <opencv2/opencv.hpp>

class Camera
{
	cv::VideoCapture m_Capture;
public:
	Camera();
	Camera(const std::string &pRtsp);
	virtual ~Camera();
	bool getFrame(cv::Mat &p_Img);
};

#endif // !CAMERA_H

