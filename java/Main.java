
import java.util.ArrayList;
import java.util.List;
// import java.time.LocalDate;
import java.util.Date;

import components.*;
import software.*;

public class Main {
    public static void main(String[] args) {
        // LocalDate today = LocalDate.now();
        Date installationDate = new Date();

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
        cpus.add(new CPU("CPU-001", "Intel", "Core i5-10400F", 150.99, "SN-CPU-001", installationDate, true, 3.6, 6, 12,
                "x64", 12.0, true, "LGA1200"));
        cpus.add(new CPU("CPU-002", "AMD", "Ryzen 7 3700X", 329.99, "SN-CPU-002", installationDate, true, 3.8, 8, 16,
                "x64", 16.0, true, "AM4"));
        cpus.add(new CPU("CPU-003", "Intel", "Core i7-10700K", 374.99, "SN-CPU-003", installationDate, true, 4.0, 8, 16,
                "x64", 16.0, true, "LGA1200"));
        cpus.add(new CPU("CPU-004", "AMD", "Ryzen 5 3600", 199.99, "SN-CPU-004", installationDate, true, 3.7, 6, 12,
                "x64", 12.0, true, "AM4"));
        cpus.add(new CPU("CPU-005", "AMD", "Ryzen 9 3900X", 499.99, "SN-CPU-005", installationDate, true, 3.9, 12, 24,
                "x64", 24.0, true, "AM4"));
        cpus.add(new CPU("CPU-006", "Intel", "Core i7-11700K", 399.99, "SN-CPU-006", installationDate, true, 4.2, 8, 16,
                "x64", 16.0, true, "LGA1200"));
        cpus.add(new CPU("CPU-007", "Intel", "Core i3-10100", 119.99, "SN-CPU-007", installationDate, true, 3.5, 4, 8,
                "x64", 8.0, true, "LGA1200"));
        cpus.add(new CPU("CPU-008", "AMD", "Ryzen 5 5600X", 299.99, "SN-CPU-008", installationDate, true, 3.6, 6, 12,
                "x64", 12.0, true, "AM4"));
        cpus.add(new CPU("CPU-009", "Intel", "Core i7-9700K", 349.99, "SN-CPU-009", installationDate, true, 3.8, 8, 16,
                "x64", 16.0, true, "LGA1151"));
        cpus.add(new CPU("CPU-010", "Intel", "Core i7-12700K", 350.99, "SN-CPU-010", installationDate, true, 4.2, 8, 16,
                "x64", 16.0, true, "LGA1700"));

        // Create RAM modules
        List<RAM> rams = new ArrayList<>();
        rams.add(new RAM("RAM-001", "Corsair", "Vengeance LPX", 79.99, "SN-RAM-001", installationDate, true, 16, "DDR4",
                3600, false));
        rams.add(new RAM("RAM-002", "G.Skill", "Trident Z", 149.99, "SN-RAM-002", installationDate, true, 32, "DDR4",
                3200, false));
        rams.add(new RAM("RAM-003", "Kingston", "HyperX Fury", 49.99, "SN-RAM-003", installationDate, true, 8, "DDR4",
                3000, false));
        rams.add(new RAM("RAM-004", "Crucial", "Ballistix", 74.99, "SN-RAM-004", installationDate, true, 16, "DDR4",
                3200, false));
        rams.add(new RAM("RAM-005", "TeamGroup", "T-Force Delta", 84.99, "SN-RAM-005", installationDate, true, 16,
                "DDR4", 3600, false));
        rams.add(new RAM("RAM-006", "Patriot", "Viper Steel", 159.99, "SN-RAM-006", installationDate, true, 32, "DDR4",
                3600, false));
        rams.add(new RAM("RAM-007", "ADATA", "XPG Z1", 39.99, "SN-RAM-007", installationDate, true, 8, "DDR4", 2666,
                false));
        rams.add(new RAM("RAM-008", "GeIL", "EVO POTENZA", 69.99, "SN-RAM-008", installationDate, true, 16, "DDR4",
                3000, false));
        rams.add(new RAM("RAM-009", "Silicon Power", "XPOWER Turbine", 139.99, "SN-RAM-009", installationDate, true, 32,
                "DDR4", 3200, false));
        rams.add(new RAM("RAM-010", "Mushkin", "Redline", 89.99, "SN-RAM-010", installationDate, true, 16, "DDR4", 3600,
                false));

        // Create GPUs
        List<GraphicsCard> gpus = new ArrayList<>();
        gpus.add(new GraphicsCard("GPU-001", "NVIDIA", "GeForce RTX 3070", 499.99, "SN-GPU-001", installationDate, true,
                "PCIe 4.0", 8, "RTX 3070", 5888, 3, 1));
        gpus.add(new GraphicsCard("GPU-002", "NVIDIA", "GeForce RTX 3080", 699.99, "SN-GPU-002", installationDate, true,
                "PCIe 4.0", 10, "RTX 3080", 8704, 3, 1));
        gpus.add(new GraphicsCard("GPU-003", "NVIDIA", "GeForce RTX 3090", 1499.99, "SN-GPU-003", installationDate,
                true, "PCIe 4.0", 24, "RTX 3090", 10496, 3, 1));
        gpus.add(new GraphicsCard("GPU-004", "AMD", "Radeon RX 6800 XT", 649.99, "SN-GPU-004", installationDate, true,
                "PCIe 4.0", 8, "RX 6800 XT", 4608, 3, 1));
        gpus.add(new GraphicsCard("GPU-005", "AMD", "Radeon RX 6900 XT", 999.99, "SN-GPU-005", installationDate, true,
                "PCIe 4.0", 16, "RX 6900 XT", 5120, 3, 1));
        gpus.add(new GraphicsCard("GPU-006", "NVIDIA", "GeForce RTX 3060", 329.99, "SN-GPU-006", installationDate, true,
                "PCIe 4.0", 12, "RTX 3060", 3584, 3, 1));
        gpus.add(new GraphicsCard("GPU-007", "NVIDIA", "GeForce RTX 2060", 349.99, "SN-GPU-007", installationDate, true,
                "PCIe 3.0", 8, "RTX 2060", 1920, 3, 1));
        gpus.add(new GraphicsCard("GPU-008", "NVIDIA", "GeForce GTX 1660 Ti", 279.99, "SN-GPU-008", installationDate,
                true, "PCIe 3.0", 6, "GTX 1660 Ti", 1536, 3, 1));
        gpus.add(new GraphicsCard("GPU-009", "AMD", "Radeon RX 5700 XT", 399.99, "SN-GPU-009", installationDate, true,
                "PCIe 4.0", 8, "RX 5700 XT", 2560, 3, 1));
        gpus.add(new GraphicsCard("GPU-010", "NVIDIA", "GeForce GTX 1650", 149.99, "SN-GPU-010", installationDate, true,
                "PCIe 3.0", 4, "GTX 1650", 896, 3, 1));

        // Create Storage
        List<SSD> ssds = new ArrayList<>();
        ssds.add(new SSD("SSD-001", "Samsung", "970 EVO Plus", 149.99, "SN-SSD-001", installationDate, true, 1000, 7000,
                5000, "TLC", 600));
        ssds.add(new SSD("SSD-002", "WD", "Black SN750", 79.99, "SN-SSD-002", installationDate, true, 500, 3500, 3000,
                "TLC", 300));
        ssds.add(new SSD("SSD-003", "Samsung", "980 PRO", 299.99, "SN-SSD-003", installationDate, true, 2000, 7000,
                5000, "TLC", 1200));
        ssds.add(new SSD("SSD-004", "Crucial", "P5", 129.99, "SN-SSD-004", installationDate, true, 1000, 3400, 3000,
                "TLC", 600));
        ssds.add(new SSD("SSD-005", "Kingston", "KC2500", 89.99, "SN-SSD-005", installationDate, true, 500, 3500, 3000,
                "TLC", 300));
        ssds.add(new SSD("SSD-006", "ADATA", "XPG SX8200 Pro", 139.99, "SN-SSD-006", installationDate, true, 1000, 5000,
                4500, "TLC", 600));
        ssds.add(new SSD("SSD-007", "Sabrent", "Rocket 4 Plus", 399.99, "SN-SSD-007", installationDate, true, 2000,
                7000, 5000, "TLC", 1200));
        ssds.add(new SSD("SSD-008", "Seagate", "FireCuda 520", 149.99, "SN-SSD-008", installationDate, true, 1000, 3500,
                3000, "TLC", 600));
        ssds.add(new SSD("SSD-009", "Intel", "660p", 69.99, "SN-SSD-009", installationDate, true, 500, 3400, 3000,
                "QLC", 300));
        ssds.add(new SSD("SSD-010", "Patriot", "Viper VP4100", 159.99, "SN-SSD-010", installationDate, true, 1000, 3500,
                3000, "TLC", 600));

        // Create Cooling
        List<AirCooling> airCoolings = new ArrayList<>();
        airCoolings.add(new AirCooling("COOL-001", "Noctua", "NH-D15", 89.99, "SN-COOL-001", installationDate, true,
                150, 2, 1500));
        airCoolings.add(new AirCooling("COOL-002", "Cooler Master", "Hyper 212", 39.99, "SN-COOL-002", installationDate,
                true, 120, 1, 2000));
        airCoolings.add(new AirCooling("COOL-003", "be quiet!", "Dark Rock Pro 4", 79.99, "SN-COOL-003",
                installationDate, true, 140, 2, 1500));
        airCoolings.add(new AirCooling("COOL-004", "Corsair", "A500", 59.99, "SN-COOL-004", installationDate, true, 120,
                2, 1700));
        airCoolings.add(new AirCooling("COOL-005", "Arctic", "Freezer 34", 29.99, "SN-COOL-005", installationDate, true,
                92, 1, 1800));

        for (int i = 0; i < 5 && i < computers.size(); ++i) {
            computers.get(i).setCooling(airCoolings.get(i));
        }

        // Create Liquid Cooling
        List<LiquidCooling> liquidCoolings = new ArrayList<>();
        liquidCoolings.add(new LiquidCooling("LC-001", "Corsair", "H100i RGB Platinum", 129.99, "SN-LC-001",
                installationDate, true, 240, 240.0, "Water", true));
        liquidCoolings.add(new LiquidCooling("LC-002", "NZXT", "Kraken X73", 179.99, "SN-LC-002", installationDate,
                true, 360, 360.0, "Water", true));
        liquidCoolings.add(new LiquidCooling("LC-003", "Cooler Master", "MasterLiquid ML280", 139.99, "SN-LC-003",
                installationDate, true, 280, 280.0, "Water", true));
        liquidCoolings.add(new LiquidCooling("LC-004", "EVGA", "CLC 240", 119.99, "SN-LC-004", installationDate, true,
                240, 240.0, "Water", true));
        liquidCoolings.add(new LiquidCooling("LC-005", "Thermaltake", "Floe Riing RGB 360", 199.99, "SN-LC-005",
                installationDate, true, 360, 360.0, "Water", true));

        for (int i = 5; i < computers.size(); ++i) {
            computers.get(i).setCooling(liquidCoolings.get(i - 5));
        }
        // Create Power Supplies
        List<PowerSupply> psus = new ArrayList<>();
        psus.add(new PowerSupply("PSU-001", "Corsair", "RM750x", 124.99, "SN-PSU-001", installationDate, true, 750,
                "80+ Gold", true));
        psus.add(new PowerSupply("PSU-002", "EVGA", "600 BQ", 59.99, "SN-PSU-002", installationDate, true, 650,
                "80+ Bronze", true));
        psus.add(new PowerSupply("PSU-003", "Seasonic", "Prime TX-850", 199.99, "SN-PSU-003", installationDate, true,
                850, "80+ Platinum", true));
        psus.add(new PowerSupply("PSU-004", "Cooler Master", "MWE 550", 49.99, "SN-PSU-004", installationDate, true,
                550, "80+ Bronze", true));
        psus.add(new PowerSupply("PSU-005", "Corsair", "RM1000x", 159.99, "SN-PSU-005", installationDate, true, 1000,
                "80+ Gold", true));
        psus.add(new PowerSupply("PSU-006", "EVGA", "SuperNOVA 750 P2", 139.99, "SN-PSU-006", installationDate, true,
                750, "80+ Platinum", true));
        psus.add(new PowerSupply("PSU-007", "Seasonic", "Focus GX-650", 109.99, "SN-PSU-007", installationDate, true,
                650, "80+ Gold", true));
        psus.add(new PowerSupply("PSU-008", "Cooler Master", "V850", 129.99, "SN-PSU-008", installationDate, true, 850,
                "80+ Gold", true));
        psus.add(new PowerSupply("PSU-009", "Corsair", "CX550M", 69.99, "SN-PSU-009", installationDate, true, 550,
                "80+ Gold", true));
        psus.add(new PowerSupply("PSU-010", "EVGA", "SuperNOVA 1000 P2", 229.99, "SN-PSU-010", installationDate, true,
                1000, "80+ Platinum", true));

        for (int i = 0; i < computers.size(); ++i) {
            computers.get(i).setPowerSupply(psus.get(i));
        }
        // Create Motherboards
        List<Motherboard> motherboards = new ArrayList<>();
        motherboards.add(new Motherboard("MB-001", "ASUS", "ROG Strix Z690-A", 299.99, "SN-MB-001", installationDate,
                true, "Z690", "ATX", 4, 3, 6, true, new ArrayList<>()));
        motherboards.add(new Motherboard("MB-002", "MSI", "MPG Z490 Gaming Edge", 189.99, "SN-MB-002", installationDate,
                true, "Z490", "ATX", 4, 2, 6, true, new ArrayList<>()));
        motherboards
                .add(new Motherboard("MB-003", "Gigabyte", "Z590 AORUS Elite", 249.99, "SN-MB-003", installationDate,
                        true, "Z590", "ATX", 4, 3, 6, true, new ArrayList<>()));
        motherboards
                .add(new Motherboard("MB-004", "ASRock", "B550 Phantom Gaming", 159.99, "SN-MB-004", installationDate,
                        true, "B550", "ATX", 4, 2, 6, true, new ArrayList<>()));
        motherboards
                .add(new Motherboard("MB-005", "ASUS", "TUF Gaming X570-Plus", 189.99, "SN-MB-005", installationDate,
                        true, "X570", "ATX", 4, 3, 6, true, new ArrayList<>()));
        motherboards.add(new Motherboard("MB-006", "MSI", "MAG B550 Tomahawk", 179.99, "SN-MB-006", installationDate,
                true, "B550", "ATX", 4, 2, 6, true, new ArrayList<>()));
        motherboards.add(new Motherboard("MB-007", "Gigabyte", "B450 AORUS Pro", 129.99, "SN-MB-007", installationDate,
                true, "B450", "ATX", 4, 2, 6, true, new ArrayList<>()));
        motherboards.add(new Motherboard("MB-008", "ASRock", "X570 Taichi", 299.99, "SN-MB-008", installationDate,
                true, "X570", "ATX", 4, 3, 6, true, new ArrayList<>()));
        motherboards.add(new Motherboard("MB-009", "ASUS", "Prime Z390-A", 169.99, "SN-MB-009", installationDate,
                true, "Z390", "ATX", 4, 2, 6, true, new ArrayList<>()));
        motherboards
                .add(new Motherboard("MB-010", "MSI", "Z370 Gaming Pro Carbon", 159.99, "SN-MB-010", installationDate,
                        true, "Z370", "ATX", 4, 2, 6, true, new ArrayList<>()));

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
        bioses.add(
                new BIOS("BIOS-001", "ASUS", "F11", 0.0, "1.0", "LK-001", 16.0, "F11", "All", installationDate, true));
        bioses.add(new BIOS("BIOS-002", "MSI", "E7C91IMS", 0.0, "1.0", "LK-002", 16.0, "E7C91IMS", "All",
                installationDate, true));
        bioses.add(new BIOS("BIOS-003", "Gigabyte", "F20", 0.0, "1.0", "LK-003", 16.0, "F20", "All", installationDate,
                true));
        bioses.add(new BIOS("BIOS-004", "ASRock", "P1.20", 0.0, "1.0", "LK-004", 16.0, "P1.20", "All", installationDate,
                true));
        bioses.add(
                new BIOS("BIOS-005", "ASUS", "F12", 0.0, "1.0", "LK-005", 16.0, "F12", "All", installationDate, true));
        bioses.add(new BIOS("BIOS-006", "MSI", "E7C37IMS", 0.0, "1.0", "LK-006", 16.0, "E7C37IMS", "All",
                installationDate, true));
        bioses.add(new BIOS("BIOS-007", "Gigabyte", "F50", 0.0, "1.0", "LK-007", 16.0, "F50", "All", installationDate,
                true));
        bioses.add(new BIOS("BIOS-008", "ASRock", "P3.00", 0.0, "1.0", "LK-008", 16.0, "P3.00", "All", installationDate,
                true));
        bioses.add(
                new BIOS("BIOS-009", "ASUS", "F10", 0.0, "1.0", "LK-009", 16.0, "F10", "All", installationDate, true));
        bioses.add(new BIOS("BIOS-010", "MSI", "E7B45IMS", 0.0, "1.0", "LK-010", 16.0, "E7B45IMS", "All",
                installationDate, true));

        for (int i = 0; i < computers.size(); ++i) {
            computers.get(i).setBios(bioses.get(i));
        }
        // Create OS
        List<OperatingSystem> operatingSystems = new ArrayList<>();
        operatingSystems.add(new OperatingSystem("OS-001", "Microsoft", "Windows 11", 139.99, "22H2", "LK-OS-001",
                15000, "Windows", "10.0.22000", true, true));
        operatingSystems.add(new OperatingSystem("OS-002", "Microsoft", "Windows 10", 119.99, "21H1", "LK-OS-002",
                15000, "Windows", "10.0.19043", true, true));
        operatingSystems.add(new OperatingSystem("OS-003", "Canonical", "Ubuntu 20.04", 0.0, "Focal Fossa", "LK-OS-003",
                2000, "Ubuntu", "5.4.0", true, true));
        operatingSystems.add(new OperatingSystem("OS-004", "Fedora Project", "Fedora 34", 0.0, "Workstation",
                "LK-OS-004", 2000, "Fedora", "5.11.0", true, true));
        operatingSystems.add(new OperatingSystem("OS-005", "Debian", "Debian 11", 0.0, "Bullseye", "LK-OS-005", 2000,
                "Debian", "5.10.0", true, true));
        operatingSystems.add(new OperatingSystem("OS-006", "Arch Linux", "Arch Rolling", 0.0, "N/A", "LK-OS-006", 2000,
                "Arch", "5.13.0", true, true));
        operatingSystems.add(new OperatingSystem("OS-007", "Red Hat", "CentOS 8", 0.0, "Stream", "LK-OS-007", 2000,
                "CentOS", "4.18.0", true, true));
        operatingSystems.add(new OperatingSystem("OS-008", "Red Hat", "Red Hat Enterprise Linux 8", 349.99,
                "Enterprise", "LK-OS-008", 2000, "Red Hat", "4.18.0", true, true));
        operatingSystems.add(new OperatingSystem("OS-009", "Apple", "macOS 11", 0.0, "Big Sur", "LK-OS-009", 15000,
                "macOS", "20.0.0", true, true));
        operatingSystems.add(new OperatingSystem("OS-010", "Microsoft", "Windows 8.1", 99.99, "Update 3", "LK-OS-010",
                15000, "Windows", "6.3.9600", true, true));

        for (int i = 0; i < computers.size(); ++i) {
            computers.get(i).setOperatingSystem(operatingSystems.get(i));
        }
        displayTable(computers);

    }

    private static void displayTable(List<Computer> computers) {
        // Define column headers
        String[] headers = { "Computer Name", "CPU Model", "RAM Size (GB)", "GPU Model", "Storage Size (GB)" };

        // Calculate maximum width for each column
        int[] maxWidths = new int[headers.length];
        for (int i = 0; i < headers.length; i++) {
            maxWidths[i] = headers[i].length();
        }

        for (Computer computer : computers) {
            maxWidths[0] = Math.max(maxWidths[0], computer.getName().length());
            maxWidths[1] = Math.max(maxWidths[1], computer.getMotherboard().getCpu().getModel().length());
            maxWidths[2] = Math.max(maxWidths[2],
                    String.valueOf(computer.getMotherboard().getRam()).length());
            maxWidths[3] = Math.max(maxWidths[3], computer.getMotherboard().getExpansionCard().getModel().length());
            maxWidths[4] = Math.max(maxWidths[4],
                    String.valueOf(computer.getMotherboard().getStorage()).length());
        }

        // Print table header
        printLine(maxWidths);
        printRow(headers, maxWidths);
        printLine(maxWidths);

        // Print table rows
        for (Computer computer : computers) {
            String[] row = {
                    computer.getName(),
                    computer.getMotherboard().getCpu().getModel(),
                    String.valueOf(computer.getMotherboard().getRam()),
                    computer.getMotherboard().getExpansionCard().getModel(),
                    String.valueOf(computer.getMotherboard().getStorage())
            };
            printRow(row, maxWidths);
        }
        printLine(maxWidths);
    }

    private static void printLine(int[] maxWidths) {
        System.out.print("+");
        for (int width : maxWidths) {
            for (int i = 0; i < width + 2; i++) {
                System.out.print("-");
            }
            System.out.print("+");
        }
        System.out.println();
    }

    private static void printRow(String[] row, int[] maxWidths) {
        System.out.print("|");
        for (int i = 0; i < row.length; i++) {
            System.out.print(" " + row[i]);
            for (int j = row[i].length(); j < maxWidths[i]; j++) {
                System.out.print(" ");
            }
            System.out.print(" |");
        }
        System.out.println();
    }
}