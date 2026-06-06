inherit ROOM;
void create() {
	set( "short", "$HIR$麥當勞$HIW$--$HIC$東之路$HIB$長廊$NOR$" );
	set( "owner", "hild" );
	set( "object", ([
		"amount4"  : 1,
		"file6"    : "/open/mogi/castle/obj/seven7-dark-head",
		"file1"    : "/obj/gift/hobowdan",
		"amount1"  : 1,
		"file2"    : "/obj/gift/hobowdan",
		"file10"   : "/open/mogi/castle/obj/seven1-dark-head",
		"amount7"  : 1,
		"amount6"  : 1,
		"file7"    : "/open/mogi/castle/obj/seven3-dark-head",
		"amount5"  : 1,
		"file8"    : "/open/mogi/castle/obj/seven4-dark-head",
		"file4"    : "/open/mogi/castle/obj/seven5-dark-head",
		"file9"    : "/open/mogi/castle/obj/seven2-dark-head",
		"file5"    : "/open/mogi/castle/obj/seven6-dark-head",
		"amount9"  : 1,
		"amount8"  : 1,
		"amount10" : 1,
		"amount2"  : 1,
	]) );
	set( "build", 10014 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room441.c",
	]) );
	set( "long", @LONG
這裡是一個很大很大的餐館，要等你點完了東西才能來這裡坐的喔。這裡有好多張的椅子
你可以一張張的把它合併起來，再把一張張的桌子給合併，那你就可以跟親朋好友在一起用餐
了。不過你也要看一下位子的方向喔，只有西邊有門喔。
LONG);
	setup();
	replace_program(ROOM);
}
