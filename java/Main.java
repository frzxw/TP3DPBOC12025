import java.util.ArrayList;
import java.util.List;
import java.time.LocalDate;

import components.*;
import software.*;

public class Main {
    public static void main(String[] args) {
        LocalDate today = LocalDate.now();

        // Create computers
        List<Computer> computers = new ArrayList<>();
        computers.add(new Computer("Dell OptiPlex"));
        computers.add(new Computer("HP Pavilion"));
        computers.add(new Computer("Lenovo ThinkCentre"));
        computers.add(new Computer("Apple iMac"));
        computers.add(new Computer("Asus ZenBook"));
        computers.add(new Computer("Acer Aspire"));
        computers.add(new Computer("Microsoft Surface"));
        computers.add(new Computer("Samsung Galaxy Book"));
        computers.add(new Computer("MSI Prestige"));
        computers.add(new Computer("Alienware Aurora R11"));

        // Create CPUs and install to each computer
        List<CPU> cpus = new ArrayList<>();
        cpus.add(new CPU("Intel", "Core i5-10400F", 3.6, 6, 12));
        cpus.add(new CPU("AMD", "Ryzen 7 3700X", 3.8, 8, 16));
        cpus.add(new CPU("Intel", "Core i7-10700K", 4.0, 8, 16));
        cpus.add(new CPU("AMD", "Ryzen 5 3600", 3.7, 6, 12));
        cpus.add(new CPU("AMD", "Ryzen 9 3900X", 3.9, 12, 24));
        cpus.add(new CPU("Intel", "Core i7-11700K", 4.2, 8, 16));
        cpus.add(new CPU("Intel", "Core i3-10100", 3.5, 4, 8));
        cpus.add(new CPU("AMD", "Ryzen 5 5600X", 3.6, 6, 12));
        cpus.add(new CPU("Intel", "Core i7-9700K", 3.8, 8, 16));
        cpus.add(new CPU("Intel", "Core i7-12700K", 4.2, 8, 16));

        // Create RAM modules
        List<RAM> rams = new ArrayList<>();
        rams.add(new RAM(16, "DDR4", 3600));
        rams.add(new RAM(32, "DDR4", 3200));
        rams.add(new RAM(8, "DDR4", 3000));
        rams.add(new RAM(16, "DDR4", 3200));
        rams.add(new RAM(16, "DDR4", 3600));
        rams.add(new RAM(32, "DDR4", 3600));
        rams.add(new RAM(8, "DDR4", 2666));
        rams.add(new RAM(16, "DDR4", 3000));
        rams.add(new RAM(32, "DDR4", 3200));
        rams.add(new RAM(16, "DDR4", 3600));

        // Create GPUs
        List<GraphicsCard> gpus = new ArrayList<>();
        gpus.add(new GraphicsCard(8, "RTX 3070"));
        gpus.add(new GraphicsCard(10, "RTX 3080"));
        gpus.add(new GraphicsCard(24, "RTX 3090"));
        gpus.add(new GraphicsCard(8, "RX 6800 XT"));
        gpus.add(new GraphicsCard(16, "RX 6900 XT"));
        gpus.add(new GraphicsCard(12, "RTX 3060"));
        gpus.add(new GraphicsCard(8, "RTX 2060"));
        gpus.add(new GraphicsCard(6, "GTX 1660 Ti"));
        gpus.add(new GraphicsCard(8, "RX 5700 XT"));
        gpus.add(new GraphicsCard(4, "GTX 1650"));

        // Create Storage
        List<SSD> ssds = new ArrayList<>();
        ssds.add(new SSD(1000, 7000, 5000));
        ssds.add(new SSD(500, 3500, 3000));
        ssds.add(new SSD(2000, 7000, 5000));
        ssds.add(new SSD(1000, 3400, 3000));
        ssds.add(new SSD(500, 3500, 3000));
        ssds.add(new SSD(1000, 5000, 4500));
        ssds.add(new SSD(2000, 7000, 5000));
        ssds.add(new SSD(1000, 3500, 3000));
        ssds.add(new SSD(500, 3400, 3000));
        ssds.add(new SSD(1000, 3500, 3000));

        // Create Cooling
        List<AirCooling> airCoolings = new ArrayList<>();
        airCoolings.add(new AirCooling(150, 2, 1500));
        airCoolings.add(new AirCooling(120, 1, 2000));
        airCoolings.add(new AirCooling(140, 2, 1500));
        airCoolings.add(new AirCooling(120, 2, 1700));
        airCoolings.add(new AirCooling(92, 1, 1800));

        for (int i = 0; i < 5 && i < computers.size(); ++i) {
            computers.get(i).setCooling(airCoolings.get(i));
        }

        // Create Liquid Cooling
        List<LiquidCooling> liquidCoolings = new ArrayList<>();
        liquidCoolings.add(new LiquidCooling(240, 240.0, "Water", true));
        liquidCoolings.add(new LiquidCooling(360, 360.0, "Water", true));
        liquidCoolings.add(new LiquidCooling(280, 280.0, "Water", true));
        liquidCoolings.add(new LiquidCooling(240, 240.0, "Water", true));
        liquidCoolings.add(new LiquidCooling(360, 360.0, "Water", true));

        for (int i = 5; i < computers.size(); ++i) {
            computers.get(i).setCooling(liquidCoolings.get(i - 5));
        }

        // Create Power Supplies
        List<PowerSupply> psus = new ArrayList<>();
        psus.add(new PowerSupply(750, "80+ Gold"));
        psus.add(new PowerSupply(650, "80+ Bronze"));
        psus.add(new PowerSupply(850, "80+ Platinum"));
        psus.add(new PowerSupply(550, "80+ Bronze"));
        psus.add(new PowerSupply(1000, "80+ Gold"));
        psus.add(new PowerSupply(750, "80+ Platinum"));
        psus.add(new PowerSupply(650, "80+ Gold"));
        psus.add(new PowerSupply(850, "80+ Gold"));
        psus.add(new PowerSupply(550, "80+ Gold"));
        psus.add(new PowerSupply(1000, "80+ Platinum"));

        for (int i = 0; i < computers.size(); ++i) {
            computers.get(i).setPowerSupply(psus.get(i));
        }

        // Create Motherboards
        List<Motherboard> motherboards = new ArrayList<>();
        motherboards.add(new Motherboard("ASUS", "ROG Strix Z690-A"));
        motherboards.add(new Motherboard("MSI", "MPG Z490 Gaming Edge"));
        motherboards.add(new Motherboard("Gigabyte", "Z590 AORUS Elite"));
        motherboards.add(new Motherboard("ASRock", "B550 Phantom Gaming"));
        motherboards.add(new Motherboard("ASUS", "TUF Gaming X570-Plus"));
        motherboards.add(new Motherboard("MSI", "MAG B550 Tomahawk"));
        motherboards.add(new Motherboard("Gigabyte", "B450 AORUS Pro"));
        motherboards.add(new Motherboard("ASRock", "X570 Taichi"));
        motherboards.add(new Motherboard("ASUS", "Prime Z390-A"));
        motherboards.add(new Motherboard("MSI", "Z370 Gaming Pro Carbon"));

        for (int i = 0; i < motherboards.size(); ++i) {
            motherboards.get(i).installCPU(cpus.get(i));
            motherboards.get(i).installRAM(rams.get(i));
            motherboards.get(i).installExpansionCard(gpus.get(i));
            motherboards.get(i).installStorage(ssds.get(i));
        }

        for (int i = 0; i < computers.size(); ++i) {
            computers.get(i).setMotherboard(motherboards.get(i));
        }

        // Create BIOS
        List<BIOS> bioses = new ArrayList<>();
        bioses.add(new BIOS("ASUS", "F11"));
        bioses.add(new BIOS("MSI", "E7C91IMS"));
        bioses.add(new BIOS("Gigabyte", "F20"));
        bioses.add(new BIOS("ASRock", "P1.20"));
        bioses.add(new BIOS("ASUS", "F12"));
        bioses.add(new BIOS("MSI", "E7C37IMS"));
        bioses.add(new BIOS("Gigabyte", "F50"));
        bioses.add(new BIOS("ASRock", "P3.00"));
        bioses.add(new BIOS("ASUS", "F10"));
        bioses.add(new BIOS("MSI", "E7B45IMS"));

        for (int i = 0; i < computers.size(); ++i) {
            computers.get(i).setBios(bioses.get(i));
        }

        // Create OS
        List<OperatingSystem> operatingSystems = new ArrayList<>();
        operatingSystems.add(new OperatingSystem("Windows", "11", "22H2"));
        operatingSystems.add(new OperatingSystem("Windows", "10", "21H1"));
        operatingSystems.add(new OperatingSystem("Ubuntu", "20.04", "Focal Fossa"));
        operatingSystems.add(new OperatingSystem("Fedora", "34", "Workstation"));
        operatingSystems.add(new OperatingSystem("Debian", "11", "Bullseye"));
        operatingSystems.add(new OperatingSystem("Arch", "Rolling", "N/A"));
        operatingSystems.add(new OperatingSystem("CentOS", "8", "Stream"));
        operatingSystems.add(new OperatingSystem("Red Hat", "8", "Enterprise"));
        operatingSystems.add(new OperatingSystem("macOS", "11", "Big Sur"));
        operatingSystems.add(new OperatingSystem("Windows", "8.1", "Update 3"));

        for (int i = 0; i < computers.size(); ++i) {
            computers.get(i).setOperatingSystem(operatingSystems.get(i));
        }

    }
}