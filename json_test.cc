#include <iomanip>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
  json j;
  j["0"]["x"] = 1;
  j["1"]["x"] = 1;
  j["2"]["x"] = 1.4;
  j["2"]["y"] = 1.4;
  j["2"]["y"] = 1.7;
  j.erase(j.find("2"));

  std::cout << std::setw(4) << j << std::endl;
}