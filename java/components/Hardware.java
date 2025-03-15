package components;

import java.util.Date;

public abstract class Hardware extends Component {
    private String serialNumber;
    private Date installationDate;
    private boolean physicallyInstalled;

    public Hardware(String id, String manufacturer, String model, double price, String serialNumber,
            Date installationDate, boolean physicallyInstalled) {
        super(id, manufacturer, model, price);
        this.serialNumber = serialNumber;
        this.installationDate = installationDate;
        this.physicallyInstalled = physicallyInstalled;
    }

    public String getSerialNumber() {
        return serialNumber;
    }

    public void setSerialNumber(String serialNumber) {
        this.serialNumber = serialNumber;
    }

    public Date getInstallationDate() {
        return installationDate;
    }

    public void setInstallationDate(Date installationDate) {
        this.installationDate = installationDate;
    }

    public boolean isPhysicallyInstalled() {
        return physicallyInstalled;
    }

    public void setPhysicallyInstalled(boolean physicallyInstalled) {
        this.physicallyInstalled = physicallyInstalled;
    }
}