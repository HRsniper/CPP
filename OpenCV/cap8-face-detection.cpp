#include <iostream>
#include <string>

#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>

#include <opencv4/opencv2/objdetect.hpp>

using namespace std;
using namespace cv;

int main(int argc, char const *argv[]) {
  string image_path = "murtazaface.png";

  Mat img = imread(image_path);

  if (img.empty()) {
    cout << "Não foi possível ler a imagem: " << image_path << endl;
    return 1;
  }

  // Classe classificadora em cascata usada para detecção de objetos.
  CascadeClassifier faceCascade;

  string xml_path = "haarcascade_frontalface_default.xml";
  // Carrega um classificador de um arquivo.
  faceCascade.load(xml_path);

  if (faceCascade.empty()) {
    cout << "Não foi possível ler o XML: " << xml_path << endl;
    return 1;
  }

  vector<Rect> faces;
  // Detecta objetos de tamanhos diferentes na imagem de entrada. Os objetos detectados são retornados como
  // uma lista de retângulos.
  faceCascade.detectMultiScale(img, faces, 1.1, 10);

  for (size_t i = 0; i < faces.size(); i++) {
    rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 255, 0), 2);
  }

  imshow("Image", img);

  waitKey(0);

  return 0;
}