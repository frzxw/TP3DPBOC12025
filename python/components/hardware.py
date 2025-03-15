from datetime import date

class Hardware:
    def __init__(self, serial_number="", installation_date=None, physically_installed=False):
        self._serial_number = serial_number
        self._installation_date = installation_date if installation_date is not None else date.today()
        self._physically_installed = physically_installed

    # Setters
    def set_serial_number(self, serial_number):
        self._serial_number = serial_number

    def set_installation_date(self, installation_date):
        self._installation_date = installation_date

    def set_physically_installed(self, physically_installed):
        self._physically_installed = physically_installed

    # Getters
    def get_serial_number(self):
        return self._serial_number

    def get_installation_date(self):
        return self._installation_date

    def is_physically_installed(self):
        return self._physically_installed