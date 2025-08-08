package singleton;


public class Singleton {

    /*
    it is just a class which can create only one object
    so bascially to stop people from creating more objects
    you have to stop people form  using your constructer , thus
    we will make the constructor private
     */

    private Singleton(){
         /*
         Private means this would be allowed to use here only thus prve
         ting people from using the constructor

          */
    }

    private static Singleton instance; // jdo not know what is this and
                                    // what does this does

    /*(
    So we will create a fucniton that will give you only a instance

     */

    public  static Singleton getInstance(){
        // here we will also check if the instaced is alrady ror not create or not

        if(instance ==null){
            instance  = new Singleton();
        }else {
            return instance;
        }

        // why was the statik keyword neccsarrey here ? :
        /*
            when ever we are accesinsg some funciotn / varible by the claass name
            isnated of  the object name thus we need it to be static


         */
        return null;
    }
}
