using System;

namespace Settings {
    public class OptionEventArg : EventArgs {
        private int _font;
        private int _color;

        public OptionEventArg(int f, int c) {
            Font = f;
            Color = c;
        }

        public int Font {
            get { return _font; }
            set { _font = value; }
        }
        public int Color {
            get { return _color; }
            set { _color = value; }
        }
    }
}