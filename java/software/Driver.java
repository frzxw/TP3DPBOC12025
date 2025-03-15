package software;

import components.Software;

public class Driver extends Software {
    private String deviceName;
    private String driverVersion;
    private String supportedOS;
    private boolean isSigned;

    public Driver(String id, String manufacturer, String model, double price, String version, String licenseKey,
            double sizeMB,
            String deviceName, String driverVersion, String supportedOS, boolean isSigned) {
        super(id, manufacturer, model, price, version, licenseKey, sizeMB);
        this.deviceName = deviceName;
        this.driverVersion = driverVersion;
        this.supportedOS = supportedOS;
        this.isSigned = isSigned;
    }

    public String getDeviceName() {
        return deviceName;
    }

    public void setDeviceName(String deviceName) {
        this.deviceName = deviceName;
    }

    public String getDriverVersion() {
        return driverVersion;
    }

    public void setDriverVersion(String driverVersion) {
        this.driverVersion = driverVersion;
    }

    public String getSupportedOS() {
        return supportedOS;
    }

    public void setSupportedOS(String supportedOS) {
        this.supportedOS = supportedOS;
    }

    public boolean isSigned() {
        return isSigned;
    }

    public void setSigned(boolean signed) {
        isSigned = signed;
    }
}