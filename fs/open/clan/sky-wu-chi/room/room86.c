// Room : /open/clan/sky-wu-chi/room/room86.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "clan_room", "天道無極" );
	set( "short", "燕仔的臥房" );
	set( "owner", "working" );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "light_up", 1 );
	set( "object", ([
		"file4"    : "/open/mogi/castle/obj/sspill",
		"file5"    : "/open/fire-hole/obj/g-pill",
		"file10"   : "/open/mogi/castle/obj/ninepill",
		"amount3"  : 446,
		"amount9"  : 435,
		"file8"    : "/open/fire-hole/obj/b-pill",
		"amount4"  : 105,
		"amount7"  : 33,
		"file6"    : "/open/fire-hole/obj/r-pill",
		"amount10" : 15,
		"amount6"  : 97,
		"amount1"  : 148,
		"file1"    : "/open/mon/obj/mon-pill",
		"amount8"  : 527,
		"file9"    : "/open/fire-hole/obj/k-pill",
		"amount5"  : 414,
		"file7"    : "/open/fire-hole/obj/w-pill",
		"amount2"  : 300,
		"file2"    : "/open/fire-hole/obj/p-pill",
		"file3"    : "/open/fire-hole/obj/y-pill",
	]) );
	set( "build", 14294 );
	set( "long", @LONG
      /＼              ／\
        ▕   ＼＿＿ˍˍˍ／ ▕
        ▕ ／￣    ◥██◤╲
         ∕                  ﹨    $HBCYN$常常獨自一個人在深夜裡想著妳    $NOR$
         ︳   /￣\    /￣\   ▕    $HBCYN$  想著我們過去的點點滴滴        $NOR$
         ︳   ︳ZZ   ZZ  ︳  ▕    $HBCYN$    因為過去有太多太多美好的回憶$NOR$
        ┼    \ˍ/    \ˍ/    ┼   $HBCYN$      總是在不知不覺中就回想起  $NOR$
         ﹨ˍ      ●      ˍ∕    $HBCYN$        不管我們兩相隔多麼遠    $NOR$
         ¯╲ˍ    ‧    ˍ／_     $HBCYN$          我依然思念著妳        $NOR$
         ╭─◤¯¯¯￣◥◤﹨
        （   ︳           /﹀﹀\◢█
       （____︳  ▕ ／  ▕ .‧. █◤
             \︿︿/ ︺︺︺＼●／  
LONG);
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 1 */
  "east" : "/open/clan/sky-wu-chi/room/room85",
]) );
	set( "cmkroom", 1 );
	setup();

	}
