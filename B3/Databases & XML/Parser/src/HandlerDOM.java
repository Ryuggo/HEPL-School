import org.xml.sax.SAXException;
import org.xml.sax.SAXParseException;
import org.xml.sax.helpers.DefaultHandler;



public class HandlerDOM extends DefaultHandler {
    public void warning(SAXParseException e) throws SAXException {
        System.out.println("WARNING : "+ e.getMessage ());
    }
    public void error(SAXParseException e) throws SAXException {
        System.out.println("ERROR : "+ e.getMessage ()); throw e;
    }
    public void fatalError(SAXParseException e) throws SAXException {
        System.out.println("FATAL : "+ e.getMessage ()); throw e;
    }
}

