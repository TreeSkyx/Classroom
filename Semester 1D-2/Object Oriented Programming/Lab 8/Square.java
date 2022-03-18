public class Square extends GeomatricObject implements Colorable {
    private double side;
    
    public Square(){

    }

    public Square(double side){
        this.side = side;
    }

    public Square(double side, String color, boolean filled){
        super(color,filled);
        setSide(side);
    }

    public double getSide(){
        return side;
    }

    public void setSide(double side){
        this.side = side;
    }

    @Override
    public double getArea(){
        return Math.pow(side, 2);
    }

    @Override
    public double getPerimeter(){
        return side * 4;
    }
    // Uncomment if Colorable implement -> howToColor is void
    /* 
    @Override
    public void howToColor(){
        if(getFilled() == false)
            System.out.println("Not filled!");
        else
            System.out.println("Color: " + getColor());
            //return "Color all four side is " + getColor();
    }
    */

    // Uncomment if Colorable implement -> howToColor is String
    @Override
    public String howToColor(){
        if(getFilled() == false)
            return "Not filled!";
        else
            return "Color all four side is " + getColor();
    }

    @Override
    public String toString(){
        return super.toString() + "\nSide: " + side + "\nArea: " + getArea() + "\nPerimeter: " + getPerimeter();
    }
}
