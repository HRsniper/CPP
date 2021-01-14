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
  // caminho para eng.traineddata
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

  std::vector<std::string> split_array;
  boost::split(split_array, outBox, boost::is_any_of("\n"));

  // for (size_t i = 0; i < split_array.size(); i++) {
  //   std::cout << split_array[i] << std::endl;
  // }

  std::vector<std::string> sub_split_array0;
  boost::split(sub_split_array0, split_array[0], boost::is_any_of(" "));

  std::vector<std::string> sub_split_array1;
  boost::split(sub_split_array1, split_array[1], boost::is_any_of(" "));

  std::vector<std::string> sub_split_array2;
  boost::split(sub_split_array2, split_array[2], boost::is_any_of(" "));

  std::vector<std::string> sub_split_array3;
  boost::split(sub_split_array3, split_array[3], boost::is_any_of(" "));

  std::vector<std::string> sub_split_array4;
  boost::split(sub_split_array4, split_array[4], boost::is_any_of(" "));

  std::vector<std::string> sub_split_array5;
  boost::split(sub_split_array5, split_array[5], boost::is_any_of(" "));

  std::vector<std::string> sub_split_array6;
  boost::split(sub_split_array6, split_array[6], boost::is_any_of(" "));

  std::vector<std::string> sub_split_array7;
  boost::split(sub_split_array7, split_array[7], boost::is_any_of(" "));

  cv::Point pt1 = cv::Point(std::stoi(sub_split_array0[1]), std::stoi(sub_split_array0[2]));
  // cv::Point y = cv::Point(std::stoi(sub_split_array0[2]));
  cv::Point pt2 = cv::Point(std::stoi(sub_split_array0[3]), std::stoi(sub_split_array0[4]));
  // cv::Point h = cv::Point(std::stoi(sub_split_array0[4]));
  std::cout << pt1 << std::endl;
  std::cout << pt2 << std::endl;

  cv::rectangle(img, cv::Point(6, 50), cv::Point(61, 107), cv::Scalar(0, 0, 255));

  // std::vector<std::vector<std::string>> expect = {
  //   // {"text","x","y","width","height"}
  //   { "H", "6", "50", "61", "107", "0" },    { "R", "73", "50", "129", "107", "0" },
  //   { "s", "158", "49", "202", "92", "0" },  { "n", "209", "50", "254", "92", "0" },
  //   { "i", "263", "50", "280", "107", "0" }, { "p", "290", "34", "336", "92", "0" },
  //   { "e", "340", "49", "389", "92", "0" },  { "r", "396", "50", "429", "92", "0" }
  // };

  // destruindo e limpando tesseract OCR engine
  tesseract->Clear();
  tesseract->End();

  int key = cv::waitKey(0); // Aguardando ate pressionamento de tecla na janela para fechar a janela

  return 0;
}
