package components;

import java.util.Date;

public class Cooling extends Hardware {
    private int maxThermalDissipation;

    public Cooling(String id, String manufacturer, String model, double price, String serialNumber,
            Date installationDate, boolean physicallyInstalled, int maxThermalDissipation) {
        super(id, manufacturer, model, price, serialNumber, installationDate, physicallyInstalled);
        this.maxThermalDissipation = maxThermalDissipation;
    }

    public int getMaxThermalDissipation() {
        return maxThermalDissipation;
    }

    public void setMaxThermalDissipation(int maxThermalDissipation) {
        this.maxThermalDissipation = maxThermalDissipation;
    }
}