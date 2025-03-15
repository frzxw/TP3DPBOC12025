package components;

import java.util.Date;

public class SSD extends StorageDevice {
    private String nandType;
    private int tbw;

    public SSD(String id, String manufacturer, String model, double price, String serialNumber, Date installationDate,
            boolean physicallyInstalled, int capacityGB, int readSpeedMBs, int writeSpeedMBs, String nandType,
            int tbw) {
        super(id, manufacturer, model, price, serialNumber, installationDate, physicallyInstalled, capacityGB,
                readSpeedMBs, writeSpeedMBs);
        this.nandType = nandType;
        this.tbw = tbw;
    }

    public String getNandType() {
        return nandType;
    }

    public void setNandType(String nandType) {
        this.nandType = nandType;
    }

    public int getTbw() {
        return tbw;
    }

    public void setTbw(int tbw) {
        this.tbw = tbw;
    }
}