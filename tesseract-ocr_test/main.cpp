#include <iostream>
#include <string>
#include <vector>

#include <leptonica/allheaders.h>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <tesseract/baseapi.h>

#include <boost/algorithm/string.hpp>

int main(int argc, char const *argv[]) {
  const char *tessdata_path = "C:/Desenvolvimento/msys64/mingw64/share/tessdata";
  std::string image_path    = cv::samples::findFile("testopencv.bmp");

  cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);
  cv::cvtColor(img, img, cv::COLOR_BGR2RGB);

  if (img.empty()) {
    std::cout << "Não foi possível ler a imagem: " << image_path << std::endl;
    return 1;
  }

  cv::imshow("Aperte qualquer tecla para fechar", img);

  // inicializando tesseract OCR engine
  tesseract::TessBaseAPI *tesseract = new tesseract::TessBaseAPI();
  // tesseract::TessBaseAPI tesseract;

  tesseract->Init(tessdata_path, "eng", tesseract::OEM_COUNT);
  tesseract->SetPageSegMode(tesseract::PSM_AUTO);

  tesseract->SetImage(img.data, img.size().width, img.size().height, img.channels(), img.step);

  std::string outText = tesseract->GetUTF8Text();
  // int         confidence = tesseract->MeanTextConf();

  // detectando letras
  std::string outBox = tesseract->GetBoxText(0);

  std::cout << "Text: " << outText;
  // std::cout << "Confidence: " << confidence << std::endl;
  // std::cout << "Box: " << outBox << std::endl;

  std::vector<std::string> r;
  boost::split(r, outBox, boost::is_any_of("\n"));

  for (int i = 0; i < r.size() - 1; i++) {
    std::cout << r[i] << std::endl;
  }

  // destruindo e limpando tesseract OCR engine
  tesseract->Clear();
  tesseract->End();

  int key = cv::waitKey(0); // Aguardando ate pressionamento de tecla na janela para fechar a janela

  return 0;
}
