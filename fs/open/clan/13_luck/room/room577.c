inherit ROOM;
void create() {
	set( "short", "前廳" );
	set( "owner", "roarii" );
	set( "object", ([
		"amount8"  : 1,
		"amount2"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"amount9"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 13050 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room578",
		"north"     : "/open/clan/13_luck/room/room576",
	]) );
	set( "long", @LONG
當你踏進這廳堂一步，你眼前的裝飾已經不是能用奢華來形容
的了。廳中四方八穩，頗有一爭天下武林之霸氣，空氣中似乎瀰漫
著些微冷殺的氣氛，多麼冷的感覺啊。往前方可通達易水樓的中心
『水雲廳』。
LONG);
	setup();
	replace_program(ROOM);
}
