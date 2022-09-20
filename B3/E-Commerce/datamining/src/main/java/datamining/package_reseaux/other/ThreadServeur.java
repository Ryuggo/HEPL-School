package datamining.package_reseaux.other;

import java.io.*;
import java.net.*;

import datamining.package_reseaux.Interface.ConsoleServeur;
import datamining.package_reseaux.Interface.Requete;
import datamining.package_reseaux.Interface.SourceTaches;



public class ThreadServeur extends Thread {
    int port;
    ServerSocket SSocket = null;
    Socket CSocket = null;
    Requete req;

    private SourceTaches tachesAExecuter;
    private ConsoleServeur guiApplication;

    public ThreadServeur(int p, SourceTaches st) {
        port = p; tachesAExecuter = st;
    }

    public void run() {
        try {
            SSocket = new ServerSocket(port);
        }
        catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("Démarrage du pool de threads");

        for (int i = 0; i < 3; i++) {
            ThreadClient thr = new ThreadClient(tachesAExecuter, "Thread du pool n° " + i);
            thr.start();
        }

        while (!isInterrupted()) {
            System.out.println("Serveur en attente d'une connexion");
            try {
                CSocket = SSocket.accept();
            }
            catch (IOException e) {
                e.printStackTrace();
            }

            System.out.println("Le serveur est connecté");
            try {
                ObjectInputStream ois = new ObjectInputStream(CSocket.getInputStream());

                //Reçus
                req = (Requete) ois.readObject();
            }
            catch (IOException | ClassNotFoundException e) {
                e.printStackTrace();
            }

            Runnable travail = req.createRunnable(CSocket, guiApplication);
            if (travail != null) {
                tachesAExecuter.recordTache(travail);
            }
        }
    }
}
