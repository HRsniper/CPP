#include <iostream>
#include <string>

// #include <opencv4/opencv2/opencv.hpp>
// #include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>

int main(int argc, char const *argv[]) {
  cv::VideoCapture cap(0);
  cv::Mat          img;

  while (true) {
    cap.read(img);
    cv::imshow("Aperte qualquer tecla para fechar", img);
    cv::waitKey(1); // Aguardando ate pressionamento de tecla
  }

  return 0;
}
