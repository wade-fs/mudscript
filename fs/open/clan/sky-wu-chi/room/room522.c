inherit ROOM;
void create() {
	set( "short", "血痕居-螳螂拳" );
	set( "owner", "holeman" );
	set( "build", 10055 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room524.c",
		"east"      : "/open/clan/sky-wu-chi/room/room525",
		"south"     : "/open/clan/sky-wu-chi/room/room519.c",
	]) );
	set( "long", @LONG

    太祖長拳身為首    懷德的摔捋硬崩
    韓通的通背為母    劉興的拘摟採手
    溫元的短拳更奇    燕青的占拿跌法
    馬藉的短打最奇    林沖的鴛鴦腳強
    孫恒的猴拳且盛    孟甦的七勢連拳
    黃粘的靠身難近    崔連的窩裡剖捶
    綿世的面掌飛疾    楊滾的棍採入直
    金相的磕手通拳    王朗的螳螂總敵



LONG);
	setup();
	replace_program(ROOM);
}
