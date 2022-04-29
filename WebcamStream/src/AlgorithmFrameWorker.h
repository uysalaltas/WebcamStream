#pragma once
#include <opencv2/opencv.hpp>

class AlgorithmFrameWorker
{
public:
	AlgorithmFrameWorker(cv::Mat& frame);
	void ProcessFrame();
private:
	void MeasureLeftRightIntensity();
private:
	cv::Mat& m_frame;
	cv::TickMeter _tickMeter;

	int m_rows = 0;
	int m_cols = 0;
	int m_intensityLeft = 0;
	int m_intensityRight = 0;
	int m_algorithmPerformance = 0;
};

