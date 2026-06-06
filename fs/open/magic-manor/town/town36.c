inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "破屋");
        set ("long", @LONG
一間破舊的屋子，屋頂也已經破了一個大洞了，這裏則常常有幾
個落魄的乞丐會將這當成住所，向路過的好心人仕們布施一些剩菜剩
飯來溫飽。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "north"  : __DIR__"town30",
	]));

	set("objects", ([ /* sizeof() == 1 */
	"/open/capital/npc/beggar" : 1,
	]));

        setup();
}
