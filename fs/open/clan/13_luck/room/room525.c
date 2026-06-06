inherit ROOM;
void create() {
	set( "short", "前廳一" );
	set( "build", 10044 );
	set( "owner", "fireer" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room524.c",
		"south"     : "/open/clan/13_luck/room/room518",
		"east"      : "/open/clan/13_luck/room/room526.c",
	]) );
	set( "long", @LONG
當你踏進這廳堂一步，你的雙眼突然被一陣金色光芒給刺傷，等了
好一會兒，你的雙眼才漸漸的恢復，這時你才發現眼前的裝飾已經不是
能用奢華來形容的了。廳中四方八穩，頗有一爭天下武林之霸氣，空氣
中似乎瀰漫著些微冷殺的氣氛，多麼冷的感覺啊。往前方可通達易水樓
的中心『水雲廳』。
LONG);
	setup();
	replace_program(ROOM);
}
