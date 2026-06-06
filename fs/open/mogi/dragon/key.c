// 鑰匙, 有鎖的房間請到 /u/w/wade/room/key_room 參考
inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIB + "藍鑰匙" + NOR, ({ "bluekey","key", "blue" }) );
        set("unit", "把");
        set("no_auc",1);
set("no_get",1);
set("no_give",1);
        set("long", "一把看起來普普的鑰匙，專門用來開門上的鎖用的。\n");
        // 底下這個是設定它可以用的房間
        set ("key_of_room", ({ __DIR__"key_room"}) );

}

