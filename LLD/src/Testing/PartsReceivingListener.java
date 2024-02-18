package Testing;

public class PartsReceivingListener extends KafkaCommonListener{

    @Override
    protected void test2( String val ) {
        System.out.println( "Inside test2 " + val );
    }
}
