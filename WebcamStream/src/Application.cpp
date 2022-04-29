#include "Application.h"

Application::Application()
{
	std::cout << "Application Created" << std::endl;
}

Application::~Application()
{
	std::cout << "Application Destructed" << std::endl;
}

void Application::Run()
{
	cv::VideoCapture cap(0);
	if (!cap.isOpened())
	{
		std::cout << "Camera is not found" << std::endl;
		return;
	}

	// Call threads
	RotateFrameWorker workerRotate(m_mainFrame);
	AlgorithmFrameWorker workerAlgorithm(m_mainFrame);

	std::thread worker1(&RotateFrameWorker::ProcessFrame, std::ref(workerRotate));
	std::thread worker2(&AlgorithmFrameWorker::ProcessFrame, std::ref(workerAlgorithm));

	while (true)
	{
		cap >> m_mainFrame;
	}
}
