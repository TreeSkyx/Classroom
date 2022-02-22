public class Pro3_64010815 {
    public static void main(String[] args) {
        Person person = new Person("Jane", "1 ChalongKrung", "0812345611","email11@gmail.com");
        Student student = new Student("Noon", "2 ChalongKrung", "0812345622","email22@gmail.com", Student.JUNIOR);
        Employee employee = new Employee("Meow","3 ChalongKrung", "0812345633", "email33@gmail.com", 202, 10000);
        Faculty faculty = new Faculty("Bow", "4 ChalongKrung", "0812345644","email44@gmail.com",102,25000,"8am to 8pm","Engineer");
        Staff staff = new Staff("Kim", "5 ChalongKrung", "0812345655","email55@gmail.com",502,30000,"Senior Engineer");

        System.out.println(person.toString());
		System.out.println(student.toString());
		System.out.println(employee.toString());
		System.out.println(faculty.toString());
		System.out.println(staff.toString());
    }
    
}
