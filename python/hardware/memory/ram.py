from datetime import date
from components.component import Component
from components.hardware import Hardware
from interfaces.upgradable import Upgradable

class RAM(Hardware, Upgradable, Component):
    def __init__(self, capacity_gb=0, ram_type="", speed_mhz=0, is_ecc=False, serial_number="", installation_date=None, physically_installed=False, id="", manufacturer="", model="", price=0.0):
        Hardware.__init__(self, serial_number, installation_date, physically_installed)
        Component.__init__(self, id, manufacturer, model, price)
        self._capacity_gb = capacity_gb
        self._ram_type = ram_type
        self._speed_mhz = speed_mhz
        self._is_ecc = is_ecc

    # Setters
    def set_capacity_gb(self, capacity_gb):
        self._capacity_gb = capacity_gb

    def set_ram_type(self, ram_type):
        self._ram_type = ram_type

    def set_speed_mhz(self, speed_mhz):
        self._speed_mhz = speed_mhz

    def set_is_ecc(self, is_ecc):
        self._is_ecc = is_ecc

    # Getters
    def get_capacity_gb(self):
        return self._capacity_gb

    def get_ram_type(self):
        return self._ram_type

    def get_speed_mhz(self):
        return self._speed_mhz

    def get_is_ecc(self):
        return self._is_ecc

    def upgrade(self):
        print("RAM upgraded")
        return True

    def downgrade(self):
        print("RAM downgraded")
        return True