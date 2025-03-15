package software;

public class GameEngine extends Application {
    private String engineName;
    private String supportedPlatforms;
    private boolean isOpenSource;

    public GameEngine(String id, String manufacturer, String model, double price, String version, String licenseKey,
            double sizeMB, String appName, String developer, String supportedOS, String engineName,
            String supportedPlatforms, boolean isOpenSource) {
        super(id, manufacturer, model, price, version, licenseKey, sizeMB, appName, developer, supportedOS);
        this.engineName = engineName;
        this.supportedPlatforms = supportedPlatforms;
        this.isOpenSource = isOpenSource;
    }

    public String getEngineName() {
        return engineName;
    }

    public void setEngineName(String engineName) {
        this.engineName = engineName;
    }

    public String getSupportedPlatforms() {
        return supportedPlatforms;
    }

    public void setSupportedPlatforms(String supportedPlatforms) {
        this.supportedPlatforms = supportedPlatforms;
    }

    public boolean isOpenSource() {
        return isOpenSource;
    }

    public void setOpenSource(boolean openSource) {
        isOpenSource = openSource;
    }
}