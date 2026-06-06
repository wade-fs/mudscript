inherit ROOM;
void create() {
	set( "short", "水晶蟲洞前段" );
	set( "owner", "dracula" );
	set( "object", ([
		"file10"   : "/open/ping/obj/gold_hand",
		"file5"    : "/open/scholar/obj/icefan",
		"file1"    : "/daemon/class/blademan/obj/shield",
		"file4"    : "/daemon/class/fighter/armband",
		"amount8"  : 1,
		"file2"    : "/open/dancer/obj/yuawaist",
		"amount1"  : 1,
		"amount6"  : 1,
		"amount10" : 1,
		"amount9"  : 1,
		"amount7"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"file3"    : "/open/mon/obj/ghost-legging",
		"file9"    : "/open/ping/obj/ring-2",
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"file8"    : "/open/mon/obj/ghost-cloak",
		"amount2"  : 1,
		"file6"    : "/open/snow/obj/figring",
	]) );
	set( "build", 10080 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room167.c",
		"down"      : "/open/clan/ou-cloud-club/room/room109",
	]) );
	set( "long", @LONG
這是一個極寒冷極絕望的異空間甬道。眼中所見只有一片蕭索的冰凍。洞穴四壁
均為光滑晶瑩、無法攀附的水晶岩壁......無數個大小不一的乳白透明蛆蛹包裹著
千萬光年前的死屍骨骸，孤寂地垂懸在遙遠的甬道頂端。似有若無的鬼魂痛苦呻
吟景象，不斷如失了焦的畫面般重疊在你的視網模之間......

彷彿聽到遠處傳來數萬個骯髒骨盆相撞擊的聲音，液化腦隨在骨管中流動的聲音。

一股不知名的詭異力量促使你繼續向西方走去......

LONG);
	setup();
	replace_program(ROOM);
}








