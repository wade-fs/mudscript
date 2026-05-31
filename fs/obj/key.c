// 鑰匙, 有鎖的房間請到 /u/w/wade/room/key_room 參考
inherit ITEM;

void create()
{
        set_name("鑰匙", ({ "gold key","key" }) );
        set("unit", "把");
        set("long", "一把看起來普普的鑰匙，專門用來開門上的鎖用的。\n");
	// 底下這個是設定它可以用的房間
	set ("key_of_room", ({ "/u/w/wade/workroom", "/u/w/wade/room/key_room"}) );
	setup();
}
