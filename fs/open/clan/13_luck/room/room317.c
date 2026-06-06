inherit ROOM;
void create() {
	set( "short", "吉祥置物箱庚" );
	set( "owner", "upup" );
	set( "object", ([
		"file7"    : "/open/capital/obj/force_book",
		"amount6"  : 1,
		"file4"    : "/open/gblade/obj/sa-head",
		"file5"    : "/open/magic-manor/obj/sun-heart",
		"amount7"  : 1,
		"amount8"  : 3,
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"amount1"  : 1,
		"amount5"  : 1,
		"file8"    : "/open/mon/obj/mon_item",
		"file1"    : "/open/capital/obj/force_book",
		"file6"    : "/open/scholar/room/newplan/obj/s-shield",
		"amount4"  : 1,
		"amount9"  : 1,
	]) );
	set( "build", 10122 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room305",
	]) );
	set( "long", @LONG

    這裡是吉祥置物櫃庚，專門為還沒有房間的新進幫眾所設立的，此
環境優雅舒適，讓新進的幫眾有個可以去的地方跟休息的地方，使他們
快點成為十三吉祥的戰力，一起為幫派的未來而努力，一同打拼，人居
玉宇千年茂，日印華堂百業興，希望能為天下第一大幫而邁進。

LONG);
	setup();
	replace_program(ROOM);
}
