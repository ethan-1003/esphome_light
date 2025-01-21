#include "my_addressable_lambda.h"
#include <cstdlib>  // rand(), srand()

namespace esphome {
namespace my_addressable_lambda {

void random_color_effect(light::AddressableLight &it) {
  // Ví dụ hiệu ứng đơn giản: mỗi lần update, set màu ngẫu nhiên cho từng pixel
  for (int i = 0; i < it.size(); i++) {
    it[i] = Color::random_color();
  }
}

}  // namespace my_addressable_lambda
}  // namespace esphome

