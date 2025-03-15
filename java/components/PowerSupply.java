package components;

import java.util.Date;

public class PowerSupply extends Hardware {
    private int wattage;
    private String certification;
    private boolean modular;

    public PowerSupply(String id, String manufacturer, String model, double price, String serialNumber,
            Date installationDate, boolean physicallyInstalled, int wattage, String certification, boolean modular) {
        super(id, manufacturer, model, price, serialNumber, installationDate, physicallyInstalled);
        this.wattage = wattage;
        this.certification = certification;
        this.modular = modular;
    }

    public int getWattage() {
        return wattage;
    }

    public void setWattage(int wattage) {
        this.wattage = wattage;
    }

    public String getCertification() {
        return certification;
    }

    public void setCertification(String certification) {
        this.certification = certification;
    }

    public boolean isModular() {
        return modular;
    }

    public void setModular(boolean modular) {
        this.modular = modular;
    }
}