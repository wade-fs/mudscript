inherit ROOM;
void create() {
	set( "short", "虛擬海洋" );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room47",
		"east"      : "/open/clan/13_luck/room/room32.c",
		"south"     : "/open/clan/13_luck/room/room34.c",
	]) );
	set( "long", @LONG

    漂浮在海上也有好幾個對時了，妳始終找不路，正當妳在煩惱時
，突然發現前方好像有人的吵雜聲，可是妳在怎麼用力看還是看不道
路地，於是妳就依著聲音的方向划去，聲音越來越大聲了，看來朝著
這方向去應該是能找到出路了。    

LONG);
	setup();
	replace_program(ROOM);
}
