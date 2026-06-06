inherit ROOM;
void create() {
	set( "short", "刀魂淨地" );
	set( "owner", "hild" );
	set( "build", 10208 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/sky-wu-chi/room/room546.c",
		"out"       : "/open/clan/sky-wu-chi/room/room441",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "long", @LONG
這裡是所有刀的葬身也是藏身之地，有絕世好刀、也有破銅爛刀，但
是你很難從外表去看出來一把刀的好壞，一定要經過加持後才能使用之。
若你真的想要從這裡找出一把好的刀，便要仔仔細細的去尋找，但至於有
無可能找到你理想的刀，除了平常求神拜佛外，你也只能靠運氣了。
LONG);
	setup();
	replace_program(ROOM);
}
