#pragma once

#include "esphome/components/light/addressable_light.h"

namespace esphome {
namespace my_addressable_lambda {

/**
 * Hàm này sẽ được gọi trong addressable_lambda.
 * Nó nhận tham chiếu `it` (AddressableLight) 
 * để bạn có thể set màu từng LED.
 */
void random_color_effect(light::AddressableLight &it);

}  // namespace my_addressable_lambda
}  // namespace esphome

