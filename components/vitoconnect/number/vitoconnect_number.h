#pragma once

#include "esphome/core/component.h"
#include "esphome/components/number/number.h"
#include "../vitoconnect_datapoint.h"

namespace esphome {
namespace vitoconnect {

class OPTOLINKNumber : public number::Number, public Datapoint {

  public:
    OPTOLINKNumber();
    ~OPTOLINKNumber();

    void decode(uint8_t* data, uint8_t length, Datapoint* dp = nullptr) override;
    void encode(uint8_t* raw, uint8_t length, void* data) override;
    void encode(uint8_t* raw, uint8_t length, float data);

    void control(float value);
};

}  // namespace vitoconnect
}  // namespace esphome