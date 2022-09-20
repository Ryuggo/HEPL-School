package datamining.package_reseaux.other;

import datamining.package_reseaux.Interface.SourceTaches;



public class ThreadClient extends Thread {
    private SourceTaches tachesAExecuter;
    //private String nom;

    Runnable tacheEnCours;

    public ThreadClient(SourceTaches st, String n) {
        tachesAExecuter = st;
        //nom = n;
    }

    public void run() {
        while(!isInterrupted()) {
            try {
                System.out.println("Thread client avant getTache");
                tacheEnCours = tachesAExecuter.getTache();
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("Tache en cours");
            tacheEnCours.run();
        }
    }
}
