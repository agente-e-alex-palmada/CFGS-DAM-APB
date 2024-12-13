package lectura.i.exriptura.de.fitxers;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class LecturaIExripturaDeFitxers {

    public static void main(String[] args) throws IOException {
        int opcio = 0;
        while (opcio != 3) {
            //Cridem la funció menu, i quan la variable opcio sigui 7, el bucle termina, i el programa també.
            menu();
            Scanner teclado = new Scanner(System.in);
            System.out.print("Escull opció: ");
            opcio = teclado.nextInt();
            seleccio(opcio);
        }
    }

    public static void menu() {
        System.out.println("1.- Crear usuaris");
        System.out.println("2.- Iniciar sessió");
        System.out.println("3.- Sortir");
    }

    public static void seleccio(int opcio) throws IOException {
        switch (opcio) {
            case 1:
                exercici1();
                break;
            case 2:
                exercici2();
                break;
        }
    }

    private static void exercici1() throws IOException {
        //Crea un arxiu per escriure
        FileWriter uc = new FileWriter("./nom_usuaris.txt", true);
        //Crea una variable tipus string amb usuari inicialitzat
        String usuari = "", contra;
        //Scanner és una variable que escriu en una variable el text qaue introduim
        Scanner enter = new Scanner(System.in);
        //Mentres que usuari no sigui igual a res, continua
        while (!"".equals(usuari)) {
            System.out.println("Introdueix nom usuari: ");
            //Cridem la funció enter linea, i o remplaça a usuari
            usuari = enter.nextLine();
            //Si usuari no és igual a res, continua
            if (!"".equals(usuari)) {
                System.out.println("Introdueix password usuari: ");
                contra = enter.nextLine();
                //Escriu en la linea usuari:contrasenya\salt de linea
                uc.write(usuari + ":" + contra + "\n");
            }
        }
        //Tanca el fitxer
        uc.close();
    }

    public static void exercici2() throws FileNotFoundException, IOException {
        //Validació del fitxer
        File uc = new File("./nom_usuaris.txt");
        if (uc.exists()) {
            FileReader lain = new FileReader(uc);
            BufferedReader line = new BufferedReader(lain);
            while (line != null){
                if (usuari+":"+contra.equals(line)){
                 
                }
            }
        }
    }
}
