from datetime import date
from hardware.peripheral.peripheral import Peripheral

class Mouse(Peripheral):
    def __init__(self, button_count=0, has_scroll_wheel=False, dpi=0, serial_number="", installation_date=None, physically_installed=False, connection_type="", wireless=False, name="", id="", manufacturer="", model="", price=0.0):
        super().__init__(serial_number, installation_date, physically_installed, connection_type, wireless, name, id, manufacturer, model, price)
        self._button_count = button_count
        self._has_scroll_wheel = has_scroll_wheel
        self._dpi = dpi

    # Setters
    def set_button_count(self, button_count):
        self._button_count = button_count

    def set_has_scroll_wheel(self, has_scroll_wheel):
        self._has_scroll_wheel = has_scroll_wheel

    def set_dpi(self, dpi):
        self._dpi = dpi

    # Getters
    def get_button_count(self):
        return self._button_count

    def get_has_scroll_wheel(self):
        return self._has_scroll_wheel

    def get_dpi(self):
        return self._dpi

    def connect(self):
        print("Mouse connected")
        return True

    def disconnect(self):
        print("Mouse disconnected")
        return True