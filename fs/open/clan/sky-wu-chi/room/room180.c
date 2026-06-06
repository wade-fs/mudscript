inherit ROOM;
void create() {
	set( "short", "$HIB$邪月正廳$NOR$" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room182.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"south"     : "/open/clan/sky-wu-chi/room/room178.c",
	]) );
	set( "long", @LONG
走到這,突然你停止了腳步,對於邪月正廳,你不禁嘖嘖稱奇了起來
整間正廳用了邪月水晶打造而成,所以,浮現著輕藍色的光芒....
閃耀的水晶正閃閃發亮著,使你眼睛因光芒而漸漸失去感覺,模糊中
只見幾個大字....邪~~~月~~~正~~~廳
LONG);
	setup();
	replace_program(ROOM);
}
