inherit ROOM;
void create() {
	set( "short", "憶廬" );
	set( "owner", "dunga" );
	set( "object", ([
		"amount5"  : 1,
		"file5"    : "/open/port/obj/wolf_ring",
		"amount8"  : 1,
		"amount4"  : 1,
		"file1"    : "/open/killer/obj/k_ring",
		"file3"    : "/daemon/class/bonze/puty_pullium",
		"amount3"  : 1,
		"amount6"  : 1,
		"file8"    : "/open/port/obj/wolf_ring",
		"amount2"  : 1,
		"file6"    : "/daemon/class/fighter/figring",
		"file4"    : "/open/wind-rain/obj/sun_red_cloth",
		"file7"    : "/open/gsword/obj/may_ring",
		"file2"    : "/open/tendo/obj/chaosbelt",
		"amount1"  : 1,
		"amount7"  : 1,
	]) );
	set( "build", 10734 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room125",
	]) );
	set( "long", @LONG
                 
                 憶廬
                 
從思定走進來為邪王的武器房憶廬，四周以塞北
至寒白玉石為壁，若你內力精深以達如意自轉的
境界當可以勁測知，此牆厚過兩人寬，真不知當時是
如何運過來的，這絕非人力所能為，但偏偏就在
你眼前，這放置著邪王出道至今所用的武器，相信當
邪王站在這時定當回憶起以往至今大小的猛戰，每
次都是以堅毅的信念度過，而今可以在此回味，
彷彿不過昨日....
然後後面就是邪王和其妻的閨房了
LONG);
	setup();
	replace_program(ROOM);
}
