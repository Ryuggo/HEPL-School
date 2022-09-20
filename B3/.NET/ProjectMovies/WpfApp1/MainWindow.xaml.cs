using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Windows;
using BLL;
using DTO;

namespace WPFMain
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private BllManager bll = new BllManager();
        private int pos = 0;
        private int posSearch = 0;
        private int pagination = 100;
        private int paginationDisplay = 10;
        private List<MovieDTO>? listLoaded = new List<MovieDTO>();


        public MainWindow()
        {
            InitializeComponent();

            listLoaded = bll.FindListMovie(pos, pagination);
            RefreshList();
        }
        
        private void Button_Search_Click(object sender, RoutedEventArgs e)
        {
            posSearch = pos = 0;
            SearchList();
            RefreshList();
        }

        private void Button_View_Click(object sender, RoutedEventArgs e)
        {
            MovieDTO m = (MovieDTO)MovieDG.SelectedItem;
            WPFSettings.MainWindow moreInformation = new WPFSettings.MainWindow(m.IdMovie);
            moreInformation.ShowDialog();
        }

        private void Button_Next_Click(object sender, RoutedEventArgs e)
        {
            if (listLoaded.Count == 100 || pos < listLoaded.Count - 10)
                pos += 10;
            if (pos % 100 == 0 && pos != 0)
            {
                posSearch += 100;
                pos = 0;
                SearchList();
            }
            RefreshList();
        }

        private void Button_Previous_Click(object sender, RoutedEventArgs e)
        {
            pos = pos < 10 ? 0 : pos - 10;
            if (pos % 100 == 0 && pos != 0)
            {
                posSearch -= 100;
                pos = 90;
                SearchList();
            }
            RefreshList();
        }

        private void SearchList()
        {
            try
            {
                string txt = TBSearchMovie.Text.Trim();
                if (txt == "")
                {
                    listLoaded = bll.FindListMovie(posSearch, pagination);
                }
                else
                {
                    listLoaded = new List<MovieDTO>();
                    
                    listLoaded = bll.SearchOrAnd(txt, posSearch, pagination);
                }
            }
            catch (Exception ex)
            {
                Console.Error.WriteLine(ex.Message);
                listLoaded = bll.FindListMovie(posSearch, pagination);
            }
        }
        

        public void RefreshList()
        {
            ObservableCollection<MovieDTO> listCollec = new ObservableCollection<MovieDTO>();
            int i = 0;
            foreach (var x in listLoaded.Skip(pos))
            {
                if(int.TryParse(x.Runtime, out _))
                {
                    int runtime = Int32.Parse(x.Runtime);
                    int minute = runtime % 60;
                    int hour = 0;
                    while (runtime > 59)
                    {
                        runtime -= 60;
                        hour++;
                    }
                    x.Runtime = hour + "h " + minute;
                }

                listCollec.Add(x);
                i++;
                if (i >= paginationDisplay)
                    break;
            }
            MovieDG.ItemsSource = listCollec;

            btnPrevious.IsEnabled = !(pos == 0);
            btnNext.IsEnabled = (pos < listLoaded.Count - 10);
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("You can use '&', '|', '!' to make better search on movie and actors." +
                "\n\n    '&' : merges multiple requirement for the search." +
                "\n    '|'   : allows multiple search in one go." +
                "\n    '!'   : removes unwanted tag. It needs to be at the end." +
                "\nYou can have multiple reject, simply separe them with ','" +
                "\n\nEx: potter&harr|pirates|rooms!fire,stone");
        }
    }
}