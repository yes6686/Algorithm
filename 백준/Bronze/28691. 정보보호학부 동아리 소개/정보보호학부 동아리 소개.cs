namespace Solution {
    
  class Program {
    static void Main(string[] args) {
       Dictionary<char, string> clubMap = new Dictionary<char, string> {
        {'M', "MatKor"},
        {'W', "WiCys"},
        {'C', "CyKor"},
        {'A', "AlKor"},
        {'$', "$clear"}
      };
      char firstLetter =  Console.ReadLine()![0];
      Console.WriteLine(clubMap[firstLetter]);
    }
  }
}