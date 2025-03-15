from components.software import Software
from interfaces.bootable import Bootable
from interfaces.executable import Executable
from interfaces.upgradable import Upgradable

class OperatingSystem(Software, Bootable, Upgradable):
    def __init__(self, os_name="", kernel_version="", is_64_bit=False, software_version="", license_key="", size_mb=0.0):
        super().__init__(software_version, license_key, size_mb)
        self._os_name = os_name
        self._kernel_version = kernel_version
        self._is_64_bit = is_64_bit
        self._installed = False

    # Setters
    def set_os_name(self, os_name):
        self._os_name = os_name

    def set_kernel_version(self, kernel_version):
        self._kernel_version = kernel_version

    def set_is_64_bit(self, is_64_bit):
        self._is_64_bit = is_64_bit

    def set_installed(self, installed):
        self._installed = installed

    # Getters
    def get_os_name(self):
        return self._os_name

    def get_kernel_version(self):
        return self._kernel_version

    def get_is_64_bit(self):
        return self._is_64_bit

    def is_installed(self):
        return self._installed

    def boot(self):
        print("Operating System booted")
        return True

    def shutdown(self):
        print("Operating System shutdown")

    def restart(self):
        print("Operating System restarted")

    def upgrade(self):
        print("Operating System upgraded")
        return True

    def downgrade(self):
        print("Operating System downgraded")
        return True