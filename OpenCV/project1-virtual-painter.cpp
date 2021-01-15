#include <iostream>
#include <string>

#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>

#include <opencv4/opencv2/objdetect.hpp>

using namespace std;
using namespace cv;

Mat imgs;

// cores pegadas pelo color-picker
vector<vector<int>> Colors = {
  // hmin,smin,vmin,hmax,smax,vmax
  { 170, 88, 206, 179, 149, 255 }, // red
  { 85, 53, 158, 107, 120, 215 },  // green
  { 102, 81, 197, 117, 144, 255 }, // blue
};

vector<Scalar> ColorsValues = {
  { 0, 0, 255 }, // red
  { 0, 255, 0 }, // green
  { 255, 0, 0 }  // blue
};

vector<vector<int>> newPoints;

vector<vector<int>> findColor(Mat imgs);

Point getContours(Mat imgDilate);

void drawOnCanvas(vector<vector<int>> newPoints, vector<Scalar> ColorsValues);

int main(int argc, char const *argv[]) {
  int          camera_id = 0;
  VideoCapture capture(camera_id);

  while (true) {
    capture.read(imgs);

    newPoints = findColor(imgs);
    drawOnCanvas(newPoints, ColorsValues);

    imshow("Virtual Painter", imgs);
    waitKey(1); // Aguardando 1ms entre as images
  }

  return 0;
}

vector<vector<int>> findColor(Mat imgs) {
  int hmin = 0, smin = 14, vmin = 151;
  int hmax = 209, smax = 121, vmax = 255;
  Mat imgHsv, mask;

  cvtColor(imgs, imgHsv, COLOR_BGR2HSV);

  for (size_t i = 0; i < Colors.size(); i++) {

    Scalar lowerLimit(Colors[i][0], Colors[i][1], Colors[i][2]);
    Scalar upperLimit(Colors[i][3], Colors[i][4], Colors[i][5]);

    inRange(imgHsv, lowerLimit, upperLimit, mask);

    Point topMiddlePoint = getContours(mask);

    if (topMiddlePoint.x != 0 && topMiddlePoint.y != 0) {

      newPoints.push_back({ topMiddlePoint.x, topMiddlePoint.y, int(i) });
    }

    imshow(to_string(i), mask);
  }
  return newPoints;
}

Point getContours(Mat imgDilate) {
  vector<vector<Point>> contours;
  vector<Vec4i>         hierarchy;

  findContours(imgDilate, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

  vector<vector<Point>> contoursPoly(contours.size());
  vector<Rect>          boundRect(contours.size());
  Point                 Points(0, 0);

  for (size_t i = 0; i < contours.size(); i++) {
    double area = contourArea(contours[i]);
    cout << "area" << i << ": " << area << endl;

    if (area > 100) {

      double perimeter    = arcLength(contours[i], true);
      double roundNumbers = 0.02 * perimeter;

      approxPolyDP(contours[i], contoursPoly[i], roundNumbers, true);
      boundRect[i] = boundingRect(contoursPoly[i]);

      Points.x = boundRect[i].x + boundRect[i].width / 2;
      Points.y = boundRect[i].y;

      drawContours(imgs, contoursPoly, i, Scalar(0, 255, 0), 2);
      rectangle(imgs, boundRect[i].tl(), boundRect[i].br(), Scalar(255, 0, 0), 2);
    }
  }
  return Points;
}

void drawOnCanvas(vector<vector<int>> newPoints, vector<Scalar> ColorsValues) {

  for (size_t i = 0; i < newPoints.size(); i++) {
    circle(imgs, Point(newPoints[i][0], newPoints[i][1]), 10, ColorsValues[newPoints[i][2]], FILLED);
  }
}