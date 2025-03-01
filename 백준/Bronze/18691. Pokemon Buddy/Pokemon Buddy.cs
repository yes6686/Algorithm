namespace Solution {
  class Program {
    static void Main(string[] args) {

      var caseCnt = int.Parse(Console.ReadLine()!);

      for (var i = 0; i < caseCnt; i++) {
        var input = Console.ReadLine()!.Split(' ');
        var group = int.Parse(input[0]);
        var initialCandies = int.Parse(input[1]);
        var evolveCandies = int.Parse(input[2]);

        var requiredCandies = evolveCandies - initialCandies;

        int requriedKm;
        if (group == 1) requriedKm = requiredCandies;
        else if (group == 2) requriedKm = 3 * requiredCandies;
        else requriedKm = 5 * requiredCandies;

        if (requriedKm <= 0) Console.WriteLine("0");
        else Console.WriteLine($"{requriedKm}");
      }
    }
  }
}