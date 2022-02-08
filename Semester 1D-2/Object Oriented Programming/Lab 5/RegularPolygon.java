public class RegularPolygon {
    /* Data fields */
    private int n;
    private double side;
    private double x;
    private double y;

    /* Constructors */
    // Default
    RegularPolygon(){
        n = 3;
        side  = 1;
        x = 0;
        y = 0;
    }

    // Specific number of side and length of side with center (0,0)
    RegularPolygon(int newN, double newSide){
        n  = newN;
        side = newSide;
        x = 0;
        y = 0;    
    }

    // Specific number of side and length of side with center (x,y)
    RegularPolygon(int newN, double newSide, double newX, double newY){
        n = newN;
        side = newSide;
        x = newX;
        y = newY;
    }  

    /* Mutator methods */
    // Set n
    public void setN(int newN){
        n = newN;
    }

    // Set side
    public void setSide(double newSide){
        side  = newSide;
    }

    // Set X
    public void setX(double newX){
        x = newX;
    }

    // Set Y
    public void setY(double newY){
        y = newY;
    }

    /* Accessor */
    // Return n
    public int getN(){
        return n;
    }

    // Return side
    public double getSide(){
        return side;
    }

    // Retuen X
    public double getX(){
        return x;
    }

    // Return Y
    public double getY(){
        return y;
    }

    /* Method */
    public double getPerimeter(){
        return side * n;
    }

    public double getArea(){
        return (n * Math.pow(side, 2)) / (4 * Math.tan(Math.PI/n));
    }
}
