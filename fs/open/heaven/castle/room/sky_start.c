#include <ansi.h>
inherit ROOM;
 
void create()
{
        set("short", "荒舞修羅道");
        set("long", @LONG
這裡是通往天界之城的必經之地，也是介於人類與神族之間的悲劇族
群 -- 修羅出沒的地方，由於天界眾神與魔界之間長年的征戰，使得天界
元氣大傷，也讓修羅日漸坐大，虎視眈眈的想佔領天界之城，如果你想踏
進這塊危機四伏的區域，得先作好心裡準備。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"sky1",
]));
        set("no_clean_up", 0);
        set("outdoors", 1);

        setup();
        }
