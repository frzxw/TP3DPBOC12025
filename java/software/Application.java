package software;

import components.Software;

public class Application extends Software {
    private String appName;
    private String developer;
    private String supportedOS;

    public Application(String id, String manufacturer, String model, double price, String version, String licenseKey,
            double sizeMB, String appName, String developer, String supportedOS) {
        super(id, manufacturer, model, price, version, licenseKey, sizeMB);
        this.appName = appName;
        this.developer = developer;
        this.supportedOS = supportedOS;
    }

    public String getAppName() {
        return appName;
    }

    public void setAppName(String appName) {
        this.appName = appName;
    }

    public String getDeveloper() {
        return developer;
    }

    public void setDeveloper(String developer) {
        this.developer = developer;
    }

    public String getSupportedOS() {
        return supportedOS;
    }

    public void setSupportedOS(String supportedOS) {
        this.supportedOS = supportedOS;
    }
}