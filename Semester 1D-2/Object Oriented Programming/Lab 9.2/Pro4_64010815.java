import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.input.KeyCode;

public class Pro4_64010815 extends Application {
    @Override
    public void start(Stage primaryStage){
        CarPane pane = new CarPane();

        pane.setOnMousePressed(e -> pane.pause());
        pane.setOnMouseReleased(e ->pane.play());

        pane.setOnKeyPressed(e -> {
            if (e.getCode() == KeyCode.UP){
                pane.increaseSpeed();
            }
            else if (e.getCode() == KeyCode.DOWN){
                pane.decreaseSpeed();
            }
        });

        Scene scene = new Scene(pane, 650, 250);
        primaryStage.setTitle("Exercise15_29");
        primaryStage.setScene(scene);
        primaryStage.show();
        pane.requestFocus();
    }
    public static void main(String[] args) {
        launch(args);
    }
}
