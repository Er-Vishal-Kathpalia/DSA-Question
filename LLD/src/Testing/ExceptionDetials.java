package Testing;


public class ExceptionDetials {

    private ExceptionReportDetails exceptionReportDetails;

    public ExceptionReportDetails getExceptionReportDetails() {
        return exceptionReportDetails;
    }

    public void setExceptionReportDetails( ExceptionReportDetails exceptionReportDetails ) {
        this.exceptionReportDetails = exceptionReportDetails;
    }

    public static class ExceptionReportDetails{
        private String status;

        public String getStatus() {
            return status;
        }

        public void setStatus( String status ) {
            this.status = status;
        }
    }

}
