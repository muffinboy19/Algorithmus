package staticPackage;

public class InnerClass {
    static class Test{
        String name ;
        public Test(String name){
            this.name = name;
        }
    }
    public static void main(String [] args){
        Test a = new Test("Gaurv ");
        Test b = new Test("ishant");

        System.out.println(a.name);
        System.out.printf(b.name);

        // herre we will get 2 diff names despite being called as a static
        /*
        varible the resaon understood for htis is h
        1. since the static keyword does not say that it would have same value
        for all of its instance
        2 . it bascailly says that i will be independet from object varibles
        but since the Test  class is static thus does not depend on teh InnerClass
        3. but the main and Test can have instance of each other within them as they both ar inner to it
        thus main had 2 diff instance of the Test  thus 2 diff values

         */
    }
}


/*
outisde classes cannot be static
reason : becuse it istslf is not dependend on any other class

when you put a class inside another class
the inside class now depends on teh outside class


so fi the innser class is static which is not depending on object how can it call somthing
which is dpendeont on ojbect bcz the other ( inner class ) depends on the outside class

while a class which is inside if declatred inner does not need the
instance of the outside class to run




 */
