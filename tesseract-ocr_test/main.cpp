#include <iostream>
#include <string>

#include <leptonica/allheaders.h>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <tesseract/baseapi.h>

int main(int argc, char const *argv[]) {

  std::string image_path = cv::samples::findFile("testopencv.bmp");

  cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);

  if (img.empty()) {
    std::cout << "Não foi possível ler a imagem: " << image_path << std::endl;
    return 1;
  }

  cv::imshow("Aperte qualquer tecla para fechar", img);

  // initilize tesseract OCR engine
  tesseract::TessBaseAPI *tesseract = new tesseract::TessBaseAPI();
  // tesseract::TessBaseAPI tesseract;

  tesseract->Init("tessdata", "osd", tesseract::OEM_COUNT);
  tesseract->SetPageSegMode(tesseract::PSM_AUTO);

  tesseract->SetImage(img.data, img.cols, img.rows, 1, img.step);

  std::string outText    = std::string(tesseract->GetUTF8Text());
  int         confidence = tesseract->MeanTextConf();

  std::cout << "Text: " << outText << std::endl;
  std::cout << "Confidence: " << confidence << std::endl;

  // destroy tesseract OCR engine
  tesseract->Clear();
  tesseract->End();

  int k = cv::waitKey(0); // Aguardando ate pressionamento de tecla na janela para fechar a janela

  return 0;
}
