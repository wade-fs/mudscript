inherit ROOM;
void create() {
	set( "short", "望月樓二樓" );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/13_luck/room/room593.c",
		"down"      : "/open/clan/13_luck/room/room114.c",
		"east"      : "/open/clan/13_luck/room/room633.c",
		"west"      : "/open/clan/13_luck/room/room129.c",
		"north"     : "/open/clan/13_luck/room/room647.c",
		"south"     : "/open/clan/13_luck/room/room637",
	]) );
	set( "long", @LONG

    你正走在望月樓二樓的走廊上，店小二裏裏外外忙得團團轉。往
裡面望去，只見那房間的裝修充滿了盛明時候的風味，滿屋子的琳瑯
玉石襯著柔和的光線，洋溢著溫馨的氣氛。八仙桌上置著一壺剛泡好
的烏龍茶，只覺茶香沁入心脾，精神為之一爽。

LONG);
	setup();
	replace_program(ROOM);
}
