inherit ROOM;
void create() {
	set( "short", "『桃花樹林』 " );
	set( "owner", "mill" );
	set( "object", ([
		"amount8"  : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/capital/room/king/obj/dagger1",
		"amount10" : 1,
		"file8"    : "/obj/gift/xiandan",
		"file7"    : "/obj/gift/bingtang",
		"file1"    : "/open/killer/headkill/obj/f_dag",
		"file4"    : "/open/killer/obj/dagger",
		"amount7"  : 1,
		"amount1"  : 1,
		"amount6"  : 1,
		"amount9"  : 1,
		"file9"    : "/open/killer/obj/fire-knife",
		"file6"    : "/open/magic-manor/obj/fon-sky-sword",
		"file10"   : "/open/capital/obj/chen_dagger",
		"file3"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount3"  : 1,
		"file5"    : "/open/killer/obj/dagger",
	]) );
	set( "build", 10143 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room259",
		"north"     : "/open/clan/13_luck/room/room261.c",
	]) );
	set( "long", @LONG
愈往桃花林的裡面走，愈覺得危機四伏，總覺得似乎有人在偷窺著你。
可是在這麼漂亮的景色下面，就算有人來偷襲你，似乎也是心甘情願的。而
四周的小動物也蹦蹦跳跳的圍繞著你繞圈圈，而讓你的心情也跟著愉悅起來
了。
LONG);
	setup();
	replace_program(ROOM);
}
