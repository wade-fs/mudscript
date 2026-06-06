inherit ROOM;
void create() {
	set( "short", "珊珊的閨房" );
	set( "owner", "shan" );
	set( "object", ([
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"amount4"  : 104,
		"amount2"  : 1,
		"file1"    : "/open/fire-hole/obj/r-pill",
		"file3"    : "/obj/gift/xiandan",
		"amount6"  : 35,
		"file6"    : "/open/fire-hole/obj/g-pill",
		"file10"   : "/open/ghost-hole/obj/light-spirit",
		"amount1"  : 20,
		"amount3"  : 1,
		"amount10" : 1,
		"amount5"  : 16,
		"file2"    : "/obj/gift/unknowdan",
		"file5"    : "/open/fire-hole/obj/w-pill",
		"file7"    : "/open/fire-hole/obj/k-pill",
		"amount7"  : 31,
	]) );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room217",
	]) );
	set( "build", 10089 );
	set( "light_up", 1 );
	set( "long", @LONG
                         ▲  ▲   ▲  ▲   ▲  ▲  ▲
                        ▲  ▲   ▲  ▲   ▲  ▲  ▲
                         ▲  ▲ ▲  ▲ ▲   ▲   ▲
                   ▲ ▲  ▲ ▲   ▲   ▲ ▲    ▲  ▲ ▲
                   █ █ ▲ ▲  ▲  ▲  ▲ ▲ ▲ ▲ █ █
                   █ █  ▲ ▲▲  ▲▲▲  ▲▲ ▲  █ █
                 ▲█ █    ◥◣▲▲▲▲▲▲◢◤    █ █▲
                 ██ █      ▓◣ ▲  ▲ ◢▓      █ ██
                 ██ █▲    ▓▓▓▓▓▓▓▓    ▲█ ██
               ◢█│ │█◣  ◥██████◤  ◢█│ │█◣
           ▅▅███████▅▅▅▅▅▅▅▅▅███████▅▅
LONG);
	setup();
	replace_program(ROOM);
}
