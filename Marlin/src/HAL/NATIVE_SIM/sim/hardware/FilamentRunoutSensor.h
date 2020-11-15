#pragma once

#include "Gpio.h"
#include "../user_interface.h"

class FilamentRunoutSensor {
public:
  FilamentRunoutSensor(pin_type runout_pin, bool runtout_trigger_value) : runout_pin(runout_pin), runtout_trigger_value(runtout_trigger_value) {
    Gpio::pin_map[runout_pin].value = !runtout_trigger_value;
  }

  void ui_info_callback(UiWindow*) {
    ImGui::Checkbox("Filament Present ", (bool*)&filament_present);
    if (filament_present) {
      Gpio::pin_map[runout_pin].value = !runtout_trigger_value;

    }
    else {
      Gpio::pin_map[runout_pin].value = runtout_trigger_value;
    }
  }

private:
  pin_type runout_pin;
  bool runtout_trigger_value;
  bool filament_present = true;
};
