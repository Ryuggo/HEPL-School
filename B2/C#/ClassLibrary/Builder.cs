using System;
using System.Collections.ObjectModel;

namespace ClassLibrary {
    [Serializable]
    public class Builder {
        public string Name { get; set; }
        public ObservableCollection<Model> Models { get; set; }
        public ObservableCollection<Component> Components { get; set; }

        public Builder() : this("\0", new ObservableCollection<Model>(), new ObservableCollection<Component>()) { }
        public Builder(string n, ObservableCollection<Model> m, ObservableCollection<Component> c) {
            Name = n;
            Models = m;
            Components = c;
        }
    }
}
