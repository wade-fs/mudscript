inherit ROOM;
void create() {
	set( "short", "浪味仙的家" );
	set( "object", ([
		"amount5"  : 1,
		"amount6"  : 1,
		"amount3"  : 4,
		"amount7"  : 1,
		"amount9"  : 23,
		"amount8"  : 21,
		"amount10" : 23,
		"file9"    : "/open/fire-hole/obj/p-pill",
		"file2"    : "/open/fire-hole/obj/g-pill",
		"amount2"  : 5,
		"file5"    : "/open/mon/obj/ghost-legging",
		"file10"   : "/open/mogi/castle/obj/ninepill",
		"file3"    : "/open/fire-hole/obj/r-pill",
		"file7"    : "/open/mon/obj/ghost-helmet",
		"amount4"  : 1,
		"file1"    : "/open/mon/obj/mon-pill",
		"amount1"  : 49,
		"file4"    : "/open/mon/obj/ghost-claw",
		"file6"    : "/open/mon/obj/ghost-cloak",
		"file8"    : "/open/fire-hole/obj/b-pill",
	]) );
	set( "build", 10598 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room475",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "long", @LONG
    '  .  '  .  '  .○  '  .  '  .  ' .  '  .  '  .  ' ●.  ' .
'  . ' . ' .  ○' .  '  .  '  .  '  .  '  .  '  .  '  . ' .
            ┌┐            自已的家總是最溫暖的
    ◢◣◥███◣                    ╱╲
  ◢██◣◥███◣                ╱    ╲
  │╭╮│  田 田 │          ╱╲╱        ╲╱╲
                                                                                
  ││││  田 田 │       ╱                      ╲
﹏└┴┴┴────┘﹏﹏╱﹏﹏﹏Υ﹏﹏﹏Υ﹏﹏﹏﹏Υ﹏╲﹏Υ
--
==========================================================

LONG);
	setup();
	replace_program(ROOM);
}
