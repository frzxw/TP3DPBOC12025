package components;

import java.util.Date;

public class Monitor extends Peripheral {
    private double screenSizeInches;
    private int resolutionWidth;
    private int resolutionHeight;
    private int refreshRate;
    private String panelType;

    public Monitor(String id, String manufacturer, String model, double price, String serialNumber, Date installationDate,
            boolean physicallyInstalled, String name, String connectionType, boolean wireless, double screenSizeInches,
            int resolutionWidth, int resolutionHeight, int refreshRate, String panelType) {
        super(id, manufacturer, model, price, serialNumber, installationDate, physicallyInstalled, name, connectionType, wireless);
        this.screenSizeInches = screenSizeInches;
        this.resolutionWidth = resolutionWidth;
        this.resolutionHeight = resolutionHeight;
        this.refreshRate = refreshRate;
        this.panelType = panelType;
    }

    public double getScreenSizeInches() {
        return screenSizeInches;
    }

    public void setScreenSizeInches(double screenSizeInches) {
        this.screenSizeInches = screenSizeInches;
    }

    public int getResolutionWidth() {
        return resolutionWidth;
    }

    public void setResolutionWidth(int resolutionWidth) {
        this.resolutionWidth = resolutionWidth;
    }

    public int getResolutionHeight() {
        return resolutionHeight;
    }

    public void setResolutionHeight(int resolutionHeight) {
        this.resolutionHeight = resolutionHeight;
    }

    public int getRefreshRate() {
        return refreshRate;
    }

    public void setRefreshRate(int refreshRate) {
        this.refreshRate = refreshRate;
    }

    public String getPanelType() {
        return panelType;
    }

    public void setPanelType(String panelType) {
        this.panelType = panelType;
    }
}