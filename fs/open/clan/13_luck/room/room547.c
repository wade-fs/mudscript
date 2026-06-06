inherit ROOM;
void create() {
	set( "short", "珍重" );
	set( "owner", "dfyw" );
	set( "object", ([
		"amount7"  : 418,
		"amount1"  : 1,
		"amount8"  : 9,
		"amount2"  : 1,
		"file9"    : "/obj/stone/suipian",
		"file8"    : "/obj/stone/jiao",
		"file1"    : "/open/capital/obj/4-2",
		"file2"    : "/open/capital/obj/4-1",
		"file7"    : "/obj/stone/powder",
		"amount9"  : 44,
	]) );
	set( "build", 10042 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room555",
		"east"      : "/open/clan/13_luck/room/room550.c",
		"up"        : "/open/clan/13_luck/room/room548",
		"west"      : "/open/clan/13_luck/room/room546.c",
	]) );
	set( "long", @LONG
我們要珍惜每一段關係。假設你還能活60年好了 !
等你60年後，快死之前，請你拿起一隻筆和一張紙，想一想，寫下你這
一生中「 真正愛過 」的 10 個人。爸媽兄弟姊妹都可以，是真正愛過
的喔 !那種只愛三個禮拜的不算是真愛。能寫到超過是最好，不到 1 0
個也沒關係。我現在想，我就好像寫不出來10 個呢！
LONG);
	setup();
	replace_program(ROOM);
}
