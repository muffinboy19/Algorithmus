package AbstractClass;

abstract public class Parent {
    int age;

    public Parent(int age) {
        this.age = age;
    }

    abstract  void carrer(String name);
    abstract  void partner(String name ,int age);

}
