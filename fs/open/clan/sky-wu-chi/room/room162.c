inherit ROOM;
void create() {
	set( "short", "幕後錢莊的家" );
	set( "owner", "yuki" );
	set( "object", ([
		"amount4"  : 11000,
		"file8"    : "/obj/gift/xisuidan",
		"file4"    : "/open/killer/obj/bellstar",
		"amount5"  : 16,
		"amount3"  : 332,
		"amount9"  : 1,
		"file6"    : "/open/capital/obj/icer",
		"amount8"  : 1,
		"file10"   : "/obj/stone/jiao",
		"amount10" : 3,
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount1"  : 1,
		"file1"    : "/open/ping/questsfan/obj/diamond_armor",
		"amount7"  : 1,
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"file2"    : "/open/killer/obj/fire-knife",
		"file3"    : "/obj/stone/powder",
		"amount6"  : 1,
		"file5"    : "/obj/stone/suipian",
	]) );
	set( "light_up", 1 );
	set( "build", 11123 );
	set( "exits", ([
		"up"        : "/open/clan/sky-wu-chi/room/room203",
		"down"      : "/open/clan/sky-wu-chi/room/room204.c",
		"west"      : "/open/clan/sky-wu-chi/room/room202.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "long", @LONG
走進這裡突然一陣閃光在眼前
有金光
白光
五色的光芒
你拿出太陽眼鏡帶上
才看清楚
原來...牆壁是金子作的
玻璃是鑽石鑲成的
地板全都是白銀
原來你到了一個大財主的家了
這裡是大財主smalltwo的家..幫裡有95%的錢是靠它在提供的
這裡豪華的設備讓你瞠目結舌
LONG);
	setup();
	replace_program(ROOM);
}
