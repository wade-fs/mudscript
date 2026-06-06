inherit ROOM;
void create() {
	set( "short", "麥當勞--東南區" );
	set( "owner", "hild" );
	set( "object", ([
		"file9"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount3"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-gem",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount10" : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount8"  : 1,
		"amount6"  : 1,
		"amount1"  : 1,
		"amount9"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount7"  : 1,
		"file4"    : "/open/magic-manor/obj/master_snake_head",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-leggings",
	]) );
	set( "build", 13196 );
	set( "exits", ([
		"northwest" : "/open/clan/sky-wu-chi/room/room441",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
這裡是一個很大很大的餐館，要等你點完了東西才能來這裡坐的喔。這裡有好多張的椅子
你可以一張張的把它合併起來，再把一張張的桌子給合併，那你就可以跟親朋好友在一起用餐
了。不過你也要看一下位子的方向喔，只有西北方有門喔。
LONG);
	setup();
	replace_program(ROOM);
}
