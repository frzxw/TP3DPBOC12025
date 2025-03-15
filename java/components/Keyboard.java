package components;

import java.util.Date;

public class Keyboard extends Peripheral {
    private boolean mechanical;
    private String layoutType;
    private boolean hasBacklight;

    public Keyboard(String id, String manufacturer, String model, double price, String serialNumber, Date installationDate,
            boolean physicallyInstalled, String name, String connectionType, boolean wireless, boolean mechanical,
            String layoutType, boolean hasBacklight) {
        super(id, manufacturer, model, price, serialNumber, installationDate, physicallyInstalled, name, connectionType, wireless);
        this.mechanical = mechanical;
        this.layoutType = layoutType;
        this.hasBacklight = hasBacklight;
    }

    public boolean isMechanical() {
        return mechanical;
    }

    public void setMechanical(boolean mechanical) {
        this.mechanical = mechanical;
    }

    public String getLayoutType() {
        return layoutType;
    }

    public void setLayoutType(String layoutType) {
        this.layoutType = layoutType;
    }

    public boolean hasBacklight() {
        return hasBacklight;
    }

    public void setBacklight(boolean hasBacklight) {
        this.hasBacklight = hasBacklight;
    }
}