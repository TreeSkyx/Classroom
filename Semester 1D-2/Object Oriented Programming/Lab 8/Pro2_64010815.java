public class Pro2_64010815 {
    public static void main(String[] args) {
        GeomatricObject[] squares = {new Square(1,"red",true), new Square(3.2), new Square(5), new Square(7), new Square(14)};

        for(int i=0; i < squares.length; i++){
            System.out.println("\nSquare no." + (i+1));
            System.out.println("Area: " + squares[i].getArea());
            /* if howToColor function is String */
            System.out.println("How to color: " + ((Square)squares[i]).howToColor());
            /* if howToColor function is void */
            //((Square)squares[i]).howToColor();
            
        }
    }
}
