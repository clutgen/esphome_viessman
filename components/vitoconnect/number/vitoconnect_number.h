#pragma once

#include "esphome/components/number/number.h"
#include "../vitoconnect_datapoint.h"

namespace esphome {
namespace vitoconnect {

class OPTOLINKNumber : public number::Number {

  public:
    OPTOLINKNumber();
    ~OPTOLINKNumber();
};

}  // namespace vitoconnect
}  // namespace esphome