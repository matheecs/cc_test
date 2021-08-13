
#include <armadillo>
#include <chrono>
#include <iostream>

using namespace std;
using namespace arma;

int main() {
  auto t1 = chrono::high_resolution_clock::now();
  mat A(10000, 2000, fill::randu);
  mat B(10000, 2000, fill::randu);
  mat C = A * B.t();
  cout << C(0, 0) << C(999, 999) << endl;
  auto t2 = chrono::high_resolution_clock::now();
  cout << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() << endl;
  return 0;
}