using System;
using System.IO;
using System.Numerics;

namespace laba3_zi_forms
{
    // Статический класс для методов расширения
    public static class BigIntegerExtensions
    {
        // Проверка, является ли число простым (быстрая проверка)
        public static bool IsProbablyPrime(this BigInteger value, int witnesses = 10)
        {
            DiffieHellmanEncryption diffieHellmanEncryption = new DiffieHellmanEncryption();
            if (value <= 1) return false;
            if (value == 2 || value == 3) return true;
            if (value % 2 == 0) return false;

            BigInteger d = value - 1;
            int s = 0;

            while (d % 2 == 0)
            {
                d /= 2;
                s += 1;
            }

            Random rand = new Random();

            for (int i = 0; i < witnesses; i++)
            {
                BigInteger a = diffieHellmanEncryption.RandomIntegerBelow(value - 2) + 2;
                BigInteger x = BigInteger.ModPow(a, d, value);

                if (x == 1 || x == value - 1) continue;

                for (int r = 1; r < s; r++)
                {
                    x = BigInteger.ModPow(x, 2, value);

                    if (x == 1) return false;
                    if (x == value - 1) break;
                }

                if (x != value - 1) return false;
            }

            return true;
        }
    }
    public class DiffieHellmanEncryption
    {
        public string inputFilePath;
        public string encryptedFilePath;
        public string decryptedFilePath;

        public DiffieHellmanEncryption()
        {
            inputFilePath = @"C:\Users\lihac\source\repos\laba3(zi)console\laba3(zi)console\bin\Debug\input.txt";
            encryptedFilePath = "output_encrypted.txt";
            decryptedFilePath = "output_decrypted.txt";
        }

        // Генерация случайного простого числа
        public BigInteger GeneratePrime(int bitLength)
        {
            Random random = new Random();
            while (true)
            {
                byte[] bytes = new byte[(bitLength + 7) / 8];
                random.NextBytes(bytes);
                bytes[bytes.Length - 1] &= 0x7F; // Убедиться, что число положительное
                BigInteger primeCandidate = new BigInteger(bytes);

                if (primeCandidate.IsProbablyPrime()) return primeCandidate; // Вызов метода расширения
            }
        }

        public BigInteger RandomIntegerBelow(BigInteger n)
        {
            Random rnd = new Random();
            byte[] bytes = n.ToByteArray();
            BigInteger result;

            do
            {
                rnd.NextBytes(bytes);
                bytes[bytes.Length - 1] &= (byte)0x7F;  // Убедиться, что число положительное
                result = new BigInteger(bytes);
            } while (result >= n || result == 0);

            return result;
        }

        // Главная функция шифрования
        public void EncryptFile(string inputFilePath, string outputFilePath, byte[] keyBytes)
        {
            // Прочитать файл и зашифровать его
            byte[] inputBytes = File.ReadAllBytes(inputFilePath);
            byte[] encryptedBytes = EncryptBytes(inputBytes, keyBytes);

            // Записать зашифрованный файл
            File.WriteAllBytes(outputFilePath, encryptedBytes);
        }

        // Шифрование байт с использованием XOR (простое шифрование для примера)
        public byte[] EncryptBytes(byte[] data, byte[] key)
        {
            byte[] result = new byte[data.Length];

            for (int i = 0; i < data.Length; i++)
            {
                result[i] = (byte)(data[i] ^ key[i % key.Length]);
            }

            return result;
        }

        // Расшифровка файла
        public void DecryptFile(string encryptedFilePath, string outputFilePath, byte[] keyBytes)
        {
            // Прочитать зашифрованный файл
            byte[] encryptedBytes = File.ReadAllBytes(encryptedFilePath);

            // Расшифровать данные
            byte[] decryptedBytes = EncryptBytes(encryptedBytes, keyBytes);

            // Записать расшифрованный файл
            File.WriteAllBytes(outputFilePath, decryptedBytes);
        }

        public void Main()
        {
            // Генерация публичных параметров p и g
            int bitLength = 20;
            BigInteger p = GeneratePrime(bitLength);
            BigInteger g = GeneratePrime(bitLength - 5);

            // Генерация случайных секретных чисел x и y
            BigInteger x = RandomIntegerBelow(p - 2) + 1;
            BigInteger y = RandomIntegerBelow(p - 2) + 1;

            // Вычисление значений A и B для обмена ключами
            BigInteger A = BigInteger.ModPow(g, x, p);
            BigInteger B = BigInteger.ModPow(g, y, p);

            // Вычисление общего ключа
            BigInteger secretKeyA = BigInteger.ModPow(B, x, p);

            // Применение функции тангенса к секретному ключу
            double transformedKey = Math.Tan((double)(secretKeyA % 1000000));  // Используем остаток для уменьшения значений

            // Преобразуем ключ в пригодный для шифрования
            byte[] keyBytes = BitConverter.GetBytes(transformedKey);

            // Шифрование файла
            EncryptFile(inputFilePath, encryptedFilePath, keyBytes);
            Console.WriteLine("Файл успешно зашифрован!");

            // Расшифровка файла
            DecryptFile(encryptedFilePath, decryptedFilePath, keyBytes);
            Console.WriteLine("Файл успешно расшифрован!");
        }
    }
}
