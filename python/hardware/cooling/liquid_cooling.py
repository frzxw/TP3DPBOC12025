from datetime import date
from hardware.cooling.cooling import Cooling

class LiquidCooling(Cooling):
    def __init__(self, serial_number="", installation_date=None, physically_installed=False, max_thermal_dissipation=0, id="", manufacturer="", model="", price=0.0, fluid_volume=0.0, fluid_type="", has_pump=False):
        super().__init__(serial_number, installation_date, physically_installed, max_thermal_dissipation, id, manufacturer, model, price)
        self._fluid_volume = fluid_volume
        self._fluid_type = fluid_type
        self._has_pump = has_pump

    # Setters
    def set_fluid_volume(self, fluid_volume):
        self._fluid_volume = fluid_volume

    def set_fluid_type(self, fluid_type):
        self._fluid_type = fluid_type

    def set_has_pump(self, has_pump):
        self._has_pump = has_pump

    # Getters
    def get_fluid_volume(self):
        return self._fluid_volume

    def get_fluid_type(self):
        return self._fluid_type

    def get_has_pump(self):
        return self._has_pump