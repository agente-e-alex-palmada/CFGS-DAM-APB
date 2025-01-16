package apb_ra3_p1;

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import static java.util.Map.entry;
import java.util.Scanner;

/**
 *
 * @author AluCiclesGS1
 */
public class APB_RA3_P1 {

    // Main uses menu and select for every task
    public static void main(String[] args) throws IOException, SQLException {
        int option = 0;
        //
        menu();
        while (option != 6) {
            Scanner keyboard = new Scanner(System.in);
            System.out.print("Select option: ");
            option = keyboard.nextInt();
            selection(option);
        }
    }

    // Show all options
    public static void menu() {
        System.out.println("****************************************");
        System.out.println("******************MENU******************");
        System.out.println("1.- List all players and their games");
        System.out.println("2.- Insert new players");
        System.out.println("3.- Update data from a player");
        System.out.println("4.- Insert new game between two players");
        System.out.println("5.- Delete a player and their games");
        System.out.println("6.- Exit");
    }

    // Gets the user int and goes to the exercice
    public static void selection(int option) throws IOException, SQLException {
        switch (option) {
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
                exercice4();
                break;
            case 5:
                exercice5();
                break;
        }
    }

    // At this exercice, the function does a query to the databse and get the data, then it shows the data from the query with sout's.
    private static void exercice1() throws SQLException {
        // Trys to get the driver
        try {
            Class.forName("org.postgresql.Driver");
        } catch (ClassNotFoundException ex) {
            System.out.println("Error at registering SQL driver: " + ex);
        }
        // Connects to the databse with the password
        Connection connection = null;
        connection = DriverManager.getConnection(
                "jdbc:postgresql://127.0.0.1:5432/clash",
                "postgres", "accedir");
        // Creates the query and saves it on a variable
        Statement stmt = connection.createStatement();
        ResultSet rs = stmt.executeQuery("SELECT * FROM jugadors");

        // Show all the information from the data obtained
        while (rs.next()) {
            System.out.println("ID: " + rs.getString("id"));
            System.out.println("Player name: " + rs.getString("nom"));
            System.out.println("Level: " + rs.getString("nivell"));
            System.out.println("Trophies: " + rs.getString("copes"));
            System.out.println("Gold: " + rs.getString("oro"));
            System.out.println("Gems: " + rs.getString("gemes"));
            System.out.println("Stars: " + rs.getString("estrelles"));

            // Saves in a variable the ID of the player, it can do another query to show all games from the players
            int id = rs.getInt("id");

            // Prepares the another query
            String query = "SELECT * FROM partides WHERE idjugador1= " + id + " OR idjugador2= " + id;
            Statement stmt2 = connection.createStatement();
            ResultSet rt = stmt2.executeQuery(query);
            while (rt.next()) {
                System.out.println("Result: " + rt.getString("resultat"));
                System.out.println("Time: " + rt.getString("temps"));
                System.out.println("Game type: " + rt.getString("tipus"));
                System.out.println("Blue player: " + rt.getString("idjugador1"));
                System.out.println("Red player: " + rt.getString("idjugador2"));
            }
            System.out.println("\n");
        }
        // Closes the connection
        connection.close();
    }

    // In this exercice, adds a new user to the database. The user, as being new, will not have any games, stats or anything else, just the name and the default ID scaling from the last one.
    private static void exercice2() throws SQLException {
        try {
            Class.forName("org.postgresql.Driver");
        } catch (ClassNotFoundException ex) {
            System.out.println("Error at registering SQL driver: " + ex);
        }

        Connection connection = null;
        connection = DriverManager.getConnection(
                "jdbc:postgresql://127.0.0.1:5432/clash",
                "postgres", "accedir");

        // Asks for the new player name, and then does a query to the table players so it can add the new player, inserts the new ID and his name.
        Scanner entry = new Scanner(System.in);
        System.out.println("Enter the new player name: ");
        String name = entry.nextLine();
        System.out.println("");

        // Gets the last ID from the database
        int id = lastID() + 1;
        PreparedStatement insertPlayer = connection.prepareStatement("INSERT INTO jugadors(id, nom) VALUES (?, ?)");
        insertPlayer.setInt(1, id);
        insertPlayer.setString(2, name);
        insertPlayer.executeUpdate();
        connection.close();
    }

    // This function is used to get the last ID from the database, so when we introduce a new player, it will scale plus 1 from the last one
    private static int lastID() throws SQLException {
        int id = 0;
        Connection connection = null;
        connection = DriverManager.getConnection("jdbc:postgresql://127.0.0.1:5432/clash", "postgres", "accedir");
        try {
            Statement stmt = connection.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT id FROM jugadors order by id ASC");
            while (rs.next()) {
                id = rs.getInt("id");
            }
        } catch (SQLException ex) {
            System.out.println("Exception error from SQL: ");
            System.out.println(ex.getMessage());
        }
        connection.close();
        return id;
    }

    // In this exercice, we are going to UPDATE the data from a player, first it will show what players there are and modify their stats, if nothing is introduced, the data stays the same.
    private static void exercice3() throws SQLException {
        try {
            Class.forName("org.postgresql.Driver");
        } catch (ClassNotFoundException ex) {
            System.out.println("Error at registering SQL driver: " + ex);
        }
        Connection connection = null;
        connection = DriverManager.getConnection(
                "jdbc:postgresql://127.0.0.1:5432/clash",
                "postgres", "accedir");
        try {
            // Shows the players that can be selected
            Statement stmt = connection.createStatement();
            ResultSet playersData = stmt.executeQuery("SELECT * FROM jugadors");
            while (playersData.next()) {
                System.out.println("ID: " + playersData.getString("id"));
                System.out.println("Player name: " + playersData.getString("nom"));
                System.out.println("");
            }

            // Asks the user to seelct a player
            Scanner entry = new Scanner(System.in);
            System.out.println("Select which player do you want to modify by their ID: ");

            // Parse the string to a int, so string cannot be a int if isn't parsed.
            String inputID = entry.nextLine();
            int id = Integer.parseInt(inputID);

            // Checks if it exists
            String checkQuery = "SELECT * FROM jugadors WHERE id = ?";
            PreparedStatement pstmtCheck = connection.prepareStatement(checkQuery);
            pstmtCheck.setInt(1, id);
            ResultSet checkResult = pstmtCheck.executeQuery();

            // In case that exists:
            if (checkResult.next()) {
                // Show all the information from the data obtained
                while (checkResult.next()) {
                    System.out.println("ID: " + checkResult.getString("id"));
                    System.out.println("Player name: " + checkResult.getString("nom"));
                    System.out.println("Level: " + checkResult.getString("nivell"));
                    System.out.println("Trophies: " + checkResult.getString("copes"));
                    System.out.println("Gold: " + checkResult.getString("oro"));
                    System.out.println("Gems: " + checkResult.getString("gemes"));
                    System.out.println("Stars: " + checkResult.getString("estrelles"));
                    System.out.println("\n");
                }

                // Start the loop to keep asking the user for stat modifications
                while (true) {
                    System.out.println("1. Name");
                    System.out.println("2. Level");
                    System.out.println("3. Trophies");
                    System.out.println("4. Gold");
                    System.out.println("5. Gems");
                    System.out.println("6. Stars");
                    System.out.println("Type 'exit' to quit.");
                    System.out.print("Enter your choice: ");
                    String choice = entry.nextLine();

                    if (choice.equalsIgnoreCase("exit")) {
                        break;  // Exit the loop if the user chooses 'exit'
                    }

                    // Validating input and executing corresponding modification
                    String updateQuery = "";
                    PreparedStatement pstmtUpdate = null;

                    switch (choice) {
                        case "1": // Modify Name
                            System.out.print("Enter the new name (or press Enter to keep it unchanged): ");
                            String newName = entry.nextLine();
                            if (newName.isEmpty()) {
                                break; // If input is empty, keep the value unchanged
                            }
                            updateQuery = "UPDATE jugadors SET nom = ? WHERE id = ?";
                            pstmtUpdate = connection.prepareStatement(updateQuery);
                            pstmtUpdate.setString(1, newName);
                            pstmtUpdate.setInt(2, id);
                            break;
                        case "2": // Modify Level
                            System.out.print("Enter the new level (or press Enter to keep it unchanged): ");
                            String newLevel = entry.nextLine();
                            if (newLevel.isEmpty()) {
                                break; // If input is empty, keep the value unchanged
                            }
                            updateQuery = "UPDATE jugadors SET nivell = ? WHERE id = ?";
                            pstmtUpdate = connection.prepareStatement(updateQuery);
                            pstmtUpdate.setString(1, newLevel);
                            pstmtUpdate.setInt(2, id);
                            break;
                        case "3": // Modify Trophies
                            System.out.print("Enter the new number of trophies (or press Enter to keep it unchanged): ");
                            String newTrophies = entry.nextLine();
                            if (newTrophies.isEmpty()) {
                                break; // If input is empty, keep the value unchanged
                            }
                            updateQuery = "UPDATE jugadors SET copes = ? WHERE id = ?";
                            pstmtUpdate = connection.prepareStatement(updateQuery);
                            pstmtUpdate.setString(1, newTrophies);
                            pstmtUpdate.setInt(2, id);
                            break;
                        case "4": // Modify Gold
                            System.out.print("Enter the new amount of gold (or press Enter to keep it unchanged): ");
                            String newGold = entry.nextLine();
                            if (newGold.isEmpty()) {
                                break; // If input is empty, keep the value unchanged
                            }
                            updateQuery = "UPDATE jugadors SET oro = ? WHERE id = ?";
                            pstmtUpdate = connection.prepareStatement(updateQuery);
                            pstmtUpdate.setString(1, newGold);
                            pstmtUpdate.setInt(2, id);
                            break;
                        case "5": // Modify Gems
                            System.out.print("Enter the new amount of gems (or press Enter to keep it unchanged): ");
                            String newGems = entry.nextLine();
                            if (newGems.isEmpty()) {
                                break; // If input is empty, keep the value unchanged
                            }
                            updateQuery = "UPDATE jugadors SET gemes = ? WHERE id = ?";
                            pstmtUpdate = connection.prepareStatement(updateQuery);
                            pstmtUpdate.setString(1, newGems);
                            pstmtUpdate.setInt(2, id);
                            break;
                        case "6": // Modify Stars
                            System.out.print("Enter the new number of stars (or press Enter to keep it unchanged): ");
                            String newStars = entry.nextLine();
                            if (newStars.isEmpty()) {
                                break; // If input is empty, keep the value unchanged
                            }
                            updateQuery = "UPDATE jugadors SET estrelles = ? WHERE id = ?";
                            pstmtUpdate = connection.prepareStatement(updateQuery);
                            pstmtUpdate.setString(1, newStars);
                            pstmtUpdate.setInt(2, id);
                            break;
                        default:
                            System.out.println("Invalid choice. Please select a valid stat.");
                            continue;
                    }
                    // If detects there's a modification, it executes the update
                    if (pstmtUpdate != null) {
                        int rowsAffected = pstmtUpdate.executeUpdate();
                        if (rowsAffected > 0) {
                            System.out.println("Player stat updated successfully.");
                        } else {
                            System.out.println("Failed to update player stat.");
                        }
                    }
                }
            }
            // In case of error, it prints it
        } catch (SQLException e) {
            System.out.println(e);
        }
    }

    // In this exercice, we will introduce a new games between two players.
    private static void exercice4() throws SQLException {
        try {
            Class.forName("org.postgresql.Driver");
        } catch (ClassNotFoundException ex) {
            System.out.println("Error at registering SQL driver: " + ex);
        }
        Connection connection = null;
        connection = DriverManager.getConnection(
                "jdbc:postgresql://127.0.0.1:5432/clash",
                "postgres", "accedir");

        try {
            Scanner entry = new Scanner(System.in);

            // Get result of the game
            System.out.println("Enter the result of the game (e.g., '1-2', '2-2', '0-1'): ");
            String result = entry.nextLine();

            // Get time of the game
            System.out.println("Enter the time of the game (in minutes, e.g., 2:13): ");
            String time = entry.nextLine();

            // Get the type of the game
            System.out.println("Enter the type of the game (e.g., 'Friendly', 'Ranked'): ");
            String gameType = entry.nextLine();

            // Loop to get valid player IDs
            int player1ID = 0;
            int player2ID = 0;

            // Ensure valid player 1 ID
            while (true) {
                System.out.println("Enter the ID of Player 1: ");
                try {
                    player1ID = Integer.parseInt(entry.nextLine());
                    if (isValidPlayer(connection, player1ID)) {
                        break;  // Exit loop if Player 1 ID is valid
                    } else {
                        System.out.println("Invalid Player 1 ID. Please enter a valid ID.");
                    }
                } catch (NumberFormatException e) {
                    System.out.println("Invalid input format. Please enter a valid integer for Player 1 ID.");
                }
            }

            // Ensure valid player 2 ID
            while (true) {
                System.out.println("Enter the ID of Player 2: ");
                try {
                    player2ID = Integer.parseInt(entry.nextLine());
                    if (isValidPlayer(connection, player2ID)) {
                        break;  // Exit loop if Player 2 ID is valid
                    } else {
                        System.out.println("Invalid Player 2 ID. Please enter a valid ID.");
                    }
                } catch (NumberFormatException e) {
                    System.out.println("Invalid input format. Please enter a valid integer for Player 2 ID.");
                }
            }

            // Calculate the new game ID (assuming it's based on the last game ID)
            int id = lastIDGames() + 1;  // Make sure `lastIDGames()` works as intended

            // Prepare the SQL query to insert a new game
            PreparedStatement insertNewGame = connection.prepareStatement(
                "INSERT INTO partides(id, resultat, temps, tipus, idjugador1, idjugador2) VALUES (?, ?, ?, ?, ?, ?)"
            );

            // Set the values in the PreparedStatement
            insertNewGame.setInt(1, id);
            insertNewGame.setString(2, result);
            insertNewGame.setString(3, time);
            insertNewGame.setString(4, gameType);
            insertNewGame.setInt(5, player1ID);
            insertNewGame.setInt(6, player2ID);

            // Execute the insert query
            int rowsAffected = insertNewGame.executeUpdate();
            if (rowsAffected > 0) {
                System.out.println("New game inserted successfully!");
            } else {
                System.out.println("Failed to insert new game.");
            }

        } catch (SQLException e) {
            System.out.println("Error: " + e.getMessage());
        } catch (NumberFormatException e) {
            System.out.println("Invalid input format. Please enter valid numbers for player IDs and time.");
        } finally {
            try {
                if (connection != null) {
                    connection.close();
                }
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }

    // Helper method to check if a player ID is valid
    private static boolean isValidPlayer(Connection connection, int playerId) throws SQLException {
        String checkQuery = "SELECT id FROM jugadors WHERE id = ?";
        PreparedStatement pstmtCheck = connection.prepareStatement(checkQuery);
        pstmtCheck.setInt(1, playerId);
        ResultSet resultSet = pstmtCheck.executeQuery();
        return resultSet.next();  // Returns true if the player exists
    }
    
    // This function is used to get the last ID from games, so when we introduce a new player, it will scale plus 1 from the last one
    private static int lastIDGames() throws SQLException {
        int id = 0;
        Connection connection = null;
        connection = DriverManager.getConnection("jdbc:postgresql://127.0.0.1:5432/clash", "postgres", "accedir");
        try {
            Statement stmt = connection.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT id FROM partides order by id ASC");
            while (rs.next()) {
                id = rs.getInt("id");
            }
        } catch (SQLException ex) {
            System.out.println("Exception error from SQL: ");
            System.out.println(ex.getMessage());
        }
        connection.close();
        return id;
    }
    private static void exercice5() {

    }
}
