namespace Solution {
  class Program {
    static void Main(string[] args) {

      var m = int.Parse(Console.ReadLine()!);
      var n = int.Parse(Console.ReadLine()!);

      var ans = (2 * m) + (2 * n) - 4;

      if (m == 1 || n == 1) ans = (m + n) - 1;

      Console.WriteLine(ans);

    }
  }
}