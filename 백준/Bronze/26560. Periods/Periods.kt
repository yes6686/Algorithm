import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    repeat(readLine().toInt()) {
        val cur = readLine()
        bw.write(if (cur.last() != '.') cur.padEnd(cur.length + 1, '.') else cur)
        bw.newLine()
    }
    bw.flush()
    bw.close()
}