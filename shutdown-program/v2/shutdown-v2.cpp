#ifdef _WIN32
  #include <Windows.h>
#else
  #include <unistd.h>
#endif

#include <boost/algorithm/string.hpp>
#include <cmath>
#include <cstdlib>
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

string getFormattedTime(int fullTimeInSeconds) {
  int oneHour = 3600;
  int hours   = floor(fullTimeInSeconds / oneHour);
  int minutes = floor((fullTimeInSeconds % oneHour) / 60);

  string hm("");
  hm.append(formatHours(hours));
  hm.append("\033[0;32mh\033[0m");
  hm.append(":");
  hm.append(formatMinuts(minutes));
  hm.append("\033[0;34mm\033[0m");

  // cout << "getFormattedTime: " << formatHours(hours) << ":" << formatMinuts(minutes) << "\n";
  return hm;
};

int formatfullTimeInSeconds(string fullTime) {
  vector<string> split;
  boost::split(split, fullTime, boost::is_any_of(":"));

  // for (size_t i = 0; i < split.size(); i++) {
  //   cout << split[i] << "\n";
  // }

  string formatedHours  = formatHours(stoi(split[0]));
  string formatedMinuts = formatMinuts(stoi(split[1]));

  int hours   = stoi(formatedHours) * 60 * 60;
  int minutes = stoi(formatedMinuts) * 60;
  // cout << "formatfullTimeInSeconds h: " << hours << " m:" << minutes << "\n";

  int fullTimeInSeconds = hours + minutes;
  // cout << "formatfullTimeInSeconds: " << fullTimeInSeconds << "\n";

  return fullTimeInSeconds;
};

string inputStringSystem(int fullTimeInSeconds) {
  string command("");
  command.append("Shutdown /s /t ");
  command.append(to_string(fullTimeInSeconds));

  return command;
};

int main(int argc, char const *argv[]) {
  system("title desligar automaticamente com tempo especificado");

  string time("");

  cout << "digite um tempo para desligar o \033[0;36mSISTEMA\033[0m em "
          "\033[0;32mhh\033[0m:\033[0;34mmm\033[0m"
          " | \033[0;32mhh\033[0m=horas : \033[0;34mmm\033[0m=minutos\n";
  cout << "\033[31;107m 9 \033[0m para cancelar o desligamento\n";
  cout << "\033[0;31m=> \033[0m";
  cin >> time;

  if (time == "9") {
    cout << "\033[0;32mdesligamento cancelado...\033[0m\n";
    system("Shutdown /a");
    Sleep(1000); // espera 1 segundo para finalizar o shutdown
    return 0;
  }

  if (time.empty()) {
    cout << "\033[0;31mtempo invalido\033[0m\n";
    return 1;
  }

  if (time.length() < 2 || time.length() > 4) {
    cout << "\033[0;31mtempo invalido\033[0m\n";
    return 1;
  }

  int fullTimeInSeconds = formatfullTimeInSeconds(time);
  // cout << "fullTimeInSeconds: " << fullTimeInSeconds << "\n";

  string formattedTimeHm = getFormattedTime(fullTimeInSeconds);
  // cout << "formattedTimeHm: " << formattedTimeHm << "\n";

  cout << "\033[0;31mdesligando em:\033[0m " << formattedTimeHm << "\n";

  string command = inputStringSystem(fullTimeInSeconds);
  system(command.c_str());

  Sleep(1000); // espera 1 segundo para desligar o sistema
  return 0;
}
