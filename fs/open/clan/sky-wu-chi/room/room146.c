inherit ROOM;
void create() {
	set( "short", "$HIY$NISA的浴室$NOR$" );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "light_up", 1 );
	set( "build", 10240 );
	set( "object", ([
		"file8"    : "/open/ping/questsfan/obj/posthumous",
		"amount7"  : 1,
		"file4"    : "/open/sky/obj/lucky_grasslink",
		"amount10" : 1,
		"amount8"  : 1,
		"file1"    : "/open/mon/obj/ghost-claw",
		"amount5"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/sky/obj/lucky_grasslink",
		"file7"    : "/open/ping/questsfan/obj/stone",
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"amount1"  : 1,
		"amount4"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
	]) );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room78.c",
		"north"     : "/open/clan/sky-wu-chi/room/room144",
	]) );
	set( "long", @LONG
你走在名為『白虎』走廊上你感覺到有一種不寒而慄的殺氣，心種有股如同
走在鋼索般一樣危險而刺激，你巧運起內勁正等待未知的可能性。當你走到走廊
的中段時，你乍然的發現在東方有一個奇特的聚會場所。於是乎，你就越興奮的
朝『七彩結界』的方向走了過去。但是卻有一股奇特的『曼沱羅之盾』擋住了你
要往東邊走去的路中，那發現你可能要集中精神才有辦法走過。

LONG);
	setup();
	replace_program(ROOM);
}
