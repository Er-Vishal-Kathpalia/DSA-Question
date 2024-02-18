package Testing;

import java.util.List;

public abstract class KafkaCommonListener {

    public void test( String val ){
        System.out.println( "Inside test " + val );
        test2( val );

    }
    protected abstract void test2( String val );

}
