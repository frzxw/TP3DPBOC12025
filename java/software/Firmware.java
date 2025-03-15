package software;

import components.Software;

import java.util.Date;

public class Firmware extends Software {
    private String firmwareVersion;
    private String supportedHardware;
    private Date releaseDate;
    private boolean installed;

    public Firmware(String id, String manufacturer, String model, double price, String version, String licenseKey,
            double sizeMB, String firmwareVersion, String supportedHardware, Date releaseDate, boolean installed) {
        super(id, manufacturer, model, price, version, licenseKey, sizeMB);
        this.firmwareVersion = firmwareVersion;
        this.supportedHardware = supportedHardware;
        this.releaseDate = releaseDate;
        this.installed = installed;
    }

    public String getFirmwareVersion() {
        return firmwareVersion;
    }

    public void setFirmwareVersion(String firmwareVersion) {
        this.firmwareVersion = firmwareVersion;
    }

    public String getSupportedHardware() {
        return supportedHardware;
    }

    public void setSupportedHardware(String supportedHardware) {
        this.supportedHardware = supportedHardware;
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