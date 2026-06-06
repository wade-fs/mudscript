inherit ROOM;
void create() {
	set( "short", "$HIR$穹蒼$HIC$無涯$NOR$" );
	set( "owner", "robo" );
	set( "exits", ([
		"down"      : "/open/clan/dark-forest/room/room23",
		"west"      : "/open/clan/dark-forest/room/room28",
	]) );
	set( "object", ([
		"file8"    : "/open/mogi/castle/obj/sspill",
		"file2"    : "/open/mon/obj/thousand-nectar",
		"amount1"  : 1,
		"amount4"  : 47,
		"amount5"  : 370,
		"file5"    : "/open/fire-hole/obj/g-pill",
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"file4"    : "/open/fire-hole/obj/w-pill",
		"file7"    : "/open/ping/questsfan/obj/stone",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"file3"    : "/open/fire-hole/obj/r-pill",
		"amount10" : 1,
		"amount3"  : 131,
		"amount8"  : 42,
		"amount2"  : 85,
		"amount6"  : 8,
		"file10"   : "/open/ghost-hole/obj/water-spirit",
	]) );
	set( "build", 10464 );
	set( "light_up", 1 );
	set( "long", @LONG
踏入此地，讓人不禁讚嘆，在人間怎會有如此奇幻的地方
，放眼望去無邊無盡，有一種心曠神怡的感覺。此時，赫然發
現一個驚人的景象，在那綻藍的天際，有一位世外高人運起一
身血紅氣勁吸取這天地之氣以增強其自身功力，此人便是歷代
守護渾天寶鑑中血穹蒼光晶一族的族王--穹蒼(Juan)。為保光
晶祕密，族王穹蒼正欲殺了你以守護光晶，你見此象，二句不
說，轉身拔腿就跑，怎知一股血紅氣勁己殺至...
．
LONG);
	setup();
	replace_program(ROOM);
}
