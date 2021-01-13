#include <iostream>
#include <string>

// #include <opencv4/opencv2/opencv.hpp>
// #include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>

int main(int argc, char const *argv[]) {
  std::string image_path = "testopencvimage.bmp";

  cv::Mat img = cv::imread(image_path);

  if (img.empty()) {
    std::cout << "Não foi possível ler a imagem: " << image_path << std::endl;
    return 1;
  }

  cv::imshow("Aperte qualquer tecla para fechar", img);

  cv::waitKey(0); // Aguardando ate pressionamento de tecla na janela para fechar a janela

  return 0;
}
