package AbstractClass;

public class Main {
    /*
    Abstract class :
    when teh Method does not have a body n totally depends on the child
    for it . ( overriding)
    so you want to make sure that the child would override all the necessary
    abstract methods.

    easy to call  them : child class responsiblity.

    any class which contaisn one or more abstract methods must be
    declare as abstract.


    we cannot create objects of an abstract class
        because many method of the class does not havea body so if a object
        would call taht method it would give us error hence there is not ojbect
        for a abstract class

    static methods are those which cannot be overriden
    while absract methods are those which should be overrieden hence
    a static abstract method does not exist


    NO abstract constructor

     */

    public  static  void main(String[] args){
        Son gaurav = new Son(23);
        gaurav.carrer("engineer");
        Daughter trisha = new Daughter(23);
        trisha.carrer("houseWife");
        trisha.partner("kuldeep",21);
        gaurav.partner("priyam",19);


    }
}
