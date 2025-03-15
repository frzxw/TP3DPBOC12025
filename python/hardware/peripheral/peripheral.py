from datetime import date
from components.component import Component
from components.hardware import Hardware
from interfaces.connectable import Connectable

class Peripheral(Hardware, Connectable, Component):
    def __init__(self, serial_number="", installation_date=None, physically_installed=False, connection_type="", wireless=False, name="", id="", manufacturer="", model="", price=0.0):
        Hardware.__init__(self, serial_number, installation_date, physically_installed)
        Component.__init__(self, id, manufacturer, model, price)
        self._connection_type = connection_type
        self._wireless = wireless
        self._name = name

    # Setters
    def set_connection_type(self, connection_type):
        self._connection_type = connection_type

    def set_wireless(self, wireless):
        self._wireless = wireless

    def set_name(self, name):
        self._name = name

    # Getters
    def get_connection_type(self):
        return self._connection_type

    def is_wireless(self):
        return self._wireless

    def get_name(self):
        return self._name

    def connect(self):
        print("Peripheral connected")
        return True

    def disconnect(self):
        print("Peripheral disconnected")
        return True