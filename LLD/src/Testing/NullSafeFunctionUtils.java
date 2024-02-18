package Testing;

import java.util.NoSuchElementException;
import java.util.function.Function;

import static java.util.Objects.nonNull;

public class NullSafeFunctionUtils {

    public static <I, O> O getField( Function<I, O> function, I object) {
        try {
            return function.apply(object);
        } catch ( NullPointerException | NoSuchElementException | IndexOutOfBoundsException ignored) {
        }
        return null;
    }

    public static <I, O> O getFieldOrDefault(Function<I, O> function, I object, O defaultValue) {
        O result = getField(function, object);
        return nonNull(result) ? result : defaultValue;
    }
}
