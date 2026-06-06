inherit ROOM;
void create() {
	set( "short", "$HIR$麥當勞$HIW$--$HIC$北之路$HIB$長廊$NOR$" );
	set( "owner", "hild" );
	set( "object", ([
		"file5"    : "/open/fire-hole/obj/r-pill",
		"amount4"  : 22,
		"file1"    : "/open/killer/obj/atman_pill",
		"file4"    : "/open/fire-hole/obj/w-pill",
		"file8"    : "/open/mogi/castle/obj/sspill",
		"file6"    : "/open/mon/obj/mon-pill",
		"amount2"  : 192,
		"file3"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount5"  : 100,
		"file2"    : "/open/fire-hole/obj/g-pill",
		"amount3"  : 60,
		"file7"    : "/open/mogi/castle/obj/ninepill",
		"amount1"  : 800,
		"amount6"  : 323,
		"amount7"  : 50,
		"amount8"  : 42,
	]) );
	set( "build", 11754 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room441",
	]) );
	set( "long", @LONG
這裡是一個很大很大的餐館，要等你點完了東西才能來這裡坐的喔。這裡有好多張的椅子
你可以一張張的把它合併起來，再把一張張的桌子給合併，那你就可以跟親朋好友在一起用餐
了。不過你也要看一下位子的方向喔，只有南邊有門喔。
LONG);
	setup();
	replace_program(ROOM);
}
