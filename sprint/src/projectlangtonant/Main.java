package projectlangtonant;

import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.util.ArrayList;
import java.util.List;


public class Main extends Application {

    Board.Direction tmpDirection = Board.Direction.North;
    String tmpHandling = "RL";
    Scene scene;
    AntLoop antLoop;


    @Override
    public void start(Stage window) throws Exception{
        window.setTitle("Langton Ant");

        /**
         * Creating box containing handling stuff
         */
        TextField inputHandling = new TextField();
        Button buttonHandling = new Button("Set handling");
        buttonHandling.setOnAction( e -> antLoop.changeHandling(inputHandling.getText()));
        Label handlingText = new Label("Handling:");
        VBox handlingBox = new VBox(10);
        handlingBox.setPadding(new Insets(20,20,20,10));
        handlingBox.getChildren().addAll(handlingText,inputHandling, buttonHandling);

        /**
         * Creating box containing direction stuff
         */
        GridPane gridPane = new GridPane();
        gridPane.setPadding(new Insets(20,20,20,20));
        gridPane.setVgap(20);
        gridPane.setHgap(20);
        Button buttonDirectionN = new Button("N");
        buttonDirectionN.setOnAction( e -> tmpDirection = Board.Direction.North);
        gridPane.setConstraints(buttonDirectionN, 1,0);
        Button buttonDirectionW = new Button("W");
        buttonDirectionW.setOnAction( e -> tmpDirection = Board.Direction.West);
        gridPane.setConstraints(buttonDirectionW, 0,1);
        Button buttonDirectionS = new Button("S");
        buttonDirectionS.setOnAction( e -> tmpDirection = Board.Direction.South);
        gridPane.setConstraints(buttonDirectionS, 1,2);
        Button buttonDirectionE = new Button("E");
        buttonDirectionE.setOnAction( e -> tmpDirection = Board.Direction.East);
        gridPane.setConstraints(buttonDirectionE, 2,1);
        gridPane.getChildren().addAll(buttonDirectionN,buttonDirectionW,buttonDirectionS,buttonDirectionE);
        Label directionText = new Label("Direction:");
        VBox directionOptions = new VBox();
        directionOptions.getChildren().addAll(directionText, gridPane);
        /////////////////
        Button startButton = new Button("START");
        startButton.setStyle("-fx-background-color: MediumSeaGreen");
        startButton.setPrefSize(150,50);
        Button pauseButton = new Button("PAUSE");
        pauseButton.setStyle("-fx-background-color: Yellow");
        pauseButton.setPrefSize(150,50);
        Button stopButton = new Button("CLEAR");
        stopButton.setStyle("-fx-background-color: Red");
        stopButton.setPrefSize(150,50);
        VBox controllButtons = new VBox( 20);
        controllButtons.getChildren().addAll(startButton, pauseButton, stopButton);
        /////////////////
        VBox frequencyBox = new VBox(20);
        TextField inputFrequency = new TextField();
        Button buttonFrequency = new Button("Set frequency");
        buttonFrequency.setOnAction( e -> antLoop.setFrequency(inputFrequency.getText()));
        Label frequencyText = new Label("Frequency:");
        frequencyBox.getChildren().addAll(frequencyText,inputFrequency,buttonFrequency);

        Label antNumber = new Label("Ants: 0");
        /////////////////
        VBox layoutOptions = new VBox(20);
        layoutOptions.getChildren().addAll(handlingBox, directionOptions, controllButtons,frequencyBox,antNumber);
        /////////////////
        Canvas canvas = new Canvas(600, 600);
        GraphicsContext gc = canvas.getGraphicsContext2D();
        canvas.setOnMouseClicked(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                int x = (int)event.getX()/4;
                int y = (int)event.getY()/4;
                antLoop.addAnt(x,y,tmpDirection);
            }
        });
        /////////////////
        HBox layout = new HBox(20);
        layout.getChildren().addAll(canvas,layoutOptions);
        /////////////////
        VBox everything = new VBox(20);
        HBox texts = new HBox(10);
        Label stepsText = new Label("Step no:");
        Label stepsNumber = new Label("0");
        texts.getChildren().addAll(stepsText, stepsNumber);
        everything.getChildren().addAll(layout, texts);
        /////////////////
        Scene scene = new Scene(everything, 800, 700);
        window.setResizable(false);
        window.setScene(scene);
        window.show();
        /////////////////

        antLoop = new AntLoop();
        antLoop.mainLoop(gc, startButton, pauseButton, stopButton, stepsNumber, antNumber);
        antLoop.changeHandling(tmpHandling);
    }

      public static void main(String[] args) {
        launch(args);
    }
}
