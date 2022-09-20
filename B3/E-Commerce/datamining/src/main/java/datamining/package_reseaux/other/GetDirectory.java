package datamining.package_reseaux.other;


public class GetDirectory {
    public static String FileDir(String file) {
        return System.getProperty("user.dir") + System.getProperty("file.separator") + "Files" + System.getProperty("file.separator") + file;
    }
}