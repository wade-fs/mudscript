inherit ROOM;
void create() {
	set( "short", "$HIR$麥當勞$HIW$--$HIC$西之路$HIB$長廊$NOR$" );
	set( "owner", "hild" );
	set( "object", ([
		"amount1"  : 1,
		"amount2"  : 1,
		"amount6"  : 1,
		"amount5"  : 1,
		"file1"    : "/open/killer/memory/static",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/magic-manor/obj/magic-sign",
	]) );
	set( "build", 15021 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room441",
	]) );
	set( "long", @LONG
這裡是一個很大很大的餐館，要等你點完了東西才能來這裡坐的喔。這裡有好多張的椅子
你可以一張張的把它合併起來，再把一張張的桌子給合併，那你就可以跟親朋好友在一起用餐
了。不過你也要看一下位子的方向喔，只有東邊有門喔。
LONG);
	setup();
	replace_program(ROOM);
}
