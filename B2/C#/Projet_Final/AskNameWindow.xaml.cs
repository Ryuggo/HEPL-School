using System.Windows;
using System.Windows.Media;

namespace Projet_Final {
    public partial class AskNameWindow : Window {
        public AskNameWindow() {
            InitializeComponent();
            UserName = null;
        }
        public AskNameWindow(int b, int f) {
            InitializeComponent();
            UserName = null;

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
        public string UserName { get; set; }


        // Settings Final Buttons
        private void Ok_Button_Click(object sender, RoutedEventArgs e) {
            UserName = UserNameText.Text;
            this.Close();
        }
        private void Cancel_Button_Click(object sender, RoutedEventArgs e) {
            this.Close();
        }
    }
}
