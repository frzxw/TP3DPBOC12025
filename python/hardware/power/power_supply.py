from datetime import date
from components.component import Component
from components.hardware import Hardware

class PowerSupply(Hardware, Component):
    def __init__(self, wattage=0, certification="", modular=False, id="", manufacturer="", model="", price=0.0, serial_number="", installation_date=None, physically_installed=False):
        Hardware.__init__(self, serial_number, installation_date, physically_installed)
        Component.__init__(self, id, manufacturer, model, price)
        self._wattage = wattage
        self._certification = certification
        self._modular = modular

    # Setters
    def set_wattage(self, wattage):
        self._wattage = wattage

    def set_certification(self, certification):
        self._certification = certification

    def set_modular(self, modular):
        self._modular = modular

    # Getters
    def get_wattage(self):
        return self._wattage

    def get_certification(self):
        return self._certification

    def is_modular(self):
        return self._modular