#include "TestIncludes.h"
#include "TextWrapper.h"


TEST(TextWrapper, CreateInstance){
    auto wrapper = TextWrapper{};
}

/*TEST(TextWrapper, HasColumnsGetter){
    auto wrapper = TextWrapper{};
    EXPECT_EQ(10, wrapper.columns());
}*/

TEST(TextWrapper, HasConstructor){
    auto wrapper = TextWrapper(5,"Hi, friends!");
    EXPECT_EQ(5, wrapper.nCol);
}

TEST(TextWrapper, ConstructorString){
    auto wrapper = TextWrapper(5, "Hello, World!");
    EXPECT_EQ("Hello, World!", wrapper.Words);
}

TEST(TextWrapper, NumberOfCharacters){
    auto wrapper = TextWrapper(5, "baracuda");
    EXPECT_EQ(8, wrapper.nLength);
}

TEST(TextWrapper, Wrapping){
    auto wrapper = TextWrapper(2, "");
    EXPECT_EQ("", wrapper.wrapping());
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