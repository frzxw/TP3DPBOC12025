package interfaces;

public interface Bootable {
    boolean boot();
    void shutdown();
    void restart();
}