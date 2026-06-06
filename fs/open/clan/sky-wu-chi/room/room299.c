inherit ROOM;
void create() {
	set( "short", "匕首房" );
	set( "owner", "sblade" );
	set( "light_up", 1 );
	set( "build", 10715 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room189",
		"south"     : "/open/clan/sky-wu-chi/room/room307.c",
		"east"      : "/open/clan/sky-wu-chi/room/room364.c",
		"west"      : "/open/clan/sky-wu-chi/room/room257.c",
	]) );
	set( "long", @LONG
這裡是一間小小的匕首房,一面掛滿匕首的牆,一絲陰暗的光線,
一台精緻的刑檯,幾件小小的拷問工具,精簡的組成了這間匕首房,
小木桌上散佈著幾張名單,上面是一些得罪過伊耳謎的人,
伊耳謎最喜歡在這裡計劃如何暗殺人了！！
LONG);
	setup();
	replace_program(ROOM);
}
