package components;

public abstract class Software extends Component {
    protected String version;
    protected String licenseKey;
    protected double sizeMB;

    public Software(String id, String manufacturer, String model, double price, String version, String licenseKey,
            double sizeMB) {
        super(id, manufacturer, model, price);
        this.version = version;
        this.licenseKey = licenseKey;
        this.sizeMB = sizeMB;
    }

    public String getVersion() {
        return version;
    }

    public void setVersion(String version) {
        this.version = version;
    }

    public String getLicenseKey() {
        return licenseKey;
    }

    public void setLicenseKey(String licenseKey) {
        this.licenseKey = licenseKey;
    }

    public double getSizeMB() {
        return sizeMB;
    }

    public void setSizeMB(double sizeMB) {
        this.sizeMB = sizeMB;
    }
}