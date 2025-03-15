from datetime import date
from components.component import Component
from components.hardware import Hardware

class CPU(Hardware, Component):
    def __init__(self, serial_number="", installation_date=None, physically_installed=False, clock_speed_ghz=0.0, cores=0, threads=0, architecture="", cache_size=0.0, hyperthreading=False, id="", manufacturer="", model="", price=0.0, socket_type=""):
        Hardware.__init__(self, serial_number, installation_date, physically_installed)
        Component.__init__(self, id, manufacturer, model, price)
        self._clock_speed_ghz = clock_speed_ghz
        self._cores = cores
        self._threads = threads
        self._architecture = architecture
        self._cache_size = cache_size
        self._hyperthreading = hyperthreading
        self._socket_type = socket_type

    # Setters
    def set_clock_speed_ghz(self, clock_speed_ghz):
        self._clock_speed_ghz = clock_speed_ghz

    def set_cores(self, cores):
        self._cores = cores

    def set_threads(self, threads):
        self._threads = threads

    def set_architecture(self, architecture):
        self._architecture = architecture

    def set_cache_size(self, cache_size):
        self._cache_size = cache_size

    def set_hyperthreading(self, hyperthreading):
        self._hyperthreading = hyperthreading

    def set_socket_type(self, socket_type):
        self._socket_type = socket_type

    # Getters
    def get_clock_speed_ghz(self):
        return self._clock_speed_ghz

    def get_cores(self):
        return self._cores

    def get_threads(self):
        return self._threads

    def get_architecture(self):
        return self._architecture

    def get_cache_size(self):
        return self._cache_size

    def is_hyperthreading(self):
        return self._hyperthreading

    def get_socket_type(self):
        return self._socket_type
    
    def get_model(self):
        return super().get_model()