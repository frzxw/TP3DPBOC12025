from components.software import Software
from interfaces.executable import Executable
from interfaces.upgradable import Upgradable

class Application(Software, Executable, Upgradable):
    def __init__(self, app_name="", developer="", supported_os="", version="", license_key="", size_mb=0.0):
        super().__init__(version, license_key, size_mb)
        self._app_name = app_name
        self._developer = developer
        self._supported_os = supported_os

    # Setters
    def set_app_name(self, app_name):
        self._app_name = app_name

    def set_developer(self, developer):
        self._developer = developer

    def set_supported_os(self, supported_os):
        self._supported_os = supported_os

    # Getters
    def get_app_name(self):
        return self._app_name

    def get_developer(self):
        return self._developer

    def get_supported_os(self):
        return self._supported_os

    def execute(self):
        print(f"Application {self._app_name} is running")

    def terminate(self):
        print(f"Application {self._app_name} has been terminated")

    def upgrade(self):
        print(f"Application {self._app_name} has been upgraded")
        return True

    def downgrade(self):
        print(f"Application {self._app_name} has been downgraded")
        return True