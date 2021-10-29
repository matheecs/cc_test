#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/LU>
#include <Eigen/QR>
#include <chrono>
#include <iostream>

using namespace Eigen;
using namespace std;
using vector3_t = Eigen::Matrix<double, 3, 1>;

class SGFliter {
 public:
  SGFliter(int F, int order) : F_(F), k_(order + 1) {
    auto t = VectorXi::LinSpaced(F_, (-(F_ - 1) / 2), ((F_ - 1) / 2))
                 .transpose()
                 .eval();  // t = -n -(n-1) ... (n-1) n

    V_.resize(F_, k_);

    for (auto i = 0; i < F_; ++i) {
      for (auto j = 0; j < k_; ++j) {
        V_(i, j) = pow(t(i), j);
      }
    }
  }

  MatrixXd getB() {
    // Compute the QR Decomposition
    MatrixXd Vd = V_.cast<double>();

    HouseholderQR<MatrixXd> qr(Vd);
    qr.compute(Vd);
    FullPivLU<MatrixXd> lu_decomp(Vd);
    auto rank = lu_decomp.rank();
    MatrixXd R = qr.matrixQR()
                     .topLeftCorner(rank, rank)
                     .template triangularView<Upper>();

    auto Rinv = R.inverse();
    MatrixXd RinvT = Rinv.transpose();
    MatrixXd VdT = Vd.transpose().eval();
    MatrixXd B = Vd * Rinv * RinvT * VdT;  // VdT * Vd = RT * R
    return B;
  }

 private:
  int F_;       // F = 2n+1
  int k_;       // k_ = order + 1
  MatrixXi V_;  // vandermonde
};

int main() {
  SGFliter sg(5, 1);
  cout << sg.getB() << endl;

  vector3_t v(10, 11, 12);

  cout << "v(0) = " << v(0) << endl;

  Eigen::Matrix<double, 4, 3> A;
  A << 1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1, 0;

  cout << A << endl;

  // auto t1 = chrono::high_resolution_clock::now();
  // MatrixXd A = MatrixXd::Random(10000, 2000);
  // MatrixXd B = MatrixXd::Random(10000, 2000);
  // MatrixXd C = A * B.transpose();
  // cout << C(0, 0) << C(999, 999) << endl;
  // auto t2 = chrono::high_resolution_clock::now();
  // cout << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() <<
  // endl;
}