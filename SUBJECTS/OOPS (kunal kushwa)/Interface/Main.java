package Interface;

public class Main {

    /*
    variable in interface : are static n final
    every method will be abstract
    you cannot create objectes
    final vairbles alwasy needs to be intilizasied

     so basicaly mulipler inheritnace is aonly posible by making hte
     class by defualt abstart hence it has to impmlnet all the confliet / all the methods
     again as they would be givne only as a body hence resolving hteo nept of which funtion woul be used



     */

    public  static  void main(String [] args){
        Car honda  = new Car();
        // thins to acess ---- there version to acess depnds on this
        honda.start();
        honda.accelarate();
        honda.stop();

    }
}
