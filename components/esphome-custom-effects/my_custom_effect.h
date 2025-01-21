#pragma once

#include "esphome.h"

namespace esphome {
namespace my_custom_effect {

/**
 * MyCustomLightEffect kế thừa AddressableLightEffect 
 * để ta có thể viết logic thay đổi màu từng LED theo thời gian.
 */
class MyCustomLightEffect : public light::AddressableLightEffect {
 public:
  // Hàm khởi chạy khi effect bắt đầu được bật
  void start() override {
    // Khởi tạo biến, reset counter, v.v...
    this->step_ = 0;
  }

  // Hàm chạy liên tục, được gọi mỗi khi cần update output cho strip
  void apply(light::ESPColor *buffer, size_t length) override {
    // Ví dụ hiệu ứng đơn giản: quét (chạy) màu xanh lam dần dần
    for (size_t i = 0; i < length; i++) {
      // Tính toán màu cho từng pixel
      float hue = float((i + this->step_)) * 360.0f / float(length);
      // Chuyển Hue -> RGB, saturation và brightness tuỳ chỉnh
      // Lưu ý: hue, saturation, brightness trong khoảng [0..1] (dạng float) với hàm fromHSV
      buffer[i] = light::ESPColor::fromHSV(hue / 360.0f, 1.0f, 1.0f);
    }

    // Tăng step để hiệu ứng chuyển động
    this->step_++;
  }

  // Hàm dọn dẹp khi effect dừng
  void stop() override {
    // Nếu cần làm gì thêm khi tắt effect thì để đây
  }

 protected:
  uint32_t step_{0};
};

}  // namespace my_custom_effect
}  // namespace esphome

