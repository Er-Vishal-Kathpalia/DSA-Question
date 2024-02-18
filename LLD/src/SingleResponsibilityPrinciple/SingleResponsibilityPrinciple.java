package SingleResponsibilityPrinciple;//SRP Single Responsibility Principle

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;


/*
Every class should has single responsibility and class name should itself defined the responsibility.
Each class should be responsible for a single part or functionality of the system.
Here Journal's responsibility is to just add the entry not creating a file that should be handled in persistance class
 */
class Journal {

    private final List<String> entries = new ArrayList<>();
    private static int count = 0;

    public void addEntry( String text ){
        System.out.println(" Entry added ");
        entries.add( "" + (++count) + ": " + text );
    }

    public void removeEntry( int index ){
        entries.remove( index );
    }

    @Override
    public String toString() {
        return String.join( System.lineSeparator(), entries );
    }

    // here we break SRP
    public void save(String filename) throws Exception
    {
        try ( PrintStream out = new PrintStream(filename))
        {
            out.println(toString());
        }
    }

    public void load(String filename) {}
    public void load( URL url) {}
}

class Persistance {

    public void saveInFile( Journal journal, String fileName, boolean overwrite ) throws FileNotFoundException {
        if( overwrite || new File( fileName ).exists() ){
            try ( PrintStream out = new PrintStream( fileName ) ) {
                out.println( journal );
            }
        }
    }

    public void load( Journal journal, String filename) {}
    public void load( Journal journal, URL url) {}

}


public class SingleResponsibilityPrinciple {
    public static void main( String[] args ) throws FileNotFoundException {
        Journal journal = new Journal();
        journal.addEntry( "Hello World" );
        journal.addEntry( "New Entry in Hello world class" );
        journal.addEntry( "Corrupt Entry" );
        journal.removeEntry( 2 );
        System.out.println(journal);
        Persistance persistance = new Persistance();
        persistance.saveInFile( journal, "helloworld.txt", true );

    }
}
