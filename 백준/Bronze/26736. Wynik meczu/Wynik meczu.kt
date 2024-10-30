fun main() {
    val line = readln().toCharArray()
    println("${line.count { it == 'A' }} : ${line.count { it == 'B' }}")
}