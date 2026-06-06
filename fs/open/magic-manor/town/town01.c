inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "武器店");
        set ("long", @LONG
雲風鎮裏面一間頗具規模的武器店，店內所販賣的各式武器可說
是應有盡有，每件武器的品質可說是絕對有保證，架上也可以看到幾
件展示的武器，但看起來是這間店的收藏的不賣品。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "south"  : __DIR__"town07",
]));
        set("light_up", 1);
        setup();
}
