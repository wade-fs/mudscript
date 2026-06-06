// 鑰匙, 有鎖的房間請到 /u/w/wade/workroom 參考
inherit ITEM;

void create()
{
        set_name("石鑰匙", ({ "stonekey","key" }) );
        set("long", "這是一把具有磁性的石鑰匙。\n");
        set("unit", "把");
        set_weight(800);
        set("no_drop",1);
        set("value", 0);
}
