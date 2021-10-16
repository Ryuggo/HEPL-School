using ClassLibrary;
using Microsoft.Win32;
using System;
using System.IO;
using System.Windows;
using System.Windows.Input;
using System.Windows.Media;

namespace AddComponent {
    public partial class AddComponentWindow : Window {
        public string filePath = string.Empty;

        public AddComponentWindow() {
            InitializeComponent();

            Comp = new Component();
            NameText.Text = "";
        }
        public AddComponentWindow(int b, int f) {
            InitializeComponent();

            Comp = new Component();
            NameText.Text = "";

            var bc = new BrushConverter();
            if (b == 1) {
                Window.Background = (Brush)bc.ConvertFrom("#181735");
                Window.Foreground = (Brush)bc.ConvertFrom("#ffffff");
            } else {
                Window.Background = (Brush)bc.ConvertFrom("#ffffff");
                Window.Foreground = (Brush)bc.ConvertFrom("#000000");
            }
            Window.FontSize = f;
        }

        public Component Comp { get; set; }


        // Windows Close, Minimize and Drag
        private void Window_Drag_MouseDown(object sender, MouseButtonEventArgs e) {
            if (e.LeftButton == MouseButtonState.Pressed)
                DragMove();
        }

        private void Close_Button_Click(object sender, RoutedEventArgs e) {
            Comp.Name = "NONE";
            this.Close();
        }


        // Settings Final Buttons
        private void Ok_Button_Click(object sender, RoutedEventArgs e) {
            if (AddComp.DataContext is Component c) {
                Boolean check = true;
                var bc = new BrushConverter();

                if (String.IsNullOrWhiteSpace(NameText.Text) == true) {
                    check = false;
                    NameColor.Background = (Brush)bc.ConvertFrom("DarkRed");
                } else
                    NameColor.Background = (Brush)bc.ConvertFrom("#181735");

                if (String.IsNullOrWhiteSpace(filePath) == true)
                    c.Image = "NONE";
                else
                    c.Image = filePath;

                if (c.Price <= 0) {
                    check = false;
                    PriceColor.Background = (Brush)bc.ConvertFrom("DarkRed");
                } else
                    PriceColor.Background = (Brush)bc.ConvertFrom("#181735");

                if (check == true) {
                    Comp = c;
                    Comp.Date = DatePicker.SelectedDate.Value.Date;
                    this.Close();
                }
            }
        }

        private void Cancel_Button_Click(object sender, RoutedEventArgs e) {
            Comp.Name = "NONE";
            this.Close();
        }

        private void Image_Click(object sender, RoutedEventArgs e) {
            var fileContent = string.Empty;

            OpenFileDialog openFileDialog = new OpenFileDialog();
            //openFileDialog.InitialDirectory = "c:\\";
            openFileDialog.Filter = "Image Files (JPG, PNG, BMP)|*.jpg; *.jpeg; *.png; *.bmp|Gif Files|*.gif|All files (*.*)|*.*";
            openFileDialog.FilterIndex = 1;
            openFileDialog.RestoreDirectory = true;

            if ((bool)openFileDialog.ShowDialog()) {
                //Get the path of specified file
                filePath = openFileDialog.FileName;

                //Read the contents of the file into a stream
                var fileStream = openFileDialog.OpenFile();

                using (StreamReader reader = new StreamReader(fileStream)) {
                    fileContent = reader.ReadToEnd();
                }
            }
        }
    }
}
