#include <boost/algorithm/string.hpp>
#include <cmath>
#include <fmt/core.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string formatHours(int hours) {
  if (hours < 10) {
    string h("0");
    h.append(to_string(hours));
    // cout << "formatHours: " << h << "\n";
    return h;
  }

  // cout << "formatHours: " << to_string(hours) << "\n";
  return to_string(hours);
};

string formatMinuts(int minuts) {
  if (minuts < 10) {
    string m("0");
    m.append(to_string(minuts));
    // cout << "formatMinuts: " << m << "\n";
    return m;
  }

  // cout << "formatMinuts: " << to_string(minuts) << "\n";
  return to_string(minuts);
};

string getFormatTime(int fullTimeInSeconds) {
  int oneHour = 3600;
  int hours   = floor(fullTimeInSeconds / oneHour);
  int minutes = floor((fullTimeInSeconds % oneHour) / 60);

  string hm("");
  hm.append(formatHours(hours));
  hm.append(":");
  hm.append(formatMinuts(minutes));

  // cout << "getFormatTime: " << formatHours(hours) << ":" << formatMinuts(minutes) << "\n";
  return hm;
};

int formatTimeInSeconds(string fullTime) {
  vector<string> split;
  boost::split(split, fullTime, boost::is_any_of(":"));

  // for (size_t i = 0; i < split.size(); i++) {
  //   cout << split[i] << "\n";
  // }

  string formatedHours  = formatHours(stoi(split[0]));
  string formatedMinuts = formatMinuts(stoi(split[1]));

  int hours   = stoi(formatedHours) * 60 * 60;
  int minutes = stoi(formatedMinuts) * 60;
  // cout << "formatTimeInSeconds h: " << hours << " m:" << minutes << "\n";

  int fullTimeInSeconds = hours + minutes;
  // cout << "formatTimeInSeconds: " << fullTimeInSeconds << "\n";

  return fullTimeInSeconds;
};

int main(int argc, char const *argv[]) {
  string time("");

  cout << "digite um tempo em hh:mm | hh=Horas, mm=Minutos\n";
  cout << "=> ";
  cin >> time;

  if (time.empty()) {
    cout << "tempo invalido\n";
    return 1;
  }

  if (time.length() < 2 || time.length() > 4) {
    cout << "tempo invalido\n";
    return 1;
  }

  int timeInSeconds = formatTimeInSeconds(time);
  cout << "timeInSeconds: " << timeInSeconds << "\n";

  string formatedTimeHm = getFormatTime(timeInSeconds);
  cout << "formatedTimeHm: " << formatedTimeHm << "\n";

  return 0;
}
