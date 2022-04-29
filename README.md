# WebcamStream
Project for assignment.

As requested, 2 workers were created and run on different threads.

In Worker 2, CIELab color space is used. 

The reasons are:
* CIELab space can seperate lightness value from color.
* Designed to approximate human vision.

## Usage

Currently only support windows.

Run `GenerateProject.bat` and open `WebcamStream.sln` in Visual Studio 2022. That's it.

vendor folders contain 3th party libraries and tools (OpenCV, pramake).

src folder contains source file.
