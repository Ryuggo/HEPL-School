import java.io.*;
import java.util.*;



public class Main {
    static BufferedReader br = null;
    static BufferedWriter bf1 = null;
    static BufferedWriter bf2 = null;
    static BufferedWriter bf3 = null;

    static boolean XSD = true;


    public static void main(String[] args) {
        try {
            br = new BufferedReader(new FileReader(GetNomFichier("movies.txt")));
            bf1 = new BufferedWriter(new FileWriter(GetNomFichier("movies.dtd")));
            bf2 = new BufferedWriter(new FileWriter(GetNomFichier("movies.xml")));
            bf3 = new BufferedWriter(new FileWriter(GetNomFichier("movies.xsd")));
        } catch (IOException e) {
            e.printStackTrace();
        }

        String[][] names = {{"id", "unsignedShort"},
                        {"title", "string"},
                        {"originalTitle", "string"},
                        {"releaseDate", "date"},
                        {"status", "string"},
                        {"voteAverage", "decimal"},
                        {"voteCount", "unsignedShort"},
                        {"runtime", "unsignedShort"},
                        {"certification", ""},
                        {"posterPath", "string"},
                        {"budget", "unsignedInt"},
                        {"tagline", ""},
                        {"genre", "", "idg", "unsignedInt", "nameg", "string"},
                        {"director", "", "idd", "unsignedInt", "named", "string"},
                        {"actor", "", "ida", "unsignedInt", "namea", "string", "charactera", "string"}};

        WriteXML("movie", names);

        if(XSD)
            WriteXSD("movie", names);
        else
            WriteDTD();

        try {
            bf1.close();
            bf2.close();
            bf3.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public static void WriteDTD() {
        WriteFichier("<!ELEMENT movies (movie*)>\n", 1);
        WriteFichier("<!ELEMENT movie (id,title,originalTitle,releaseDate,status,voteAverage,voteCount,runtime,certification,posterPath,budget,tagline,genres,directors,actors)>\n", 1);
        WriteFichier("<!ELEMENT id (#PCDATA)>\n", 1);
        WriteFichier("<!ELEMENT title (#PCDATA)>\n", 1);
        WriteFichier("<!ELEMENT originalTitle (#PCDATA)>\n", 1);
        WriteFichier("<!ELEMENT releaseDate (#PCDATA)>\n", 1);
        WriteFichier("<!ELEMENT status (#PCDATA)>\n", 1);
        WriteFichier("<!ELEMENT voteAverage (#PCDATA)>\n", 1);
        WriteFichier("<!ELEMENT voteCount (#PCDATA)>\n", 1);
        WriteFichier("<!ELEMENT runtime (#PCDATA)>\n", 1);
        WriteFichier("<!ELEMENT certification (#PCDATA)>\n", 1);
        WriteFichier("<!ELEMENT posterPath (#PCDATA)>\n", 1);
        WriteFichier("<!ELEMENT budget (#PCDATA)>\n", 1);
        WriteFichier("<!ELEMENT tagline (#PCDATA)>\n", 1);
        WriteFichier("<!ELEMENT genres ((genre)*)>\n", 1);
            WriteFichier("<!ELEMENT genre ((idg, nameg)*)>\n", 1);
            WriteFichier("<!ELEMENT idg (#PCDATA)>\n", 1);
            WriteFichier("<!ELEMENT nameg (#PCDATA)>\n", 1);
        WriteFichier("<!ELEMENT directors ((director)*)>\n", 1);
            WriteFichier("<!ELEMENT director ((idd, named)*)>\n", 1);
            WriteFichier("<!ELEMENT idd (#PCDATA)>\n", 1);
            WriteFichier("<!ELEMENT named (#PCDATA)>\n", 1);
        WriteFichier("<!ELEMENT actors ((actor)*)>\n", 1);
            WriteFichier("<!ELEMENT actor ((ida, namea, charactera)*)>\n", 1);
            WriteFichier("<!ELEMENT ida (#PCDATA)>\n", 1);
            WriteFichier("<!ELEMENT namea (#PCDATA)>\n", 1);
            WriteFichier("<!ELEMENT charactera (#PCDATA)>", 1);
    }


    public static void WriteXML(String global, String[][] names) {
        WriteFichier("<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\n", 2);
        WriteFichier("<?xml-stylesheet href =\"./"+ global +"s.xslt\" type=\"text/xsl\" ?>\n", 2);
        WriteFichier("<!DOCTYPE "+ global +"s SYSTEM \""+ global +"s.dtd\">\n", 2);
        if(XSD)
            WriteFichier("<"+ global +"s xsi:noNamespaceSchemaLocation=\""+ global +"s.xsd\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" >\n", 2);
        else
            WriteFichier("<"+ global +"s>\n", 2);

        try {
            while(true) {
                String line = br.readLine();
                if(line == null)
                    break;
                Vector<String> infos = Divide("‣", line);
    
                WriteFichier("<"+ global +">\n", 2);
                for(int i = 0; i < infos.size(); i++) {
                    if(names[i].length <= 2)
                        WriteXMLTag(names[i][0], infos.get(i), 1);
                    else {
                        if(infos.get(i).equals("") == false)
                            WriteXMLTagPlus(names[i], infos.get(i));
                        else
                            WriteXMLTagPlusEmpty(names[i]);
                    }
                }
                WriteFichier("</"+ global +">\n", 2);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public static void WriteXMLTag(String balise, String chaine, int i) {
        chaine = chaine.replaceAll("&", "&amp;");

        try {
            for(int j = 0; j < i; j++)
                bf2.write("\t");

            bf2.write("<" + balise + ">");
            if(chaine.equals("") == false)
                bf2.write(chaine);
            else {
                if(balise.equals("releaseDate"))
                    bf2.write("2000-01-01");
                else
                    bf2.write("0");
            }
            bf2.write("</" + balise + ">\n");
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }
    public static void WriteXMLTagPlus(String[] balise, String chaine) {
        WriteFichier("\t<"+ balise[0] +"s>\n", 2);

        ListIterator<String> lContents = Divide("‖", chaine).listIterator();
        while(lContents.hasNext()) {
            WriteFichier("\t\t<"+ balise[0] +">\n", 2);

            String info = lContents.next().toString();
            Vector<String> infos = Divide("․", info);
            for(int i = 2, j = 0; i < balise.length; i+=2, j++)
                WriteXMLTag(balise[i], infos.get(j), 3);

            WriteFichier("\t\t</"+ balise[0] +">\n", 2);
        }
        WriteFichier("\t</"+ balise[0] +"s>\n", 2);
    }
    public static void WriteXMLTagPlusEmpty(String[] balise) {
        WriteFichier("\t<"+ balise[0] +"s>\n", 2);
        WriteFichier("\t\t<"+ balise[0] +">\n", 2);

        for(int i = 2; i < balise.length; i+=2)
            WriteXMLTag(balise[i], "", 3);

        WriteFichier("\t\t</"+ balise[0] +">\n", 2);
        WriteFichier("\t</"+ balise[0] +"s>\n", 2);
    }


    public static void WriteXSD(String global, String[][] names) {
        WriteFichier("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n", 3);
        WriteFichier("<xs:schema attributeFormDefault=\"unqualified\" elementFormDefault=\"qualified\" xmlns:xs=\"http://www.w3.org/2001/XMLSchema\">\n", 3);
        WriteXSDOpen(nbSpace(1), global + "s", 0);
        WriteXSDOpen(nbSpace(4), global, 1);

        for(int i = 0; i < names.length; i++) {
            if(names[i].length <= 2)
                WriteXSDElem(names[i], 7, 0);
            else
                WriteXSDElemPlus(names[i], 7, 0);
        }

        WriteXSDClose(nbSpace(4));
        WriteXSDClose(nbSpace(1));
        WriteFichier("</xs:schema>", 3);
    }
    public static void WriteXSDElem(String[] element, int i, int start) {
        String space = nbSpace(i);

        String elem = space + "<xs:element name=\""+ element[start] +"\"";
        if(element[start+1].equals("") == false)
            elem += " type=\"xs:"+ element[start+1] +"\"";
        elem += " />\n";

        WriteFichier(elem, 3);
    }
    public static void WriteXSDElemPlus(String[] element, int i, int start) {
        WriteXSDOpen(nbSpace(i), element[start] + "s", 0);
        WriteXSDOpen(nbSpace(i+3), element[start], 1);

        for(int j = 2; j < element.length; j+=2)
            WriteXSDElem(element, i+6, start+j);

        WriteXSDClose(nbSpace(i+3));
        WriteXSDClose(nbSpace(i));
    }

    public static void WriteXSDOpen(String space, String elem, int i) {
        if(i == 0)
            WriteFichier(space + "<xs:element name=\""+ elem +"\">\n", 3);
        else
            WriteFichier(space + "<xs:element maxOccurs=\"unbounded\" name=\""+ elem +"\">\n", 3);
        WriteFichier(space + " <xs:complexType>\n", 3);
        WriteFichier(space + "  <xs:sequence>\n", 3);
    }
    public static void WriteXSDClose(String space) {
        WriteFichier(space + "  </xs:sequence>\n", 3);
        WriteFichier(space + " </xs:complexType>\n", 3);
        WriteFichier(space + "</xs:element>\n", 3);
    }
    public static String nbSpace(int i) {
        String space = "";
        for(int j = 0; j < i; j++)
            space += " ";
        return space;
    }


    public static void WriteFichier(String chaine, int i) {
        try {
            switch(i) {
                case 1:
                    bf1.write(chaine);
                break;
                case 2:
                    bf2.write(chaine);
                break;
                case 3:
                    bf3.write(chaine);
                break;
            }
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }


    public static String readAll(BufferedReader reader) {
        StringBuffer buffer = new StringBuffer();

        while (true) {
            try {
                String line = reader.readLine();

                if(line == null) break;
                buffer.append(line + "\n");
            }
            catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return buffer.toString();
    }


    public static Vector<String> Divide(String sep, String chaine) {
        Vector<String> infos = new Vector<String>();

        for(int i = 0, j = 0; i != -1; j = i+1) {
            i = chaine.indexOf(sep, j);
            infos.add(i != -1 ? chaine.substring(j, i) : chaine.substring(j));
        }
        return infos;
    }

    public static String GetNomFichier(String nomf) {
        return System.getProperty("user.dir") + System.getProperty("file.separator") + "XML" + System.getProperty("file.separator") + "Fichiers" + System.getProperty("file.separator") + nomf;
    }
}
