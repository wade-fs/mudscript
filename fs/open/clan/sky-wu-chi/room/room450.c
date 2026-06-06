inherit ROOM;
void create() {
	set( "short", "麥當勞--東北區" );
	set( "owner", "hild" );
	set( "object", ([
		"amount4"  : 1,
		"file6"    : "/obj/gift/lingzhi",
		"amount1"  : 1,
		"file1"    : "/open/gsword/obj1/blosword",
		"file2"    : "/open/gsword/obj1/blosword",
		"amount7"  : 1,
		"amount6"  : 1,
		"file7"    : "/obj/gift/bingtang",
		"amount5"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file8"    : "/obj/gift/bingtang",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file9"    : "/obj/gift/bingtang",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount9"  : 1,
		"amount8"  : 1,
		"amount2"  : 1,
	]) );
	set( "build", 11235 );
	set( "exits", ([
		"southwest" : "/open/clan/sky-wu-chi/room/room441",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
這裡是一個很大很大的餐館，要等你點完了東西才能來這裡坐的喔。這裡有好多張的椅子
你可以一張張的把它合併起來，再把一張張的桌子給合併，那你就可以跟親朋好友在一起用餐
了。不過你也要看一下位子的方向喔，只有西南方有門喔。
LONG);
	setup();
	replace_program(ROOM);
}
