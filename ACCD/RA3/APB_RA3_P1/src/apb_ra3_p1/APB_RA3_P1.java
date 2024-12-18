package apb_ra3_p1;

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

/**
 *
 * @author AluCiclesGS1
 */
public class APB_RA3_P1 {

    public static void main(String[] args) throws IOException, SQLException {
        try {
            Class.forName("org.postgresql.Driver");
        } catch (ClassNotFoundException ex) {
            System.out.println("Error al registrar el driver de PostgreSQL: " + ex);
        }

        Connection connection = null;
        // Database connect
        // Conectamos con la base de datos
        connection = DriverManager.getConnection(
                "jdbc:postgresql://127.0.0.1:5432/clash",
                "postgres", "accedir");

        Statement stmt = connection.createStatement();
        ResultSet rs = stmt.executeQuery("SELECT * FROM jugadors");

        while (rs.next()) {
            System.out.println("ID: " + rs.getString("id"));
            System.out.println("Nom del jugador: " + rs.getString("nom"));
            System.out.println("Nivell: " + rs.getString("nivell"));
            System.out.println("Copes: " + rs.getString("copes"));
            System.out.println("Or: " + rs.getString("oro"));
            System.out.println("Gemes: " + rs.getString("gemes"));
            System.out.println("Estrelles: " + rs.getString("estrelles"));
            System.out.println("Gemes: " + rs.getString("gemes"));

            int id = rs.getInt("id");
            String query = "SELECT * FROM partides WHERE idjugador1= " + id + " OR idjugador2= " + id;
            Statement stmt2 = connection.createStatement();
            ResultSet rt = stmt2.executeQuery(query);
            while (rt.next()) {
                System.out.println("Resultat: " + rt.getString("resultat"));
                System.out.println("Temps: " + rt.getString("temps"));
                System.out.println("Tipus de partida: " + rt.getString("tipus"));
                System.out.println("Jugador blau: " + rt.getString("idjugador1"));
                System.out.println("Jugador vermell: " + rt.getString("idjugador2"));
            }

            System.out.println("\n");
        }
        connection.close();
    }

}
