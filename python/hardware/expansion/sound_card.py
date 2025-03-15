from datetime import date
from hardware.expansion.expansion_card import ExpansionCard

class SoundCard(ExpansionCard):
    def __init__(self, channels=0, bit_depth=0, sample_rate=0, interface_type="", serial_number="", installation_date=None, physically_installed=False, id="", manufacturer="", model="", price=0.0):
        super().__init__(interface_type, serial_number, installation_date, physically_installed, id, manufacturer, model, price)
        self._channels = channels
        self._bit_depth = bit_depth
        self._sample_rate = sample_rate

    # Setters
    def set_channels(self, channels):
        self._channels = channels

    def set_bit_depth(self, bit_depth):
        self._bit_depth = bit_depth

    def set_sample_rate(self, sample_rate):
        self._sample_rate = sample_rate

    # Getters
    def get_channels(self):
        return self._channels

    def get_bit_depth(self):
        return self._bit_depth

    def get_sample_rate(self):
        return self._sample_rate

    def connect(self):
        print("Sound card connected")
        return True

    def disconnect(self):
        print("Sound card disconnected")
        return True