from datetime import date
from hardware.cooling.cooling import Cooling

class AirCooling(Cooling):
    def __init__(self, serial_number="", installation_date=None, physically_installed=False, max_thermal_dissipation=0, id="", manufacturer="", model="", price=0.0, fan_count=0, fan_speed_rpm=0):
        super().__init__(serial_number, installation_date, physically_installed, max_thermal_dissipation, id, manufacturer, model, price)
        self._fan_count = fan_count
        self._fan_speed_rpm = fan_speed_rpm

    # Setters
    def set_fan_count(self, fan_count):
        self._fan_count = fan_count

    def set_fan_speed_rpm(self, fan_speed_rpm):
        self._fan_speed_rpm = fan_speed_rpm

    # Getters
    def get_fan_count(self):
        return self._fan_count

    def get_fan_speed_rpm(self):
        return self._fan_speed_rpm