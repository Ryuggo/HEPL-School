package com.example;

import java.util.logging.Level;
import java.util.logging.Logger;

import org.rosuda.REngine.REXP;
import org.rosuda.REngine.REXPMismatchException;
import org.rosuda.REngine.Rserve.RConnection;
import org.rosuda.REngine.Rserve.RserveException;



public class ECommerceInterfaceGraphique extends javax.swing.JFrame {
    RConnection rConn = null;
    REXP x = null;

    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(ECommerceInterfaceGraphique.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(ECommerceInterfaceGraphique.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(ECommerceInterfaceGraphique.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(ECommerceInterfaceGraphique.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new ECommerceInterfaceGraphique().setVisible(true);
            }
        });
    }
    
    public ECommerceInterfaceGraphique() {
        initComponents();
    }

    //@SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();
        jButton3 = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jButton1.setText("Se connecter à RServe");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jButton2.setText("déménagements");
        jButton2.setEnabled(false);
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });

        jButton3.setText("civilisation");
        jButton3.setEnabled(false);
        jButton3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton3ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(25, 25, 25)
                .addComponent(jButton1)
                .addGap(198, 198, 198)
                .addComponent(jButton2)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 251, Short.MAX_VALUE)
                .addComponent(jButton3, javax.swing.GroupLayout.PREFERRED_SIZE, 125, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(49, 49, 49))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(24, 24, 24)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButton1)
                    .addComponent(jButton2)
                    .addComponent(jButton3))
                .addContainerGap(577, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        try
        {
            rConn = new RConnection("localhost");
            System.out.println("connexion réussie");
            jButton2.setEnabled(true);
            jButton3.setEnabled(true);
        } 
        catch (RserveException ex) 
        {
            Logger.getLogger(ECommerceInterfaceGraphique.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_jButton1ActionPerformed

    // Déménagements
    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed
        try {
            rConn.voidEval("demenagements <-read.table (\"" + GetNomFichier("demenagements.csv") + "\", sep=\";\", header = TRUE)");
            System.out.println("data demenagements récupérées");
            
            rConn.voidEval("jpeg(file=\"" + GetNomFichier("demenagements.jpeg") + "\",width=800, height=700)");
            rConn.voidEval("dev.off()");
            rConn.voidEval("dev.new()");

            rConn.voidEval("boxplot(demenagements)");

            REXP rExp = rConn.eval("summary(demenagements)");
            System.out.println("summary :");
            System.out.println("\tTemps\t\tVolume\t\t\tNombre de grandes pieces");
            RExpPrintSummary(rExp, 3);

            rConn.voidEval("model<-lm(formula = demenagements$Temps ~ demenagements$Volume + demenagements$Nombre.de.grandes.pieces)");

            rConn.voidEval("tmp <- summary(model)");
            rExp = rConn.eval("tmp$coefficients");
            System.out.println("final summary :");
            System.out.println("\tEstimate\t\tStd. Error\t\tt value\t\tPr(>|t|)");
            RExpPrintSummary(rExp, 4);

            rExp = rConn.eval("tmp$adj.r.squared");
            System.out.println("\tAdjusted R Squared : " + rExp.asString());

// p-value to do
            rExp = rConn.eval("tmp$");
            System.out.println("\tp-value : " + "< " + rExp.asString());
        } 
        catch (RserveException ex) {
            Logger.getLogger(ECommerceInterfaceGraphique.class.getName()).log(Level.SEVERE, null, ex);
        }
        catch (REXPMismatchException e) {
            e.printStackTrace();
        }
    }//GEN-LAST:event_jButton2ActionPerformed

    // Civilisation
    private void jButton3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton3ActionPerformed
        try {
            rConn.voidEval("civilisation <-read.table (\"" + GetNomFichier("civilisation.csv") + "\", sep=\";\", header = TRUE)");
            System.out.println("data civilisation récupérées");
            
            rConn.voidEval("jpeg(file=\"" + GetNomFichier("civilisation.jpeg") + "\",width=800, height=700)");
            rConn.voidEval("dev.off()");
            rConn.voidEval("dev.new()");

            rConn.voidEval("plot(civilisation$nbrRecipient~civilisation$civilisation)");

            REXP rExp = rConn.eval("summary(civilisation)");
            System.out.println("summary :");
            System.out.println("\tnbrRecipient\t\tcivilisation");
            RExpPrintSummary(rExp, 2);

            rConn.voidEval("model<-lm(civilisation$nbrRecipient~civilisation$civilisation)");

            rExp = rConn.eval("anova(model)");
            System.out.println(rExp);
            System.out.println("anova - Analysis of Variance Table:");
            //RExpPrintSummary(rExp, 2);

            rExp = rConn.eval("pairwise.t.test(civilisation$nbrRecipient,civilisation$civilisation,p.adjust.method = \"none\",pool.sd =TRUE)");
            System.out.println(rExp);
        } 
        catch (RserveException ex) {
            Logger.getLogger(ECommerceInterfaceGraphique.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_jButton3ActionPerformed



    private void RExpPrintSummary(REXP r, int row) {
        try {
            int size = r.length() / row;
            for(int i = 0; i < size; i++) {
                for(int j = 0; j < row; j++)
                    if(r.asStrings()[i + (j*size)] != null)
                        System.out.print("\t" + r.asStrings()[i + (j*size)]);
                System.out.println("");
            }
        }
        catch (REXPMismatchException e) {
            e.printStackTrace();
        }
    }

    public static String GetNomFichier(String nomf) {
        return System.getProperty("user.dir") + System.getProperty("file.separator") + "Files" + System.getProperty("file.separator") + nomf;
    }



    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JButton jButton3;
    // End of variables declaration//GEN-END:variables
}
