using System;
using System.Collections.ObjectModel;

namespace ClassLibrary {
    [Serializable]
    public class Model {
        public string Name { get; set; }
        public int TotalPrice { get; set; }
        public ObservableCollection<Component> Components { get; set; }

        public Model() : this("\0", 0, null) { }
        public Model(string n, int p, ObservableCollection<Component> c) {
            Name = n;
            TotalPrice = p;
            Components = c;
        }
    }
}