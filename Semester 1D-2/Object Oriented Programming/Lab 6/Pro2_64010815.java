public class Pro2_64010815 {
    public static void main(String[] args) {
        Course sleep101 = new Course("Sleep101");

        sleep101.addStudent("Jane");
        sleep101.addStudent("Noon");
        sleep101.addStudent("Bow");

        sleep101.dropStudent("Jane");

        System.out.println("Student in the course: " + sleep101.getCourseName());
        String[] students = sleep101.getStudents();
        for (int i=0; i< sleep101.getNumberOfStudents(); i++){
            System.out.print(students[i] + " ");
        }
    }
}
