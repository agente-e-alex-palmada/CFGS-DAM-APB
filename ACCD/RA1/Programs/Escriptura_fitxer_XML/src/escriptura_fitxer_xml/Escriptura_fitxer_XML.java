package escriptura_fitxer_xml;

// Imported libraries
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.OutputKeys;
import javax.xml.transform.Result;
import javax.xml.transform.Source;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerConfigurationException;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

// Main class
public class Escriptura_fitxer_XML {

    // Main function, calls the menu function and continues until option 3 is selected
    public static void main(String[] args) throws IOException, Exception {
        int option = 0;
        menu(); // Show menu
        while (option != 3) {
            Scanner keyboard = new Scanner(System.in);
            System.out.print("Select option: ");
            option = keyboard.nextInt();
            select(option); // Call function based on selected option
            menu(); // Show menu again
        }
    }

    // Displays the menu on the console
    public static void menu() {
        System.out.println("*****************************************");
        System.out.println("*******************MENÚ******************");
        System.out.println("1.- Insert player stats");
        System.out.println("2.- Show player stats");
        System.out.println("3.- Exit");
    }

    // Switches based on user selection to perform actions
    // If any other number or character is typed, it shows the menu again
    public static void select(int opcio) throws ParserConfigurationException {
        switch (opcio) {
            case 1:
                exercice1(); // Option 1: Insert player stats
                break;
            case 2:
                exercice2(); // Option 2: Show player stats
                break;
            default:
                System.out.println("Select a valid option"); // Invalid option
                break;
        }
    }

    // Reads the file path, checks if the file exists, creates it if not, and calls the function to insert new players
    public static void exercice1() throws ParserConfigurationException {
        try {
            String path = "./players.xml";
            File validate = new File("./players.xml");
            if (!validate.exists()) {
                try ( FileWriter file = new FileWriter("./players.xml")) {
                    file.write("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n\n<root>\n</root>");
                }
            }
            Document doc = openFileXML(path); // Parse the XML file
            System.out.println("XML Document parsed successfully.\n\n");
            newPlayerIns(doc); // Call function to insert player data
        } catch (Exception e) {
            System.err.println("Error parsing the XML file: " + e.getMessage()); // Error if file parsing fails
        }
    }

    // Opens the XML file and calls the function to display the document on the console
    private static void exercice2() {
        try {
            Document doc = openFileXML("./players.xml"); // Parse the XML file
            System.out.println("XML Document parsed successfully.\n\n");
            showXML(doc); // Call function to display XML contents
        } catch (Exception e) {
            System.err.println("File doesn't exist or isn't correctly parsed\t" + e.getMessage()); // Error if file doesn't exist or parsing fails
        }
    }

    // Opens and parses the XML file
    public static org.w3c.dom.Document openFileXML(String fileXML) throws Exception {
        File fxml = new File(fileXML);
        DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
        Document doc = (Document) dBuilder.parse(fxml); // Parse the XML file
        doc.getDocumentElement().normalize(); // Normalize the document
        return doc; // Return the parsed document
    }

    // Inserts new players into the XML file
    private static void newPlayerIns(Document doc) throws IOException, Exception {
        Scanner entry = new Scanner(System.in);
        Node elementRoot = doc.getDocumentElement(); // Get the root element
        System.out.print("How many players do you want to insert?: ");
        int numPlayers = entry.nextInt(); // Get number of players to insert
        entry.nextLine(); // Consume the newline character
        for (int i = 0; i < numPlayers; i++) {
            Element player = doc.createElement("player"); // Create new "player" element
            Element name = doc.createElement("name");
            Element level = doc.createElement("level");
            Element gems = doc.createElement("gems");
            Element gold = doc.createElement("gold");
            Element stars = doc.createElement("stars");
            Element trophies = doc.createElement("trophies");
            Element match = doc.createElement("match");
            Element date = doc.createElement("date");
            Element result = doc.createElement("result");
            Element duration = doc.createElement("duration");
            Element type = doc.createElement("type");
            
            System.out.print("Enter name: ");
            String nameIn = entry.nextLine(); // Get player name
            name.setTextContent(nameIn); // Set the name in the element
            level.setTextContent("1"); // Default level
            gold.setTextContent("0"); // Default gold
            trophies.setTextContent("0"); // Default trophies
            gems.setTextContent("0"); // Default gems
            stars.setTextContent("0"); // Default stars
            date.setTextContent("no data"); // Default match data
            result.setTextContent("no data");
            duration.setTextContent("no data");
            type.setTextContent("no data");
            
            player.appendChild(name);
            player.appendChild(level);
            player.appendChild(gems);
            player.appendChild(gold);
            player.appendChild(stars);
            player.appendChild(trophies);
            player.appendChild(match);
            match.appendChild(date);
            match.appendChild(result);
            match.appendChild(duration);
            match.appendChild(type);
            
            elementRoot.appendChild(player); // Add the player element to the root
            saveXML(doc, "./players.xml"); // Save the updated XML file
        }
        if (numPlayers > 1) {
            System.out.println("Profiles created, run the second function to see the stats");
        } else {
            System.out.println("Profile created, run the second function to see the stats");
        }
    }

    // Saves the XML document after changes
    public static void saveXML(Document doc, String path) throws TransformerConfigurationException, TransformerException {
        Transformer tFormer = TransformerFactory.newInstance().newTransformer();
        tFormer.setOutputProperty(OutputKeys.METHOD, "xml");
        Source source = new DOMSource(doc);
        Result result = new StreamResult(new File(path));
        tFormer.transform(source, result); // Write the changes back to the XML file
    }

    // Displays the XML document data on the console
    public static void showXML(Document doc) {
        // Once the document is parsed, get all "player" elements and print their stats
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
            // For each player, display the match data (date, result, duration, type)
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
