package components;

import java.util.Date;

public class HDD extends StorageDevice {
    private int rpm;
    private int platterCount;

    public HDD(String id, String manufacturer, String model, double price, String serialNumber, Date installationDate,
            boolean physicallyInstalled, int capacityGB, int readSpeedMBs, int writeSpeedMBs, int rpm,
            int platterCount) {
        super(id, manufacturer, model, price, serialNumber, installationDate, physicallyInstalled, capacityGB,
                readSpeedMBs, writeSpeedMBs);
        this.rpm = rpm;
        this.platterCount = platterCount;
    }

    public int getRpm() {
        return rpm;
    }

    public void setRpm(int rpm) {
        this.rpm = rpm;
    }

    public int getPlatterCount() {
        return platterCount;
    }

    public void setPlatterCount(int platterCount) {
        this.platterCount = platterCount;
    }
}