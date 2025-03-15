package components;

import java.util.Date;

public class GraphicsCard extends ExpansionCard {
    private int vramGB;
    private String gpuModel;
    private int cudaCores;
    private int displayPorts;
    private int hdmiPorts;

    public GraphicsCard(String id, String manufacturer, String model, double price, String serialNumber,
            Date installationDate, boolean physicallyInstalled, String interfaceType, int vramGB, String gpuModel, int cudaCores, int displayPorts, int hdmiPorts) {
        super(id, manufacturer, model, price, serialNumber, installationDate, physicallyInstalled, interfaceType);
        this.vramGB = vramGB;
        this.gpuModel = gpuModel;
        this.cudaCores = cudaCores;
        this.displayPorts = displayPorts;
        this.hdmiPorts = hdmiPorts;
    }

    public int getVramGB() {
        return vramGB;
    }

    public void setVramGB(int vramGB) {
        this.vramGB = vramGB;
    }

    public String getGpuModel() {
        return gpuModel;
    }

    public void setGpuModel(String gpuModel) {
        this.gpuModel = gpuModel;
    }

    public int getCudaCores() {
        return cudaCores;
    }

    public void setCudaCores(int cudaCores) {
        this.cudaCores = cudaCores;
    }

    public int getDisplayPorts() {
        return displayPorts;
    }

    public void setDisplayPorts(int displayPorts) {
        this.displayPorts = displayPorts;
    }

    public int getHdmiPorts() {
        return hdmiPorts;
    }

    public void setHdmiPorts(int hdmiPorts) {
        this.hdmiPorts = hdmiPorts;
    }
}