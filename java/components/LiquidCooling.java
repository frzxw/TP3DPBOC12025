package components;

import java.util.Date;

public class LiquidCooling extends Cooling {
    private double fluidVolume;
    private String fluidType;
    private boolean hasPump;

    public LiquidCooling(String id, String manufacturer, String model, double price, String serialNumber,
            Date installationDate, boolean physicallyInstalled, int maxThermalDissipation,
            double fluidVolume, String fluidType, boolean hasPump) {
        super(id, manufacturer, model, price, serialNumber, installationDate, physicallyInstalled,
                maxThermalDissipation);
        this.fluidVolume = fluidVolume;
        this.fluidType = fluidType;
        this.hasPump = hasPump;
    }

    public double getFluidVolume() {
        return fluidVolume;
    }

    public void setFluidVolume(double fluidVolume) {
        this.fluidVolume = fluidVolume;
    }

    public String getFluidType() {
        return fluidType;
    }

    public void setFluidType(String fluidType) {
        this.fluidType = fluidType;
    }

    public boolean isHasPump() {
        return hasPump;
    }

    public void setHasPump(boolean hasPump) {
        this.hasPump = hasPump;
    }
}