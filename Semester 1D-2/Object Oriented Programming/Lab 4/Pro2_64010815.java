import java.util.GregorianCalendar;
public class Pro2_64010815 {
    public static void main(String[] args) {
        // Create calendar object
        GregorianCalendar calendar = new GregorianCalendar();

        long currentDay  = calendar.getTimeInMillis();  // Get current time in millis

        /* Display current year, month, date, and day of week */
        System.out.println("Current year, month, date, and day of week");
        System.out.println("Year is " + calendar.get(GregorianCalendar.YEAR));
        System.out.println("Month is " + calendar.get(GregorianCalendar.MONTH));
        System.out.println("Date is " + calendar.get(GregorianCalendar.DATE));
        System.out.println("Day of week is " + calendar.get(GregorianCalendar.DAY_OF_WEEK));

        System.out.println("------------"); //Braker
        
        calendar.setTimeInMillis(currentDay+(24*60*60*1000)); // Set day+1

        /* Display new data of year, month, date, and day of week */
        System.out.println("After specified the elapsed time of one day after current day");
        System.out.println("Year is " + calendar.get(GregorianCalendar.YEAR));
        System.out.println("Month is " + calendar.get(GregorianCalendar.MONTH));
        System.out.println("Date is " + calendar.get(GregorianCalendar.DATE));
        System.out.println("Day of week is " + calendar.get(GregorianCalendar.DAY_OF_WEEK));

        System.out.println(calendar.getTime()); // display date
    }
}
