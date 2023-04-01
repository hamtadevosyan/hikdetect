#include <opencv2/opencv.hpp>
#include <boost/program_options.hpp>
#include <iostream>
#include <fstream>
#include "camera.h"


void getUsernameAndPassword(const std::string &pFileName, std::string &pUserName, std::string &pPassword)
{

	std::string line;
	std::ifstream file(pFileName);
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		if (!(iss >> pUserName >> pPassword)) { break; } // error
	}
}

void getRTSPString(const std::string &pFileName, std::string &pRTSPString)
{
	std::ifstream file(pFileName);
	std::getline(file, pRTSPString);
}


int main(int argc, char **argv)
{
	namespace po = boost::program_options;
	po::options_description ops("Options");
	std::string configFile("");
	ops.add_options()
		("help", "produce help message")
		("config", po::value<std::string>(&configFile), "Config file name.")
		;

	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, ops), vm);
	po::notify(vm);

	if(vm.count("help")) {
		std::cout << ops << "\n";
		return 1;
	}
//	std::string lUserName = "";
//	std::string lPassword = "";
//	getUsernameAndPassword(configFile, lUserName, lPassword);

	//Camera cam("rtsp://UserName:Password@1.1.1.1:111/ISAPI/Streaming/Channels/102");
	std::string rtspString = "";
	getRTSPString(configFile, rtspString);
	Camera cam(rtspString);
	cv::namedWindow("TEST", cv::WINDOW_AUTOSIZE);

	cv::Mat frame;

	while(true) {
		if(!cam.getFrame(frame)) {
			std::cout << "Failed to capture image!" << std::endl;
			break;
		}
		cv::imshow("TEST", frame);

		cv::waitKey(30);
	}
	return 0;
}
