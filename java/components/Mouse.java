package components;

import java.util.Date;

public class Mouse extends Peripheral {
    private int buttonCount;
    private boolean hasScrollWheel;
    private int dpi;

    public Mouse(String id, String manufacturer, String model, double price, String serialNumber, Date installationDate,
            boolean physicallyInstalled, String name, String connectionType, boolean wireless, int buttonCount,
            boolean hasScrollWheel, int dpi) {
        super(id, manufacturer, model, price, serialNumber, installationDate, physicallyInstalled, name, connectionType, wireless);
        this.buttonCount = buttonCount;
        this.hasScrollWheel = hasScrollWheel;
        this.dpi = dpi;
    }

    public int getButtonCount() {
        return buttonCount;
    }

    public void setButtonCount(int buttonCount) {
        this.buttonCount = buttonCount;
    }

    public boolean isHasScrollWheel() {
        return hasScrollWheel;
    }

    public void setHasScrollWheel(boolean hasScrollWheel) {
        this.hasScrollWheel = hasScrollWheel;
    }

    public int getDpi() {
        return dpi;
    }

    public void setDpi(int dpi) {
        this.dpi = dpi;
    }
}