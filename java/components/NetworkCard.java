package components;

import java.util.Date;

public class NetworkCard extends ExpansionCard {
    private String macAddress;
    private int maxSpeedMbps;
    private boolean supportsWifi;
    private boolean supportsBluetooth;

    public NetworkCard(String id, String manufacturer, String model, double price, String serialNumber,
            Date installationDate, boolean physicallyInstalled, String interfaceType,
            String macAddress, int maxSpeedMbps, boolean supportsWifi, boolean supportsBluetooth) {
        super(id, manufacturer, model, price, serialNumber, installationDate, physicallyInstalled, interfaceType);
        this.macAddress = macAddress;
        this.maxSpeedMbps = maxSpeedMbps;
        this.supportsWifi = supportsWifi;
        this.supportsBluetooth = supportsBluetooth;
    }

    public String getMacAddress() {
        return macAddress;
    }

    public void setMacAddress(String macAddress) {
        this.macAddress = macAddress;
    }

    public int getMaxSpeedMbps() {
        return maxSpeedMbps;
    }

    public void setMaxSpeedMbps(int maxSpeedMbps) {
        this.maxSpeedMbps = maxSpeedMbps;
    }

    public boolean isSupportsWifi() {
        return supportsWifi;
    }

    public void setSupportsWifi(boolean supportsWifi) {
        this.supportsWifi = supportsWifi;
    }

    public boolean isSupportsBluetooth() {
        return supportsBluetooth;
    }

    public void setSupportsBluetooth(boolean supportsBluetooth) {
        this.supportsBluetooth = supportsBluetooth;
    }
}