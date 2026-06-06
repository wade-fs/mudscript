inherit ROOM;
void create() {
	set( "short", "武神居大門" );
	set( "owner", "zmud" );
	set( "object", ([
		"file9"    : "/open/ping/obj/poison_pill",
		"amount8"  : 889,
		"amount2"  : 799,
		"file6"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount7"  : 861,
		"file5"    : "/obj/gift/unknowdan",
		"file4"    : "/open/fire-hole/obj/g-pill",
		"file7"    : "/open/ping/obj/poison_pill",
		"amount1"  : 185,
		"file8"    : "/open/ping/obj/poison_pill",
		"file1"    : "/open/fire-hole/obj/w-pill",
		"file2"    : "/open/mon/obj/mon-pill",
		"amount4"  : 494,
		"amount6"  : 200,
		"amount9"  : 846,
		"amount5"  : 1,
		"file10"   : "/open/mogi/castle/obj/sspill",
		"amount10" : 250,
	]) );
	set( "build", 10261 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room71.c",
		"enter"     : "/open/clan/13_luck/room/room286",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

                      ◢■■■■■■■■■■◣
                  ◢■■■■■■■■■■■■■■◣
                ▕╬══武════神═══居══╬▏
           ◢■■■■■■■■■■■■■■■■■■■■■◣
       ▕═════════════════════════▏
         ▔█田田田田田田田田田田田田田田田田田田田田田█▔
            █|田田田田田田田田田田田田田田田田田田田|█
             █│∥∥ ∥∥ ∥∥ ∥∥ ∥∥ ∥∥ ∥∥│█
             █│║║ ║║ ║║ ║║ ║║ ║║ ║║│█
             █│║║ ▉▉ ║║ ▉▉ ║║ ▉▉ ║║│█
▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔

LONG);
	setup();
	replace_program(ROOM);
}
