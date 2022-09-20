using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Windows;
using System.Windows.Media.Imaging;
using BLL;
using DTO;

namespace WPFSettings
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private BllManager bll = new BllManager();
        private int _id = 2;
        public MainWindow()
        {
            MainWindowBase();
        }
        public MainWindow(int id)
        {
            _id = id;
            MainWindowBase();
        }

        public void MainWindowBase()
        {
            InitializeComponent();
            
            List<FullMovieDTO>? list = bll.GetFullMovieDetailsByIdMovie(_id);
            foreach (var x in list)
            {
                if (x.Movie.PosterPath != "" && !x.Movie.PosterPath.Contains("\"posters\":[]}"))
                    PosterPath.Source = new BitmapImage(new Uri("https://image.tmdb.org/t/p/original" + x.Movie.PosterPath, UriKind.RelativeOrAbsolute));
                else
                    PosterPath.Source = new BitmapImage(new Uri("https://d3aa3603f5de3f81cb9fdaa5c591a84d5723e3cb.hosting4cdn.com/wp-content/uploads/2020/11/404-poster-not-found-CG17701-1.png", UriKind.RelativeOrAbsolute));

                OriginalTitle.Content = x.Movie.OriginalTitle;
                Title.Content = x.Movie.Title;
                ReleaseDate.Content = x.Movie.ReleaseDate.ToString("MM-dd-yyyy");

                int runtime = Int32.Parse(x.Movie.Runtime);
                int minute = runtime % 60;
                int hour = 0;
                while (runtime > 59)
                {
                    runtime -= 60;
                    hour++;
                }
                Runtime.Content += hour + "h " + minute;

                Status.Content += x.Movie.Status;
                VoteAverage.Content += x.Movie.VoteAverage.ToString();
                VoteCount.Content += x.Movie.VoteCount.ToString();
                Certification.Content += x.Movie.Certification;
                Budget.Content += x.Movie.Budget.ToString();
                Tagline.Content += x.Movie.Tagline;

                foreach (var y in x.Actors) Actors.Items.Add(y.Name);
                foreach (var y in x.Types) Types.Items.Add(y.Name);
                break;
            }
            
            RefreshList();
        }

        public void Click_Valid_Comment(object sender, RoutedEventArgs e)
        {
            CommentDTO com = (CommentDTO)CommentsDG.SelectedItem;
            if(com == null) return;
            bll.ValidateCommentById(com.IdComment, !com.Validate);
            RefreshList();
        }
        public void Click_Delete_Comment(object sender, RoutedEventArgs e)
        {
            CommentDTO com = (CommentDTO)CommentsDG.SelectedItem;
            if (com == null) return;
            bll.DeleteCommentById(com.IdComment);
            RefreshList();
        }
        public void Click_Modify_Comment(object sender, RoutedEventArgs e)
        {
            CommentDTO com = (CommentDTO)CommentsDG.SelectedItem;
            if (com == null) return;
            bll.UpdateCommentById(com.IdComment, TComment.Text);
            RefreshList();
        }

        private void CommentsDG_SelectionChanged(object sender, System.Windows.Controls.SelectionChangedEventArgs e)
        {
            CommentDTO com = (CommentDTO)CommentsDG.SelectedItem;
            if (com == null) return;
            TComment.Text = com.Text;
        }

        public void RefreshList()
        {
            List<CommentDTO>? LComment = bll.GetCommentsOnMovieId(_id);
            
            ObservableCollection<CommentDTO> listComment = new ObservableCollection<CommentDTO>();
            foreach (var x in LComment)
                listComment.Add(x);

            CommentsDG.ItemsSource = listComment;
        }
    }
}