package Builder;

class Employee {
    // address
    public String streetAddress, postcode, city;
    // employment
    public String companyName, position;
    public int annualIncome;

    @Override
    public String toString() {
        return "Employee{" +
                "streetAddress='" + streetAddress + '\'' +
                ", postcode='" + postcode + '\'' +
                ", city='" + city + '\'' +
                ", companyName='" + companyName + '\'' +
                ", position='" + position + '\'' +
                ", annualIncome=" + annualIncome +
                '}';
    }
}

// builder facade
class EmployerBuilder {
    // the object we're going to build
    protected Employee employee = new Employee(); // reference!

    public EmployerJobBuilder works() {
        return new EmployerJobBuilder(employee);
    }

    public EmployerAddressBuilder lives() {
        return new EmployerAddressBuilder(employee);
    }

    public Employee build() {
        return employee;
    }
}

class EmployerAddressBuilder extends EmployerBuilder {

    public EmployerAddressBuilder( Employee employee) {
        this.employee = employee;
    }

    public EmployerAddressBuilder at( String streetAddress) {
        employee.streetAddress = streetAddress;
        return this;
    }

    public EmployerAddressBuilder withPostcode( String postcode) {
        employee.postcode = postcode;
        return this;
    }

    public EmployerAddressBuilder in( String city) {
        employee.city = city;
        return this;
    }
}

class EmployerJobBuilder extends EmployerBuilder {
    public EmployerJobBuilder( Employee employee) {
        this.employee = employee;
    }

    public EmployerJobBuilder at( String companyName) {
        employee.companyName = companyName;
        return this;
    }

    public EmployerJobBuilder asA( String position) {
        employee.position = position;
        return this;
    }

    public EmployerJobBuilder earning( int annualIncome) {
        employee.annualIncome = annualIncome;
        return this;
    }
}


public class FacetedBuilder {
    public static void main(String[] args) {
        EmployerBuilder eb = new EmployerBuilder();
        Employee employee = eb
                .lives()
                .at("123 London Road")
                .in("London")
                .withPostcode("SW12BC")
                .works()
                .at("Fabrikam")
                .asA("Engineer")
                .earning(123000)
                .build();
        System.out.println(employee);
    }
}
