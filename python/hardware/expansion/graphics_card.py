from datetime import date
from hardware.expansion.expansion_card import ExpansionCard

class GraphicsCard(ExpansionCard):
    def __init__(self, vram_gb=0, gpu_model="", cuda_cores=0, display_ports=0, hdmi_ports=0, interface_type="", serial_number="", installation_date=None, physically_installed=False, id="", manufacturer="", model="", price=0.0):
        super().__init__(interface_type, serial_number, installation_date, physically_installed, id, manufacturer, model, price)
        self._vram_gb = vram_gb
        self._gpu_model = gpu_model
        self._cuda_cores = cuda_cores
        self._display_ports = display_ports
        self._hdmi_ports = hdmi_ports

    # Setters
    def set_vram_gb(self, vram_gb):
        self._vram_gb = vram_gb

    def set_gpu_model(self, gpu_model):
        self._gpu_model = gpu_model

    def set_cuda_cores(self, cuda_cores):
        self._cuda_cores = cuda_cores

    def set_display_ports(self, display_ports):
        self._display_ports = display_ports

    def set_hdmi_ports(self, hdmi_ports):
        self._hdmi_ports = hdmi_ports

    # Getters
    def get_vram_gb(self):
        return self._vram_gb

    def get_gpu_model(self):
        return self._gpu_model

    def get_cuda_cores(self):
        return self._cuda_cores

    def get_display_ports(self):
        return self._display_ports

    def get_hdmi_ports(self):
        return self._hdmi_ports

    def connect(self):
        print("Graphics card connected")
        return True

    def disconnect(self):
        print("Graphics card disconnected")
        return True