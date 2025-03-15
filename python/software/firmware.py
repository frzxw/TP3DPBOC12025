from datetime import date
from interfaces.executable import Executable
from interfaces.upgradable import Upgradable

class Firmware(Executable, Upgradable):
    def __init__(self, firmware_version="", supported_hardware="", release_date=None, installed=False):
        self._firmware_version = firmware_version
        self._supported_hardware = supported_hardware
        self._release_date = release_date if release_date is not None else date.today()
        self._installed = installed

    # Setters
    def set_firmware_version(self, firmware_version):
        self._firmware_version = firmware_version

    def set_supported_hardware(self, supported_hardware):
        self._supported_hardware = supported_hardware

    def set_release_date(self, release_date):
        self._release_date = release_date

    def set_installed(self, installed):
        self._installed = installed

    # Getters
    def get_firmware_version(self):
        return self._firmware_version

    def get_supported_hardware(self):
        return self._supported_hardware

    def get_release_date(self):
        return self._release_date

    def is_installed(self):
        return self._installed

    def execute(self):
        print("Firmware executed")

    def terminate(self):
        print("Firmware terminated")

    def upgrade(self):
        print("Firmware upgraded")
        return True

    def downgrade(self):
        print("Firmware downgraded")
        return True