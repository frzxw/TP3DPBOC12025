from datetime import date
from hardware.expansion.expansion_card import ExpansionCard

class NetworkCard(ExpansionCard):
    def __init__(self, interface_type="", serial_number="", installation_date=None, physically_installed=False, id="", manufacturer="", model="", price=0.0, mac_address="", max_speed_mbps=0, supports_wifi=False, supports_bluetooth=False):
        super().__init__(interface_type, serial_number, installation_date, physically_installed, id, manufacturer, model, price)
        self._mac_address = mac_address
        self._max_speed_mbps = max_speed_mbps
        self._supports_wifi = supports_wifi
        self._supports_bluetooth = supports_bluetooth

    # Setters
    def set_mac_address(self, mac_address):
        self._mac_address = mac_address

    def set_max_speed_mbps(self, max_speed_mbps):
        self._max_speed_mbps = max_speed_mbps

    def set_supports_wifi(self, supports_wifi):
        self._supports_wifi = supports_wifi

    def set_supports_bluetooth(self, supports_bluetooth):
        self._supports_bluetooth = supports_bluetooth

    # Getters
    def get_mac_address(self):
        return self._mac_address

    def get_max_speed_mbps(self):
        return self._max_speed_mbps

    def is_wifi_supported(self):
        return self._supports_wifi

    def is_bluetooth_supported(self):
        return self._supports_bluetooth

    def connect(self):
        print("Network card connected")
        return True

    def disconnect(self):
        print("Network card disconnected")
        return True