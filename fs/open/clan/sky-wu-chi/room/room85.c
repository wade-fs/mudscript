// Room : /open/clan/sky-wu-chi/room/room85.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "clan_room", "天道無極" );
	set( "short", "燕仔家門口" );
	set( "owner", "working" );
	set( "object", ([
		"file5"    : "/open/killer/obj/bellstar",
		"file10"   : "/open/magic-manor/obj/maun-shadow-blade",
		"file4"    : "/open/area/house/npc/obj/snake-stone",
		"amount3"  : 1,
		"file8"    : "/open/killer/obj/atman_pill",
		"amount4"  : 1,
		"file6"    : "/open/fire-hole/obj/p-pill",
		"amount10" : 1,
		"amount6"  : 4,
		"file1"    : "/u/p/pana/q/obj/cow-head",
		"amount8"  : 156,
		"amount1"  : 1,
		"amount5"  : 50981,
		"file2"    : "/open/gblade/obj/sa-head",
		"amount2"  : 1,
		"file3"    : "/open/area/snake/npc/snake-gall",
	]) );
	set( "light_up", 1 );
	set( "build", 14387 );
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
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
  "north" : "/open/clan/sky-wu-chi/room/room4",
  "west" : "/open/clan/sky-wu-chi/room/room86.c",
]) );
	set( "cmkroom", 1 );
	setup();

	}
