namespace Solution {
  class Program {
    static void Main(string[] args) {

      var inputs = Console.ReadLine()!.Split(' ').Select(int.Parse).ToArray();
      int a = inputs[0], b = inputs[1], c = inputs[2], d = inputs[3];

      var minimumMice = inputs.Sum() - inputs.Min() + 1;

      Console.WriteLine(minimumMice);

    }
  }
}