from software.application import Application

class GameEngine(Application):
    def __init__(self, engine_name="", version="", supported_platforms="", is_open_source=False, app_name="", developer="", supported_os="", software_version="", license_key="", size_mb=0.0):
        super().__init__(app_name, developer, supported_os, software_version, license_key, size_mb)
        self._engine_name = engine_name
        self._version = version
        self._supported_platforms = supported_platforms
        self._is_open_source = is_open_source

    # Setters
    def set_engine_name(self, engine_name):
        self._engine_name = engine_name

    def set_version(self, version):
        self._version = version

    def set_supported_platforms(self, supported_platforms):
        self._supported_platforms = supported_platforms

    def set_is_open_source(self, is_open_source):
        self._is_open_source = is_open_source

    # Getters
    def get_engine_name(self):
        return self._engine_name

    def get_version(self):
        return self._version

    def get_supported_platforms(self):
        return self._supported_platforms

    def is_open_source(self):
        return self._is_open_source