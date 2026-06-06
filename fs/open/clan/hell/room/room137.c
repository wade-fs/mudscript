inherit ROOM;
void create() {
	set( "short", "裝備室" );
	set( "light_up", 1 );
	set( "build", 11442 );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/room140",
	]) );
	set( "long", @LONG
這裡是嘿嘿呵呵放裝備ㄉ地方,處處擺放著嘿嘿呵呵平時練工時所穿ㄉ裝備,雖然不是上等貨,但卻夠讓嘿嘿呵呵練功ㄌ,裡面放著寒冰,妖幻之爪,寶蓮靴,天蠶絲帶.魔法盾,金之手套.妖行甲,...............等等,如果你絕ㄉ有更適合嘿嘿呵呵川ㄉ裝備請指教
LONG);
	setup();
	replace_program(ROOM);
}
