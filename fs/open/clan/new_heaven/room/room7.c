inherit ROOM;
void create(){
	set( "owner", "xing" );
    set( "short", "$HIY$幽林小築$NOR$" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/new_heaven/room/room4",
        "enter"     : "/open/clan/new_heaven/room/room8",
	]) );
	set( "long", @LONG
清澈的溪水, 茂盛的竹林, 這裡就是傲笑紅塵所居住的幽林小築, 
自從他得道之後, 就到了新天堂居住, 並運用本身神力在雲上建立了如
此的窩, 平常都會在這裡參研更高深的武道, 有時也會下凡, 幫助需要
幫助的人, 斬妖除魔
LONG);
	setup();
	replace_program(ROOM);
}
