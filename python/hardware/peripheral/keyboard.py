from datetime import date
from hardware.peripheral.peripheral import Peripheral

class Keyboard(Peripheral):
    def __init__(self, mechanical=False, layout_type="", has_backlight=False, serial_number="", installation_date=None, physically_installed=False, connection_type="", wireless=False, name="", id="", manufacturer="", model="", price=0.0):
        super().__init__(serial_number, installation_date, physically_installed, connection_type, wireless, name, id, manufacturer, model, price)
        self._mechanical = mechanical
        self._layout_type = layout_type
        self._has_backlight = has_backlight

    # Setters
    def set_mechanical(self, mechanical):
        self._mechanical = mechanical

    def set_layout_type(self, layout_type):
        self._layout_type = layout_type

    def set_has_backlight(self, has_backlight):
        self._has_backlight = has_backlight

    # Getters
    def is_mechanical(self):
        return self._mechanical

    def get_layout_type(self):
        return self._layout_type

    def has_backlight_feature(self):
        return self._has_backlight

    def connect(self):
        print("Keyboard connected")
        return True

    def disconnect(self):
        print("Keyboard disconnected")
        return True