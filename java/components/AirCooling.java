package components;

import java.util.Date;

public class AirCooling extends Cooling {
    private int fanCount;
    private int fanSpeedRPM;

    public AirCooling(String id, String manufacturer, String model, double price, String serialNumber,
                      Date installationDate, boolean physicallyInstalled, int maxThermalDissipation,
                      int fanCount, int fanSpeedRPM) {
        super(id, manufacturer, model, price, serialNumber, installationDate, physicallyInstalled, maxThermalDissipation);
        this.fanCount = fanCount;
        this.fanSpeedRPM = fanSpeedRPM;
    }

    public int getFanCount() {
        return fanCount;
    }

    public void setFanCount(int fanCount) {
        this.fanCount = fanCount;
    }

    public int getFanSpeedRPM() {
        return fanSpeedRPM;
    }

    public void setFanSpeedRPM(int fanSpeedRPM) {
        this.fanSpeedRPM = fanSpeedRPM;
    }
}