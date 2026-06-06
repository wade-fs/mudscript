inherit ROOM;
void create() {
	set( "short", "世外桃源" );
	set( "owner", "sevenll" );
	set( "build", 23 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room100",
		"enter"     : "/open/clan/13_luck/room/room675",
	]) );
	set( "long", @LONG
傳說中只有三個人來過此境,一切都令你十分的驚奇,四周傳來
陣陣的水聲,你心理想著會不會有一作瀑布在眼前,突然間一道
強烈的水柱落下來,你抬頭一望,你竟然在一個瀑布的正下方!!
前面有的形狀詭異的牆,你不禁想要推開他。
LONG);
	setup();
	replace_program(ROOM);
}
