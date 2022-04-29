#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>
#include <thread>

#include "RotateFrameWorker.h"
#include "AlgorithmFrameWorker.h"

class Application
{
public:
	Application();
	~Application();
	void Run();
private:
	cv::Mat m_mainFrame;
};

