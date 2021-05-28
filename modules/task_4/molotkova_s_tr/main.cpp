// Copyright 2021 Molotkova Svetlana
#include <time.h>
#include <gtest/gtest.h>
#include <limits.h>
#include <iostream>
#include <vector>

#include "./vert_gauss.h"

TEST(Matrix_testing, invalid_argument1) {
  int rows = 0;
  int cols = 0;
  ASSERT_ANY_THROW(matrixCreation(rows, cols));
}

TEST(Matrix_testing, invalid_argument2) {
  int rows = -1;
  int cols = 2;
  ASSERT_ANY_THROW(matrixCreation(rows, cols));
}

TEST(Gauss_filter, 1300x1200) {
  int rows = 9000;
  int cols = 9000;
  auto rand_matrix = matrixCreation(rows, cols);
  auto matrix = transpose(rand_matrix, rows, cols);
  std::swap(cols, rows);
  clock_t start = clock();
  auto matrix_seq = gaussFilter(matrix, rows, cols, 1, 5);
  clock_t end = clock();
  double seconds = (double)(end - start) / CLOCKS_PER_SEC;

  clock_t start1 = clock();
  auto matrix_thr = gaussFilter_par(matrix, rows, cols, 1, 5);
  clock_t end1 = clock();
  double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
  std::cout << "Ses " << seconds << std::endl;
  std::cout << "Parallel " << seconds1 << std::endl;
  ASSERT_EQ(matrix_seq, matrix_thr);
}

TEST(Gauss_filter, 2500x2500) {
  int rows = 250;
  int cols = 250;
  auto rand_matrix = matrixCreation(rows, cols);
  auto matrix = transpose(rand_matrix, rows, cols);
  std::swap(cols, rows);
  auto matrix_seq = gaussFilter(matrix, rows, cols, 1, 5);
  auto matrix_thr = gaussFilter_par(matrix, rows, cols, 1, 5);
  ASSERT_EQ(matrix_seq, matrix_thr);
}

TEST(Gauss_filter, 1500x1700) {
  int rows = 100;
  int cols = 100;
  auto rand_matrix = matrixCreation(rows, cols);
  auto matrix = transpose(rand_matrix, rows, cols);
  std::swap(cols, rows);
  std::swap(cols, rows);
  auto matrix_seq = gaussFilter(matrix, rows, cols, 1, 5);
  auto matrix_thr = gaussFilter_par(matrix, rows, cols, 1, 5);
  ASSERT_EQ(matrix_seq, matrix_thr);
}

TEST(Gauss_filter, 100x1500) {
  int rows = 10000;
  int cols = 1005;
  auto rand_matrix = matrixCreation(rows, cols);
  auto matrix = transpose(rand_matrix, rows, cols);
  std::swap(cols, rows);
  std::swap(cols, rows);
  auto matrix_seq = gaussFilter(matrix, rows, cols, 1, 5);
  auto matrix_thr = gaussFilter_par(matrix, rows, cols, 1, 5);
  ASSERT_EQ(matrix_seq, matrix_thr);
}

TEST(Gauss_filter, 15000x10000) {
  int rows = 150;
  int cols = 100;
  auto rand_matrix = matrixCreation(rows, cols);
  auto matrix = transpose(rand_matrix, rows, cols);
  std::swap(cols, rows);
  std::swap(cols, rows);
  auto matrix_seq = gaussFilter(matrix, rows, cols, 1, 5);
  auto matrix_thr = gaussFilter_par(matrix, rows, cols, 1, 5);
  ASSERT_EQ(matrix_seq, matrix_thr);
}
