inherit ROOM;
void create() {
	set( "short", "齊天殿" );
	set( "object", ([
		"file5"    : "/open/fire-hole/obj/p-pill",
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"file2"    : "/open/fire-hole/obj/k-pill",
		"amount8"  : 26,
		"amount7"  : 26,
		"amount5"  : 9,
		"file10"   : "/open/port/obj/wolf_ring",
		"amount6"  : 26,
		"file7"    : "/open/fire-hole/obj/b-pill",
		"amount2"  : 28,
		"file4"    : "/open/fire-hole/obj/w-pill",
		"amount1"  : 1,
		"file8"    : "/open/fire-hole/obj/y-pill",
		"amount3"  : 57,
		"file9"    : "/open/fire-hole/obj/r-pill",
		"amount9"  : 26,
		"amount10" : 1,
		"file1"    : "/open/magic-manor/obj/lunar-heart",
		"amount4"  : 23,
		"file6"    : "/open/fire-hole/obj/g-pill",
	]) );
	set( "owner", "mad" );
	set( "build", 10552 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room24",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

                 ▕╬═╬═╬═╬═╬═╬═╬═╬═╬▏
            ◢■■■■■■■■■■■■■■■■■■■■■◣
         ▕════════════════════════▏
          ▔█田田田田田田田田田田田田田田田田田田田田田█▔
             █|田田田田田田田田田田田田田田田田田田田|█
              █│∥∥ ∥∥ ∥∥ ∥∥ ∥∥ ∥∥ ∥∥│█
             _█│║║ ║║ ║║ ║║ ║║ ║║ ║║│█_
              █│║║ ▉▉ ║║ ▉▉ ║║ ▉▉ ║║│█
   ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔
LONG);
	setup();
	replace_program(ROOM);
}
