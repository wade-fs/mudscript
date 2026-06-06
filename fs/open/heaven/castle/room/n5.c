inherit ROOM;

void create()
{
        set("short", "荒舞修羅道");
        set("long", @LONG
這裡是通往天界之城的必經之地，也是介於人神之間的悲劇族群 --
修羅出沒的地方，由於天界眾神與修羅一族之間長年的征戰，使得修羅們
變得暴戾，如果在這裡走動要格外小心，免得遭受無妄之災。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"n4.c",
]));
        set("no_clean_up", 0);
        set("outdoors", 1);

        setup();
        }

