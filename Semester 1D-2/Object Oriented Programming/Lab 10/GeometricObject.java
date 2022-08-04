public abstract class GeometricObject {
    private String color = "white";
    private boolean filled;
    private java.util.Date dateCreated;

    protected GeometricObject(){
        dateCreated = new java.util.Date();
    }
    protected GeometricObject(String color, boolean filled){
        dateCreated  = new java.util.Date();
        this.color = color;
        this.filled = filled;
    }

    public String getColor(){
        return color;
    }

    public boolean getFilled(){
        return filled;
    }
    
    public java.util.Date getDateCreated(){
        return dateCreated;
    }

    public void setColor(String color){
        this.color = color;
    }

    public void setFilled(boolean filled){
        this.filled = filled;
    }

    @Override
    public String toString(){
        return "Color: " + color + "\nFilled: " + filled + "\nDate Created: " + dateCreated;
    }

    /* Abstract */
    public abstract double getArea();

    public abstract double getPerimeter();
}
