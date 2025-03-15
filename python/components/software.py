class Software:
    def __init__(self, version="", license_key="", size_mb=0.0):
        self._version = version
        self._license_key = license_key
        self._size_mb = size_mb

    # Setters
    def set_version(self, version):
        self._version = version

    def set_license_key(self, license_key):
        self._license_key = license_key

    def set_size_mb(self, size_mb):
        self._size_mb = size_mb

    # Getters
    def get_version(self):
        return self._version

    def get_license_key(self):
        return self._license_key

    def get_size_mb(self):
        return self._size_mb