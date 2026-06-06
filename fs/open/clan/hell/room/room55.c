inherit ROOM;
void create() {
	set( "short", "$HIY$阿琳$HIM$公益彩券$NOR$" );
	set( "object", ([
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"file6"    : "/open/sky/obj/lucky_grasslink",
		"amount7"  : 1,
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"file3"    : "/open/sky/obj/lucky_grasslink",
		"amount6"  : 1,
		"amount2"  : 1,
		"file5"    : "/open/sky/obj/lucky_grasslink",
		"file2"    : "/open/sky/obj/lucky_grasslink",
		"amount4"  : 1,
		"amount8"  : 1,
		"amount5"  : 1,
		"amount9"  : 1,
		"amount1"  : 1,
		"file9"    : "/open/sky/obj/lucky_grasslink",
		"amount3"  : 1,
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"file4"    : "/open/sky/obj/lucky_grasslink",
	]) );
	set( "owner", "blur" );
	set( "build", 10382 );
	set( "exits", ([
		"south"     : "/open/clan/hell/room/room54.c",
		"west"      : "/open/clan/hell/room/room43",
		"east"      : "/open/clan/hell/room/room50.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

kalin自從退隱山湖後...
就把一切事務交給鼻屎男大飛去管理..
平常沒事..就是溜溜鳥
當然..玩鳥也是要有本錢的..
除了靠小弟大飛定時納貢的保護費...
阿琳響應政府的良政..
賣起公益彩券來了...
如果哪天你在台北車站...
看到一位風流倜儻的美男子在賣彩券
不要懷疑..那就是kalin..
記得多給他捧場喔...
LONG);
	setup();
	replace_program(ROOM);
}
