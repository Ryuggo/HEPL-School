using System;

namespace ClassLibrary {
    [Serializable]
    public class Component {
        public string Image { get; set; }
        public string Name { get; set; }
        public int Price { get; set; }
        public TypeComp Type { get; set; }
        public DateTime Date { get; set; }

        public Component() : this("\0", "\0", 0, 0, DateTime.Now) { }
        public Component(string i, string n, int p, TypeComp t, DateTime d) {
            Image = i;
            Name = n;
            Price = p;
            Type = t;
            Date = d;
        }

        public override string ToString() {
            return "Component : " + Image + " - " + Name + " (" + Price + ") " + Type + " - " + Date.Date;
        }

        public void Affiche() {
            Console.WriteLine(this.ToString());
        }
    }

    public enum TypeComp {
        Processor,
        MotherBoard,
        Memory,
        Graphic_Card
    }
}
