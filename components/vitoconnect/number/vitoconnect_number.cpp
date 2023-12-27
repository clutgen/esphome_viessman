#include "vitoconnect_number.h"

namespace esphome {
namespace vitoconnect {

static const char *TAG = "vitoconnect";

OPTOLINKNumber::OPTOLINKNumber(){
  // empty
}

OPTOLINKNumber::~OPTOLINKNumber() {
  // empty
}

void OPTOLINKNumber::decode(uint8_t* data, uint8_t length, Datapoint* dp) {
  assert(length >= _length);

  if (!dp) dp = this;

  if (_length == 1){
    int16_t tmp = 0;
    tmp = data[0];
    float value = tmp / 1.0f;
    publish_state(value);
  }

  // Commonly temperature with factor /10 or /100
  if (_length == 2){
    int16_t tmp = 0;
    tmp = data[1] << 8 | data[0];
    float value = tmp / 10.0f;
    publish_state(value);
  }
}

void OPTOLINKNumber::encode(uint8_t* raw, uint8_t length, void* data) {
  float value = *reinterpret_cast<float*>(data);
  encode(raw, length, value);
}

void OPTOLINKNumber::encode(uint8_t* raw, uint8_t length, float data) {
  assert(length >= _length);

}

void OPTOLINKNumber::control(float value){
  if (_length == 1)
  {
    uint8_t roundedValue = static_cast<uint8_t>(std::round(value));
    ESP_LOGD(TAG, "Value to update number : %d", roundedValue);
    setData(&roundedValue, _length);
  }
  else if (_length == 2)
  {
    float valueToSend = value * 10.0f;
    uint8_t array[2] = {0};
    uint16_t roundedValue = static_cast<uint16_t>(std::round(valueToSend));
    array[0] = static_cast<uint8_t>(roundedValue & 0xFF);
    array[1] = static_cast<uint8_t>((roundedValue >> 8) & 0xFF);
    ESP_LOGD(TAG, "Value to update number : %d", roundedValue);
    setData(array, _length);
  }
  else
  {
    ESP_LOGD(TAG, "Value to update not correct length. Abort");
  }
}

}  // namespace vitoconnect
}  // namespace esphome