inherit ROOM;
void create() {
	set( "short", "$HIG$DABBIE的閨房$NOR$" );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "object", ([
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"amount8"  : 1,
		"amount4"  : 1,
		"file1"    : "/open/dancer/obj/yuaboots",
		"file3"    : "/open/ping/questsfan/obj/diamond_hands",
		"file2"    : "/open/ping/questsfan/obj/diamond_cloak",
		"amount9"  : 150,
		"file6"    : "/open/capital/room/king/obj/km-cloak",
		"file4"    : "/open/prayer/obj/boris-cloth",
		"amount6"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"file8"    : "/daemon/class/blademan/obj/shield",
		"amount1"  : 1,
		"amount3"  : 1,
		"file9"    : "/open/killer/obj/s_pill",
	]) );
	set( "light_up", 1 );
	set( "build", 12120 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room151.c",
		"south"     : "/open/clan/sky-wu-chi/room/room75.c",
	]) );
	set( "long", @LONG
你走進了一個名為『朱雀』走廊的地方，你才剛走進來這裡時你馬上
發現四周的空氣因為太乾燥而產生一種爆裂的聲音，你仔細的想了一下為
什麼會這樣子，在看了一下四週都是用火紅的熔岩所做成的，馬上想到這
裡就是屬於南方的朱雀之所在，你開始覺得很熱，且越走進去你發覺熱度
是越來越高，漸漸的你也快受不了，突然間你看到了一隻火鳳凰就在前面
正在梳理牠自己的羽毛，當他看到你時，牠周圍的火燄就突然的燒的更烈
了起來，好像是在你說已經闖入了不該闖入的地方似的。

LONG);
	setup();
	replace_program(ROOM);
}
