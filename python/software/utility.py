from components.software import Software
from interfaces.executable import Executable
from interfaces.upgradable import Upgradable

class Utility(Software, Executable, Upgradable):
    def __init__(self, utility_name="", function="", version="", software_version="", license_key="", size_mb=0.0):
        super().__init__(software_version, license_key, size_mb)
        self._utility_name = utility_name
        self._function = function
        self._version = version

    # Setters
    def set_utility_name(self, utility_name):
        self._utility_name = utility_name

    def set_function(self, function):
        self._function = function

    def set_version(self, version):
        self._version = version

    # Getters
    def get_utility_name(self):
        return self._utility_name

    def get_function(self):
        return self._function

    def get_version(self):
        return self._version

    def execute(self):
        print("Utility executed")

    def terminate(self):
        print("Utility terminated")

    def upgrade(self):
        print("Utility upgraded")
        return True

    def downgrade(self):
        print("Utility downgraded")
        return True