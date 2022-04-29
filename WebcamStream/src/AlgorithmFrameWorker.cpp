#include "AlgorithmFrameWorker.h"

AlgorithmFrameWorker::AlgorithmFrameWorker(cv::Mat& frame)
	: m_frame(frame)
{

}

void AlgorithmFrameWorker::ProcessFrame()
{
	while (true)
	{
		if (!m_frame.empty())
		{
			_tickMeter.start();

			MeasureLeftRightIntensity();

			cv::Mat tempFlipFrame = m_frame.clone();
			if (m_intensityLeft > m_intensityRight)
			{
				std::cout << "Fliped" << std::endl;
				cv::flip(m_frame, tempFlipFrame, 1);
			}

			cv::imshow(
				"Worker2 Window",
				tempFlipFrame
			);

			auto sumTime = m_algorithmPerformance + _tickMeter.getTimeSec();
			if (sumTime < 1000)
			{
				auto timePassed = 1000 - sumTime;
				_sleep(timePassed);
			}
			_tickMeter.stop();
			std::cout << "Time: " << _tickMeter.getTimeSec() << std::endl;
			_tickMeter.reset();

			if (cv::waitKey(30) >= 0)
			{
				break;
			}
		}
		else
		{
			std::cout << "Frame is empty " << std::endl;
		}
	}
}

void AlgorithmFrameWorker::MeasureLeftRightIntensity()
{
	cv::Mat tempFrame;
	cv::cvtColor(
		m_frame,
		tempFrame,
		cv::COLOR_BGR2Lab
	);
	m_rows = m_frame.rows;
	m_cols = m_frame.cols;
	m_intensityLeft = 0;
	m_intensityRight = 0;

	for (int currentCols = 0; currentCols < m_cols / 2; currentCols++)
	{
		for (int currentRows = 0; currentRows < m_rows; currentRows++)
		{
			m_intensityLeft += tempFrame.at<cv::Vec3b>(currentRows, currentCols)[0];
		}
	}

	for (int currentCols = m_cols / 2; currentCols < m_cols; currentCols++)
	{
		for (int currentRows = 0; currentRows < m_rows; currentRows++)
		{
			m_intensityRight += tempFrame.at<cv::Vec3b>(currentRows, currentCols)[0];

		}
	}

	m_algorithmPerformance = rand() % 500 + 1000;
	std::cout << "Sleep: " << m_algorithmPerformance << std::endl;

	_sleep(m_algorithmPerformance);
}
