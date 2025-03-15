from datetime import date
from hardware.storage.storage_device import StorageDevice

class HDD(StorageDevice):
    def __init__(self, serial_number="", installation_date=None, physically_installed=False, capacity_gb=0, read_speed_mbs=0, write_speed_mbs=0, rpm=0, platter_count=0, id="", manufacturer="", model="", price=0.0):
        super().__init__(serial_number, installation_date, physically_installed, capacity_gb, read_speed_mbs, write_speed_mbs, id, manufacturer, model, price)
        self._rpm = rpm
        self._platter_count = platter_count

    # Setters
    def set_rpm(self, rpm):
        self._rpm = rpm

    def set_platter_count(self, platter_count):
        self._platter_count = platter_count

    # Getters
    def get_rpm(self):
        return self._rpm

    def get_platter_count(self):
        return self._platter_count

    def connect(self):
        print("HDD connected")
        return True

    def disconnect(self):
        print("HDD disconnected")
        return True