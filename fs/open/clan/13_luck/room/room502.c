inherit ROOM;
void create() {
	set( "short", "開陽堂大廳" );
	set( "object", ([
		"amount5"  : 1,
		"amount3"  : 1,
		"amount4"  : 1,
		"file5"    : "/open/mon/obj/ghost-claw",
		"file2"    : "/open/mon/obj/ghost-claw",
		"file3"    : "/open/mon/obj/ghost-claw",
		"amount1"  : 1,
		"file1"    : "/open/mon/obj/ghost-claw",
		"file4"    : "/open/mon/obj/ghost-claw",
		"amount2"  : 1,
	]) );
	set( "build", 10239 );
	set( "owner", "fireer" );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room513.c",
		"north"     : "/open/clan/13_luck/room/room501",
	]) );
	set( "long", @LONG
你冒著必死的決心來到了開陽堂，你看到廳內有個人正在練武，你
凝神一看，看到白嘯衣正在練功，可是就在此時白嘯衣好像發現了你的
存在，他以為你在偷看他練功，突然間他向你發功想取你性命，你以萬
分驚險之式閃過了他這突發之招，然後你施展輕功加速離開了此地。
LONG);
	setup();
	replace_program(ROOM);
}
