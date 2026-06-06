inherit ROOM;
void create() {
	set( "short", "小雪滴房間" );
	set( "owner", "panhermes" );
	set( "object", ([
		"amount2"  : 1,
		"amount1"  : 1,
		"file6"    : "/open/killer/headkill/obj/world_dag",
		"file5"    : "/open/mon/obj/ghost-helmet",
		"file2"    : "/open/wu/obj/figring",
		"amount4"  : 1,
		"amount10" : 1,
		"amount7"  : 1,
		"file3"    : "/open/wu/npc/obj/armband",
		"amount9"  : 1,
		"file9"    : "/daemon/class/blademan/obj/shield",
		"amount3"  : 1,
		"file1"    : "/open/mogi/castle/obj/lochagem",
		"amount8"  : 1,
		"file7"    : "/open/mon/obj/ghost-legging",
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"amount6"  : 1,
		"amount5"  : 1,
		"file4"    : "/open/wind-rain/obj/sun_red_cloth",
		"file10"   : "/open/tendo/obj/chaosbelt",
	]) );
	set( "light_up", 1 );
	set( "build", 10005 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room349",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "long", @LONG
高聳的山勢至此直轉而下，一抹清渠隨著坡道奔向
前方，順著山勢往下流去。兩旁的坡道上長滿了野生的
杏花，映著陽光，如噴花蒸霧一般，攀藤撫樹而下，只
見水上落花越多，其水越清澈，往前直走，水識越快，
耳旁隱隱聽到萬馬奔騰的聲音。

LONG);
	setup();
	replace_program(ROOM);
}
