import java.io.File;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;
public class Animals {
public static Document obrirFitxerXML(String fitxerXML) throws Exception {
        File fxml = new File(fitxerXML);
        DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
        Document doc = (Document) dBuilder.parse(fxml);
        doc.getDocumentElement().normalize();
        return doc;
    }
    public static void main(String[] args) throws Exception {
    Document doc = obrirFitxerXML("./animals.xml");
        NodeList cds = doc.getElementsByTagName("animal");
        for (int i = 0; i < cds.getLength(); i++) {
            Element cde = (Element) cds.item(i);
            System.out.print(cde.getAttribute("tipo") + ": ");
            System.out.println(cde.getElementsByTagName("nombre").item(0).getTextContent());
        }
    }
}
