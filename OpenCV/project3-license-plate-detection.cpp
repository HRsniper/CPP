#include <iostream>
#include <string>

#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>

#include <opencv4/opencv2/objdetect.hpp>

using namespace std;
using namespace cv;

// search on google for : russian number plates

int main(int argc, char const *argv[]) {
  int          camera_id = 0;
  VideoCapture cap(camera_id);
  Mat          img, imgCrop;

  // Classe classificadora em cascata usada para detecção de objetos.
  CascadeClassifier plateCascade;

  string xml_path = "haarcascade_russian_plate_number.xml";
  // Carrega um classificador de um arquivo.
  plateCascade.load(xml_path);

  if (plateCascade.empty()) {
    cout << "Não foi possível ler o XML: " << xml_path << endl;
    return 1;
  }

  vector<Rect> plates;

  while (true) {
    cap.read(img);
    // Detecta objetos de tamanhos diferentes na imagem de entrada. Os objetos detectados são retornados como
    // uma lista de retângulos.
    plateCascade.detectMultiScale(img, plates, 1.1, 10);

    for (size_t i = 0; i < plates.size(); i++) {
      imgCrop = img(plates[i]);
      // imshow(to_string(i), imgCrop);

      imwrite("Plates/" + to_string(i) + ".png", imgCrop);

      rectangle(img, plates[i].tl(), plates[i].br(), Scalar(0, 255, 0), 2);
    }

    imshow("Image", img);

    waitKey(1); // Aguardando 1ms entre as images
  }
  return 0;
}