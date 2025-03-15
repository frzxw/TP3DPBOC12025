package components;

import java.util.Date;

public class ExpansionCard extends Hardware {
    private String interfaceType;

    public ExpansionCard(String id, String manufacturer, String model, double price, String serialNumber,
            Date installationDate, boolean physicallyInstalled, String interfaceType) {
        super(id, manufacturer, model, price, serialNumber, installationDate, physicallyInstalled);
        this.interfaceType = interfaceType;
    }

    public String getInterfaceType() {
        return interfaceType;
    }

    public void setInterfaceType(String interfaceType) {
        this.interfaceType = interfaceType;
    }
}