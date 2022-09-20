package datamining.package_reseaux.Interface;

import java.net.*;

public interface Requete {
    public Runnable createRunnable(Socket s, ConsoleServeur cs);
}
