package lectura_gestio_fitxers;

import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;

public class ReadClashXML {

    public static void main(String[] args) throws IOException, Exception {
        int opcio = 0;
        menu();
        while (opcio != 4) {
            Scanner keyboard = new Scanner(System.in);
            System.out.print("Select option: ");
            opcio = keyboard.nextInt();
            seleccio(opcio);
            menu();
        }
    }

    public static void menu() {
        System.out.println("*****************************************");
        System.out.println("*******************MENÚ******************");
        System.out.println("1.- Show player stats");
        System.out.println("2.- Show player with most trophies");
        System.out.println("3.- Show temperature");
        System.out.println("4.- Sortir");
    }

    public static void seleccio(int opcio) throws IOException, Exception {
        switch (opcio) {
            case 1:
                exercice1();
                break;
            case 2:
                exercici2();
                break;
            case 3:
                exercici3();
                break;
            default:
                System.out.println("Select a valid option");
                break;
        }
    }

    public static void exercice1() throws Exception {
        try {
            //It checks if the file is parsed, if it isn't will throw an exception telling that the parsing of the file wasn't succesful
            Document doc = openFileXML("./clash.xml");
            System.out.println("XML Document parsed successfully.\n\n");
            showXML(doc);
        } catch (Exception e) {
            System.err.println("Error parsing the XML file: " + e.getMessage());
        }
    }

    //This function is used to open the XML file
    public static Document openFileXML(String fileXML) throws Exception {
        //We assign to the variable "clashxml" the string fileXML
        File clashxml = new File(fileXML);
        //It checks if it exists, if it doesn't parses the XML file.
        if (!clashxml.exists()) {
            throw new IllegalArgumentException("The file does not exist: " + fileXML);
        } else {
            DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
            DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
            Document doc = dBuilder.parse(clashxml);
            doc.getDocumentElement().normalize();
            return doc;
        }
    }

    public static void showXML(Document doc) {
        //Once we already parsed the file, we will get the tag "player" and check every player we have inside it, also shows the stats for every player
        NodeList playerList = doc.getElementsByTagName("player");
        for (int i = 0; i < playerList.getLength(); i++) {
            Element player = (Element) playerList.item(i);
            System.out.println("Name: " + player.getElementsByTagName("name").item(0).getTextContent() + "\n");
            System.out.println("\tLevel: " + player.getElementsByTagName("level").item(0).getTextContent());
            System.out.println("\tGold: " + player.getElementsByTagName("gold").item(0).getTextContent());
            System.out.println("\tTrophies: " + player.getElementsByTagName("trophies").item(0).getTextContent());
            System.out.println("\tGems: " + player.getElementsByTagName("gems").item(0).getTextContent());
            System.out.println("\tStars: " + player.getElementsByTagName("stars").item(0).getTextContent() + "\n");
            NodeList matchList = player.getElementsByTagName("match");
            //Then inside players, it searchs the match and shows the tags: date, result, duration and type.
            for (int y = 0; y < matchList.getLength(); y++) {
                Element match = (Element) matchList.item(y);
                System.out.println("\t\tDate: " + match.getElementsByTagName("date").item(0).getTextContent());
                System.out.println("\t\tResult: " + match.getElementsByTagName("result").item(0).getTextContent());
                System.out.println("\t\tDuration: " + match.getElementsByTagName("duration").item(0).getTextContent());
                System.out.println("\t\tType: " + match.getElementsByTagName("type").item(0).getTextContent() + "\n");
            }
        }
    }

    private static void exercici2() {
        try {
            //It checks if the file is parsed, if it isn't will throw an exception telling that the parsing of the file wasn't succesful
            Document doc = openFileXML("./clash.xml");
            System.out.println("XML Document parsed successfully.\n\n");
            showXMLTrophies(doc);
        } catch (Exception e) {
            System.err.println("Error parsing the XML file: " + e.getMessage());
        }
    }

    public static void showXMLTrophies(Document doc) {
        //Once we already parsed the file, we will get the tag "player" and check every player we have inside it
        NodeList playerList = doc.getElementsByTagName("player");
        //Initialize the variables
        int bestTrophies = 0;
        int trophies;
        String trophiesText;
        Element player;
        //Checks the value of throphies and formats it at an integer, then it checks if it's 
        for (int i = 0; i < playerList.getLength(); i++) {
            player = (Element) playerList.item(i);
            trophiesText = player.getElementsByTagName("trophies").item(0).getTextContent();
            trophies = Integer.parseInt(trophiesText);
            if (trophies > bestTrophies) {
                bestTrophies = trophies;
            }
        }
        for (int i = 0; i < playerList.getLength(); i++) {
            player = (Element) playerList.item(i);
            trophiesText = player.getElementsByTagName("trophies").item(0).getTextContent();
            trophies = Integer.parseInt(trophiesText);
            if (bestTrophies == trophies) {
                System.out.println("Name: " + player.getElementsByTagName("name").item(0).getTextContent() + "\n");
                System.out.println("\tLevel: " + player.getElementsByTagName("level").item(0).getTextContent());
                System.out.println("\tGold: " + player.getElementsByTagName("gold").item(0).getTextContent());
                System.out.println("\tTrophies: " + player.getElementsByTagName("trophies").item(0).getTextContent());
                System.out.println("\tGems: " + player.getElementsByTagName("gems").item(0).getTextContent());
                System.out.println("\tStars: " + player.getElementsByTagName("stars").item(0).getTextContent() + "\n");
                NodeList matchList = player.getElementsByTagName("match");
                //Then inside players, it searchs the match and shows the tags: date, result, duration and type.
                for (int y = 0; y < matchList.getLength(); y++) {
                    Element match = (Element) matchList.item(y);
                    System.out.println("\t\tDate: " + match.getElementsByTagName("date").item(0).getTextContent());
                    System.out.println("\t\tResult: " + match.getElementsByTagName("result").item(0).getTextContent());
                    System.out.println("\t\tDuration: " + match.getElementsByTagName("duration").item(0).getTextContent());
                    System.out.println("\t\tType: " + match.getElementsByTagName("type").item(0).getTextContent() + "\n");
                }
            }
        }
    }

    public static void exercici3() {
        String pathFile1 = "./meteo2015.xml", pathFile2 = "./meteo2016.xml", pathFile3 = "./meteo2017.xml";
        try {
            //It checks if the file is parsed, if it isn't will throw an exception telling that the parsing of the file wasn't succesful
            Document doc1 = openFilesXML(pathFile1);
            Document doc2 = openFilesXML(pathFile2);
            Document doc3 = openFilesXML(pathFile3);
            System.out.println("XML Documents parsed successfully.\n\n");
            showXMLs(doc1, doc2, doc3, pathFile1, pathFile2, pathFile3);
        } catch (Exception e) {
            System.err.println("Error parsing the XML file: " + e.getMessage());
        }
    }

    public static Document openFilesXML(String filesXML) throws Exception {
        File files = new File(filesXML);
        if (!files.exists()) {
            throw new IllegalArgumentException("The file does not exist: " + filesXML);
        } else {
            DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
            DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
            Document doc = dBuilder.parse(files);
            doc.getDocumentElement().normalize();
            return doc;
        }
    }

    public static void showXMLs(Document doc1, Document doc2, Document doc3, String pathFile1, String pathFile2, String pathFile3) {
        NodeList meteoList1 = doc1.getElementsByTagName("element");
        NodeList meteoList2 = doc2.getElementsByTagName("element");
        NodeList meteoList3 = doc3.getElementsByTagName("element");
        Element element;
        for (int i = 0; i < meteoList1.getLength(); i++) {
            element = (Element) meteoList1.item(i);
            System.out.println(pathFile1);
            System.out.println("Tmax"+"["+element.getElementsByTagName("fecha").item(0).getTextContent()+" "+element.getElementsByTagName("horatmax").item(0).getTextContent()+"]="+element.getElementsByTagName("tmax").item(0).getTextContent()+"C");
            System.out.println("Tmin"+"["+element.getElementsByTagName("fecha").item(0).getTextContent()+" "+ element.getElementsByTagName("horatmax").item(0).getTextContent()+"]="+element.getElementsByTagName("tmin").item(0).getTextContent()+"C"+"\n");
        }
        for (int i = 0; i < meteoList2.getLength(); i++) {
            element = (Element) meteoList1.item(i);
            System.out.println(pathFile2);
            System.out.println("Tmax"+"["+element.getElementsByTagName("fecha").item(0).getTextContent()+" "+ element.getElementsByTagName("horatmax").item(0).getTextContent()+"]="+element.getElementsByTagName("tmax").item(0).getTextContent()+"C");
            System.out.println("Tmin"+"["+element.getElementsByTagName("fecha").item(0).getTextContent()+" "+ element.getElementsByTagName("horatmax").item(0).getTextContent()+"]="+element.getElementsByTagName("tmin").item(0).getTextContent()+"C"+"\n");
        }
        for (int i = 0; i < meteoList3.getLength(); i++) {
            element = (Element) meteoList1.item(i);
            System.out.println(pathFile3);
            System.out.println("Tmax"+"["+element.getElementsByTagName("fecha").item(0).getTextContent()+" "+ element.getElementsByTagName("horatmax").item(0).getTextContent()+"]="+element.getElementsByTagName("tmax").item(0).getTextContent()+"C");
            System.out.println("Tmin"+"["+element.getElementsByTagName("fecha").item(0).getTextContent()+" "+ element.getElementsByTagName("horatmax").item(0).getTextContent()+"]="+element.getElementsByTagName("tmin").item(0).getTextContent()+"C"+"\n");
        }
    }
}
