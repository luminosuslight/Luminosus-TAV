using System;
using System.Collections.Generic;
using System.Text;

namespace MatrixVerification
{
    public class Matrix
    {
        #region props
        #endregion

        #region public methods
        public void HsvToRgb(float h, float s, float v, out float r, out float g, out float b)
        {
            r = 0;
            g = 0;
            b = 0;

            if (s == 0)
            {
                r = g = b = v;
                return;
            }

            float f, p, q, t;
            int i = (int)(h * 6);
            f = (h * 6) - i;
            p = v * (1 - s);
            q = v * (1 - s * f);
            t = v * (1 - s * (1 - f));
            i = i % 6;
            switch (i)
            {
                case 0:
                    {
                        r = v;
                        g = t;
                        b = p;
                        break;
                    }
                case 1:
                    {
                        r = q;
                        g = v;
                        b = p;
                        break;
                    }
                case 2:
                    {
                        r = p;
                        g = v;
                        b = t;
                        break;
                    }
                case 3:
                    {
                        r = p;
                        g = q;
                        b = v;
                        break;
                    }
                case 4:
                    {
                        r = t;
                        g = p;
                        b = v;
                        break;
                    }
                case 5:
                    {
                        r = v;
                        g = p;
                        b = q;
                        break;
                    }
                default:
                    {
                        r = 0;
                        g = 0;
                        b = 0;
                        break;
                    }
            }
        }
        #endregion

        #region ctor
        #endregion

        #region private members
        #endregion

        #region private methods
        #endregion
    }
}
