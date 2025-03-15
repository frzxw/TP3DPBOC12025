package components;

import java.util.Date;
import java.util.List;
import java.util.ArrayList;

public class Motherboard extends Hardware {
    private String chipset;
    private String formFactor;
    private int ramSlotsCount;
    private int pcieSlotsCount;
    private int sataPortsCount;
    private boolean hasIntegratedGPU;
    private List<String> supportedCPUs;
    private CPU cpu;
    private List<RAM> ramSlots;
    private List<ExpansionCard> expansionSlots;
    private List<StorageDevice> storageSlots;
    private GraphicsCard gpu;
    private NetworkCard networkCard;
    private SoundCard soundCard;

    public Motherboard(String id, String manufacturer, String model, double price, String serialNumber,
            Date installationDate, boolean physicallyInstalled,
            String chipset, String formFactor, int ramSlotsCount, int pcieSlotsCount, int sataPortsCount,
            boolean hasIntegratedGPU,
            List<String> supportedCPUs) {
        super(id, manufacturer, model, price, serialNumber, installationDate, physicallyInstalled);
        this.chipset = chipset;
        this.formFactor = formFactor;
        this.ramSlotsCount = ramSlotsCount;
        this.pcieSlotsCount = pcieSlotsCount;
        this.sataPortsCount = sataPortsCount;
        this.hasIntegratedGPU = hasIntegratedGPU;
        this.supportedCPUs = supportedCPUs;
        this.ramSlots = new ArrayList<>();
        this.expansionSlots = new ArrayList<>();
        this.storageSlots = new ArrayList<>();
    }

    public String getChipset() {
        return chipset;
    }

    public void setChipset(String chipset) {
        this.chipset = chipset;
    }

    public String getFormFactor() {
        return formFactor;
    }

    public void setFormFactor(String formFactor) {
        this.formFactor = formFactor;
    }

    public int getRamSlotsCount() {
        return ramSlotsCount;
    }

    public void setRamSlotsCount(int ramSlotsCount) {
        this.ramSlotsCount = ramSlotsCount;
    }

    public int getPcieSlotsCount() {
        return pcieSlotsCount;
    }

    public void setPcieSlotsCount(int pcieSlotsCount) {
        this.pcieSlotsCount = pcieSlotsCount;
    }

    public int getSataPortsCount() {
        return sataPortsCount;
    }

    public void setSataPortsCount(int sataPortsCount) {
        this.sataPortsCount = sataPortsCount;
    }

    public boolean isHasIntegratedGPU() {
        return hasIntegratedGPU;
    }

    public void setHasIntegratedGPU(boolean hasIntegratedGPU) {
        this.hasIntegratedGPU = hasIntegratedGPU;
    }

    public List<String> getSupportedCPUs() {
        return supportedCPUs;
    }

    public void setSupportedCPUs(List<String> supportedCPUs) {
        this.supportedCPUs = supportedCPUs;
    }

    public CPU getCpu() {
        return cpu;
    }

    public void setCpu(CPU cpu) {
        this.cpu = cpu;
    }

    public List<RAM> getRamSlots() {
        return ramSlots;
    }

    public void setRamSlots(List<RAM> ramSlots) {
        this.ramSlots = ramSlots;
    }

    public List<ExpansionCard> getExpansionSlots() {
        return expansionSlots;
    }

    public void setExpansionSlots(List<ExpansionCard> expansionSlots) {
        this.expansionSlots = expansionSlots;
    }

    public List<StorageDevice> getStorageSlots() {
        return storageSlots;
    }

    public void setStorageSlots(List<StorageDevice> storageSlots) {
        this.storageSlots = storageSlots;
    }

    public GraphicsCard getGpu() {
        return gpu;
    }

    public void setGpu(GraphicsCard gpu) {
        this.gpu = gpu;
    }

    public NetworkCard getNetworkCard() {
        return networkCard;
    }

    public void setNetworkCard(NetworkCard networkCard) {
        this.networkCard = networkCard;
    }

    public SoundCard getSoundCard() {
        return soundCard;
    }

    public void setSoundCard(SoundCard soundCard) {
        this.soundCard = soundCard;
    }

    public void installCPU(CPU cpu) {
        this.cpu = cpu;
    }

    public void installRAM(RAM ram) {
        if (ramSlots.size() < ramSlotsCount) {
            ramSlots.add(ram);
        }
    }

    public void installExpansionCard(ExpansionCard card) {
        if (expansionSlots.size() < pcieSlotsCount) {
            expansionSlots.add(card);
        }
    }

    public void installStorage(StorageDevice storage) {
        if (storageSlots.size() < sataPortsCount) {
            storageSlots.add(storage);
        }
    }

    public void removeCPU() {
        this.cpu = null;
    }

    public void removeRAM(RAM ram) {
        ramSlots.remove(ram);
    }

    public void removeExpansionCard(ExpansionCard card) {
        expansionSlots.remove(card);
    }

    public void removeStorage(StorageDevice storage) {
        storageSlots.remove(storage);
    }

    public void displayInfo() {

    }
}