// Room : /open/clan/sky-wu-chi/room/room14.c
inherit ROOM;
void create(){
	set( "cmkroom", 1 );
	set( "light_up", 1 );
	set( "long", @LONG
這裡是花巷草弄一號，身旁的是小新
的狗窩，看起來小小的，其實是個大宅院
裡面是小新家的人所住的房間，平常早上
小新家的人都不在，所以看起來空空蕩蕩
的，不過仔細一瞧，還是有人嘛。。。。
只不過小新家的人都在睡而以。

LONG);
	set( "short", "$HIC$【$NOR$小新家大門$HIC$】$NOR$小狗窩" );
	set( "object", ([
		"file6"    : "/open/gsword/obj1/bpball",
		"amount6"  : 1,
		"amount8"  : 1,
		"amount1"  : 1,
		"amount10" : 1,
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount4"  : 1,
		"amount9"  : 1,
		"file5"    : "/open/gsword/obj1/bpball",
		"amount5"  : 1,
		"amount7"  : 1,
		"file1"    : "/open/quests/snake/npc/obj/snake-key-2",
		"file9"    : "/open/gsword/obj1/bpball",
		"file10"   : "/open/gsword/obj1/bpball",
		"file4"    : "/open/gblade/obj/sa-head",
		"amount3"  : 1,
		"file7"    : "/open/gsword/obj1/bpball",
		"file8"    : "/open/mogi/dragon/obj/key",
	]) );
	set( "build", 10055 );
	set( "exits", ([
		"enter"     : "/open/clan/sky-wu-chi/room/room154.c",
		"east"      : "/open/clan/sky-wu-chi/room/room8.c",
	]) );
	set( "clan_room", "天道無極" );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	setup();

	}
