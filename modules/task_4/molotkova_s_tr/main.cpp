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

TEST(Gauss_filter, 90x90) {
  int rows = 90;
  int cols = 90;
  auto rand_matrix = matrixCreation(rows, cols);
  auto matrix = transpose(rand_matrix, rows, cols);
  std::swap(cols, rows);
  auto matrix_seq = gaussFilter(matrix, rows, cols, 1, 5);
  auto matrix_thr = gaussFilter_par(matrix, rows, cols, 1, 5);
  ASSERT_EQ(matrix_seq, matrix_thr);
}

TEST(Gauss_filter, 10x10) {
  int rows = 10;
  int cols = 10;
  auto rand_matrix = matrixCreation(rows, cols);
  auto matrix = transpose(rand_matrix, rows, cols);
  std::swap(cols, rows);
  auto matrix_seq = gaussFilter(matrix, rows, cols, 1, 5);
  auto matrix_thr = gaussFilter_par(matrix, rows, cols, 1, 5);
  ASSERT_EQ(matrix_seq, matrix_thr);
}

TEST(Gauss_filter, 18x17) {
  int rows = 18;
  int cols = 17;
  auto rand_matrix = matrixCreation(rows, cols);
  auto matrix = transpose(rand_matrix, rows, cols);
  std::swap(cols, rows);
  std::swap(cols, rows);
  auto matrix_seq = gaussFilter(matrix, rows, cols, 1, 5);
  auto matrix_thr = gaussFilter_par(matrix, rows, cols, 1, 5);
  ASSERT_EQ(matrix_seq, matrix_thr);
}

TEST(Gauss_filter, 10x15) {
  int rows = 10;
  int cols = 15;
  auto rand_matrix = matrixCreation(rows, cols);
  auto matrix = transpose(rand_matrix, rows, cols);
  std::swap(cols, rows);
  std::swap(cols, rows);
  auto matrix_seq = gaussFilter(matrix, rows, cols, 1, 5);
  auto matrix_thr = gaussFilter_par(matrix, rows, cols, 1, 5);
  ASSERT_EQ(matrix_seq, matrix_thr);
}

TEST(Gauss_filter, 14x12) {
  int rows = 14;
  int cols = 12;
  auto rand_matrix = matrixCreation(rows, cols);
  auto matrix = transpose(rand_matrix, rows, cols);
  std::swap(cols, rows);
  std::swap(cols, rows);
  auto matrix_seq = gaussFilter(matrix, rows, cols, 1, 5);
  auto matrix_thr = gaussFilter_par(matrix, rows, cols, 1, 5);
  ASSERT_EQ(matrix_seq, matrix_thr);
}
