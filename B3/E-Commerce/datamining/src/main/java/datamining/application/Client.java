package datamining.application;

import java.io.*;
import java.net.*;
import java.util.Properties;

import datamining.package_reseaux.other.GetDirectory;
import datamining.package_reseaux.other.ReponseSUM;
import datamining.package_reseaux.other.RequeteSUM;

public class Client {
    static Properties prop;
    static int port;
    static String adresse;
    
    public static Properties Proper()
    {
        Properties prop = new Properties();
        try {
            prop.load(new FileInputStream(GetDirectory.FileDir("properties.txt")));
        }
        catch (IOException e) {
            e.printStackTrace();
        }

        port = Integer.parseInt(prop.getProperty("Port"));
        adresse = (String) prop.get("Adresse");

        return prop;
    }
    
    public static void Connection() {
        RequeteSUM req = null;

// Connexion au serveur
        req = new RequeteSUM(RequeteSUM.CONNEXION_RSERVE);

        ObjectInputStream ois = null;
        ObjectOutputStream oos = null;
        Socket cliSock = null;

        try {
            cliSock = new Socket(adresse, port);
            System.out.println(cliSock.getInetAddress().toString());
        }
        catch (UnknownHostException e) {
            System.err.println("Erreur ! Host non trouvé [" + e + "]");
        } catch (IOException e) {
            System.err.println("Erreur ! Pas de connexion ? [" + e + "]");
        }

        // Envoie de la requête
        try {
            oos = new ObjectOutputStream(cliSock.getOutputStream());
            oos.writeObject(req); oos.flush();
        }
        catch (IOException e) {
            System.err.println("Erreur réseau ? [" + e.getMessage() + "]");
        }

        // Lecture de la réponse
        ReponseSUM rep = null;
        try {
            ois = new ObjectInputStream(cliSock.getInputStream());
            rep = (ReponseSUM)ois.readObject();
            if(rep.getCode()==201)
                System.out.println(" *** Reponse reçue : Connection ok");
            else
                System.out.println(" *** Reponse reçue : Connection echouée");
        }
        catch (ClassNotFoundException e) {
            System.out.println("--- erreur sur la classe = " + e.getMessage());
        } catch (IOException e) {
            System.out.println("--- erreur IO = " + e.getMessage());
        }

    }
    public static String Statistics(int mois, String comp, String request, boolean age, boolean nbAccomp) {
        RequeteSUM req = null;
        
        ObjectInputStream ois = null;
        ObjectOutputStream oos = null;
        Socket cliSock = null;

        try {
            cliSock = new Socket(adresse, port);
            System.out.println(cliSock.getInetAddress().toString());
        }
        catch (UnknownHostException e) {
            System.err.println("Erreur ! Host non trouvé [" + e + "]");
        } catch (IOException e) {
            System.err.println("Erreur ! Pas de connexion ? [" + e + "]");
        }
        
        if(request.equals("REG_CORR_LUG"))
            req = new RequeteSUM(RequeteSUM.REG_CORR_LUG, mois, comp);
        else if(request.equals("REG_CORR_LUG_PLUS"))
            req = new RequeteSUM(RequeteSUM.REG_CORR_LUG_PLUS, mois, comp, age, nbAccomp);
        else if(request.equals("ANOVA_1_LUG"))
            req = new RequeteSUM(RequeteSUM.ANOVA_1_LUG, mois, comp);
        else if(request.equals("ANOVA_2_LUG_HF"))
            req = new RequeteSUM(RequeteSUM.ANOVA_2_LUG_HF, mois, comp);
        
        try {
            oos = new ObjectOutputStream(cliSock.getOutputStream());
            oos.writeObject(req); oos.flush();
        }
        catch (IOException e) {
            System.err.println("Erreur réseau ? [" + e.getMessage() + "]");
        }

        // Lecture de la réponse
        ReponseSUM rep = null;
        try {
            ois = new ObjectInputStream(cliSock.getInputStream());
            rep = (ReponseSUM)ois.readObject();
            if(rep.getCode() == 301) {
                System.out.println(" *** Reponse reçue : Statistic ok");
                System.out.println(rep.getChargeUtile());
            }
            else
                System.out.println(" *** Reponse reçue : Statistic echouée");
        }
        catch (ClassNotFoundException e) {
            System.out.println("--- erreur sur la classe = " + e.getMessage());
        } catch (IOException e) {
            System.out.println("--- erreur IO = " + e.getMessage());
        }

        return rep.getChargeUtile();
    }
}