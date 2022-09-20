package datamining.package_reseaux.other;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;



public class MySQL {
    public static Connection MySQL_Connexion(String BDD, String port,String IP,String user, String password) {
        System.out.println("Essai de connexion JDBC");
        Connection con;
        try {
            //Class driver = Class.forName("com.mysql.cj.jdbc.Driver");
            Class.forName("com.mysql.cj.jdbc.Driver");
        } 
        catch (ClassNotFoundException e) {
            System.out.println("Driver MySQL non chargé " + e.getMessage());
        }

        try {
            con = DriverManager.getConnection("jdbc:mysql://" + IP + ":" + port + "/" + BDD, user, password);
            System.out.println("Connexion à la base de donnée ok");

            return con;
        } 
        catch (SQLException e) {
            System.out.println("Erreur JDBC-OBCD : " + e.getMessage() + " ** " + e.getSQLState() + "--\n\n");
            return null;
        }
    }
}
