using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace ManagedWar
{
    class Program
    {
        //Reference (https://msdn.microsoft.com/en-us/library/2x8kf7zx.aspx)
        static void Main(string[] args)
        {
            var deck = new ManagedCasino.ManagedDeck();
            var player_card = deck.Draw();
            var computer_card = deck.Draw();
            Console.WriteLine("You got a: " + player_card);
            Console.WriteLine("I got a: " + computer_card);

            if (computer_card < player_card)
                Console.WriteLine("You Won!\n");
            else
                Console.WriteLine("You lost.\n");


            
        }
    }
}
