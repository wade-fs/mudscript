 // 鑰匙, 有鎖的房間請到 /u/w/wade/room/key_room 參考
#include <ansi.h>
#include "/open/open.h"
inherit ITEM;

void create()
{
        set_name(HIB + "鑰匙" + NOR, ({"blue key","key"}) );
        set("unit", "把");
        set("long", "這是一把藍色的鑰匙。\n");
        // 底下這個是設定它可以用的房間
        set ("key_of_room", ({ "/open/wu/room/gen17"}) );
        set("no_drop",1);
}
