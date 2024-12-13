package apb_ra1_p1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Random;
import java.util.Scanner;

public class APB_RA1_P1 {

    public static void main(String[] args) throws IOException {
        int opcio = 0;
        //Cridem la funció menu, i quan la variable opcio sigui 7, el bucle termina, i el programa també.
        menu();
        while (opcio != 7) {
            Scanner teclado = new Scanner(System.in);
            System.out.print("Escull opció: ");
            opcio = teclado.nextInt();
            seleccio(opcio);
        }
    }
    //Aquí expresa totes les opcions del menú
    public static void menu() {
        System.out.println("********************************************");
        System.out.println("**********************MENÚ******************");
        System.out.println("1.- Comprovar existència de fitxers");
        System.out.println("2.- Llistar arxius");
        System.out.println("3.- Crear i escriure en arxiu TXT");
        System.out.println("4.- Mostrar contingut d'arxius");
        System.out.println("5.- Crear directori i arxiu amb nom aleatori");
        System.out.println("6.- Comentari i execució de codi");
        System.out.println("7.- Sortir");
    }
    //Cada cas crida una funcio segons l'exercici
    public static void seleccio(int opcio) throws IOException {
        switch (opcio) {
            case 1:
                exercici1();
                break;
            case 2:
                exercici2();
                break;
            case 3:
                exercici3();
                break;
            case 4:
                exercici4();
                break;
            case 5:
                exercici5();
                break;
            case 6:
                exercici6();
                break;
        }
    }
    //Assigna a dues variables els dos fitxers i comprova si el fitxer existeix
    public static void exercici1() {
        File f1 = new File("./prova/nop.txt");
        File f2 = new File("C:\\Windows\\notepad.exe");
        if (f1.exists()) {
            System.out.println("El fitxer existeix!");
        } else {
            System.out.println("El fitxer no existeix!");
        }
        if (f2.exists()) {
            System.out.println("El fitxer existeix!");
        } else {
            System.out.println("El fitxer no existeix!");
        }
    }
    //Assigna a una variable la ruta de la carpeta i la llista
    public static void exercici2() {
        File carpeta = new File("C:\\Windows\\");
        String[] llista = carpeta.list();
        for (String nom : llista) {
            System.out.println(nom);
        }
    }
    //Assigna 
    public static void exercici3() throws IOException {
        FileWriter arxiu = new FileWriter("./Text_escrit.txt");
        arxiu.write("Aquest és un primer escrit al meu primer arxiu");
        arxiu.close();
        System.out.println("El primer arxiu ha sigut creat ocrrectament");
        FileWriter arxiu2 = new FileWriter("./Text_a_escriure.txt");
        Scanner tixt1 = new Scanner(System.in);
        System.out.print("Escriu el text: ");
        String text = tixt1.nextLine();
        arxiu2.write(text);
        arxiu2.close();
        System.out.print("El text s'ha guardat en el fitxer. ");
    }

    public static void exercici4() throws FileNotFoundException, IOException {
        File f1 = new File("./Text_escrit.txt");
        File f2 = new File("./Text_a_escriure.txt");
        File f3 = new File("./Apunts.pdf");
        if (f1.exists() && f2.exists() && f3.exists()) {
            FileReader lectura1 = new FileReader("./Text_escrit.txt");
            FileReader lectura2 = new FileReader("./Text_a_escriure.txt");
            FileReader lectura3 = new FileReader("./Apunts.pdf");
            BufferedReader buf1 = new BufferedReader(lectura1);
            BufferedReader buf2 = new BufferedReader(lectura2);
            BufferedReader buf3 = new BufferedReader(lectura3);
            System.out.println("Aquest és el text del primer arxiu:");
            String linia = buf1.readLine();
            while (linia != null) {
                System.out.println(linia);
                linia = buf1.readLine();
            }
            System.out.println("Aquest és el text del segón arxiu");
            String linia2 = buf2.readLine();
            while (linia2 != null) {
                System.out.println(linia2);
                linia2 = buf2.readLine();
            }
            System.out.println("Aquest és el text del PDF");
            String linia3 = buf3.readLine();
            while (linia3 != null) {
                System.out.println(linia3);
                linia3 = buf3.readLine();
            }
        } else {
            System.out.println("Els fitxers no existeixen, has de fer abans la opció 3");
        }
    }

    public static String textAleatori() {
        String SALTCHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
        StringBuilder salt = new StringBuilder();
        Random rnd = new Random();
        while (salt.length() < 5) { // length of the random string.
            int index = (int) (rnd.nextFloat() * SALTCHARS.length());
            salt.append(SALTCHARS.charAt(index));
        }
        String saltStr = salt.toString();
        return saltStr;
    }

    public static void exercici5() throws IOException {
        Path dirPath = Paths.get("./directori");
        boolean resultat = false;
        if (Files.notExists(dirPath)) {
            File directori = new File("./directori");
            System.out.println("El directori s'ha creat");
            resultat = directori.mkdir();
        } else {
            System.out.println("El directori ja existeix");
        }
        FileWriter arxi = new FileWriter("./directori/" + textAleatori() + ".txt");
        arxi.write("Hola mon!");
        arxi.close();
        System.out.println("El fitcer de text s'ha creat");
    }

    private static void exercici6() {
        //Scanner començara a llegir el fitxer que li indiquem
        Scanner sc = new Scanner(System.in);
        System.out.println("Entra l'adreça d'un fitxer: ");
        //Guarda el que hem escrit en "adreçaFitxer"
        String adrecaFitxer = sc.next();
        //Crea un fitxer i es passa el que hem escrit
        File f = new File(adrecaFitxer);
        if (f.isFile()) {
            //Diu el nom del fitxer, la ruta del fitxer i la longitud en bytes del fitxer.
            System.out.println("Nom: " + f.getName());
            System.out.println("Path: " + f.getPath());
            System.out.println("Longitud: " + f.length() + " bytes");
        } else {
            System.out.println("El fitxer no existeix\n");
        }
    }
}
