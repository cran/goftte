//Use of functions computed by Klaus K. Holst in gof package

#ifndef EXTRA_H
#define EXTRA_H

#include <cmath>
#include <functional>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include "matrix.h"

using namespace scythe;
using namespace std;

inline Matrix<unsigned> boolidx(const Matrix<bool> &idx) {
  unsigned n = sum(idx);
  Matrix<unsigned> Ridx(n,1);
  unsigned pos = 0;
  for (unsigned i=0; i<n; i++)  {
    if (idx[i]) { Ridx[i]=pos; pos++; }
  }
  return(Ridx);
}

template <typename T>
inline Matrix<T> chrows(const Matrix<T> &m, const Matrix<bool> &idx) {
  assert (m.rows()==idx.size()); 
  Matrix<unsigned> Ridx = boolidx(idx);
  Matrix<T> res(Ridx.size(), m.cols());
  for (unsigned i=0; i<Ridx.size(); i++) {
    res(i,_) = m(Ridx[i],_);
  }  
  return(res);
}
template <typename T>
inline Matrix<T> chrows(const Matrix<T> &m, const Matrix<unsigned> &idx) {
  Matrix<T> res(idx.size(), m.cols(), false);
  for (unsigned i=0; i<idx.size(); i++) {
    res(i,_) = m(idx[i],_);
  }
  return(res);
}

template <typename T>
Matrix<T> multCol(const Matrix<T> &m, const Matrix<T> &c) { // Multiply vector c with each column of m
  Matrix<T> res = m;
  for (unsigned i=0; i<m.cols(); i++)
    res(_,i) %= c;
  return(res);
}

template <typename T>
inline  Matrix<T> apply(const Matrix<T> &m, unsigned doRow,T (*fun)(const Matrix<T>&)){
  if(doRow==1){
    Matrix<T> res(m.rows(),1);
    for (unsigned i=0; i<m.rows(); i++) {
      Matrix<T> r = m(i,_);
      res[i] = (*fun)(r);      
      //      res(i,_) = fun(r);
    } 
    return(res);  
  } else {
    Matrix<T> res(m.cols(),1);
    for (unsigned i=0; i<m.cols(); i++) {
      Matrix<T> r = m(_,i);
      //      res(i,_) = fun(r);
      res[i] = (*fun)(r);
    }
    return(res);   
  }
}

template <typename T, typename FUNCTOR>
inline Matrix<T> apply(const Matrix<T> &m, unsigned doRow, FUNCTOR fun){
  //Matrix<T> apply(const Matrix<T> &m, unsigned doRow, T (*fun)(const Matrix<T>&)){
  if(doRow==1){
    Matrix<T> res(m.rows(),1);
    for (unsigned i=0; i<m.rows(); i++) {
      Matrix<T> r = m(i,_);
      //      res[i] = (*fun)(r);      
      res[i] = fun(r);
    } 
    return(res);  
  } else {
    Matrix<T> res(m.cols(),1);
    for (unsigned i=0; i<m.cols(); i++) {
      Matrix<T> r = m(_,i);
      res[i] = fun(r);
    }
    return(res);   
  }
}

#endif /* EXTRA_H */
