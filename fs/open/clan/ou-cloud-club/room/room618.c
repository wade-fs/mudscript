inherit ROOM;
void create() {
	set( "short", "$HIC$暴龍道 1$NOR$" );
	set( "object", ([
		"amount8"  : 398,
		"file2"    : "/open/mon/obj/mon-pill",
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"file1"    : "/open/fire-hole/obj/w-pill",
		"file8"    : "/open/fire-hole/obj/p-pill",
		"amount10" : 1,
		"amount2"  : 292,
		"amount3"  : 694,
		"amount6"  : 404,
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
		"amount7"  : 417,
		"amount1"  : 808,
		"file3"    : "/open/fire-hole/obj/g-pill",
		"amount4"  : 510,
		"amount9"  : 1,
		"amount5"  : 650,
		"file4"    : "/open/fire-hole/obj/k-pill",
		"file5"    : "/open/fire-hole/obj/r-pill",
		"file7"    : "/open/fire-hole/obj/y-pill",
		"file6"    : "/open/fire-hole/obj/b-pill",
	]) );
	set( "owner", "taa" );
	set( "build", 11101 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room616",
	]) );
	set( "long", @LONG

                                                      ____
          ___                                      .-~. /_ -._
         `-._~-.                                  / /_  ~o\  :Y
             \  \                                / : \~x.  ` ')
              ]  Y                              /  |  Y< ~-.__j
             /   !                        _.--~T : l  l<  /.-~
            /   /                 ____.--~ .   ` l /~\ \<|Y
           /   /             .-~~         /| .    ',-~\ \L|
          /   /             /     .^   \ Y~Y \.^>/l_    --'
         /   Y           .- (  .  l__  j_j l_/ /~_.-~    .
        Y    l          /    \  )    ~~~.  / `/ ~ / \.__/l_
        |     \     _.-       ~-{__     l  :  l._Z~-.___.--~
        |      ~---~           /   ~~ ---\_  ' __[>
        l  .                _.^   ___     _>-y~
         \  \     .      .-~   .-~   ~>--   /
          \  ~---             /     ./  _.-'
            -.,_____.,_  _.--~\     _.-~
                               `. ~(
                                 )  \
                                /,`--'~\--'~\

LONG);
	setup();
	replace_program(ROOM);
}
