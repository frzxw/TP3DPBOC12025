from hardware.motherboard.motherboard import Motherboard
from hardware.power.power_supply import PowerSupply
from hardware.cooling.air_cooling import AirCooling
from hardware.cooling.liquid_cooling import LiquidCooling
from hardware.peripheral.monitor import Monitor
from hardware.peripheral.keyboard import Keyboard
from hardware.peripheral.mouse import Mouse
from software.operating_system import OperatingSystem
from software.application import Application
from software.bios import BIOS
from software.driver import Driver
from interfaces.bootable import Bootable
from components.component import Component

class Computer(Bootable, Component):
    def __init__(self, id="", manufacturer="", model="", price=0.0, name=""):
        super().__init__(id, manufacturer, model, price)
        self.name = name
        self.power_status = False
        self.motherboard = None
        self.power_supply = None
        self.cooling = None
        self.peripherals = []
        self.installed_software = []
        self.bios = None
        self.operating_system = None
        self.drivers = []

    def __del__(self):
        if self.motherboard:
            del self.motherboard
        if self.power_supply:
            del self.power_supply
        if self.cooling:
            del self.cooling
        if self.bios:
            del self.bios
        if self.operating_system:
            del self.operating_system
        for peripheral in self.peripherals:
            del peripheral
        for software in self.installed_software:
            del software
        for driver in self.drivers:
            del driver

    def boot(self):
        if not self.power_status and self.power_supply and self.motherboard and self.bios:
            print(f"Starting computer {self.name}...")
            self.bios.boot()
            if self.operating_system:
                self.operating_system.boot()
                print(f"Welcome to {self.operating_system.get_os_name()} version {self.operating_system.get_version()}")
            else:
                print("No operating system found!")
                return False
            self.power_status = True
            return True
        return False

    def shutdown(self):
        if self.power_status:
            print(f"Shutting down computer {self.name}...")
            if self.operating_system:
                self.operating_system.shutdown()
            self.power_status = False

    def restart(self):
        if self.power_status:
            print(f"Restarting computer {self.name}...")
            if self.operating_system:
                self.operating_system.restart()
            self.power_status = False
            self.boot()

    def set_name(self, name):
        self.name = name

    def set_motherboard(self, mobo):
        if self.motherboard:
            del self.motherboard
        self.motherboard = mobo

    def set_power_supply(self, psu):
        if self.power_supply:
            del self.power_supply
        self.power_supply = psu

    def set_cooling(self, cool):
        if self.cooling:
            del self.cooling
        self.cooling = cool

    def set_bios(self, new_bios):
        if self.bios:
            del self.bios
        self.bios = new_bios

    def set_operating_system(self, os):
        if self.operating_system:
            del self.operating_system
        self.operating_system = os

    def get_name(self):
        return self.name

    def is_powered(self):
        return self.power_status

    def get_motherboard(self):
        return self.motherboard

    def get_power_supply(self):
        return self.power_supply

    def get_cooling(self):
        return self.cooling

    def get_bios(self):
        return self.bios

    def get_operating_system(self):
        return self.operating_system

    def add_peripheral(self, peripheral):
        if peripheral:
            self.peripherals.append(peripheral)
            peripheral.connect()

    def remove_peripheral(self, peripheral):
        if peripheral in self.peripherals:
            peripheral.disconnect()
            self.peripherals.remove(peripheral)

    def install_software(self, software):
        if software and self.operating_system:
            self.installed_software.append(software)
            print(f"Software installed: {type(software).__name__}")

    def uninstall_software(self, software):
        if software in self.installed_software:
            print(f"Software uninstalled: {type(software).__name__}")
            self.installed_software.remove(software)

    def install_driver(self, driver):
        if driver and self.operating_system:
            self.drivers.append(driver)
            print(f"Driver installed: {driver.get_device_name()}")

    def uninstall_driver(self, driver):
        if driver in self.drivers:
            print(f"Driver uninstalled: {driver.get_device_name()}")
            self.drivers.remove(driver)

    def display_specifications(self):
        print("Computer Specifications:")
        print(f"Name: {self.name}")
        print(f"Manufacturer: {self.get_manufacturer()}")
        print(f"Model: {self.get_model()}")
        print(f"Power status: {'ON' if self.power_status else 'OFF'}")

        print("\nHardware Components:")
        if self.motherboard:
            print(f"Motherboard: {self.motherboard.get_manufacturer()} {self.motherboard.get_model()}")
            self.motherboard.display_info()

        if self.power_supply:
            print(f"Power Supply: {self.power_supply.get_manufacturer()} {self.power_supply.get_model()} ({self.power_supply.get_wattage()}W, {self.power_supply.get_certification()})")

        if self.cooling:
            print(f"Cooling System: {self.cooling.get_manufacturer()} {self.cooling.get_model()}")
            print(f"Max Thermal Dissipation: {self.cooling.get_max_thermal_dissipation()}W")

            if isinstance(self.cooling, AirCooling):
                print("Type: Air Cooling")
                print(f"Fans: {self.cooling.get_fan_count()} @ {self.cooling.get_fan_speed_rpm()} RPM")
            elif isinstance(self.cooling, LiquidCooling):
                print("Type: Liquid Cooling")
                print(f"Fluid: {self.cooling.get_fluid_type()} ({self.cooling.get_fluid_volume()} ml)")
                print(f"Has pump: {'Yes' if self.cooling.get_has_pump() else 'No'}")

        print("\nPeripherals:")
        for peripheral in self.peripherals:
            print(f"{peripheral.get_name()}: {peripheral.get_manufacturer()} {peripheral.get_model()}")

            if isinstance(peripheral, Monitor):
                print(f"Monitor: {peripheral.get_screen_size_inches()}\" {peripheral.get_resolution_width()}x{peripheral.get_resolution_height()} @ {peripheral.get_refresh_rate()}Hz ({peripheral.get_panel_type()})")
            elif isinstance(peripheral, Keyboard):
                print(f"Keyboard: {peripheral.get_layout_type()}{' (Mechanical)' if peripheral.is_mechanical() else ''}{' with backlight' if peripheral.has_backlight_feature() else ''}")
            elif isinstance(peripheral, Mouse):
                print(f"Mouse: {peripheral.get_button_count()} buttons, {peripheral.get_dpi()} DPI{' with scroll wheel' if peripheral.get_has_scroll_wheel() else ''}")

        print("\nSoftware:")
        if self.bios:
            print(f"BIOS: {self.bios.get_manufacturer()} version {self.bios.get_firmware_version()}")

        if self.operating_system:
            print(f"OS: {self.operating_system.get_os_name()} {self.operating_system.get_version()}{' (64-bit)' if self.operating_system.get_is_64_bit() else ' (32-bit)'}")

        print(f"Installed Applications: {len(self.installed_software)}")
        for software in self.installed_software:
            if isinstance(software, Application):
                print(f"{software.get_app_name()} by {software.get_developer()} (ver {software.get_version()})")

        print(f"Installed Drivers: {len(self.drivers)}")
        for driver in self.drivers:
            print(f"{driver.get_device_name()} driver (ver {driver.get_driver_version()}){' [Signed]' if driver.get_is_signed() else ' [Unsigned]'}")

    def calculate_power_consumption(self):
        total_watts = 0
        if self.motherboard:
            total_watts += 50
            if self.motherboard.get_cpu():
                cpu = self.motherboard.get_cpu()
                total_watts += int(cpu.get_cores() * cpu.get_clock_speed_ghz() * 10)
            total_watts += len(self.motherboard.get_ram_slots()) * 3
            if self.motherboard.get_gpu():
                total_watts += self.motherboard.get_gpu().get_vram_gb() * 20
            total_watts += len(self.motherboard.get_storage_slots()) * 8
        return total_watts

    def estimate_value(self):
        total_value = self.get_price()
        if self.motherboard:
            total_value += self.motherboard.get_price()
        if self.power_supply:
            total_value += self.power_supply.get_price()
        if self.cooling:
            total_value += self.cooling.get_price()
        for peripheral in self.peripherals:
            total_value += peripheral.get_price()
        depreciation_rate = 0.85
        total_value *= depreciation_rate
        return total_value

    def run_application(self, app):
        if self.power_status and app:
            print(f"Running {app.get_app_name()}...")
            app.execute()
        else:
            print(f"Cannot run application. Computer is {'on' if self.power_status else 'off'}")

    def close_application(self, app):
        if app:
            print(f"Closing {app.get_app_name()}...")
            app.terminate()

    def upgrade_system(self):
        if not self.power_status:
            print("Starting system upgrade...")
            success = True
            if self.bios:
                success &= self.bios.upgrade()
            if self.operating_system:
                success &= self.operating_system.upgrade()
            for driver in self.drivers:
                success &= driver.upgrade()
            print(f"System upgrade {'completed successfully' if success else 'failed'}")
            return success
        else:
            print("Cannot upgrade while system is running. Please shut down first.")
            return False