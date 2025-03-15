from datetime import date
from computer.computer import Computer
from hardware.motherboard.motherboard import Motherboard
from hardware.processor.cpu import CPU
from hardware.memory.ram import RAM
from hardware.storage.ssd import SSD
from hardware.storage.hdd import HDD
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
from software.utility import Utility
import random

def create_demo_computer(today):
    # Create a demo computer with some default components
    mobo = Motherboard("MB-001", "ASUS", "ROG Strix Z690-A", 299.99, "SN-MB-001", today, True, "Z690", "ATX", 4, 3, 6, True)
    psu = PowerSupply(750, "80+ Gold", True, "PSU-001", "Corsair", "RM750x", 124.99, "SN-PSU-001", today, True)
    cooling = AirCooling("SN-COOL-001", today, True, 150, "COOL-001", "Noctua", "NH-D15", 89.99, 2, 1500)
    os = OperatingSystem("Windows", "11", True, "22H2", "XXXXX-XXXXX-XXXXX-XXXXX", 16000.0)
    bios = BIOS("ASUS", today, "F11", "Z690", today, True)
    computer = Computer("PC-001", "Custom Build", "Gaming Desktop", 1599.99, "Gaming PC")
    
    # Create and install CPU
    cpu = CPU("SN-CPU-001", today, True, 3.6, 8, 16, "x86_64", 16, True, "CPU-001", "Intel", "Core i7-9700K", 379.99, "LGA1151")
    mobo.install_cpu(cpu)
    
    # Create and install RAM
    ram1 = RAM(16, "DDR4", 3200, False, "SN-RAM-001", today, True, "RAM-001", "Corsair", "Vengeance LPX", 79.99)
    ram2 = RAM(16, "DDR4", 3200, False, "SN-RAM-002", today, True, "RAM-002", "Corsair", "Vengeance LPX", 79.99)
    mobo.install_ram(ram1)
    mobo.install_ram(ram2)
    
    # Create and install Storage Devices
    ssd = SSD("SN-SSD-001", today, True, 1000, 3500, 3000, "SSD-001", "Samsung", "970 EVO Plus", 149.99, "TLC", 600)
    hdd = HDD("SN-HDD-001", today, True, 2000, 150, 150, 7200, 2, "HDD-001", "Seagate", "Barracuda", 59.99)
    mobo.install_storage(ssd)
    mobo.install_storage(hdd)
    
    computer.set_motherboard(mobo)
    computer.set_power_supply(psu)
    computer.set_cooling(cooling)
    computer.set_bios(bios)
    computer.set_operating_system(os)
    return computer

def create_random_computer(today):
    # Create a computer with random components
    mobo = Motherboard(
        f"MB-{random.randint(100, 999)}", 
        random.choice(["ASUS", "MSI", "Gigabyte", "ASRock", "Biostar", "EVGA"]), 
        random.choice(["ROG Strix Z690-A", "MAG B550 TOMAHAWK", "AORUS ELITE", "Phantom Gaming 4", "Racing B450GT3", "Z490 FTW"]), 
        random.uniform(100, 500), 
        f"SN-MB-{random.randint(100, 999)}", 
        today, 
        True, 
        random.choice(["Z690", "B550", "X570", "H510", "B450", "Z490"]), 
        random.choice(["ATX", "Micro-ATX", "Mini-ITX", "E-ATX"]), 
        random.randint(2, 8), 
        random.randint(1, 4), 
        random.randint(4, 10), 
        True
    )
    psu = PowerSupply(
        random.randint(500, 1000), 
        random.choice(["80+ Bronze", "80+ Silver", "80+ Gold", "80+ Platinum", "80+ Titanium"]), 
        True, 
        f"PSU-{random.randint(100, 999)}", 
        random.choice(["Corsair", "EVGA", "Seasonic", "Cooler Master", "Thermaltake", "Antec"]), 
        random.choice(["RM750x", "SuperNOVA 750 G5", "Focus GX-750", "V850", "Toughpower GF1", "HCG750"]), 
        random.uniform(50, 200), 
        f"SN-PSU-{random.randint(100, 999)}", 
        today, 
        True
    )
    cooling = random.choice([
        AirCooling(
            f"SN-COOL-{random.randint(100, 999)}", 
            today, 
            True, 
            random.randint(100, 200), 
            f"COOL-{random.randint(100, 999)}", 
            random.choice(["Noctua", "Cooler Master", "be quiet!", "NZXT", "Arctic", "Thermaltake"]), 
            random.choice(["NH-D15", "Hyper 212", "Dark Rock Pro 4", "Kraken X63", "Freezer 34", "Riing Silent 12"]), 
            random.uniform(50, 150), 
            random.randint(1, 3), 
            random.randint(1000, 2000)
        ),
        LiquidCooling(
            f"SN-COOL-{random.randint(100, 999)}", 
            today, 
            True, 
            random.randint(100, 200), 
            f"COOL-{random.randint(100, 999)}", 
            random.choice(["Corsair", "NZXT", "Cooler Master", "Thermaltake", "EKWB", "Alphacool"]), 
            random.choice(["H100i", "Kraken X73", "MasterLiquid ML240L", "Pacific CL360", "EK-AIO 240", "Eisbaer LT240"]), 
            random.uniform(100, 300), 
            random.randint(1, 3), 
            random.randint(1000, 2000)
        )
    ])
    os = OperatingSystem(
        random.choice(["Windows", "Linux", "macOS"]), 
        random.choice(["10", "11", "Ubuntu 20.04", "Ubuntu 22.04", "Big Sur", "Monterey", "Debian 10", "Debian 11", "Fedora 34", "Fedora 35"]), 
        True, 
        random.choice(["21H1", "22H2", "Focal Fossa", "Jammy Jellyfish", "11.6", "12.3", "Buster", "Bullseye", "34", "35"]), 
        f"{random.randint(10000, 99999)}-{random.randint(10000, 99999)}-{random.randint(10000, 99999)}-{random.randint(10000, 99999)}", 
        random.uniform(8000, 32000)
    )
    bios = BIOS(
        random.choice(["ASUS", "MSI", "Gigabyte", "ASRock", "Biostar", "EVGA"]), 
        today, 
        f"F{random.randint(1, 20)}", 
        random.choice(["Z690", "B550", "X570", "H510", "B450", "Z490"]), 
        today, 
        True
    )
    computer = Computer(
        f"PC-{random.randint(100, 999)}", 
        random.choice(["Dell", "HP", "Lenovo", "Acer", "Asus", "Apple", "MSI", "Alienware", "Samsung", "Toshiba", "Sony", "Fujitsu", "Panasonic", "LG", "Huawei"]), 
        random.choice(["Inspiron", "Pavilion", "ThinkCentre", "Aspire", "ROG", "MacBook Pro", "Prestige", "Aurora", "Galaxy Book", "Dynabook", "VAIO", "Lifebook", "Toughbook", "Gram", "MateBook"]), 
        random.uniform(800, 2500), 
        random.choice(["Gaming PC", "Workstation", "Home PC", "Server", "Media Center", "Ultrabook", "Convertible", "All-in-One"])
    )
    
    # Create and install CPU
    cpu = CPU(
        f"SN-CPU-{random.randint(100, 999)}", 
        today, 
        True, 
        random.uniform(2.0, 5.0), 
        random.randint(4, 16), 
        random.randint(8, 32), 
        random.choice(["x86_64", "ARM"]), 
        random.randint(6, 32), 
        True, 
        f"CPU-{random.randint(100, 999)}", 
        random.choice(["Intel", "AMD"]), 
        random.choice(["Core i5-10400F", "Core i7-11700K", "Ryzen 5 5600X", "Ryzen 7 5800X"]), 
        random.uniform(150, 500), 
        random.choice(["LGA1200", "AM4"])
    )
    mobo.install_cpu(cpu)
    
    # Create and install RAM
    ram1 = RAM(
        random.randint(8, 32), 
        random.choice(["DDR4", "DDR5"]), 
        random.randint(2400, 3600), 
        False, 
        f"SN-RAM-{random.randint(100, 999)}", 
        today, 
        True, 
        f"RAM-{random.randint(100, 999)}", 
        random.choice(["Corsair", "G.Skill", "Kingston", "Crucial", "Patriot"]), 
        random.choice(["Vengeance LPX", "Ripjaws V", "HyperX Fury", "Ballistix", "Viper 4"]), 
        random.uniform(50, 150)
    )
    ram2 = RAM(
        random.randint(8, 32), 
        random.choice(["DDR4", "DDR5"]), 
        random.randint(2400, 3600), 
        False, 
        f"SN-RAM-{random.randint(100, 999)}", 
        today, 
        True, 
        f"RAM-{random.randint(100, 999)}", 
        random.choice(["Corsair", "G.Skill", "Kingston", "Crucial", "Patriot"]), 
        random.choice(["Vengeance LPX", "Ripjaws V", "HyperX Fury", "Ballistix", "Viper 4"]), 
        random.uniform(50, 150)
    )
    mobo.install_ram(ram1)
    mobo.install_ram(ram2)
    
    # Create and install Storage Devices
    ssd = SSD(
        f"SN-SSD-{random.randint(100, 999)}", 
        today, 
        True, 
        random.randint(256, 2000), 
        random.randint(1500, 3500), 
        random.randint(1000, 3000), 
        f"SSD-{random.randint(100, 999)}", 
        random.choice(["Samsung", "Western Digital", "Crucial", "Kingston", "Seagate"]), 
        random.choice(["970 EVO Plus", "SN750", "MX500", "A2000", "FireCuda 520"]), 
        random.uniform(50, 200), 
        random.choice(["TLC", "MLC", "QLC"]), 
        random.randint(300, 600)
    )
    hdd = HDD(
        f"SN-HDD-{random.randint(100, 999)}", 
        today, 
        True, 
        random.randint(1000, 4000), 
        random.randint(100, 200), 
        random.randint(100, 200), 
        random.randint(5400, 7200), 
        random.randint(1, 4), 
        f"HDD-{random.randint(100, 999)}", 
        random.choice(["Seagate", "Western Digital", "Toshiba", "Hitachi", "Samsung"]), 
        random.choice(["Barracuda", "Blue", "P300", "Ultrastar", "Spinpoint"]), 
        random.uniform(30, 100)
    )
    mobo.install_storage(ssd)
    mobo.install_storage(hdd)
    
    computer.set_motherboard(mobo)
    computer.set_power_supply(psu)
    computer.set_cooling(cooling)
    computer.set_bios(bios)
    computer.set_operating_system(os)
    return computer

def display_computer_table(computers):
    if not computers:
        print("\n[!] No computers available.\n")
        return

    headers = ["No", "Name", "Manufacturer", "Model", "CPU", "RAM", "Storage", "Power"]
    rows = []

    for i, computer in enumerate(computers):
        row = [
            str(i + 1),
            str(computer.get_name()),
            str(computer.get_manufacturer()),
            str(computer.get_model()),
            str(computer.get_motherboard().get_cpu_model()),
            str(computer.get_motherboard().get_ram()),
            str(computer.get_motherboard().get_storage()),
            "On" if computer.is_powered() else "Off"
        ]
        rows.append(row)

    # Calculate dynamic column widths
    column_widths = [max(len(str(item)) for item in column) for column in zip(headers, *rows)]

    # Print header
    header_row = " | ".join(f"{header:<{column_widths[i]}}" for i, header in enumerate(headers))
    print("\n")
    print(header_row)
    print("-" * (sum(column_widths) + len(headers) * 3 - 1))

    # Print rows
    for row in rows:
        print(" | ".join(f"{item:<{column_widths[i]}}" for i, item in enumerate(row)))

def main():
    today = date(2025, 3, 15)
    computers = [create_demo_computer(today)]
    for _ in range(9):
        computers.append(create_random_computer(today))
    display_computer_table(computers)

if __name__ == "__main__":
    main()
