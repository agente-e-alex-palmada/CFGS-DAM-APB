package accd_ra5_apb;

import generated.CartaType;
import generated.ClanType;
import generated.ClashType;
import generated.JugadorType;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import javax.xml.bind.JAXBContext;
import javax.xml.bind.JAXBException;
import javax.xml.bind.MarshalException;
import javax.xml.bind.Marshaller;
import javax.xml.bind.Unmarshaller;

public class main {

    public static void getCardIDs() {
        // TODO here
    }

    public static int getLastPlayerId() {

        // Todo
        return 0;
    }

    public static void createPlayers() throws JAXBException {
        String name;
        System.out.println("\nDigues el nom del nou jugador: ");
        Scanner userInput = new Scanner(System.in);
        name = userInput.nextLine();

        // Generate player
        JugadorType player = new JugadorType();
        player.setNom(name);

        // Generate card
        CartaType card = new CartaType();
        card.setNomcart("Gigante");
        card.setNivellcart(1);
        card.setRaresa("rara");

        // Bind the card to the player
        player.getCarta().add(card);

        JAXBContext context = JAXBContext.newInstance(ClashType.class);
        Unmarshaller unmarshaller = context.createUnmarshaller();
        ClashType clash = (ClashType) unmarshaller.unmarshal(new File("src/accd_ra5_apb/clash_1.xml"));

        clash.getJugador().add(player);

        // TODO ALEX, BE CAREFUL
        try {
            File file = new File("./clashMarshaller.xml");
            JAXBContext jaxbContext = JAXBContext.newInstance(ClashType.class);
            Marshaller jaxbMarshaller = jaxbContext.createMarshaller();
            jaxbMarshaller.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, true);
            jaxbMarshaller.setProperty(Marshaller.JAXB_ENCODING, "UTF-8");
            jaxbMarshaller.marshal(clash, file);
            jaxbMarshaller.marshal(clash, System.out);
        } catch (JAXBException e) {
            e.printStackTrace();
        }
    }

    public static void showPlayers() throws JAXBException {
        JAXBContext context = JAXBContext.newInstance(ClashType.class);
        Unmarshaller unmarshaller = context.createUnmarshaller();
        ClashType clash = (ClashType) unmarshaller.unmarshal(new File("src/accd_ra5_apb/clash_1.xml"));

        System.out.println("\nVersio: " + clash.getVersio());

        ArrayList<JugadorType> jugadors = (ArrayList<JugadorType>) clash.getJugador();

        for (JugadorType j : jugadors) {
            System.out.println("Jugador: " + j.getId());

            System.out.println("\tNom: " + j.getNom());
            System.out.println("\tCopes: " + j.getCopes());
            System.out.println("\tNivell: " + j.getNivell() + "\n");
            System.out.println("Cartes del jugador:");
            ArrayList<CartaType> cartes = (ArrayList<CartaType>) j.getCarta();
            for (CartaType c : cartes) {
                System.out.println("\tNom: " + c.getNomcart());
                System.out.println("\tNivell: " + c.getNivellcart());
                System.out.println("\tRaresa: " + c.getRaresa() + "\n");
            }
            ClanType clan = j.getClan();
            System.out.println("Clan:");
            System.out.println("\tNom: " + clan.getNomClan());
            System.out.println("\tCopes: " + clan.getCopesClan());
            System.out.println("\tTipus: " + clan.getTipusClan() + "\n");
        }
    }

    public static void main(String[] args) throws IOException, JAXBException {
        int select = -1;

        while (select != 0) {
            menu();
            Scanner userInput = new Scanner(System.in);
            System.out.print("Selecciona una opció: ");
            select = userInput.nextInt();
            selection(select);
        }
    }

    public static void menu() {
        System.out.println("-------- Menu --------");
        System.out.println("0. Sortir");
        System.out.println("1. Mostrar dades dels jugadors, cartes i clans.");
        System.out.println("2. Crear nou jugador.");
    }

    //Cada cas crida una funcio segons l'exercici
    public static void selection(int select) throws JAXBException {
        switch (select) {
            case 1:
                showPlayers();
                break;
            case 2:
                createPlayers();
                break;
            default:
                break;
        }
    }
}
