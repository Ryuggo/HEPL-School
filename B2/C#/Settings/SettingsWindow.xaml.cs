using Microsoft.Win32;
using System;
using System.IO;
using System.Windows;
using System.Windows.Input;
using System.Windows.Media;

namespace Settings {
    public partial class SettingsWindow : Window {
        public delegate void OptionHandler(object sender, OptionEventArg e);

        public event OptionHandler ColorMode_C;
        public event OptionHandler Font_S;

        public int ColorMode = 1;

        public SettingsWindow() {
            InitializeComponent();
        }
        public SettingsWindow(int b, int f) {
            InitializeComponent();

            ColorMode = b;
            var bc = new BrushConverter();
            if (ColorMode == 1) {
                Window.Background = (Brush)bc.ConvertFrom("#181735");
                Window.Foreground = (Brush)bc.ConvertFrom("#ffffff");
            } else {
                Window.Background = (Brush)bc.ConvertFrom("#ffffff");
                Window.Foreground = (Brush)bc.ConvertFrom("#000000");
            }
            Font_Size.Value = f;
        }

        // Windows Close, Minimize and Drag
        private void Window_Drag_MouseDown(object sender, MouseButtonEventArgs e) {
            if (e.LeftButton == MouseButtonState.Pressed)
                DragMove();
        }

        private void Close_Button_Click(object sender, RoutedEventArgs e) {
            this.Close();
        }


        // Settings Final Buttons
        private void Ok_Button_Click(object sender, RoutedEventArgs e) {
            try {
                int fs = Convert.ToInt32(Font_Size.Value);

                ColorMode_C?.Invoke(this, new OptionEventArg(-1, ColorMode));
                Font_S?.Invoke(this, new OptionEventArg(fs, -1));
            } catch (Exception exc) {
                MessageBox.Show("Value Error : " + exc.Message);
            }
            this.Close();
        }

        private void Cancel_Button_Click(object sender, RoutedEventArgs e) {
            this.Close();
        }

        private void Apply_Button_Click(object sender, RoutedEventArgs e) {
            try {
                int fs = Convert.ToInt32(Font_Size.Value);

                ColorMode_C?.Invoke(this, new OptionEventArg(-1, ColorMode));
                Font_S?.Invoke(this, new OptionEventArg(fs, -1));
            } catch (Exception exc) {
                MessageBox.Show("Value Error : " + exc.Message);
            }
        }

        private void ColorMode_Button_Click(object sender, RoutedEventArgs e) {
            var bc = new BrushConverter();
            if (ColorMode == 0) {
                ColorMode = 1;
                Window.Background = (Brush)bc.ConvertFrom("#181735");
                Window.Foreground = (Brush)bc.ConvertFrom("#ffffff");
            } else {
                ColorMode = 0;
                Window.Background = (Brush)bc.ConvertFrom("#ffffff");
                Window.Foreground = (Brush)bc.ConvertFrom("#000000");
            }
        }


        private string filePath = string.Empty;
        private void Folder_Click(object sender, RoutedEventArgs e) {
            OpenFileDialog openFileDialog = new OpenFileDialog();

            openFileDialog.ValidateNames = false;
            openFileDialog.CheckFileExists = false;
            openFileDialog.CheckPathExists = true;
            openFileDialog.FileName = "Folder Selection.";

            if ((bool)openFileDialog.ShowDialog()) {
                filePath = Path.GetDirectoryName(openFileDialog.FileName);
                RegistryKey rk = Registry.CurrentUser.CreateSubKey("CSharp Projet Final");
                rk.SetValue("Saves", filePath);
                rk.SetValue("BackGround", ColorMode);
                rk.SetValue("Font", Convert.ToInt32(Font_Size.Value));
            }
        }
    }
}
