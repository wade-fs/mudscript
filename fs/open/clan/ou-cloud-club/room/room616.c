inherit ROOM;
void create() {
	set( "short", "$HIC$暴龍道$NOR$" );
	set( "object", ([
		"amount4"  : 192,
		"file5"    : "/open/killer/obj/atman_pill",
		"amount10" : 1,
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"file10"   : "/open/gblade/obj/sa-head",
		"file2"    : "/open/fire-hole/obj/r-pill",
		"file9"    : "/open/fire-hole/obj/k-pill",
		"amount5"  : 119,
		"amount8"  : 49,
		"amount2"  : 186,
		"amount9"  : 82,
		"file4"    : "/open/fire-hole/obj/y-pill",
		"amount3"  : 54,
		"amount6"  : 283,
		"file3"    : "/open/fire-hole/obj/w-pill",
		"amount1"  : 85,
		"amount7"  : 235,
		"file7"    : "/open/fire-hole/obj/b-pill",
		"file8"    : "/open/fire-hole/obj/g-pill",
		"file6"    : "/open/fire-hole/obj/p-pill",
	]) );
	set( "owner", "taa" );
	set( "build", 10008 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room618",
		"east"      : "/open/clan/ou-cloud-club/room/room431",
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
