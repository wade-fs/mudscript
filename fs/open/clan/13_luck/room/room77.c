inherit ROOM;
void create() {
	set( "short", "劍客居" );
	set( "build", 678 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room76",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    這裡是狂想仙劍派劍客的專屬房間，也是他平常用來鑽研各種武
功秘笈的地方，房間內的擺設非常簡單，只有幾本書，一把劍和一枝
釣竿，大部份的時間都不在家，只有特定的時間會出現於此，修練武
功及秘笈，將自己的劍術發揮到及至，這是身為劍客一生的使命。

LONG);
	setup();
	replace_program(ROOM);
}
