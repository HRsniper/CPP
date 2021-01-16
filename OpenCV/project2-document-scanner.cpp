#include <iostream>
#include <string>

#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>

#include <opencv4/opencv2/objdetect.hpp>

using namespace std;
using namespace cv;

Mat           preProcessing(Mat ImgOriginal);
vector<Point> getContours(Mat imgDilate);
void          drawPoints(vector<Point> points, Scalar color);
vector<Point> reorder(vector<Point> points);
Mat           getWarp(Mat imgOriginal, vector<Point> points, float width, float height);
Mat           imageCrop(int cropValue, Mat imgOriginal);

Mat           imgOriginal, imgCanny, imgGray, imgThre, imgBlur, imgDilate, imgErode, imgWarp, imgCrop;
vector<Point> initialPoints, docPoints;
float         width = 450, height = 596;

int main(int argc, char const *argv[]) {

  string image_path = "testopencvpaper.jpg";
  imgOriginal       = imread(image_path);
  // resize(imgOriginal, imgOriginal, Size(), 0.5, 0.5);

  // preprossesamento
  imgThre = preProcessing(imgOriginal);

  // pegar os contornos
  initialPoints = getContours(imgThre);
  // drawPoints(initialPoints, Scalar(255, 0, 0));
  docPoints = reorder(initialPoints);
  // drawPoints(docPoints, Scalar(0, 0, 255));

  // retorcer a imagem
  imgWarp = getWarp(imgOriginal, docPoints, width, height);

  // recortar
  imgCrop = imageCrop(5, imgWarp);

  imshow("Image Original", imgOriginal);
  // imshow("Image Dilate", imgThre);
  imshow("Image Crop", imgCrop);
  waitKey(0); // Aguardando ate pressionamento de tecla

  return 0;
}

Mat preProcessing(Mat ImgOriginal) {
  cvtColor(ImgOriginal, imgGray, COLOR_BGR2GRAY);
  GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
  Canny(imgBlur, imgCanny, 25, 75);
  Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
  dilate(imgCanny, imgDilate, kernel);
  // erode(imgDilate, imgErode, kernel);

  return imgDilate;
}

vector<Point> getContours(Mat imgDilate) {
  vector<vector<Point>> contours;
  vector<Vec4i>         hierarchy;

  findContours(imgDilate, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

  vector<vector<Point>> contoursPoly(contours.size());
  vector<Rect>          boundRect(contours.size());
  vector<Point>         Biggest;
  int                   maxArea;

  for (size_t i = 0; i < contours.size(); i++) {
    double area = contourArea(contours[i]);
    cout << "area" << i << ": " << area << endl;

    if (area > 1000) {

      double perimeter    = arcLength(contours[i], true);
      double roundNumbers = 0.02 * perimeter;

      approxPolyDP(contours[i], contoursPoly[i], roundNumbers, true);

      int areaEdges = contoursPoly[i].size();

      if (area > maxArea && areaEdges == 4) {
        Biggest = {
          { contoursPoly[i][0] }, { contoursPoly[i][1] }, { contoursPoly[i][2] }, { contoursPoly[i][3] }
        };

        maxArea = area;

        // drawContours(imgOriginal, contoursPoly, i, Scalar(0, 255, 0), 4);
      }

      // boundRect[i] = boundingRect(contoursPoly[i]);
      // rectangle(imgOriginal, boundRect[i].tl(), boundRect[i].br(), Scalar(255, 0, 0), 2);
    }
  }
  return Biggest;
}

void drawPoints(vector<Point> points, Scalar color) {

  for (size_t i = 0; i < points.size(); i++) {
    circle(imgOriginal, points[i], 4, color, FILLED);
    putText(imgOriginal, to_string(i), points[i], FONT_HERSHEY_PLAIN, 2, color, 2);
  }
}

// reorder os pontos 0,1,2,3 para sempre sair na mesma posição
vector<Point> reorder(vector<Point> points) {
  vector<Point> newPoints;
  vector<int>   sumPoints, subPoints;

  for (size_t i = 0; i < 4; i++) {
    sumPoints.push_back(points[i].x + points[i].y);
    subPoints.push_back(points[i].x - points[i].y);
  }

  //                         get index value
  newPoints.push_back(points[min_element(sumPoints.begin(), sumPoints.end()) - sumPoints.begin()]); // 0
  newPoints.push_back(points[max_element(subPoints.begin(), subPoints.end()) - subPoints.begin()]); // 1
  newPoints.push_back(points[min_element(subPoints.begin(), subPoints.end()) - subPoints.begin()]); // 2
  newPoints.push_back(points[max_element(sumPoints.begin(), sumPoints.end()) - sumPoints.begin()]); // 3

  return newPoints;
}

Mat getWarp(Mat imgOriginal, vector<Point> points, float width, float height) {
  //                         top-left  top-right  botton-left botton-right
  Point2f src[4]         = { points[0], points[1], points[2], points[3] };
  Point2f destination[4] = { { 0.0f, 0.0f }, { width, 0.0f }, { 0.0f, height }, { width, height } };

  Mat matrix = getPerspectiveTransform(src, destination);

  warpPerspective(imgOriginal, imgWarp, matrix, Point(width, height));

  return imgWarp;
}

Mat imageCrop(int cropValue, Mat imgWarp) {

  Rect roi(cropValue, cropValue, width - (2 * cropValue), height - (2 * cropValue));
  imgCrop = imgWarp(roi);
  return imgCrop;
}