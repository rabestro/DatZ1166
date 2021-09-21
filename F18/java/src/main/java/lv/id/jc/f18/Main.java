package lv.id.jc.f18;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Scanner;

import static java.util.function.Function.identity;
import static java.util.stream.Collectors.counting;
import static java.util.stream.Collectors.groupingBy;

public final class Main {
    public static void main(String[] args) throws IOException {

        Files.writeString(Paths.get("out.txt"),
                new Scanner(Paths.get("in.txt"))
                        .useDelimiter("\\W+")
                        .tokens()
                        .map(String::length)
                        .collect(groupingBy(identity(), counting()))
                        .toString()
        );
    }
}
