namespace Solution {
  class Program {
    static void Main(string[] args) {

      var n = int.Parse(Console.ReadLine()!);

      for (int i = 0; i < n; i++) {
        var input = Console.ReadLine()?.Split();
        var c = int.Parse(input![0]);
        var p = int.Parse(input![1]);

        var beforeDiscount = c * p;
        var discount = 2 * (c - 1);
        var afterDiscount = beforeDiscount - discount;

        Console.WriteLine($"{c} {p}");
        Console.WriteLine(afterDiscount);
      }
    }
  }
}