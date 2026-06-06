inherit ROOM;
void create() {
	set( "short", "麥當勞--西北區" );
	set( "owner", "hild" );
	set( "object", ([
		"amount6"  : 1,
		"amount1"  : 1,
		"amount4"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"amount3"  : 1,
	]) );
	set( "build", 10076 );
	set( "light_up", 1 );
	set( "exits", ([
		"southeast" : "/open/clan/sky-wu-chi/room/room441",
	]) );
	set( "long", @LONG
這裡是一個很大很大的餐館，要等你點完了東西才能來這裡坐的喔。這裡有好多張的椅子
你可以一張張的把它合併起來，再把一張張的桌子給合併，那你就可以跟親朋好友在一起用餐
了。不過你也要看一下位子的方向喔，只有東南方有門喔。
LONG);
	setup();
	replace_program(ROOM);
}
