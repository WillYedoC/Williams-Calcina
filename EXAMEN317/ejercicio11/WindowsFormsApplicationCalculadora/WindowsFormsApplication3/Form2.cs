﻿using System;
using System.Collections.Generic;
using System.Globalization;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApplication3
{
    public partial class Form2 : Form
    {
        string cadenaOperar;
        string resultadoAnt = "";

        public Form2()
        {
            InitializeComponent();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            string buttonText = ((Button)sender).Text;
            if (resultado.Text == "0" || resultadoAnt != "")
            {
                resultadoAnt = "";
                resultado.Text = buttonText;
                cadenaOperar = buttonText;
            }
            else
            {
                if (!(resultado.Text == "0" && buttonText == "0"))
                {
                    cadenaOperar += buttonText;
                    resultado.Text += buttonText;
                }
            }
        }

        private void resolver(object sender, EventArgs e)
        {
            double operacion = EvaluarExpresion(cadenaOperar);
            resultadoAnt += operacion;
            resultado.Text = operacion.ToString();
            cadenaOperar = operacion.ToString();
        }
        private void borrarTexto(object sender, EventArgs e)
        {
            resultado.Text = "";
            cadenaOperar = "";
        }
        private void borrarUno(object sender, EventArgs e)
        {
            if (resultado.Text.Length > 0)
            {
                resultado.Text = resultado.Text.Substring(0, resultado.Text.Length - 1);
                cadenaOperar = cadenaOperar.Substring(0, cadenaOperar.Length - 1);
            }
        }

        static double EvaluarExpresion(string expresion)
        {
            Stack<double> numeros = new Stack<double>();
            Stack<char> operadores = new Stack<char>();
            int i = 0;

            while (i < expresion.Length)
            {
                if (char.IsDigit(expresion[i]) || expresion[i] == '.')
                {
                    string numero = "";
                    while (i < expresion.Length && (char.IsDigit(expresion[i]) || expresion[i] == '.'))
                    {
                        numero += expresion[i];
                        i++;
                    }
                    numeros.Push(double.Parse(numero, CultureInfo.InvariantCulture));
                }
                else if (expresion[i] == '+' || expresion[i] == '-' || expresion[i] == '*' || expresion[i] == '÷')
                {
                    while (operadores.Count > 0 && Precedencia(operadores.Peek()) >= Precedencia(expresion[i]))
                    {
                        AplicarOperador(numeros, operadores);
                    }
                    operadores.Push(expresion[i]);
                    i++;
                }
            }

            while (operadores.Count > 0)
            {
                AplicarOperador(numeros, operadores);
            }

            return numeros.Pop();
        }


        static int Precedencia(char operador)
        {
            switch (operador)
            {
                case '+':
                case '-':
                    return 1;
                case '*':
                case '÷':
                    return 2;
                default:
                    return 0;
            }
        }
        static void AplicarOperador(Stack<double> numeros, Stack<char> operadores)
        {
            double b = numeros.Pop();
            double a = numeros.Pop();
            char operador = operadores.Pop();

            switch (operador)
            {
                case '+':
                    numeros.Push(a + b);
                    break;
                case '-':
                    numeros.Push(a - b);
                    break;
                case '*':
                    numeros.Push(a * b);
                    break;
                case '÷':
                    numeros.Push(a / b);
                    break;
            }
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            this.BackColor = Color.Black;
        }

    }
}
