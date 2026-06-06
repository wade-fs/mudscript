inherit ROOM;
void create() {
	set( "short", "小涼被" );
	set( "owner", "super" );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room129",
	]) );
	set( "object", ([
		"file9"    : "/open/magic-manor/obj/water-ball",
		"amount2"  : 1,
		"file5"    : "/daemon/class/fighter/armband",
		"file3"    : "/open/magic-manor/obj/wood-ball",
		"amount5"  : 1,
		"amount3"  : 1,
		"amount1"  : 1,
		"file1"    : "/obj/gift/hobowdan",
		"amount9"  : 1,
		"file2"    : "/open/magic-manor/obj/fire-ball",
	]) );
	set( "light_up", 1 );
	set( "build", 10011 );
	set( "long", @LONG
這是涼儲放冬天衣物的儲藏室，一疊疊的厚重衣物堆滿了半個房間
看來涼是個很念舊的人，捨不得將陪伴多年的衣物丟掉，
房間的最深處有個塵封的鑲金箱子，看來年代相當久遠，
牆壁上卻掛了一把龍骨之星，以及全套的防具，
原來這也是涼放裝備的密秘房間，難怪不想讓人進來
大概也是怕宵小竊賊吧...
LONG);
	setup();
	replace_program(ROOM);
}
