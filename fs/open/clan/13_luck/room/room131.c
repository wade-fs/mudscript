inherit ROOM;
void create() {
	set( "short", "怒海潮" );
	set( "owner", "mill" );
	set( "object", ([
		"amount5"  : 1,
		"amount4"  : 1,
		"file2"    : "/daemon/class/fighter/figring",
		"file4"    : "/open/capital/guard/gring",
		"amount3"  : 1,
		"amount9"  : 1,
		"file5"    : "/daemon/class/blademan/obj/iceblade",
		"amount6"  : 1,
		"amount1"  : 7,
		"file8"    : "/open/killer/obj/k_ring",
		"file1"    : "/open/mogi/castle/obj/sspill",
		"amount2"  : 1,
		"amount10" : 1,
		"file3"    : "/open/mogi/castle/obj/lochagem",
		"amount8"  : 1,
		"file9"    : "/open/mon/obj/ghost-cloak",
		"file10"   : "/daemon/class/blademan/obj/iceblade",
		"file6"    : "/open/killer/obj/k_ring",
	]) );
	set( "build", 10070 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room129.c",
		"south"     : "/open/clan/13_luck/room/room255",
		"north"     : "/open/clan/13_luck/room/room134.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
                                      =
    世上多少紅塵事，終歸浮沉於煙中。

        多少情緣斷續中，遺憾在心難終了。

十三幫主雖是當今武林的高手，但是唯一感嘆的卻是生命最重要的那個女
人，拉拉，在他眼睛中，看到了眼淚，不停的哭泣，哭完了流下了血淚，
血流完了，只剩一片的癡心，這片海洋便是十三奇景之一的血淚紅海。


LONG);
	setup();
	replace_program(ROOM);
}
