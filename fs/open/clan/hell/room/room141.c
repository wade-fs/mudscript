inherit ROOM;
void create() {
	set( "short", "防風林缺口" );
	set( "exits", ([
		"north"     : "/open/clan/hell/room/room134",
		"east"      : "/open/clan/hell/room/room138.c",
		"west"      : "/open/clan/hell/room/room144.c",
	]) );
	set( "long", @LONG
沿著沙灘飛掠至此,發現北面的防風林在此似乎有個缺口,地上也開始混雜了
一些泥土,而不是柔軟的沙粒,往北面防風林附近仔細的觀察了一下,果然發現地
上有一些隱隱約約的足跡,看來此地當可尋得島上的道路,你抱著尋得人煙的喜
悅,提起身法,往林中投去.

LONG);
	setup();
	replace_program(ROOM);
}
