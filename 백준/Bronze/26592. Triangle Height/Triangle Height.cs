namespace Solution {
  class Program {
    static void Main(string[] args) {
      var n = int.Parse(Console.ReadLine()!);
      for (int t = 0; t < n; t++) {
        var input = Console.ReadLine()!.Split(' ');
        var a = double.Parse(input![0]);
        var b = double.Parse(input![1]);

        double height = (2 * a) / b;
        Console.WriteLine($"The height of the triangle is {height:F2} units");
      }
    }
  }
}