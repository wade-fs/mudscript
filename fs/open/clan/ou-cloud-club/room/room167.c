inherit ROOM;
void create() {
	set( "short", "水晶蟲洞後段" );
	set( "owner", "dracula" );
	set( "object", ([
		"amount1"  : 1,
		"file3"    : "/open/mon/obj/ghost-claw",
		"amount3"  : 1,
		"file1"    : "/open/ping/obj/chilin_legging",
	]) );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room154",
	]) );
	set( "build", 10040 );
	set( "long", @LONG
水晶蟲壁繼續無盡延伸。你注意到這裡的蛆蛹顆顆都閃耀著晶瑩光芒的血腥赭紅
色，薄薄的蛹膜像是隨時會被血水撐得爆裂開來一般，





闃黑的蟲洞長廊裡一片死寂，所有聲音都被屍骨所吸蝕。

這已經是最接近死亡的地方。寒冷與恐懼緊緊嵌刺進你冰涼纖弱的心臟裡



LONG);
	setup();
	replace_program(ROOM);
}
