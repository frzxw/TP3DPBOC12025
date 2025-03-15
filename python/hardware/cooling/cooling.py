from datetime import date
from components.component import Component
from components.hardware import Hardware

class Cooling(Hardware, Component):
    def __init__(self, serial_number="", installation_date=None, physically_installed=False, max_thermal_dissipation=0, id="", manufacturer="", model="", price=0.0):
        Hardware.__init__(self, serial_number, installation_date, physically_installed)
        Component.__init__(self, id, manufacturer, model, price)
        self._max_thermal_dissipation = max_thermal_dissipation

    # Setters
    def set_max_thermal_dissipation(self, max_thermal_dissipation):
        self._max_thermal_dissipation = max_thermal_dissipation

    # Getters
    def get_max_thermal_dissipation(self):
        return self._max_thermal_dissipation