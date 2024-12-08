namespace Solution {
  class Program {
    static void Main(string[] args) {

      var n = int.Parse(Console.ReadLine()!);

      for (var i = 0; i < n; i++) {
        var input = Console.ReadLine()?.Split();

        var a = double.Parse(input![0]);
        var b = double.Parse(input![1]);

        var absDist = Math.Abs(a - b);

        Console.WriteLine("{0:F1}", absDist);
      }
    }
  }
}