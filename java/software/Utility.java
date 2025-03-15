package software;

import components.Software;

public class Utility extends Software {
    private String utilityName;
    private String function;
    private String version;

    public Utility(String id, String manufacturer, String model, double price, String version, String licenseKey,
            double sizeMB, String utilityName, String function) {
        super(id, manufacturer, model, price, version, licenseKey, sizeMB);
        this.utilityName = utilityName;
        this.function = function;
        this.version = version;
    }

    public String getUtilityName() {
        return utilityName;
    }

    public void setUtilityName(String utilityName) {
        this.utilityName = utilityName;
    }

    public String getFunction() {
        return function;
    }

    public void setFunction(String function) {
        this.function = function;
    }

    public String getVersion() {
        return version;
    }

    public void setVersion(String version) {
        this.version = version;
    }
}