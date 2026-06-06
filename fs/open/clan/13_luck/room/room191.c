inherit ROOM;
void create() {
	set( "short", "蟻王巢" );
	set( "exits", ([
		"up"        : "/open/clan/13_luck/room/room192",
	]) );
	set( "long", @LONG

　　一進到這裡，隨即聞到一股嗆鼻的腥味，定神一看這裡的四周散
佈著許多小動物的屍骸及血跡，看起來滿嚇人的，你猜測這些應是蟻
王所吃完留下的屍骸。突然，你感到一股濃濃的殺氣，原來蟻兵已發
現你的存在。心想，在不走就要成蟻王的食物了。

LONG);
	setup();
	replace_program(ROOM);
}
