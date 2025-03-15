from datetime import date
from components.component import Component
from components.hardware import Hardware
from interfaces.connectable import Connectable
from interfaces.upgradable import Upgradable

class ExpansionCard(Hardware, Component, Connectable, Upgradable):
    def __init__(self, interface_type="", serial_number="", installation_date=None, physically_installed=False, id="", manufacturer="", model="", price=0.0):
        Hardware.__init__(self, serial_number, installation_date, physically_installed)
        Component.__init__(self, id, manufacturer, model, price)
        self._interface_type = interface_type

    # Setters
    def set_interface_type(self, interface_type):
        self._interface_type = interface_type

    # Getters
    def get_interface_type(self):
        return self._interface_type

    def connect(self):
        print("Expansion card connected")
        return True

    def disconnect(self):
        print("Expansion card disconnected")
        return True

    def upgrade(self):
        print("Expansion card upgraded")
        return True

    def downgrade(self):
        print("Expansion card downgraded")
        return True