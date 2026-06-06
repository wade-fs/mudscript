inherit ROOM;
void create() {
	set( "short", "$HIY$廢公阿琳老先生$WHT$之墓$NOR$" );
	set( "object", ([
		"file1"    : "/open/wu/npc/obj/armband",
		"amount3"  : 1,
		"file3"    : "/open/wu/npc/obj/armband",
		"amount2"  : 1,
		"amount1"  : 1,
		"file2"    : "/daemon/class/fighter/armband",
	]) );
	set( "owner", "blur" );
	set( "build", 10348 );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/room44",
		"north"     : "/open/clan/hell/room/room54.c",
		"east"      : "/open/clan/hell/room/room51.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
當你看到這個墓碑時..
一定會大吃一驚...心中不禁想著..
然到紅顏都薄命嗎?
你深深嘆了口氣....

壓抑著悲傷與惋惜...
你焚香對著墓碑祭拜...

說時遲那時快..突然天雨交加...狂雷不矣..
墓塚竟然崩開一條裂縫...
飛出一隻大頭綠蒼蠅....

ACK 1000 one.. oh my god!!
LONG);
	setup();
	replace_program(ROOM);
}
