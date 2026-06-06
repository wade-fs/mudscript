 // 鑰匙, 有鎖的房間請到 /u/w/wade/room/key_room 參考
#include <ansi.h>
#include "/open/open.h"
inherit ITEM;

void create()
{
        set_name(HIR"鑰匙"NOR, ({"red key","key"}) );
        set("unit", "把");
        set("long", "這是一把赤紅紅的鑰匙。\n");
        // 底下這個是設定它可以用的房間
        set ("key_of_room", ({ "/open/wu/room/gen7"}) );
        set("no_drop",1);
}
