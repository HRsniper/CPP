#include <iostream>
#include <string>

#include <opencv4/opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char const *argv[]) {

  const string file = "D:\\Deadpool 1 (2016) e 2 (2018) (1080p)\\Deadpool 2016 Bluray 1080p Dublado.mp4";

  VideoCapture cap(file, CAP_DSHOW);

  cap.open(file, CAP_DSHOW);

  waitKey(0);

  return 0;
}
