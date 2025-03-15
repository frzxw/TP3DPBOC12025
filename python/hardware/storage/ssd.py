from datetime import date
from hardware.storage.storage_device import StorageDevice

class SSD(StorageDevice):
    def __init__(self, serial_number="", installation_date=None, physically_installed=False, capacity_gb=0, read_speed_mbs=0, write_speed_mbs=0, id="", manufacturer="", model="", price=0.0, nand_type="", tbw=0):
        super().__init__(serial_number, installation_date, physically_installed, capacity_gb, read_speed_mbs, write_speed_mbs, id, manufacturer, model, price)
        self._nand_type = nand_type
        self._tbw = tbw

    # Setters
    def set_nand_type(self, nand_type):
        self._nand_type = nand_type

    def set_tbw(self, tbw):
        self._tbw = tbw

    # Getters
    def get_nand_type(self):
        return self._nand_type

    def get_tbw(self):
        return self._tbw

    def connect(self):
        print("SSD connected")
        return True

    def disconnect(self):
        print("SSD disconnected")
        return True