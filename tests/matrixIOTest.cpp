#define BOOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"

using namespace Eigen;

struct matrixIOFixture {
  matrixIOFixture()
  {
    expectedMatrix = MatrixXd(3, 3);
    expectedMatrix << 0.680375, 0.59688, -0.329554,
        -0.211234, 0.823295, 0.536459,
        0.566198, -0.604897, -0.444451;
  }

  MatrixXd expectedMatrix;
};

BOOST_FIXTURE_TEST_SUITE(matrixIOTests, matrixIOFixture)

BOOST_AUTO_TEST_CASE(matrixIOTests)
{
  MatrixXd readMatrix = matrixIO::openData("../data/m3.csv", 3);

  BOOST_TEST(expectedMatrix(0, 0) == readMatrix(0, 0));
  BOOST_TEST(expectedMatrix(0, 1) == readMatrix(0, 1));
  BOOST_TEST(expectedMatrix(0, 2) == readMatrix(0, 2));
  BOOST_TEST(expectedMatrix(1, 0) == readMatrix(1, 0));
  BOOST_TEST(expectedMatrix(1, 1) == readMatrix(1, 1));
  BOOST_TEST(expectedMatrix(1, 2) == readMatrix(1, 2));
  BOOST_TEST(expectedMatrix(2, 0) == readMatrix(2, 0));
  BOOST_TEST(expectedMatrix(2, 1) == readMatrix(2, 1));
  BOOST_TEST(expectedMatrix(2, 2) == readMatrix(2, 2));
}

BOOST_AUTO_TEST_SUITE_END()
