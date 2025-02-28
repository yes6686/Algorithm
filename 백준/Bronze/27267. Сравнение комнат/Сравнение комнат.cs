namespace Solution {
  class Program {
    static void Main(string[] args) {
      var input = Console.ReadLine()?.Split(' ');
      var a = int.Parse(input![0]);
      var b = int.Parse(input![1]);
      var c = int.Parse(input![2]);
      var d = int.Parse(input![3]);

      var area1 = a * b;
      var area2 = c * d;

      if (area1 > area2) Console.WriteLine("M");
      else if (area1 < area2) Console.WriteLine("P");
      else Console.WriteLine("E");

    }
  }
}