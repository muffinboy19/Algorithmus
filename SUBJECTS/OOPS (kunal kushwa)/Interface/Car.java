package Interface;

public class Car implements  Engine,Break{
    @Override
    public void brake() {
        System.out.println("I brake liek a normal car");
    }

    @Override
    public void start() {
        System.out.println("Car.start");
    }

    @Override
    public void stop() {
        System.out.println("Car.stop");

    }

    @Override
    public void accelarate() {
        System.out.println("Car.accelarate");
    }
}
