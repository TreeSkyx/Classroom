import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.layout.BorderPane;
import javafx.scene.control.Label;
import javafx.geometry.Pos;

public class Pro3_64010815 extends Application {
    @Override
    public void start(Stage primaryStage){

        String timeString = clock.getHour() + ":" + clock.getMinute() + ":" + clock.getSecond();
        clock.setSecondHandVisible(false);
        Label time = new Label(timeString);

        BorderPane pane = new BorderPane();
        pane.setCenter(clock);
        pane.setBottom(time);
        BorderPane.setAlignment(time, Pos.TOP_CENTER);

        Scene scene = new Scene(pane, 250, 250);
        primaryStage.setTitle("Exercise14_28");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
    public static void main(String[] args) {
        launch(args);
    }
}
