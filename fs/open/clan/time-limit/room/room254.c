inherit ROOM;
void create() {
	set( "short", "星際大冒險1" );
	set( "object", ([
		"file3"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount8"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount1"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount3"  : 1,
		"amount4"  : 1,
		"amount7"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount5"  : 1,
		"amount2"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount9"  : 1,
	]) );
	set( "build", 10023 );
	set( "owner", "sulamark" );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room189",
		"north"     : "/open/clan/time-limit/room/room253",
	]) );
	set( "long", @LONG
    踏上和式地板，淡淡柚木地板氣味在空氣中飄盪，妳的腳掌輕輕的
趴在地板上，服貼的想馬上躺下去睡著，可惜這裡終究是小小邦的房間
，妳想休息，最好跟主人講一聲。窗台的風鈴不時傳來悅耳的鈴聲，和
煦的晚風不冷不熱，剛剛好幫妳輕解了煩戮鄐W擺了一壺溫好的清酒
，妳一飲而盡，完全不想再離開這裡了。
LONG);
	setup();
	replace_program(ROOM);
}
