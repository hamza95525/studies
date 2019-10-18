#include "TestIncludes.h"
#include "TextWrapper.h"


TEST(TextWrapper, CreateInstance){
    auto wrapper = TextWrapper();
}

TEST(TextWrapper, HasColumnsGetter){
    auto wrapper = TextWrapper{};
    EXPECT_EQ(10, wrapper.columns());
}

/*refactoring - nie zmieniamy testow tylko poprawiamy jakies warningi, itd
 * testy musza zachowywac sie tak samo przed i po refactoringu
 * zaczynamy od fazy czerwonej i teraz jak w niej jestesmy to dodajemy kawalek kodu zeby przejsc do fazy zielonej
 * red ----dodanie kodu ----> green
 * red <----+test ------ green
 * albo
 * green -----> refactoring
 * refactoring ------> green
 * juz wszystko bedzie dzialac i wtedy z zielonego sobie wychodzimy
 * green -------> OUT
 * doiplementowac reszte tego textwrapper
 * konfigurowanie ilosci kolumn i pozniej dodawac coraz bardziej zaawansowana funkcjonalnosc do tego wrappera
 *
 * 1kolumna in - " nic "  out -"nic " - czyli pusty string
 * 1kolumna jesli ktos wpisze "a" to po zawinieciu "a" na out
 * 1 kolumna - in "ab" out "a\nb"
 * 1 columna - in "abc" out "a\nb\nc"
 * 2 kolumny - in "abc" out "ab\nc"
 * 2 kolumny - in "ab cd" out "ab\ncd"
 *
 * */