#include "vitoconnect_number.h"

namespace esphome {
namespace vitoconnect {

OPTOLINKNumber::OPTOLINKNumber(){
  // empty
}

OPTOLINKNumber::~OPTOLINKNumber() {
  // empty
}

void OPTOLINKNumber::decode(uint8_t* data, uint8_t length, Datapoint* dp) {
  assert(length >= _length);

  if (!dp) dp = this;

  publish_state(data[0]);
}

void OPTOLINKNumber::encode(uint8_t* raw, uint8_t length, void* data) {
  float value = *reinterpret_cast<float*>(data);
  encode(raw, length, value);
}

void OPTOLINKNumber::encode(uint8_t* raw, uint8_t length, float data) {
  assert(length >= _length);

}

void OPTOLINKNumber::control(float value){
  uint8_t roundedValue = static_cast<uint8_t>(std::round(value));
  std::memcpy(dp->data, &roundedValue, sizeof(uint8_t));
}

}  // namespace vitoconnect
}  // namespace esphome