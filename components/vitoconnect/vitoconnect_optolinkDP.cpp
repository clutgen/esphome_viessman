/* VitoWiFi

Copyright 2019 Bert Melis

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#include "vitoconnect_optolinkDP.h"

namespace esphome {
namespace vitoconnect {

static const char *TAG = "vitoconnect";

OptolinkDP::OptolinkDP(uint16_t address, uint8_t length, bool write, uint8_t* value, void* arg) :
  address(address),
  length(length),
  write(write),
  arg(arg) {
    if (write) {
      memcpy(data, value, length);
    }
  }

OptolinkDP::OptolinkDP() :
  address(0),
  length(0),
  write(false),
  arg(nullptr) {}

OptolinkDP::OptolinkDP(const OptolinkDP& obj) {
  address = obj.address;
  length = obj.length;
  write = obj.write;
  arg = obj.arg;
  if (write) {
    //Correct dp->getData() value here
    memcpy(data, obj.data, length);
  }
}

OptolinkDP::~OptolinkDP() {
}

}  // namespace vitoconnect
}  // namespace esphome
