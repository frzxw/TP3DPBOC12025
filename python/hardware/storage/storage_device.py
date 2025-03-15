from datetime import date
from components.component import Component
from components.hardware import Hardware
from interfaces.connectable import Connectable

class StorageDevice(Hardware, Connectable, Component):
    def __init__(self, serial_number="", installation_date=None, physically_installed=False, capacity_gb=0, read_speed_mbs=0, write_speed_mbs=0, id="", manufacturer="", model="", price=0.0):
        Hardware.__init__(self, serial_number, installation_date, physically_installed)
        Component.__init__(self, id, manufacturer, model, price)
        self._capacity_gb = capacity_gb
        self._read_speed_mbs = read_speed_mbs
        self._write_speed_mbs = write_speed_mbs

    # Setters
    def set_capacity_gb(self, capacity_gb):
        self._capacity_gb = capacity_gb

    def set_read_speed_mbs(self, read_speed_mbs):
        self._read_speed_mbs = read_speed_mbs

    def set_write_speed_mbs(self, write_speed_mbs):
        self._write_speed_mbs = write_speed_mbs

    # Getters
    def get_capacity_gb(self):
        return self._capacity_gb

    def get_read_speed_mbs(self):
        return self._read_speed_mbs

    def get_write_speed_mbs(self):
        return self._write_speed_mbs

    def connect(self):
        print("Storage device connected")
        return True

    def disconnect(self):
        print("Storage device disconnected")
        return True