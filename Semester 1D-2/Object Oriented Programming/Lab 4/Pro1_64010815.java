public class Pro1_64010815 {
    public static void main(String[] args) {
        /* Create a Stock with specified symbol and name */
        Stock stock = new Stock("ORCL","Oracle Corporation");
        stock.previousClosingPrice = 34.5;
        stock.currentPrice = 34.35;
    
        /*Display the percent-change*/
        System.out.println("Symbol: " + stock.symbol);
        System.out.println("Name: " + stock.name);
        System.out.println("Previous Closing Price: " + stock.previousClosingPrice);
        System.out.println("Current Price: " + stock.currentPrice);
        System.out.println("Price Change: " + stock.getChangePercent()+"%");
    }
}
