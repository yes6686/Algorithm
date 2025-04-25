namespace Solution {
  class Program {
    static void Main(string[] args) {

      var input = Console.ReadLine()?.Split();
      var h1 = int.Parse(input![0]);
      var b1 = int.Parse(input![1]);

      input = Console.ReadLine()?.Split();
      var h2 = int.Parse(input![0]);
      var b2 = int.Parse(input![1]);

      var player1Score = 3 * h1 + b1;
      var player2Score = 3 * h2 + b2;

      string ans = "NO SCORE";
      if (player1Score > player2Score)
        ans = "1 " + (player1Score - player2Score);
      else if (player2Score > player1Score)
        ans = "2 " + (player2Score - player1Score);

      Console.WriteLine(ans);
    }
  }
}