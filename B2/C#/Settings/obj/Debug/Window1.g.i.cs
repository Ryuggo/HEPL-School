// Updated by XamlIntelliSenseFileGenerator 03-04-21 13:47:02
#pragma checksum "..\..\Window1.xaml" "{8829d00f-11b8-4213-878b-770e8597ac16}" "C9FD057AE365A642A461E411E48817D8E865AC9BFFE8AAB5E4E2A4D0017ACA9B"
//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.42000
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

using System;
using System.Diagnostics;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Effects;
using System.Windows.Media.Imaging;
using System.Windows.Media.Media3D;
using System.Windows.Media.TextFormatting;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Shell;


namespace Settings {


    /// <summary>
    /// SettingsWindow
    /// </summary>
    public partial class Window1 : System.Windows.Window, System.Windows.Markup.IComponentConnector {


#line 16 "..\..\Window1.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.StackPanel CouleurGrid;

#line default
#line hidden


#line 17 "..\..\Window1.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBox Background_Color;

#line default
#line hidden


#line 32 "..\..\Window1.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Primitives.ScrollBar Font_Size;

#line default
#line hidden


#line 47 "..\..\Window1.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Grid OkGrid;

#line default
#line hidden


#line 50 "..\..\Window1.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Grid CancelGrid;

#line default
#line hidden


#line 53 "..\..\Window1.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Grid ApplyGrid;

#line default
#line hidden

        private bool _contentLoaded;

        /// <summary>
        /// InitializeComponent
        /// </summary>
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "4.0.0.0")]
        public void InitializeComponent() {
            if (_contentLoaded) {
                return;
            }
            _contentLoaded = true;
            System.Uri resourceLocater = new System.Uri("/Labo4;component/window1.xaml", System.UriKind.Relative);

#line 1 "..\..\Window1.xaml"
            System.Windows.Application.LoadComponent(this, resourceLocater);

#line default
#line hidden
        }

        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "4.0.0.0")]
        [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Never)]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Design", "CA1033:InterfaceMethodsShouldBeCallableByChildTypes")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Maintainability", "CA1502:AvoidExcessiveComplexity")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1800:DoNotCastUnnecessarily")]
        void System.Windows.Markup.IComponentConnector.Connect(int connectionId, object target) {
            switch (connectionId) {
                case 1:
                    this.CouleurGrid = ((System.Windows.Controls.StackPanel)(target));
                    return;
                case 2:
                    this.Background_Color = ((System.Windows.Controls.TextBox)(target));

#line 23 "..\..\Window1.xaml"
                    this.Background_Color.GotFocus += new System.Windows.RoutedEventHandler(this.BackGround_Color_GotFocus);

#line default
#line hidden

#line 23 "..\..\Window1.xaml"
                    this.Background_Color.LostFocus += new System.Windows.RoutedEventHandler(this.BackGround_Color_LostFocus);

#line default
#line hidden
                    return;
                case 3:
                    this.Font_Size = ((System.Windows.Controls.Primitives.ScrollBar)(target));
                    return;
                case 4:
                    this.OkGrid = ((System.Windows.Controls.Grid)(target));
                    return;
                case 5:

#line 48 "..\..\Window1.xaml"
                    ((System.Windows.Controls.Button)(target)).Click += new System.Windows.RoutedEventHandler(this.Ok_Button_Click);

#line default
#line hidden
                    return;
                case 6:
                    this.CancelGrid = ((System.Windows.Controls.Grid)(target));
                    return;
                case 7:

#line 51 "..\..\Window1.xaml"
                    ((System.Windows.Controls.Button)(target)).Click += new System.Windows.RoutedEventHandler(this.Cancel_Button_Click);

#line default
#line hidden
                    return;
                case 8:
                    this.ApplyGrid = ((System.Windows.Controls.Grid)(target));
                    return;
                case 9:

#line 54 "..\..\Window1.xaml"
                    ((System.Windows.Controls.Button)(target)).Click += new System.Windows.RoutedEventHandler(this.Apply_Button_Click);

#line default
#line hidden
                    return;
            }
            this._contentLoaded = true;
        }
    }
}

