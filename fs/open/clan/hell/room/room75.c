inherit ROOM;
void create() {
	set( "short", "$HIR$地道$NOR$" );
	set( "light_up", 1 );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/open/magic-manor/obj/magic-sign",
	]) );
	set( "build", 1137 );
	set( "exits", ([
		"south"     : "/open/clan/hell/room/room76.c",
		"west"      : "/open/clan/hell/room/room78",
		"east"      : "/open/clan/hell/room/room77",
	]) );
	set( "long", @LONG
這裡是陰曹地府裡的神秘地方，通常除了高階層人
員能來到這裡外，其他人是不準許來到這的，看似陰暗
的地道，似乎在一旁也還有著房間。如今想到自已已來
到這，就不禁打了些冷顫，在一旁的房間裡也不時的傳
出所多聲音，似忽是在那哀嚎著。

LONG);
	setup();
	replace_program(ROOM);
}

