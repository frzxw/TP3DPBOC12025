package components;

public abstract class Component {
    protected String id;
    protected String manufacturer;
    protected String model;
    protected double price;

    public Component(String id, String manufacturer, String model, double price) {
        this.id = id;
        this.manufacturer = manufacturer;
        this.model = model;
        this.price = price;
    }

    public String getId() {
        return id;
    }

    public String getManufacturer() {
        return manufacturer;
    }

    public String getModel() {
        return model;
    }

    public double getPrice() {
        return price;
    }
}