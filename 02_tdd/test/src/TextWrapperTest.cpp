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
    auto wrapper = TextWrapper(2, "abcdefgh");
    EXPECT_EQ(8, wrapper.nLength);
}

TEST(TextWrapper, Wrapping){
    auto wrapper = TextWrapper();
    EXPECT_EQ("", wrapper.wrapping());
}

TEST(TextWrapper, WrappingTest1){
    auto wrapper = TextWrapper(1, "a");
    EXPECT_EQ("a", wrapper.wrapping());
}

TEST(TextWrapper, WrappingTest2){
    auto wrapper = TextWrapper(1, "ab");
    EXPECT_EQ("a\nb", wrapper.wrapping());
}

TEST(TextWrapper, WrappingTest3){
    auto wrapper = TextWrapper(1, "abc");
    EXPECT_EQ("a\nb\nc", wrapper.wrapping());
}

TEST(TextWrapper, WrappingTest5){ //i've made a mistake in commit, that should be 4 but in commit i called it 5 so it is 5 now
    auto wrapper = TextWrapper( 2, "abc");
    EXPECT_EQ("ab\nc", wrapper.wrapping());
}

TEST(TextWrapper, WrappingTest4){
    auto wrapper = TextWrapper(2,"ab cd");
    EXPECT_EQ("ab\ncd", wrapper.wrapping());
}

TEST(TextWrapper, WrappingTest6){
    auto wrapper = TextWrapper(3,"RAZDWATRZ");
    EXPECT_EQ("RAZ\nDWA\nTRZ", wrapper.wrapping());
}

TEST(TextWrapper, WrappingTest7){
    auto wrapper = TextWrapper(5,"RAZDWATRZYCZTERY");
    EXPECT_EQ("RAZDW\nATRZY\nCZTER\nY", wrapper.wrapping());
}

TEST(TextWrapper, WrappingTest8){
    auto wrapper = TextWrapper(2, "abcd ef gh");
    EXPECT_EQ("ab\ncd\nef\ngh", wrapper.wrapping());
}

TEST(TextWrapper, WrappingTest9){
    auto wrapper = TextWrapper(3, "abc def gh");
    EXPECT_EQ("abc\ndef\ngh", wrapper.wrapping());
}

TEST(TextWrapper, WrappingTestX){
    auto wrapper = TextWrapper(6, "aaabbbaaabbbaaabbbaaabbb");
    EXPECT_EQ("aaabbb\naaabbb\naaabbb\naaabbb", wrapper.wrapping());
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