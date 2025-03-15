from interfaces.upgradable import Upgradable

class Driver(Upgradable):
    def __init__(self, device_name="", driver_version="", supported_os="", is_signed=False):
        self._device_name = device_name
        self._driver_version = driver_version
        self._supported_os = supported_os
        self._is_signed = is_signed

    # Setters
    def set_device_name(self, device_name):
        self._device_name = device_name

    def set_driver_version(self, driver_version):
        self._driver_version = driver_version

    def set_supported_os(self, supported_os):
        self._supported_os = supported_os

    def set_is_signed(self, is_signed):
        self._is_signed = is_signed

    # Getters
    def get_device_name(self):
        return self._device_name

    def get_driver_version(self):
        return self._driver_version

    def get_supported_os(self):
        return self._supported_os

    def is_signed(self):
        return self._is_signed

    def upgrade(self):
        print("Driver upgraded")
        return True

    def downgrade(self):
        print("Driver downgraded")
        return True