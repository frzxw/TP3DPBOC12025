package components;

import java.util.Date;

public class Peripheral extends Hardware {
    private String name;
    private String connectionType;
    private boolean wireless;

    public Peripheral(String id, String manufacturer, String model, double price, String serialNumber,
            Date installationDate, boolean physicallyInstalled, String name, String connectionType, boolean wireless) {
        super(id, manufacturer, model, price, serialNumber, installationDate, physicallyInstalled);
        this.name = name;
        this.connectionType = connectionType;
        this.wireless = wireless;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getConnectionType() {
        return connectionType;
    }

    public void setConnectionType(String connectionType) {
        this.connectionType = connectionType;
    }

    public boolean isWireless() {
        return wireless;
    }

    public void setWireless(boolean wireless) {
        this.wireless = wireless;
    }
}