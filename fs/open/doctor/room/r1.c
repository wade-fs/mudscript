inherit ROOM;
void create()
{
        set("short", "藥圃");
        set("long", @LONG

    你一進入這裡，發覺這裡霧氣四散，景色模糊不以，靠的微弱的燈光
，依稀可以辨別的出這裡是個園子，低頭一看，哇～原來這裡是一個種植
藥物的場所，抬頭往前看，裡面似乎還種著更名貴的藥草。

LONG
        );
  set("can_search",1);
  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"r2",
  "east" :__DIR__"r",
  "enter" :__DIR__"1",
]));
        set("no_clean_up", 0);

        setup();
}



