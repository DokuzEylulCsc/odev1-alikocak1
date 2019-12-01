using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace aliKocak2018280031
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text == "")
            {
                MessageBox.Show("Lütfen sayı giriniz!!!");
            }
            int arabicNumber;
            arabicNumber = Convert.ToInt16(textBox1.Text);
            if (arabicNumber == 0 || arabicNumber > 3999)
            {
                MessageBox.Show("Lütfen 1-3999 arasında değer giriniz!!!");
                textBox1.Clear();
            }
            int birler = 0, onlar = 0, yüzler = 0, binler = 0;
            if (arabicNumber < 10)
            {
                birler = arabicNumber;
            }
            else if (arabicNumber >= 10 && arabicNumber < 100)
            {
                birler = arabicNumber % 10;
                onlar = arabicNumber / 10;
            }
            else if (arabicNumber >= 100 && arabicNumber < 1000)
            {
                birler = arabicNumber % 10;
                onlar = (arabicNumber % 100) / 10;
                yüzler = (arabicNumber / 100);
            }
            else
            {
                birler = arabicNumber % 10;
                onlar = (arabicNumber % 100) / 10;
                yüzler = (arabicNumber % 1000) / 100;
                binler = arabicNumber / 1000;
            }
            string[] romaBirler = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
            string[] romaOnlar = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
            string[] romaYüzler = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCC", "CM" };
            string[] romaBinler = { "", "M", "MM", "MMM" };
            textBox2.Text = (romaBinler[binler] + romaYüzler[yüzler] + romaOnlar[onlar] + romaBirler[birler]);
        }

        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            int basilanTus = Convert.ToInt32(e.KeyChar);
            if (!(basilanTus >= 48 && basilanTus <= 57 || basilanTus==8))
            {
                e.Handled = true;
            }
        }

        private void textBox2_KeyPress(object sender, KeyPressEventArgs e)
        {
            int basilanTus = Convert.ToInt32(e.KeyChar);
            if (basilanTus >= 48 && basilanTus <= 57)
            {
                e.Handled = true;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (textBox2.Text == "")
            {
                MessageBox.Show("Lütfen roma rakamı giriniz!!!");
            }
            string romaRakamı = textBox2.Text.ToUpper();

            int sayi = 0, esit = 0, ters, sonHali = 0;
            for (int i = 0; i < romaRakamı.Length; i++)
            {
                esit = sayi;
                switch (romaRakamı[i])
                {
                    case 'I': sayi = 1; break;
                    case 'V': sayi = 5; break;
                    case 'X': sayi = 10; break;
                    case 'L': sayi = 50; break;
                    case 'C': sayi = 100; break;
                    case 'D': sayi = 500; break;
                    case 'M': sayi = 1000; break;
                    default: MessageBox.Show("Tanımsız değer girdiniz!!!") ; break;
                }
                if (sayi > esit)
                {
                    ters = -2 * esit;
                }
                else
                {
                    ters = 0;
                }
                sonHali += sayi + ters;
            }
            textBox1.Text = sonHali.ToString();
        }
    }
}
/*KAYNAKÇA
 1-)http://csharphelper.com/blog/2016/04/convert-to-and-from-roman-numerals-in-c/
 2-)https://www.geeksforgeeks.org/converting-roman-numerals-decimal-lying-1-3999/
 3-)https://social.msdn.microsoft.com/Forums/tr-TR/af876721-45af-4544-abb9-dc4baf81ded3/textbox-karakter-girii-snrlama?forum=csharptr
 4-)http://muratbilginerncfkr.blogspot.com/2013/12/43-c-gorsel-programlama-43-keypress.html
 5-)https://github.com/DokuzEylulCsc/odev2-mertdemirturk/blob/master/MertDemirt%C3%BCrk_2019280070/odev2/Form1.cs
 */
