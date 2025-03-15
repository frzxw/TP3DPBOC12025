from datetime import date
from hardware.peripheral.peripheral import Peripheral

class Monitor(Peripheral):
    def __init__(self, screen_size_inches=0.0, resolution_width=0, resolution_height=0, refresh_rate=0, panel_type="", serial_number="", installation_date=None, physically_installed=False, connection_type="", wireless=False, name="", id="", manufacturer="", model="", price=0.0):
        super().__init__(serial_number, installation_date, physically_installed, connection_type, wireless, name, id, manufacturer, model, price)
        self._screen_size_inches = screen_size_inches
        self._resolution_width = resolution_width
        self._resolution_height = resolution_height
        self._refresh_rate = refresh_rate
        self._panel_type = panel_type

    # Setters
    def set_screen_size_inches(self, screen_size_inches):
        self._screen_size_inches = screen_size_inches

    def set_resolution_width(self, resolution_width):
        self._resolution_width = resolution_width

    def set_resolution_height(self, resolution_height):
        self._resolution_height = resolution_height

    def set_refresh_rate(self, refresh_rate):
        self._refresh_rate = refresh_rate

    def set_panel_type(self, panel_type):
        self._panel_type = panel_type

    # Getters
    def get_screen_size_inches(self):
        return self._screen_size_inches

    def get_resolution_width(self):
        return self._resolution_width

    def get_resolution_height(self):
        return self._resolution_height

    def get_refresh_rate(self):
        return self._refresh_rate

    def get_panel_type(self):
        return self._panel_type

    def connect(self):
        print("Monitor connected")
        return True

    def disconnect(self):
        print("Monitor disconnected")
        return True