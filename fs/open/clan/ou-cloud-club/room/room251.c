inherit ROOM;
void create() {
	set( "short", "$HIC$Nine Inch Nails$NOR$" );
	set( "owner", "devil" );
	set( "object", ([
		"file1"    : "/open/killer/obj/bellstar",
		"file8"    : "/open/killer/obj/bellstar",
		"file5"    : "/open/killer/obj/bellstar",
		"amount5"  : 98534,
		"amount3"  : 99999,
		"amount4"  : 1,
		"amount8"  : 99999,
		"file7"    : "/open/killer/obj/bellstar",
		"file6"    : "/open/killer/obj/bellstar",
		"file4"    : "/open/mogi/castle/obj/sspill",
		"amount9"  : 99000,
		"amount2"  : 99999,
		"file3"    : "/open/killer/obj/bellstar",
		"amount7"  : 99999,
		"amount1"  : 99999,
		"amount6"  : 99999,
		"file10"   : "/open/killer/obj/bellstar",
		"file9"    : "/open/killer/obj/bellstar",
		"file2"    : "/open/killer/obj/bellstar",
		"amount10" : 98681,
	]) );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room255",
		"up"        : "/open/clan/ou-cloud-club/room/room177.c",
	]) );
	set( "build", 15614 );
	set( "long", @LONG
  
  The Fragile 打破既定音樂格局，全面改造音樂結構，優美精緻
的旋律織進不協調的吵雜空間，並且無預警的轉入交響弦樂的世界
，然後再切入另一境界，更出人意表的是弦樂與電子合成器的鋪設
比重，再經由獨到的思緒過濾，使作品萃取出一種全然不同的旋律
架勢。

LONG);
	setup();
	replace_program(ROOM);
}
