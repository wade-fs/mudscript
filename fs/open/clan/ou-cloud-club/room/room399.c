inherit ROOM;
void create() {
	set( "short", "欣的武器室" );
	set( "object", ([
		"file7"    : "/obj/gift/bingtang",
		"amount3"  : 2,
		"amount9"  : 1,
		"amount2"  : 500,
		"file5"    : "/open/ghost-hole/obj/light-spirit",
		"file4"    : "/obj/gift/xisuidan",
		"amount6"  : 7,
		"file9"    : "/open/killer/memory/static",
		"file2"    : "/open/fire-hole/obj/g-pill",
		"amount8"  : 6,
		"amount1"  : 51,
		"amount4"  : 1,
		"amount7"  : 1,
		"file3"    : "/obj/stone/jiao",
		"amount5"  : 1,
		"file1"    : "/obj/stone/powder",
		"file6"    : "/obj/stone/suipian",
		"file8"    : "/open/ping/obj/poison_pill",
	]) );
	set( "light_up", 1 );
	set( "build", 10028 );
	set( "owner", "lts" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room216.c",
		"south"     : "/open/clan/ou-cloud-club/room/room487.c",
		"north"     : "/open/clan/ou-cloud-club/room/room488.c",
		"east"      : "/open/clan/ou-cloud-club/room/room579",
	]) );
	set( "long", @LONG
          大量買相同物件請不要用 <數量> buy <東西> from <生物>
          因為這樣會讓您容易變成機器人, 上述的命令數視為 <數量> 個.
          此外, 上述的方式也非常耗 CPU, 是前面說明的 <數量> 倍,
          綜合以上說明, 在此特別呼籲各位用本命令特別提供的語法買東西.

LONG);
	setup();
	replace_program(ROOM);
}
