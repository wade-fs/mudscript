inherit ROOM;
void create() {
	set( "short", "Ｂｅｂｅ的神秘小屋" );
	set( "owner", "uesz" );
	set( "item_desc", ([
		"c_room_item BEBE的客廳" : @ITEM
　　　　


　　　　　﹛耤耤蒬o裡是ＢＥＢＥ神秘花園～～～

　　　　　　　　　
ITEM,
	]) );
	set( "light_up", 1 );
	set( "build", 10032 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room117",
		"west"      : "/open/clan/hell/room/room5.c",
	]) );
	set( "long", @LONG

　　你剛來到這裡的大門，就感覺到一股不知哪裡來的聲音
對你說『～～小孩子～這裡不是你來的地方喔～～還不快回
家讀書』，你再仔細的一看，原來這裡就是傳說中Ｂｅｂｅ
的神秘小屋‧
LONG);
	setup();
	replace_program(ROOM);
}
