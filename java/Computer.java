import components.*;
import software.*;

import java.util.List;
import java.util.ArrayList;

public class Computer {
    private String name;
    private boolean powerStatus;
    private Motherboard motherboard;
    private PowerSupply powerSupply;
    private Cooling cooling;
    private List<Peripheral> peripherals;
    private List<Software> installedSoftware;
    private BIOS bios;
    private OperatingSystem operatingSystem;
    private List<Driver> drivers;

    public Computer(String name) {
        this.name = name;
        this.powerStatus = false;
        this.peripherals = new ArrayList<>();
        this.installedSoftware = new ArrayList<>();
        this.drivers = new ArrayList<>();
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public boolean isPowerStatus() {
        return powerStatus;
    }

    public void setPowerStatus(boolean powerStatus) {
        this.powerStatus = powerStatus;
    }

    public Motherboard getMotherboard() {
        return motherboard;
    }

    public void setMotherboard(Motherboard motherboard) {
        this.motherboard = motherboard;
    }

    public PowerSupply getPowerSupply() {
        return powerSupply;
    }

    public void setPowerSupply(PowerSupply powerSupply) {
        this.powerSupply = powerSupply;
    }

    public Cooling getCooling() {
        return cooling;
    }

    public void setCooling(Cooling cooling) {
        this.cooling = cooling;
    }

    public List<Peripheral> getPeripherals() {
        return peripherals;
    }

    public void setPeripherals(List<Peripheral> peripherals) {
        this.peripherals = peripherals;
    }

    public List<Software> getInstalledSoftware() {
        return installedSoftware;
    }

    public void setInstalledSoftware(List<Software> installedSoftware) {
        this.installedSoftware = installedSoftware;
    }

    public BIOS getBios() {
        return bios;
    }

    public void setBios(BIOS bios) {
        this.bios = bios;
    }

    public OperatingSystem getOperatingSystem() {
        return operatingSystem;
    }

    public void setOperatingSystem(OperatingSystem operatingSystem) {
        this.operatingSystem = operatingSystem;
    }

    public List<Driver> getDrivers() {
        return drivers;
    }

    public void setDrivers(List<Driver> drivers) {
        this.drivers = drivers;
    }

    public void installPeripheral(Peripheral peripheral) {
        this.peripherals.add(peripheral);
    }

    public void installSoftware(Software software) {
        this.installedSoftware.add(software);
    }

    public void installDriver(Driver driver) {
        this.drivers.add(driver);
    }
}