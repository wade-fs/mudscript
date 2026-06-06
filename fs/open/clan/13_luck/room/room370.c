inherit ROOM;
void create() {
	set( "short", "乾坤殿" );
	set( "owner", "evonne" );
	set( "build", 10488 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room366",
	]) );
	set( "long", @LONG

　　進到殿內，這才發現原來乾坤殿竟是一個三角立體空間，全以特
殊的奧里哈康金屬建成的，除了出入口之外，完全密不透風。殿中的
太極圈，分陰陽兩極，稀有烏金的陰極內有天外隕石，燒起烈日似的
陽火，千年寒鐵的陽極內有寒精堆砌成圓月，透出月華似的冷寒。
LONG);
	setup();
	replace_program(ROOM);
}
