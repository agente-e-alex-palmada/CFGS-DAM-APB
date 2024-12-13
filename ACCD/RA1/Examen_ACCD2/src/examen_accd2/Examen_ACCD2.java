/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package examen_accd2;

// Imported libraries
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
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

/**
 *
 * @author AluCiclesGS1
 */
public class Examen_ACCD2 {

// Funció principal que crida al menu
    public static void main(String[] args) throws IOException, Exception {
        int option = 0;
        menu(); // Mostra el menu
        //Mentres la opció no sigui igual al número 5, no tanca el programa
        while (option != 5) {
            //Llegeix l'input del jugador
            Scanner keyboard = new Scanner(System.in);
            System.out.print("Select option: ");
            option = keyboard.nextInt();
            select(option); // Call function based on selected option
            menu(); // Show menu again
        }
    }

    // Imprimeix en la consola un menú de les opcions disponibles
    public static void menu() {
        System.out.println("\n\n*****************************************");
        System.out.println("*******************MENÚ******************");
        System.out.println("1.- Mostrar jugador amb les estadistiques més baixes");
        System.out.println("2.- Inserir un jugaodr al XML");
        System.out.println("3.- Creació d'un usuari");
        System.out.println("4.- Mostrar correus electronics i els seus usuaris");
        System.out.println("5.- Exit");
    }

    // Depenent de la opció del usuari, cridará una funció o un altre
    public static void select(int opcio) throws ParserConfigurationException, IOException {
        switch (opcio) {
            case 1:
                exercice1();
                break;
            case 2:
                exercice2();
                break;
            case 3:
                exercice3();
                break;
            case 4:
                exercici4();
                break;
            default:
                System.out.println("Select a valid option");
                break;
        }
    }

    private static void exercice1() {
        try {
            Document doc = openFileXML("./Jugadors.xml"); // obre el fitxer XML a la funció
            System.out.println("XML Document parsed successfully.\n\n");
            showXML(doc); // Mostra el contingut del XML
        } catch (Exception e) {
            System.err.println("File doesn't exist or isn't correctly parsed\t" + e.getMessage()); // Si n'hi ha error, ho mostra en pantalla
        }
    }

    // Parsea el document XML
    public static org.w3c.dom.Document openFileXML(String fileXML) throws Exception {
        File fxml = new File(fileXML);
        DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
        Document doc = (Document) dBuilder.parse(fxml); // Parse the XML file
        doc.getDocumentElement().normalize(); // Normalize the document
        return doc; // Return the parsed document
    }

    // Mostra en pantalla el document XML
    public static void showXML(Document doc) {
        // Una vegada el document és correcte, filtra si el nivell és el més petit, el guarda en una variable i només mostra l'usuari que compleix la condició
        NodeList playerList = doc.getElementsByTagName("jugador");
        NodeList inventaris = doc.getElementsByTagName("inventari");
        NodeList objectes = doc.getElementsByTagName("objecte");
        Element jugador;
        int lessLvl = 100, lvl;
        String lessLvlTxt;
        for (int i = 0; i < playerList.getLength(); i++) {
            jugador = (Element) playerList.item(i);
            lessLvlTxt = jugador.getElementsByTagName("nivell").item(0).getTextContent();
            lvl = Integer.parseInt(lessLvlTxt);
            if (lvl < lessLvl) {
                lessLvl = lvl;
            }
        }
        for (int i = 0; i < playerList.getLength(); i++) {
            Element player = (Element) playerList.item(i);
            lessLvlTxt = player.getElementsByTagName("nivell").item(0).getTextContent();
            lvl = Integer.parseInt(lessLvlTxt);
            if (lessLvl == lvl) {
                System.out.println("Nom: " + player.getElementsByTagName("nom").item(0).getTextContent() + "\n");
                System.out.println("\tOr: " + player.getElementsByTagName("or").item(0).getTextContent());
                System.out.println("\tNivell: " + player.getElementsByTagName("nivell").item(0).getTextContent());
                System.out.println("\tVida: " + player.getElementsByTagName("vida").item(0).getTextContent());
                System.out.println("\tDany: " + player.getElementsByTagName("atac").item(0).getTextContent());
                System.out.println("\tDefensa: " + player.getElementsByTagName("defensa").item(0).getTextContent());
                System.out.println("\tMagia: " + player.getElementsByTagName("magia").item(0).getTextContent() + "\n");
                for (int k = 0; k < inventaris.getLength(); k++) {
                    Element objecte = (Element) objectes.item(k);
                    System.out.println("\t\tNom: " + objecte.getElementsByTagName("nomObj").item(0).getTextContent());
                    System.out.println("\t\tTipus: " + objecte.getElementsByTagName("tipusObj").item(0).getTextContent());
                    System.out.println("\t\tNivell del objecte: " + objecte.getElementsByTagName("nivellObj").item(0).getTextContent());
                }
            }
        }
    }

    private static void exercice2() {
        try {
            Document doc = openFileXML("./Jugadors.xml"); // Parse the XML file
            System.out.println("XML Document parsed successfully.\n\n");
            newPlayerIns(doc); // Call function to insert new players
        } catch (Exception e) {
            System.err.println("File doesn't exist or isn't correctly parsed\t" + e.getMessage()); // Error if file doesn't exist or parsing fails
        }
    }

    // Inserta nous jugadors al fitxer XML, fa per defecte les estádistiques de vida i demes, pero fent una variable string entry next line podem inserir també la resta d'stats
    private static void newPlayerIns(Document doc) throws IOException, Exception {
        Scanner entry = new Scanner(System.in);
        Node elementRoot = doc.getDocumentElement(); // Get the root element
        System.out.print("Cuants jugadors vols insertar?: ");
        int numPlayers = entry.nextInt(); // Get number of players to insert
        entry.nextLine(); // Consume the newline character
        for (int i = 0; i < numPlayers; i++) {
            Element player = doc.createElement("jugador"); // Create new "player" element
            Element name = doc.createElement("nom");
            Element gold = doc.createElement("or");
            Element lvl = doc.createElement("nivell");
            Element hp = doc.createElement("vida");
            Element dmg = doc.createElement("atac");
            Element dfs = doc.createElement("defensa");
            Element mgk = doc.createElement("magia");
            Element inv = doc.createElement("inventari");
            Element obj = doc.createElement("objecte");
            Element nobj = doc.createElement("nomObj");
            Element type = doc.createElement("tipusObj");
            Element lobj = doc.createElement("nivellObj");
            System.out.print("Digues el nom: ");
            String nameIn = entry.nextLine(); // Get player name
            name.setTextContent(nameIn); // Set the name in the element
            gold.setTextContent("0");
            lvl.setTextContent("1");
            hp.setTextContent("100");
            dmg.setTextContent("100");
            dfs.setTextContent("100");
            mgk.setTextContent("100");
            nobj.setTextContent("Pale Briar"); //Default weapon
            type.setTextContent("Destra"); // Default level
            lobj.setTextContent("1"); // Default gold
            player.appendChild(name);
            player.appendChild(gold);
            player.appendChild(lvl);
            player.appendChild(gold);
            player.appendChild(hp);
            player.appendChild(dmg);
            player.appendChild(dfs);
            player.appendChild(mgk);
            player.appendChild(inv);
            inv.appendChild(obj);
            obj.appendChild(nobj);
            obj.appendChild(type);
            obj.appendChild(lobj);
            elementRoot.appendChild(player); // Add the player element to the root
            saveXML(doc, "./Jugadors.xml"); // Save the updated XML file
        }
        // Si s'insereixen més d'un jugador, el missatge será diferent
        if (numPlayers > 1) {
            System.out.println("Profiles created, run the second function to see the stats");
        } else {
            System.out.println("Profile created, run the second function to see the stats");
        }
    }

    // Guarda el fitxer XML
    public static void saveXML(Document doc, String path) throws TransformerConfigurationException, TransformerException {
        Transformer tFormer = TransformerFactory.newInstance().newTransformer();
        tFormer.setOutputProperty(OutputKeys.METHOD, "xml");
        Source source = new DOMSource(doc);
        Result result = new StreamResult(new File(path));
        tFormer.transform(source, result); // Write the changes back to the XML file
    }

    private static void exercice3() throws IOException {
        try (
                 FileWriter uc = new FileWriter("./usuaris.txt", true)) {
            String correu, usuari = "a", contra;
            //Scanner és una variable que escriu en una variable el text qaue introduim
            Scanner enter = new Scanner(System.in);
            //Mentres que usuari no sigui igual a res, continua
            while (!"".equals(usuari)) {
                System.out.println("Introdueix nom d'usuari: ");
                //Cridem la funció enter linea, i o remplaça a usuari
                usuari = enter.nextLine();
                //Si usuari no és igual a res, continua
                if (!"".equals(usuari)) {
                    System.out.println("Introdueix contrasenya usuari: ");
                    contra = enter.nextLine();
                    System.out.println("Introdueix correu electronic: ");
                    correu = enter.nextLine();
                    //Escriu en la linea usuari:contrasenya\salt de linea
                    uc.write(usuari + ":" + contra + ":" + correu + "\n");
                }
            }
            //Tanca el fitxer
        }
    }

    private static void exercici4() throws FileNotFoundException, IOException {
        // En una variable File, obre el fitxer
        File f1 = new File("./usuaris.txt");
        if (f1.exists()) {
            // Llegeix el fitxer
            FileReader lectura1 = new FileReader("./usuaris.txt");
            BufferedReader buf1 = new BufferedReader(lectura1);
            System.out.println("\n\nContingut de l'arxiu \"usuaris\"");
            String linia = buf1.readLine();
            // Mentres hi hagi contingut en l'String, mostrará en pantalla el valor de la variable.
            while (linia != null) {
                System.out.println(linia);
                linia = buf1.readLine();
            }
        }
    }
}
