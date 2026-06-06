inherit ROOM;
void create() {
	set( "short", "$HIR$麥當勞$HIW$--$HIC$南之路$HIB$長廊$NOR$" );
	set( "owner", "hild" );
	set( "object", ([
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
		"amount2"  : 1,
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"amount9"  : 1,
		"file6"    : "/open/mogi/castle/obj/fire-king-head",
		"file8"    : "/open/mogi/castle/obj/fire-king-head",
		"amount7"  : 1,
		"amount10" : 1,
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"file2"    : "/open/mogi/castle/obj/fire-king-head",
		"amount5"  : 1,
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"amount6"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"amount8"  : 1,
		"amount1"  : 1,
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
	]) );
	set( "build", 15262 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room441",
	]) );
	set( "long", @LONG
這裡是一個很大很大的餐館，要等你點完了東西才能來這裡坐的喔。這裡有好多張的椅子
你可以一張張的把它合併起來，再把一張張的桌子給合併，那你就可以跟親朋好友在一起用餐
了。不過你也要看一下位子的方向喔，只有北邊有門喔。
LONG);
	setup();
	replace_program(ROOM);
}
