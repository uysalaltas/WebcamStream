#include "RotateFrameWorker.h"

RotateFrameWorker::RotateFrameWorker(cv::Mat& frame)
	: m_frame(frame)
{

}

void RotateFrameWorker::ProcessFrame()
{
	while (true)
	{
		if (!m_frame.empty())
		{
			if (m_frameIndex % 2 == 1) 
			{
				m_frameBuffer[m_frameBufferIndex] = m_frame;
				RotateFrame();

				cv::cvtColor(
					m_tempFrame,
					m_tempFrame,
					cv::COLOR_BGR2GRAY
				);

				cv::imshow(
					"Worker1 Window", 
					m_tempFrame
				);

				ParameterController();
			}
			
			m_frameIndex += 1;
			
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

void RotateFrameWorker::RotateFrame()
{
	if (m_frameBufferIndex % 5 == 0)
	{
		if (m_frameRotation == 3)
		{
			m_frameRotation = 0;
		}
		else
		{
			m_frameRotation += 1;
		}
	}

	m_tempFrame = m_frameBuffer[m_frameBufferIndex].clone();

	if (m_frameRotation < 3)
	{
		cv::rotate(
			m_tempFrame,
			m_tempFrame,
			m_frameRotation
		);
	}
}

void RotateFrameWorker::ParameterController()
{
	m_frameBufferIndex += 1;
	if (m_frameBufferIndex == 10)
	{
		m_frameBufferIndex = 0;
	}
}
