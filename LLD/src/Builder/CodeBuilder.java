package Builder;

import java.util.ArrayList;
import java.util.List;

class Code{
    private String name;
    private String type;

    public String getName() {
        return name;
    }

    public String getType() {
        return type;
    }

    public Code( String name, String type){
        this.name = name;
        this.type = type;
    }
}

class CodeBuilder {
    private String className;

    private List<Code> codes = new ArrayList<>();
    public CodeBuilder(String className){
        this.className = className;
    }

    public CodeBuilder addField(String name, String type){
        Code code = new Code(name,type);
        codes.add( code );
        return this;
    }

    public String toStringImpl() {
        String ans = "";
        for( Code code : codes ){
            String name = code.getName();
            String type = code.getType();
            String val = "  public " + type + " " + name + ";\n";
            ans += val;
        }
        return ans;
    }

    @Override
    public String toString() {
        return "public class "+ className +"\n" +
                "{"+"\n" +
                toStringImpl() +
                "}";
    }
}

class Demo{
    public static void main( String[] args ) {
        CodeBuilder cb = new CodeBuilder("Person")
                .addField("name", "String")
                .addField("age", "int");
        System.out.println(cb);
    }
}

/*

public class Person
{
  public String name;
  public int age;
}

 */