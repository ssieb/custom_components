#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/modbus/modbus.h"

namespace esphome {
namespace kuntze {

class Kuntze : public PollingComponent, public modbus::ModbusDevice {
 public:
  void set_ph_sensor(sensor::Sensor *ph_sensor) { ph_sensor_ = ph_sensor; }
  void set_temperature_sensor(sensor::Sensor *temperature_sensor) { temperature_sensor_ = temperature_sensor; }
  void set_dis1_sensor(sensor::Sensor *dis1_sensor) { dis1_sensor_ = dis1_sensor; }
  void set_dis2_sensor(sensor::Sensor *dis2_sensor) { dis2_sensor_ = dis2_sensor; }
  void set_redox_sensor(sensor::Sensor *redox_sensor) { redox_sensor_ = redox_sensor; }
  void set_ec_sensor(sensor::Sensor *ec_sensor) { ec_sensor_ = ec_sensor; }
  void set_oci_sensor(sensor::Sensor *oci_sensor) { oci_sensor_ = oci_sensor; }

  void loop() override;
  void update() override;

  void on_modbus_data(const std::vector<uint8_t> &data) override;

  void dump_config() override;

 protected:
  int state_{0};
  bool waiting_{false};
  long last_send_{0};

  sensor::Sensor *ph_sensor_;
  sensor::Sensor *temperature_sensor_;
  sensor::Sensor *dis1_sensor_;
  sensor::Sensor *dis2_sensor_;
  sensor::Sensor *redox_sensor_;
  sensor::Sensor *ec_sensor_;
  sensor::Sensor *oci_sensor_;
};

}  // namespace kuntze
}  // namespace esphome
