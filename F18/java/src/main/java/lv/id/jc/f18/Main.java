package lv.id.jc.f18;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Scanner;
import java.util.function.Function;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws IOException {
        var map = new Scanner(Paths.get("in.txt"))
                .useDelimiter("\\W+")
                .tokens()
                .map(String::length)
                .collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));

        Files.writeString(Paths.get("out.txt"), map.toString());
    }
}
