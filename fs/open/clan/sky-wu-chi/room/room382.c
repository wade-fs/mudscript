inherit ROOM;
void create() {
	set( "short", "白雪公主的房間---" );
	set( "owner", "panhermes" );
	set( "object", ([
		"amount8"  : 370,
		"file9"    : "/open/mogi/castle/obj/sspill",
		"amount9"  : 400,
		"file8"    : "/open/mogi/castle/obj/sspill",
	]) );
	set( "build", 10061 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room383",
	]) );
	set( "long", @LONG
你正在白雪公主的房間，一片粉紅色的景像讓你在不知不覺中也變的溫柔起來，
就連太陽也都照射出粉紅色的光芒。一張粉紅色的書桌上擺滿了各式各樣的書籍
，想必白雪公主也是個愛看書的人，粉紅的倚子上則有一件白色的淑女帽，在房
間中格外顯眼。
LONG);
	setup();
	replace_program(ROOM);
}
