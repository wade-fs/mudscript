inherit ROOM;
void create() {
	set( "short", "天璣堂大廳" );
	set( "object", ([
		"file8"    : "/open/mon/obj/ghost-helmet",
		"file2"    : "/open/mon/obj/ghost-helmet",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/mon/obj/ghost-cloak",
		"file5"    : "/open/mon/obj/ghost-cloak",
		"file4"    : "/open/mon/obj/ghost-cloak",
		"file3"    : "/open/mon/obj/ghost-cloak",
		"amount7"  : 1,
		"amount10" : 1,
		"file7"    : "/open/mon/obj/ghost-cloak",
		"amount3"  : 1,
		"file10"   : "/open/mon/obj/ghost-helmet",
		"amount8"  : 1,
		"file1"    : "/open/mon/obj/ghost-cloak",
		"amount9"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/mon/obj/ghost-helmet",
	]) );
	set( "owner", "aaabc" );
	set( "build", 12137 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room520",
		"north"     : "/open/clan/13_luck/room/room509",
	]) );
	set( "long", @LONG
你冒著必死的決心來到了天璣堂，你突然看到一陣人影閃過，叔夜
衣帶著一群殺手出現在你的後方，由他們的衣著看來好像是要出門執行
任務，每個人身上都散發出一種殺人的氣息，令你感到死亡氣息。這時
叔夜衣說道：「請盡速離去，不然殺無赦。」，於是你加快腳步離開了
天璣堂大廳。
LONG);
	setup();
	replace_program(ROOM);
}
