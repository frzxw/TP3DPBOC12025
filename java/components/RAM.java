package components;

import java.util.Date;

public class RAM extends Hardware {
    private int capacityGB;
    private String type;
    private int speedMHz;
    private boolean isECC;

    public RAM(String id, String manufacturer, String model, double price, String serialNumber, Date installationDate,
            boolean physicallyInstalled, int capacityGB, String type, int speedMHz, boolean isECC) {
        super(id, manufacturer, model, price, serialNumber, installationDate, physicallyInstalled);
        this.capacityGB = capacityGB;
        this.type = type;
        this.speedMHz = speedMHz;
        this.isECC = isECC;
    }

    public int getCapacityGB() {
        return capacityGB;
    }

    public void setCapacityGB(int capacityGB) {
        this.capacityGB = capacityGB;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public int getSpeedMHz() {
        return speedMHz;
    }

    public void setSpeedMHz(int speedMHz) {
        this.speedMHz = speedMHz;
    }

    public boolean isECC() {
        return isECC;
    }

    public void setECC(boolean isECC) {
        this.isECC = isECC;
    }
}