inherit ROOM;
void create() {
	set( "short", "鳳無雙的刑求室" );
	set( "owner", "sblade" );
	set( "object", ([
		"amount1"  : 1,
		"file4"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file6"    : "/open/mon/obj/mon-pill",
		"file3"    : "/open/capital/obj/blade2",
		"amount8"  : 1,
		"file2"    : "/open/poison/obj/armband1",
		"amount7"  : 1,
		"amount3"  : 1,
		"amount6"  : 1,
		"file1"    : "/open/killer/obj/fire-knife",
		"file8"    : "/open/ghost-hole/obj/fire-spirit",
		"file7"    : "/open/beggar/obj/legs",
		"file5"    : "/open/killer/headkill/obj/world_dag",
		"amount5"  : 1,
		"amount2"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 10366 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room317",
		"south"     : "/open/clan/sky-wu-chi/room/room299.c",
	]) );
	set( "long", @LONG
一走進房間裡，你可以看到鳳無雙正在忙著清理血漬呢。旁邊的電視正撥放著滿清十大酷刑，在小茶几上還擺放著一些刑具，令你覺得整個人都緊張了起來。當你坐下來的時候，你注意到在桌上有一張鳳無雙鞭打寒雪冰霜的照片，照片裡的寒雪冰霜看起來十分的舒服呢。
LONG);
	setup();
	replace_program(ROOM);
}
