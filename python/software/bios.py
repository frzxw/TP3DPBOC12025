from datetime import date
from software.firmware import Firmware
from interfaces.bootable import Bootable

class BIOS(Firmware, Bootable):
    def __init__(self, manufacturer="", release_date=None, firmware_version="", supported_hardware="", firmware_release_date=None, installed=False):
        super().__init__(firmware_version, supported_hardware, firmware_release_date)
        self._manufacturer = manufacturer
        self._release_date = release_date if release_date is not None else date.today()
        self._installed = installed

    # Setters
    def set_manufacturer(self, manufacturer):
        self._manufacturer = manufacturer

    def set_release_date(self, release_date):
        self._release_date = release_date

    def set_installed(self, installed):
        self._installed = installed

    # Getters
    def get_manufacturer(self):
        return self._manufacturer

    def get_release_date(self):
        return self._release_date

    def is_installed(self):
        return self._installed

    def boot(self):
        print("BIOS booted")
        return True

    def shutdown(self):
        print("BIOS shutdown")

    def restart(self):
        print("BIOS restarted")