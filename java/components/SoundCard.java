package components;

import java.util.Date;

public class SoundCard extends ExpansionCard {
    private int channels;
    private int bitDepth;
    private int sampleRate;

    public SoundCard(String id, String manufacturer, String model, double price, String serialNumber,
            Date installationDate, boolean physicallyInstalled, String interfaceType, int channels, int bitDepth,
            int sampleRate) {
        super(id, manufacturer, model, price, serialNumber, installationDate, physicallyInstalled, interfaceType);
        this.channels = channels;
        this.bitDepth = bitDepth;
        this.sampleRate = sampleRate;
    }

    public int getChannels() {
        return channels;
    }

    public void setChannels(int channels) {
        this.channels = channels;
    }

    public int getBitDepth() {
        return bitDepth;
    }

    public void setBitDepth(int bitDepth) {
        this.bitDepth = bitDepth;
    }

    public int getSampleRate() {
        return sampleRate;
    }

    public void setSampleRate(int sampleRate) {
        this.sampleRate = sampleRate;
    }
}