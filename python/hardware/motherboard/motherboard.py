from datetime import date
from components.component import Component
from components.hardware import Hardware
from hardware.processor.cpu import CPU
from hardware.memory.ram import RAM
from hardware.expansion.expansion_card import ExpansionCard
from hardware.expansion.graphics_card import GraphicsCard
from hardware.expansion.network_card import NetworkCard
from hardware.expansion.sound_card import SoundCard
from hardware.storage.storage_device import StorageDevice
from hardware.storage.ssd import SSD
from hardware.storage.hdd import HDD

class Motherboard(Component, Hardware):
    def __init__(self, id="", manufacturer="", model="", price=0.0, serial_number="", installation_date=None, physically_installed=False, chipset="", form_factor="", ram_slots_count=0, pcie_slots_count=0, sata_ports_count=0, has_integrated_gpu=False):
        super().__init__(id, manufacturer, model, price)
        Hardware.__init__(self, serial_number, installation_date, physically_installed)
        self._chipset = chipset
        self._form_factor = form_factor
        self._ram_slots_count = ram_slots_count
        self._pcie_slots_count = pcie_slots_count
        self._sata_ports_count = sata_ports_count
        self._has_integrated_gpu = has_integrated_gpu
        self._supported_cpus = []
        self._cpu = None
        self._ram_slots = []
        self._expansion_slots = []
        self._storage_slots = []
        self._gpu = None
        self._network_card = None
        self._sound_card = None

    # Setters
    def set_chipset(self, chipset):
        self._chipset = chipset

    def set_form_factor(self, form_factor):
        self._form_factor = form_factor

    def set_ram_slots_count(self, count):
        self._ram_slots_count = count

    def set_pcie_slots_count(self, count):
        self._pcie_slots_count = count

    def set_sata_ports_count(self, count):
        self._sata_ports_count = count

    def set_has_integrated_gpu(self, has_integrated_gpu):
        self._has_integrated_gpu = has_integrated_gpu

    def set_supported_cpus(self, cpus):
        self._supported_cpus = cpus

    def set_cpu(self, cpu):
        self._cpu = cpu

    def set_ram_slots(self, ram_slots):
        self._ram_slots = ram_slots

    def set_expansion_slots(self, expansion_slots):
        self._expansion_slots = expansion_slots

    def set_storage_slots(self, storage_slots):
        self._storage_slots = storage_slots

    def set_gpu(self, gpu):
        self._gpu = gpu

    def set_network_card(self, network_card):
        self._network_card = network_card

    def set_sound_card(self, sound_card):
        self._sound_card = sound_card

    # Getters
    def get_chipset(self):
        return self._chipset

    def get_form_factor(self):
        return self._form_factor

    def get_ram_slots_count(self):
        return self._ram_slots_count

    def get_pcie_slots_count(self):
        return self._pcie_slots_count

    def get_sata_ports_count(self):
        return self._sata_ports_count

    def get_has_integrated_gpu(self):
        return self._has_integrated_gpu

    def get_supported_cpus(self):
        return self._supported_cpus

    def get_cpu(self):
        return self._cpu

    def get_ram_slots(self):
        return self._ram_slots

    def get_expansion_slots(self):
        return self._expansion_slots

    def get_storage_slots(self):
        return self._storage_slots

    def get_gpu(self):
        return self._gpu

    def get_network_card(self):
        return self._network_card

    def get_sound_card(self):
        return self._sound_card

    def get_ram(self):
        total_ram = sum(ram.get_capacity_gb() for ram in self._ram_slots)
        return total_ram

    def get_storage(self):
        total_storage = sum(storage.get_capacity_gb() for storage in self._storage_slots)
        return total_storage
    
    def get_cpu_model(self):
        if self._cpu:
            return self._cpu.get_model()
        else:
            return "No CPU installed"

    # Install CPU
    def install_cpu(self, new_cpu):
        self._cpu = new_cpu

    # Install RAM
    def install_ram(self, new_ram):
        if len(self._ram_slots) < self._ram_slots_count:
            self._ram_slots.append(new_ram)
        else:
            print("No available RAM slots!")

    # Install Expansion Card
    def install_expansion_card(self, card):
        if len(self._expansion_slots) < self._pcie_slots_count:
            self._expansion_slots.append(card)

            # Check specific type of expansion card
            if isinstance(card, GraphicsCard):
                self._gpu = card
            elif isinstance(card, NetworkCard):
                self._network_card = card
            elif isinstance(card, SoundCard):
                self._sound_card = card
        else:
            print("No available PCIe slots!")

    # Install Storage Device (SSD/HDD)
    def install_storage(self, storage):
        if len(self._storage_slots) < self._sata_ports_count:
            self._storage_slots.append(storage)
        else:
            print("No available SATA slots!")

    # Remove CPU
    def remove_cpu(self):
        if self._cpu:
            self._cpu = None
        else:
            print("No CPU installed to remove!")

    # Remove RAM
    def remove_ram(self, ram):
        if ram in self._ram_slots:
            self._ram_slots.remove(ram)
        else:
            print("RAM not found!")

    # Remove Expansion Card
    def remove_expansion_card(self, card):
        if card in self._expansion_slots:
            self._expansion_slots.remove(card)

            # Check specific type of expansion card
            if isinstance(card, GraphicsCard):
                self._gpu = None
            elif isinstance(card, NetworkCard):
                self._network_card = None
            elif isinstance(card, SoundCard):
                self._sound_card = None
        else:
            print("Expansion card not found!")

    # Remove Storage Device (SSD/HDD)
    def remove_storage(self, storage):
        if storage in self._storage_slots:
            self._storage_slots.remove(storage)
        else:
            print("Storage device not found!")

    # Display motherboard details
    def display_info(self):
        print(f"Motherboard: {self._model} ({self._manufacturer})")
        print(f"Chipset: {self._chipset} | Form Factor: {self._form_factor}")
        print(f"RAM Slots: {self._ram_slots_count} | PCIe Slots: {self._pcie_slots_count} | SATA Ports: {self._sata_ports_count}")

        # CPU
        if self._cpu:
            print(f"Installed CPU: {self._cpu.get_model()}")
        else:
            print("No CPU installed")

        # RAM
        print(f"Installed RAM: {len(self._ram_slots)}/{self._ram_slots_count} slots used")

        # Expansion Cards
        print(f"Installed Expansion Cards: {len(self._expansion_slots)}/{self._pcie_slots_count} slots used")
        if self._gpu:
            print(f" - Graphics Card: {self._gpu.get_model()}")
        if self._network_card:
            print(f" - Network Card: {self._network_card.get_model()}")
        if self._sound_card:
            print(f" - Sound Card: {self._sound_card.get_model()}")

        # Storage
        print(f"Installed Storage Devices: {len(self._storage_slots)}/{self._sata_ports_count} slots used")
        for storage in self._storage_slots:
            print(f" - {storage.get_model()}")