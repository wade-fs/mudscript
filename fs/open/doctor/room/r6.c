inherit ROOM;
void create()
{
        set("short", "藥圃");
        set("long", @LONG

           乾坤八卦，盡藏玄機
           亦正亦邪，非正非邪
           前後左右，並非來處
                                 
看到了這些字，你恨自己過於貪心，誤入藥園陷阱之中。

LONG
        );
        set("can_search",1);
        set("exits", ([ /* sizeof() == 6 */
  "west" : __DIR__"r6",
  "north" : __DIR__"r5",
  "south" : __DIR__"r6",
  "up" : __DIR__"r6",
  "down" : __DIR__"r6",
  "east" : __DIR__"r7",
]));
        set("no_clean_up", 0);

        setup();
        }


