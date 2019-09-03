using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace my_application
{
    public partial class NumberGameForm : Form
    {
        public int score;

        public NumberGameForm()
        {
            InitializeComponent();
            score = 0;
        }

        private void hitButton_Click(object sender, EventArgs e)
        {
            Random rnd = new Random();
            score += (rnd.Next() % 11) + 1;
            if (score <= 21)
            {
                scoreLabel.Text = score.ToString();
            }
            else
            {
                scoreLabel.Text = "Too high!";
            }
        }
    }
}
