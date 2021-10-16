using ClassLibrary;
using AddComponent;
using Settings;
using System;
using System.Windows;
using System.Windows.Input;
using System.Windows.Media;
using System.Collections.ObjectModel;
using System.Windows.Media.Imaging;
using Microsoft.Win32;
using System.Runtime.Serialization.Formatters.Binary;
using System.IO;

namespace Projet_Final {
    public partial class MainWindow : Window {
        private ObservableCollection<Component> TmpComponents = new ObservableCollection<Component>();
        private Builder Account;
        public SettingsManager Settings = new SettingsManager();

        //private string filePath = string.Empty;


        public MainWindow() {
            InitializeComponent();

            Settings.Load_Settings();
            setBackground();
            setFont();

            Init();

            DG_Computer.ItemsSource = Account.Models;
            DG_Component.ItemsSource = Account.Components;
        }

        private void Init() {
            Account = new Builder();

            Account.Components.Add(new Component("Images/CPU.png", "Intel Core i3-10100 (3.6GHz - 4.3)", 134, (TypeComp)Enum.Parse(typeof(TypeComp), "Processor"), new DateTime(2020, 4, 1, 0, 0, 0)));
            Account.Components.Add(new Component("Images/CPU.png", "Intel Core i3-10300 (3.7GHz - 4.4)", 299, (TypeComp)Enum.Parse(typeof(TypeComp), "Processor"), new DateTime(2020, 4, 1, 0, 0, 0)));
            Account.Components.Add(new Component("Images/CPU.png", "Intel Core i5-10400 (2.9GHz - 4.3)", 179, (TypeComp)Enum.Parse(typeof(TypeComp), "Processor"), new DateTime(2020, 4, 1, 0, 0, 0)));
            Account.Components.Add(new Component("Images/CPU.png", "Intel Core i5-10500 (3.1GHz - 4.5)", 219, (TypeComp)Enum.Parse(typeof(TypeComp), "Processor"), new DateTime(2020, 4, 1, 0, 0, 0)));
            Account.Components.Add(new Component("Images/CPU.png", "Intel Core i5-10600 (3.3GHz - 4.8)", 234, (TypeComp)Enum.Parse(typeof(TypeComp), "Processor"), new DateTime(2020, 4, 1, 0, 0, 0)));
            Account.Components.Add(new Component("Images/CPU.png", "Intel Core i7-10700 (2.9GHz - 4.8)", 384, (TypeComp)Enum.Parse(typeof(TypeComp), "Processor"), new DateTime(2020, 4, 1, 0, 0, 0)));
            Account.Components.Add(new Component("Images/CPU.png", "Intel Core i9-10900 (2.8GHz - 5.2)", 459, (TypeComp)Enum.Parse(typeof(TypeComp), "Processor"), new DateTime(2020, 4, 1, 0, 0, 0)));

            Account.Components.Add(new Component("Images/Mobo.png", "Asus H410", 128, (TypeComp)Enum.Parse(typeof(TypeComp), "MotherBoard"), new DateTime(2020, 4, 1, 0, 0, 0)));
            Account.Components.Add(new Component("Images/Mobo.png", "MSI B460", 82, (TypeComp)Enum.Parse(typeof(TypeComp), "MotherBoard"), new DateTime(2020, 4, 1, 0, 0, 0)));
            Account.Components.Add(new Component("Images/Mobo.png", "Asus H470", 69, (TypeComp)Enum.Parse(typeof(TypeComp), "MotherBoard"), new DateTime(2020, 4, 1, 0, 0, 0)));
            Account.Components.Add(new Component("Images/Mobo.png", "Asus Q470", 79, (TypeComp)Enum.Parse(typeof(TypeComp), "MotherBoard"), new DateTime(2020, 4, 1, 0, 0, 0)));
            Account.Components.Add(new Component("Images/Mobo.png", "MSI Z490", 109, (TypeComp)Enum.Parse(typeof(TypeComp), "MotherBoard"), new DateTime(2020, 4, 1, 0, 0, 0)));
            Account.Components.Add(new Component("Images/Mobo.png", "MSI A520", 104, (TypeComp)Enum.Parse(typeof(TypeComp), "MotherBoard"), new DateTime(2021, 1, 1, 0, 0, 0)));
            Account.Components.Add(new Component("Images/Mobo.png", "Asus H510", 84, (TypeComp)Enum.Parse(typeof(TypeComp), "MotherBoard"), new DateTime(2021, 1, 1, 0, 0, 0)));
            Account.Components.Add(new Component("Images/Mobo.png", "Asus B560", 139, (TypeComp)Enum.Parse(typeof(TypeComp), "MotherBoard"), new DateTime(2021, 1, 1, 0, 0, 0)));
            Account.Components.Add(new Component("Images/Mobo.png", "MSI H570", 139, (TypeComp)Enum.Parse(typeof(TypeComp), "MotherBoard"), new DateTime(2021, 1, 1, 0, 0, 0)));
            Account.Components.Add(new Component("Images/Mobo.png", "MSI Z590", 189, (TypeComp)Enum.Parse(typeof(TypeComp), "MotherBoard"), new DateTime(2021, 1, 1, 0, 0, 0)));

            Account.Components.Add(new Component("Images/Memory.png", "4Go - 2666MHz", 34, (TypeComp)Enum.Parse(typeof(TypeComp), "Memory"), new DateTime(2020, 4, 1, 0, 0, 0)));
            Account.Components.Add(new Component("Images/Memory.png", "2x 4Go - 3000MHz", 64, (TypeComp)Enum.Parse(typeof(TypeComp), "Memory"), new DateTime(2020, 4, 1, 0, 0, 0)));
            Account.Components.Add(new Component("Images/Memory.png", "8Go - 3200MHz", 44, (TypeComp)Enum.Parse(typeof(TypeComp), "Memory"), new DateTime(2020, 4, 1, 0, 0, 0)));
            Account.Components.Add(new Component("Images/Memory.png", "4x 4Go - 2666MHz", 134, (TypeComp)Enum.Parse(typeof(TypeComp), "Memory"), new DateTime(2020, 4, 1, 0, 0, 0)));
            Account.Components.Add(new Component("Images/Memory.png", "2x 8Go - 3000MHz", 89, (TypeComp)Enum.Parse(typeof(TypeComp), "Memory"), new DateTime(2020, 4, 1, 0, 0, 0)));
            Account.Components.Add(new Component("Images/Memory.png", "16Go - 3200MHz", 124, (TypeComp)Enum.Parse(typeof(TypeComp), "Memory"), new DateTime(2020, 4, 1, 0, 0, 0)));
            Account.Components.Add(new Component("Images/Memory.png", "4x 8Go - 2666MHz", 214, (TypeComp)Enum.Parse(typeof(TypeComp), "Memory"), new DateTime(2020, 4, 1, 0, 0, 0)));
            Account.Components.Add(new Component("Images/Memory.png", "2x 16Go - 3000MHz", 195, (TypeComp)Enum.Parse(typeof(TypeComp), "Memory"), new DateTime(2020, 4, 1, 0, 0, 0)));
            Account.Components.Add(new Component("Images/Memory.png", "32Go - 3200MHz", 199, (TypeComp)Enum.Parse(typeof(TypeComp), "Memory"), new DateTime(2020, 4, 1, 0, 0, 0)));

            Account.Components.Add(new Component("Images/GPU.png", "GeForce GTX 1060", 299, (TypeComp)Enum.Parse(typeof(TypeComp), "Graphic_Card"), new DateTime(2017, 4, 20, 0, 0, 0)));
            Account.Components.Add(new Component("Images/GPU.png", "GeForce GTX 1070", 449, (TypeComp)Enum.Parse(typeof(TypeComp), "Graphic_Card"), new DateTime(2016, 6, 10, 0, 0, 0)));
            Account.Components.Add(new Component("Images/GPU.png", "GeForce GTX 1080", 549, (TypeComp)Enum.Parse(typeof(TypeComp), "Graphic_Card"), new DateTime(2017, 4, 20, 0, 0, 0)));
            Account.Components.Add(new Component("Images/GPU.png", "GeForce RTX 2060 Super", 399, (TypeComp)Enum.Parse(typeof(TypeComp), "Graphic_Card"), new DateTime(2019, 7, 9, 0, 0, 0)));
            Account.Components.Add(new Component("Images/GPU.png", "GeForce RTX 2070 Super", 499, (TypeComp)Enum.Parse(typeof(TypeComp), "Graphic_Card"), new DateTime(2019, 7, 9, 0, 0, 0)));
            Account.Components.Add(new Component("Images/GPU.png", "GeForce RTX 2080 Super", 699, (TypeComp)Enum.Parse(typeof(TypeComp), "Graphic_Card"), new DateTime(2019, 7, 23, 0, 0, 0)));
            Account.Components.Add(new Component("Images/GPU.png", "GeForce RTX 3060 Super", 329, (TypeComp)Enum.Parse(typeof(TypeComp), "Graphic_Card"), new DateTime(2021, 2, 25, 0, 0, 0)));
            Account.Components.Add(new Component("Images/GPU.png", "GeForce RTX 3070 Super", 499, (TypeComp)Enum.Parse(typeof(TypeComp), "Graphic_Card"), new DateTime(2020, 10, 29, 0, 0, 0)));
            Account.Components.Add(new Component("Images/GPU.png", "GeForce RTX 3080 Super", 699, (TypeComp)Enum.Parse(typeof(TypeComp), "Graphic_Card"), new DateTime(2020, 9, 17, 0, 0, 0)));
            Account.Components.Add(new Component("Images/GPU.png", "GeForce RTX 3090 Super", 1499, (TypeComp)Enum.Parse(typeof(TypeComp), "Graphic_Card"), new DateTime(2020, 9, 24, 0, 0, 0)));
        }

        // Account Settings
        private void Account_New_Click(object sender, RoutedEventArgs e) {
            AskNameWindow ask_user_window = new AskNameWindow(Settings.Background, Settings.Font);

            ask_user_window.ShowDialog(); // modal window

            Account.Name = ask_user_window.UserName;
            if (Account.Name != null)
                Account_Name.Text = Account.Name;

            Account = new Builder();
            //DG_Computer.ItemsSource = ;
        }
        private void Account_Load_Click(object sender, RoutedEventArgs e) {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            RegistryKey rk = Registry.CurrentUser.OpenSubKey("CSharp Projet Final");

            openFileDialog.InitialDirectory = (string)rk.GetValue("Saves") + "\\";
            openFileDialog.Filter = "Data File (dat)|*.dat|All files (*.*)|*.*";
            openFileDialog.FilterIndex = 1;
            openFileDialog.ShowDialog();
            Path.GetFileNameWithoutExtension(openFileDialog.FileName);

            if(String.IsNullOrWhiteSpace(openFileDialog.FileName) == false) {
                BinaryFormatter binFormat = new BinaryFormatter();

                try {
                    using (Stream fStream = File.OpenRead((string)rk.GetValue("Saves") + "\\" + openFileDialog.SafeFileName)) {
                        Account = new Builder();
                        Account = (Builder)binFormat.Deserialize(fStream);

                        DG_Computer.ItemsSource = Account.Models;
                        DG_Component.ItemsSource = Account.Components;
                        Account_Name.Text = Account.Name;

                        Rm_Cpu_Click(null, null);
                        Rm_Mobo_Click(null, null);
                        Rm_Ram_Click(null, null);
                        Rm_Gpu_Click(null, null);
                    }
                } catch (FileNotFoundException error) {
                    Console.WriteLine(error.Message);
                }
            }
        }
        private void Account_Save_Click(object sender, RoutedEventArgs e) {
            BinaryFormatter binFormat = new BinaryFormatter();
            RegistryKey rk = Registry.CurrentUser.OpenSubKey("CSharp Projet Final");

            using (Stream fStream = new FileStream((string)rk.GetValue("Saves") + "\\" + Account.Name + ".dat", FileMode.Create, FileAccess.Write, FileShare.None))
                binFormat.Serialize(fStream, Account);
        }


        // Components Click
        private void Component_Select(object sender, MouseButtonEventArgs e) {
            Component row = (Component)DG_Component.SelectedItem;

            switch (Convert.ToString(row.Type)) {
                case "Processor":
                    if (Convert.ToString(row.Image).Equals("Images/CPU.png") == true)
                        row.Image = "pack://application:,,,/Images/CPU.png";
                    Cpu_Image.Source = new BitmapImage(new Uri(row.Image));

                    Cpu_Name.Text = row.Name;
                    Cpu_Data.Text = row.Price + "   (" + row.Date.ToString("d") + ")";

                    for (int i = 0; i < TmpComponents.Count; i++)
                        if (Convert.ToString(TmpComponents[i].Type).Equals("Processor"))
                            TmpComponents.Remove(TmpComponents[i]);
                    TmpComponents.Add(row);

                    break;
                case "MotherBoard":
                    if (Convert.ToString(row.Image).Equals("Images/Mobo.png") == true)
                        row.Image = "pack://application:,,,/Images/Mobo.png";
                    Mobo_Image.Source = new BitmapImage(new Uri(row.Image));

                    Mobo_Name.Text = row.Name;
                    Mobo_Data.Text = row.Price + "   (" + row.Date.ToString("d") + ")";

                    for (int i = 0; i < TmpComponents.Count; i++)
                        if (Convert.ToString(TmpComponents[i].Type).Equals("MotherBoard"))
                            TmpComponents.Remove(TmpComponents[i]);
                    TmpComponents.Add(row);

                    break;
                case "Memory":
                    if (Convert.ToString(row.Image).Equals("Images/Memory.png") == true)
                        row.Image = "pack://application:,,,/Images/Memory.png";
                    Ram_Image.Source = new BitmapImage(new Uri(row.Image));

                    Ram_Name.Text = row.Name;
                    Ram_Data.Text = row.Price + "   (" + row.Date.ToString("d") + ")";

                    for (int i = 0; i < TmpComponents.Count; i++)
                        if (Convert.ToString(TmpComponents[i].Type).Equals("Memory"))
                            TmpComponents.Remove(TmpComponents[i]);
                    TmpComponents.Add(row);

                    break;
                case "Graphic_Card":
                    if (Convert.ToString(row.Image).Equals("Images/GPU.png") == true)
                        row.Image = "pack://application:,,,/Images/GPU.png";
                    Gpu_Image.Source = new BitmapImage(new Uri(row.Image));

                    Gpu_Name.Text = row.Name;
                    Gpu_Data.Text = row.Price + "   (" + row.Date.ToString("d") + ")";

                    for (int i = 0; i < TmpComponents.Count; i++)
                        if (Convert.ToString(TmpComponents[i].Type).Equals("Graphic_Card"))
                            TmpComponents.Remove(TmpComponents[i]);
                    TmpComponents.Add(row);

                    break;
                default:
                    break;
            }
        }

        private void Component_Option(object sender, MouseButtonEventArgs e) {
            Component row = (Component)DG_Component.SelectedItem;
            Account.Components.Remove(row);
        }


        // Computer Click
        private void Computer_Option(object sender, MouseButtonEventArgs e) {
            Model row = (Model)DG_Computer.SelectedItem;
            Account.Models.Remove(row);
        }


        // Windows Close, Minimize and Drag
        private void Window_Drag_MouseDown(object sender, MouseButtonEventArgs e) {
            if (e.LeftButton == MouseButtonState.Pressed)
                DragMove();
        }
        private void Close_Button_Click(object sender, RoutedEventArgs e) {
            this.Close();
        }
        private void FullScreen_Button_Click(object sender, RoutedEventArgs e) {
            if (this.WindowState != WindowState.Maximized)
                this.WindowState = WindowState.Maximized;
            else
                this.WindowState = WindowState.Normal;
        }
        private void Minimize_Button_Click(object sender, RoutedEventArgs e) {
            this.WindowState = WindowState.Minimized;
        }


        // Settings Window
        private void Settings_Button_Click(object sender, RoutedEventArgs e) {
            SettingsWindow settings_window = new SettingsWindow(Settings.Background, Settings.Font);

            settings_window.ColorMode_C += EditColorMode;
            settings_window.Font_S += EditFontSize;

            settings_window.Show();
        }

        public void EditColorMode(object sender, OptionEventArg e) {
            Settings.Background = e.Color;
            setBackground();
            Settings.Save_Settings();
        }
        public void EditFontSize(object sender, OptionEventArg e) {
            Settings.Font = e.Font;
            setFont();
            Settings.Save_Settings();
        }

        public void setBackground() {
            var bc = new BrushConverter();

            if (Settings.Background == 1) {
                Window.Background = (Brush)bc.ConvertFrom("#181735");
                Window.Foreground = (Brush)bc.ConvertFrom("#ffffff");
            } else {
                Window.Background = (Brush)bc.ConvertFrom("#ffffff");
                Window.Foreground = (Brush)bc.ConvertFrom("#000000");
            }
        }
        public void setFont() {
            Window.FontSize = Settings.Font;
        }


        // Component Add Window
        private void Add_Component_Click(object sender, RoutedEventArgs e) {
            AddComponentWindow add_component_window = new AddComponentWindow(Settings.Background, Settings.Font);

            add_component_window.ShowDialog(); // modal window

            Component Comp = add_component_window.Comp;
            if (Comp.Name != "NONE") {
                if (Comp.Image.Equals("NONE")) {
                    switch (Convert.ToString(Comp.Type)) {
                        case "Processor":
                            Comp.Image = "pack://application:,,,/Images/CPU.png";
                            break;
                        case "MotherBoard":
                            Comp.Image = "pack://application:,,,/Images/Mobo.png";
                            break;
                        case "Memory":
                            Comp.Image = "pack://application:,,,/Images/Memory.png";
                            break;
                        case "Graphic_Card":
                            Comp.Image = "pack://application:,,,/Images/GPU.png";
                            break;
                    }
                }
                Account.Components.Add(Comp);
            }
        }


        // Computer Add
        private void Add_Model_Click(object sender, RoutedEventArgs e) {
            Model Mod = new Model();

            if (String.IsNullOrWhiteSpace(ComputerName.Text) == false && TmpComponents.Count == 4) {
                Mod.Name = ComputerName.Text;

                for (int i = 0; i < TmpComponents.Count; i++)
                    Mod.TotalPrice += TmpComponents[i].Price;

                Mod.Components = TmpComponents;

                Account.Models.Add(Mod);
            }
        }


        // Remove Component
        private void Rm_Cpu_Click(object sender, RoutedEventArgs e) {
            Cpu_Image.Source = new BitmapImage(new Uri("pack://application:,,,/Images/CPU.png"));
            Cpu_Name.Text = "Processor";
            Cpu_Data.Text = "Data";

            for (int i = 0; i < TmpComponents.Count; i++)
                if (Convert.ToString(TmpComponents[i].Type).Equals("Processor"))
                    TmpComponents.Remove(TmpComponents[i]);
        }
        private void Rm_Mobo_Click(object sender, RoutedEventArgs e) {
            Mobo_Image.Source = new BitmapImage(new Uri("pack://application:,,,/Images/Mobo.png"));
            Mobo_Name.Text = "MotherBoard";
            Mobo_Data.Text = "Data";

            for (int i = 0; i < TmpComponents.Count; i++)
                if (Convert.ToString(TmpComponents[i].Type).Equals("MotherBoard"))
                    TmpComponents.Remove(TmpComponents[i]);
        }
        private void Rm_Ram_Click(object sender, RoutedEventArgs e) {
            Ram_Image.Source = new BitmapImage(new Uri("pack://application:,,,/Images/Memory.png"));
            Ram_Name.Text = "Memory";
            Ram_Data.Text = "Data";

            for (int i = 0; i < TmpComponents.Count; i++)
                if (Convert.ToString(TmpComponents[i].Type).Equals("Memory"))
                    TmpComponents.Remove(TmpComponents[i]);
        }
        private void Rm_Gpu_Click(object sender, RoutedEventArgs e) {
            Gpu_Image.Source = new BitmapImage(new Uri("pack://application:,,,/Images/GPU.png"));
            Gpu_Name.Text = "Graphic Card";
            Gpu_Data.Text = "Data";

            for (int i = 0; i < TmpComponents.Count; i++)
                if (Convert.ToString(TmpComponents[i].Type).Equals("Graphic_Card"))
                    TmpComponents.Remove(TmpComponents[i]);
        }
    }
}
