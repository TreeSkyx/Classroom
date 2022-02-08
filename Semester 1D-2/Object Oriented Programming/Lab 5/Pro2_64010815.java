public class Pro2_64010815 {
    public static void main(String[] args) {
        // Create regularPolugon with this conditon ->
        // no-arg constructor
        RegularPolygon regularPolygon1 = new RegularPolygon();
        // n = 6 , side = 4 with center at 0,0
        RegularPolygon regularPolygon2 = new RegularPolygon(6,4);
        // n = 10 , side = 4 with center at 5.6, 7.8
        RegularPolygon regularPolygon3 = new RegularPolygon(10, 4, 5.6, 7.8);

        /* Display */
        // Regular Polygon1
        System.out.println("Regular Polygon1");
        System.out.println("---------------------------");
        System.out.println("Perimeter: "+regularPolygon1.getPerimeter());
        System.out.println("Area: "+regularPolygon1.getArea());

        System.out.println(" ");
        System.out.println("***************************"); // Breaker

        // Regular Polygon2
        System.out.println("Regular Polygon2");
        System.out.println("---------------------------");
        System.out.println("Perimeter: "+regularPolygon2.getPerimeter());
        System.out.println("Area: "+regularPolygon2.getArea());

        System.out.println(" ");
        System.out.println("***************************"); // Breaker

        // Regular Polygon3
        System.out.println("Regular Polygon3");
        System.out.println("---------------------------");
        System.out.println("Perimeter: "+regularPolygon3.getPerimeter());
        System.out.println("Area: "+regularPolygon3.getArea());
    }
}
