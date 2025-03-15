package software;

import java.util.Date;

public class BIOS extends Firmware {
    private String manufacturer;
    private Date releaseDate;
    private boolean installed;

    public BIOS(String id, String manufacturer, String model, double price, String version, String licenseKey,
            double sizeMB, String firmwareVersion, String supportedHardware, Date releaseDate, boolean installed) {
        super(id, manufacturer, model, price, version, licenseKey, sizeMB, firmwareVersion, supportedHardware, releaseDate, installed);
        this.manufacturer = manufacturer;
        this.releaseDate = releaseDate;
        this.installed = installed;
    }

    public String getManufacturer() {
        return manufacturer;
    }

    public void setManufacturer(String manufacturer) {
        this.manufacturer = manufacturer;
    }

    public Date getReleaseDate() {
        return releaseDate;
    }

    public void setReleaseDate(Date releaseDate) {
        this.releaseDate = releaseDate;
    }

    public boolean isInstalled() {
        return installed;
    }

    public void setInstalled(boolean installed) {
        this.installed = installed;
    }
}