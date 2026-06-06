inherit ROOM;
void create() {
	set( "short", "$HIR$絕焱$NOR$" );
	set( "owner", "bbsboss" );
	set( "light_up", 1 );
	set( "object", ([
		"amount5"  : 1,
		"file2"    : "/obj/gift/hobowdan",
		"amount10" : 1,
		"amount6"  : 1,
		"amount9"  : 1,
		"file6"    : "/obj/gift/xiandan",
		"file8"    : "/open/mon/obj/ghost-claw",
		"amount3"  : 1,
		"file3"    : "/open/mogi/dragon/obj/key",
		"amount8"  : 1,
		"amount4"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/ghost-hole/obj/flute",
		"amount2"  : 1,
		"file5"    : "/obj/gift/xiandan",
		"file9"    : "/open/gblade/obj/sa-head",
		"file10"   : "/open/mon/obj/ghost-claw",
		"file7"    : "/open/gblade/obj/sa-head",
		"file4"    : "/obj/gift/xisuidan",
		"amount7"  : 1,
	]) );
	set( "build", 10019 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room189",
		"west"      : "/open/clan/ou-cloud-club/room/room186.c",
	]) );
	set( "long", @LONG

      $HIY$此乃至陽之物，能給予敵人致命傷害$NOR$


咦!!這不是風林山寨寨主雷霸的隨身武器嘛....
莫非..他也被小馬給掛了.....
傳言雷霸的六脈神劍已經出神入化....一被他封穴就別想解開..
小馬果真藝高人膽大....敢在此人頭上動土....
LONG);
	setup();
	replace_program(ROOM);
}
