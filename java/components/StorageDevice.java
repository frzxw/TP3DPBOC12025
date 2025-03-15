package components;

import java.util.Date;

public class StorageDevice extends Hardware {
    private int capacityGB;
    private int readSpeedMBs;
    private int writeSpeedMBs;

    public StorageDevice(String id, String manufacturer, String model, double price, String serialNumber,
            Date installationDate, boolean physicallyInstalled, int capacityGB, int readSpeedMBs, int writeSpeedMBs) {
        super(id, manufacturer, model, price, serialNumber, installationDate, physicallyInstalled);
        this.capacityGB = capacityGB;
        this.readSpeedMBs = readSpeedMBs;
        this.writeSpeedMBs = writeSpeedMBs;
    }

    public int getCapacityGB() {
        return capacityGB;
    }

    public void setCapacityGB(int capacityGB) {
        this.capacityGB = capacityGB;
    }

    public int getReadSpeedMBs() {
        return readSpeedMBs;
    }

    public void setReadSpeedMBs(int readSpeedMBs) {
        this.readSpeedMBs = readSpeedMBs;
    }

    public int getWriteSpeedMBs() {
        return writeSpeedMBs;
    }

    public void setWriteSpeedMBs(int writeSpeedMBs) {
        this.writeSpeedMBs = writeSpeedMBs;
    }
}