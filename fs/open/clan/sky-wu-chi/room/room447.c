inherit ROOM;
void create() {
	set( "short", "麥當勞--西南區" );
	set( "owner", "intel" );
	set( "object", ([
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"amount3"  : 1,
		"amount6"  : 1,
		"amount10" : 1,
		"file3"    : "/open/magic-manor/obj/master_snake_head",
		"amount7"  : 1,
		"amount5"  : 1,
		"file2"    : "/open/gblade/obj/sa-head",
		"file10"   : "/open/magic-manor/obj/master_snake_head",
		"file6"    : "/open/magic-manor/obj/master_snake_head",
		"file5"    : "/open/magic-manor/obj/master_snake_head",
		"amount1"  : 1,
		"file7"    : "/open/magic-manor/obj/master_snake_head",
		"amount4"  : 1,
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
		"amount2"  : 1,
	]) );
	set( "build", 10079 );
	set( "exits", ([
		"northeast" : "/open/clan/sky-wu-chi/room/room441",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
這裡是一個很大很大的餐館，要等你點完了東西才能來這裡坐的喔。這裡有好多張的椅子
你可以一張張的把它合併起來，再把一張張的桌子給合併，那你就可以跟親朋好友在一起用餐
了。不過你也要看一下位子的方向喔，只有東北方有門喔。
LONG);
	setup();
	replace_program(ROOM);
}
