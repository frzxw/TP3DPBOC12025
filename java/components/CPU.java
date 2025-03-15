package components;

import java.util.Date;

public class CPU extends Hardware {
    private double clockSpeedGHz;
    private int cores;
    private int threads;
    private String architecture;
    private double cacheSize;
    private boolean hyperthreading;
    private String socketType;

    public CPU(String id, String manufacturer, String model, double price, String serialNumber, Date installationDate,
            boolean physicallyInstalled,
            double clockSpeedGHz, int cores, int threads, String architecture, double cacheSize, boolean hyperthreading,
            String socketType) {
        super(id, manufacturer, model, price, serialNumber, installationDate, physicallyInstalled);
        this.clockSpeedGHz = clockSpeedGHz;
        this.cores = cores;
        this.threads = threads;
        this.architecture = architecture;
        this.cacheSize = cacheSize;
        this.hyperthreading = hyperthreading;
        this.socketType = socketType;
    }

    // Getters and Setters
    public double getClockSpeedGHz() {
        return clockSpeedGHz;
    }

    public void setClockSpeedGHz(double clockSpeedGHz) {
        this.clockSpeedGHz = clockSpeedGHz;
    }

    public int getCores() {
        return cores;
    }

    public void setCores(int cores) {
        this.cores = cores;
    }

    public int getThreads() {
        return threads;
    }

    public void setThreads(int threads) {
        this.threads = threads;
    }

    public String getArchitecture() {
        return architecture;
    }

    public void setArchitecture(String architecture) {
        this.architecture = architecture;
    }

    public double getCacheSize() {
        return cacheSize;
    }

    public void setCacheSize(double cacheSize) {
        this.cacheSize = cacheSize;
    }

    public boolean isHyperthreading() {
        return hyperthreading;
    }

    public void setHyperthreading(boolean hyperthreading) {
        this.hyperthreading = hyperthreading;
    }

    public String getSocketType() {
        return socketType;
    }

    public void setSocketType(String socketType) {
        this.socketType = socketType;
    }
}