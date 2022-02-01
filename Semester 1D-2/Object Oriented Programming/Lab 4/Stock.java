public class Stock {
    // The stock's name & symbol
    String symbol;  
    String name;
    // The stock's price for previous day and today
    double previousClosingPrice;
    double currentPrice;

    /* Construct a stock with the specified symbol and name */
    Stock(String newSymbol, String newName){
        symbol = newSymbol;
        name = newName;
    }

    /* Get the change of percentage */
    double getChangePercent(){
        return ((currentPrice - previousClosingPrice)/ previousClosingPrice) * 100;
    }
}
