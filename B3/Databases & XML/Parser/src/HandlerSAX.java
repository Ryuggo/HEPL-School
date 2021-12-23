import org.xml.sax.SAXException;
import org.xml.sax.Attributes;
import org.xml.sax.SAXParseException;
import org.xml.sax.helpers.DefaultHandler;

import java.util.Vector;



public class HandlerSAX extends DefaultHandler {
    boolean show = false;

    int cptTag = 0, cptCertif = 0, j = -1;
    boolean title = false, vote = false;

    Vector<Vector<String>> classement = new Vector<Vector<String>>();
    Vector<String> film = new Vector<String>();

    public void characters(char[] ch, int start, int length) throws SAXException {
        String chaine = new String(ch, start, length).trim();
        if(chaine.length() > 0) {
            if(show)
                System.out.println("Caractères: " + chaine);

            if(chaine.equals("PG-13"))
                cptCertif++;

            if(title == true) {
                film = new Vector<String>();
                film.add(chaine);
            }

            if(vote == true) {
                film.add(chaine);
                j = -1;
                for(int i = 0; i < 10; i++) {
                    Vector<String> tmp = classement.get(i);
                    Double note1 = Double.parseDouble((String)tmp.get(1));
                    Double note2 = Double.parseDouble((String)film.get(1));
                    if (note1 < note2)
                        j = i;
                    else
                        break;
                }

                if(j != -1) {
                    int k = j;
                    Vector<String> tmp1 = classement.get(k);
                    for(Vector<String> tmp2 = null; k >= 0; k--) {
                        if(k-1 != -1) {
                            tmp2 = classement.get(k-1);
                            classement.set(k-1, tmp1);
                        }
                        tmp1 = tmp2;
                    }

                    classement.set(j, film);
                }
            }
        }
    }

    public void startDocument() throws SAXException {
        film.add("Name");
        film.add("0.0");

        for(int i = 0; i < 10; i++)
            classement.add(film);

        System.out.println("-- Début du document --");
    }

    public void endDocument() throws SAXException {
        System.out.println("-- Fin du document --");

        System.out.println("Nbr PG-13: " + cptCertif);
        System.out.println("compteur de tag: " + cptTag);
        System.out.println("classement: ");
        for(int i = 0; i < 10; i++)
            System.out.println(classement.get(i));
    }

    public void startElement(java.lang.String uri, java.lang.String localName, java.lang.String qName, Attributes attr) throws SAXException {
        if(show)
            System.out.println("- Début d'une balise");

        cptTag++;

        if(uri != null && uri.length() > 0 && show)
            System.out.println("uri: " + uri);

        if(qName != null && qName.length() > 0) {
            if(show)
                System.out.println("nom complet: " + qName);

            if(qName.equals("title"))
                title = true;

            if(qName.equals("voteAverage"))
                vote = true;
        }

        int nAttr = attr.getLength();
        if(show)
            System.out.println("nombre d'attributs: " + nAttr);
        if(nAttr == 0)
            return;

        if(show)
            for(int i = 0; i < nAttr; i++)
                System.out.println("attribut n°" + i + "->" + attr.getLocalName(i) + "avec valeur: " + attr.getValue(i));
    }

    public void endElement(java.lang.String uri, java.lang.String localName, java.lang.String qName) throws SAXException {
        if(show)
            System.out.println("- Fin de la balise");

        cptTag++;

        title = false;
        vote = false;
    }


    public void warning(SAXParseException e) throws SAXException {
        System.out.println("WARNING : "+ e.getMessage ());
    }
    public void error(SAXParseException e) throws SAXException {
        System.out.println("ERROR : "+ e.getMessage ()); throw e;
    }
    public void fatalError(SAXParseException e) throws SAXException {
        System.out.println("FATAL : "+ e.getMessage ()); throw e;
    }
}

