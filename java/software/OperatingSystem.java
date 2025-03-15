package software;

import components.Software;

public class OperatingSystem extends Software {
    private String osName;
    private String kernelVersion;
    private boolean is64Bit;
    private boolean installed;

    public OperatingSystem(String id, String manufacturer, String model, double price, String version,
            String licenseKey, double sizeMB, String osName, String kernelVersion, boolean is64Bit, boolean installed) {
        super(id, manufacturer, model, price, version, licenseKey, sizeMB);
        this.osName = osName;
        this.kernelVersion = kernelVersion;
        this.is64Bit = is64Bit;
        this.installed = installed;
    }

    public String getOsName() {
        return osName;
    }

    public void setOsName(String osName) {
        this.osName = osName;
    }

    public String getKernelVersion() {
        return kernelVersion;
    }

    public void setKernelVersion(String kernelVersion) {
        this.kernelVersion = kernelVersion;
    }

    public boolean is64Bit() {
        return is64Bit;
    }

    public void set64Bit(boolean is64Bit) {
        this.is64Bit = is64Bit;
    }

    public boolean isInstalled() {
        return installed;
    }

    public void setInstalled(boolean installed) {
        this.installed = installed;
    }
}