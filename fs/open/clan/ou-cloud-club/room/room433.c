inherit ROOM;
void create() {
	set( "short", "2112n" );
	set( "object", ([
		"amount9"  : 1,
		"file2"    : "/obj/stone/stone",
		"amount4"  : 1,
		"file10"   : "/open/fire-hole/obj/w-pill",
		"amount1"  : 58,
		"file6"    : "/open/capital/obj/ggpill",
		"file3"    : "/obj/stone/jiao",
		"amount5"  : 1,
		"file1"    : "/open/fire-hole/obj/g-pill",
		"file7"    : "/obj/stone/powder",
		"file8"    : "/open/mon/obj/ghost-legging",
		"amount7"  : 15,
		"file9"    : "/daemon/class/blademan/obj/shield",
		"amount10" : 2,
		"amount3"  : 2,
		"file5"    : "/obj/stone/suipian",
		"amount8"  : 1,
		"amount2"  : 1,
		"file4"    : "/obj/gift/bingtang",
		"amount6"  : 1,
	]) );
	set( "item_desc", ([
		"心築情巢" : @ITEM
ITEM,
	]) );
	set( "owner", "superpker" );
	set( "build", 10200 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room440",
	]) );
	set( "long", @LONG
這邊沒有長敘述,所以房間號碼有紅字..我先改一下..等你有控自己在改...bbsboss
這邊沒有長敘述,所以房間號碼有紅字..我先改一下..等你有控自己在改...bbsboss
這邊沒有長敘述,所以房間號碼有紅字..我先改一下..等你有控自己在改...bbsboss
這邊沒有長敘述,所以房間號碼有紅字..我先改一下..等你有控自己在改...bbsboss
這邊沒有長敘述,所以房間號碼有紅字..我先改一下..等你有控自己在改...bbsboss
這邊沒有長敘述,所以房間號碼有紅字..我先改一下..等你有控自己在改...bbsboss
這邊沒有長敘述,所以房間號碼有紅字..我先改一下..等你有控自己在改...bbsboss
這邊沒有長敘述,所以房間號碼有紅字..我先改一下..等你有控自己在改...bbsboss
LONG);
	setup();
	replace_program(ROOM);
}
