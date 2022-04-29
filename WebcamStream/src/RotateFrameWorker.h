#pragma once
#include <opencv2/opencv.hpp>

class RotateFrameWorker
{
public:
	RotateFrameWorker(cv::Mat& frame);
	void ProcessFrame();

private:
	void RotateFrame();
	void ParameterController();

private:
	cv::Mat& m_frame;
	cv::Mat m_frameBuffer[10];
	cv::Mat m_tempFrame;

	int m_frameBufferIndex = 0;
	int m_frameIndex = 0;
	int m_frameRotation = 2;
};

