#ifndef CUMRES_H
#define CUMRES_H

#include <cmath>
#include <omp.h>
#include "matrix.h" 


inline double ss2(const scythe::Matrix<double> &M) {
  return(std::sqrt(scythe::sum(M%M)));
}

double KolmogorovSmirnov(const scythe::Matrix<double> &W);

double CramerVonMises(const scythe::Matrix<double> &W, const scythe::Matrix<double> &It, unsigned var);

double AndersonDarling (const scythe::Matrix<double> &W, const scythe::Matrix<double> &It, unsigned var);

scythe::Matrix<double> ProdMat(const scythe::Matrix<double> &A, const scythe::Matrix<double> &B);

scythe::Matrix<> SumMat(const scythe::Matrix<> &M);

scythe::Matrix<> cumsum(const scythe::Matrix<> &M);

#endif /* CUMRES_H */
