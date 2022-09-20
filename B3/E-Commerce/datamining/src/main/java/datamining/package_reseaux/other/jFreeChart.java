package datamining.package_reseaux.other;

import java.awt.GridLayout;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

import javax.swing.JFrame;

import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.ChartUtils;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.data.category.DefaultCategoryDataset;
import org.jfree.data.general.DefaultPieDataset;
import org.jfree.data.statistics.HistogramDataset;
import org.jfree.data.xy.IntervalXYDataset;
import org.jfree.data.xy.XYSeries;
import org.jfree.data.xy.XYSeriesCollection;



public class jFreeChart extends javax.swing.JFrame {
    public void showPieChart() {
        // 1. Définir un dataset qui contient les data
        //DefaultPieDataset
        DefaultPieDataset ds = new DefaultPieDataset();
        ds.setValue("Parti du progrès contrôlé", 22.36);
        // 2. Se fournir un JFreeChart
        JFreeChart jfc = ChartFactory.createPieChart("Résulats des élections en Boursoulavie en 2008", ds, true, true, true);
        // 3. Fabriquer le Panel
        ChartPanel cp = new ChartPanel(jfc);
        this.getContentPane().setLayout(new GridLayout(2, 1));
        this.getContentPane().add(cp);
    }

    public static void ShowScatterPoint(String title, String x, String y, double[][] dataset) {
        XYSeries serieObs = new XYSeries("Relations " + x + "-" + y);
        for (int i = 0; i < dataset.length; i++)
            serieObs.add(dataset[i][0], dataset[i][1]);
        XYSeriesCollection ds = new XYSeriesCollection();
        ds.addSeries(serieObs);

        DisplayGraph(title, ChartFactory.createScatterPlot(title, y, x, ds, PlotOrientation.VERTICAL, true, true, false));
    }

    public static void ShowHistogram(String title, String x, String y, double[] data, String[] names) {
        HistogramDataset hd = new HistogramDataset();
        //hd.setType(HistogramType.RELATIVE_FREQUENCY);
        hd.addSeries(title, data, names.length);
        
        /*
        XYSeries serieObs = new XYSeries("Relations " + x + "-" + y);
        for (int i = 0; i < 15; i++)
            serieObs.add(dataset[i][1], annees[i]);
        XYSeriesCollection ds = new XYSeriesCollection();
        ds.addSeries(serieObs);
        */

        DisplayGraph(title, ChartFactory.createHistogram(title, y, x, hd, PlotOrientation.VERTICAL, true, true, false));
    }

    public static void DisplayGraph(String title, JFreeChart jfc) {
        JFrame frame = new JFrame();
        frame.add(new ChartPanel(jfc));

        frame.pack();
        frame.setTitle(title);
        frame.setVisible(true);
    }

    public static void SavePng(String title, JFreeChart jfc) {
        try {
            ChartUtils.saveChartAsPNG(new File(GetDirectory.FileDir(title +".png")), jfc, 800, 700);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
