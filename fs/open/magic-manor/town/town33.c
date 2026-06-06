inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "蔬菜攤");
        set ("long", @LONG
菜攤小販正叫賣著各類的新鮮蔬菜，只見蔬菜色澤飽滿，青脆爽
口，價錢也合理公道，吸引了不少鎮民在挑選購買。而這也是鎮上的
居民賴以為生的一家蔬菜攤。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "north"  : __DIR__"town27",
	]));

        setup();
}
