using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Numerics;
using System.Security.Cryptography;

namespace laba3_zi_forms
{
    public partial class Form1 : Form
    {
        DiffieHellmanEncryption diffieHellmanEncryption = new DiffieHellmanEncryption();
        public double transformedKey;
        public BigInteger p;
        public BigInteger g;
        public BigInteger x;
        public BigInteger y;
        public BigInteger A;
        public BigInteger B;
        public BigInteger secretKeyA;
        byte[] keyBytes;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            GenerateKeyFromData();
        }
        private void GenerateKeyFromData()
        {
            // Генерация публичных параметров p и g
            int bitLength = 20;
            p = diffieHellmanEncryption.GeneratePrime(bitLength);
            g = diffieHellmanEncryption.GeneratePrime(bitLength - 5);

            // Генерация случайных секретных чисел x и y
            do
            {
                do
                {
                    x = diffieHellmanEncryption.RandomIntegerBelow(p - 2) + 1;
                } while (!BigIntegerExtensions.IsProbablyPrime(x));

                do
                {
                    y = diffieHellmanEncryption.RandomIntegerBelow(p - 2) + 1;
                } while (!BigIntegerExtensions.IsProbablyPrime(y));
            } while (x == y);

            // Вычисление значений A и B для обмена ключами
            A = BigInteger.ModPow(g, x, p);
            B = BigInteger.ModPow(g, y, p);

            // Вычисление общего ключа
            secretKeyA = BigInteger.ModPow(B, x, p);

            // Применение функции тангенса к секретному ключу
            transformedKey = Math.Tan((double)(secretKeyA % 1000000));  // Используем остаток для уменьшения значений

            // Преобразуем ключ в пригодный для шифрования
            keyBytes = BitConverter.GetBytes(transformedKey);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            diffieHellmanEncryption.EncryptFile(diffieHellmanEncryption.inputFilePath, diffieHellmanEncryption.encryptedFilePath, keyBytes);
            textBox2.Text = File.ReadAllText(diffieHellmanEncryption.encryptedFilePath);
        }
        private void button2_Click(object sender, EventArgs e)
        {
            diffieHellmanEncryption.DecryptFile(diffieHellmanEncryption.encryptedFilePath, diffieHellmanEncryption.decryptedFilePath, keyBytes);
            textBox3.Text = File.ReadAllText(diffieHellmanEncryption.decryptedFilePath);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            File.WriteAllText(diffieHellmanEncryption.inputFilePath, textBox1.Text);
            label1.Text = $"p = {p}\ng = {g}\nx = {x}\ny = {y}\nA = {A}\nB = {B}\nsecretKeyA = {secretKeyA}\ntransformedKey = {transformedKey}";
        }

        private void timer1_Tick(object sender, EventArgs e)
        {

        }
    }
}

