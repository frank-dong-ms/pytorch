#include <gtest/gtest.h>

#include <ATen/ATen.h>
#include <ATen/DLConvertor.h>

#include <iostream>
// NOLINTNEXTLINE(modernize-deprecated-headers)
#include <string.h>
#include <sstream>

using namespace at;
// NOLINTNEXTLINE(cppcoreguidelines-avoid-non-const-global-variables)
TEST(TestDlconvertor, TestDlconvertor) {
  // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers)
  manual_seed(123);

  Tensor a = rand({3, 4});
  DLManagedTensor* dlMTensor = toDLPack(a);

  Tensor b = fromDLPack(dlMTensor);

  ASSERT_TRUE(a.equal(b));
}

// NOLINTNEXTLINE(cppcoreguidelines-avoid-non-const-global-variables)
TEST(TestDlconvertor, TestDlconvertorNoStrides) {
  // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers)
  manual_seed(123);

  Tensor a = rand({3, 4});
  DLManagedTensor* dlMTensor = toDLPack(a);
  dlMTensor->dl_tensor.strides = nullptr;

  Tensor b = fromDLPack(dlMTensor);

  ASSERT_TRUE(a.equal(b));
}
