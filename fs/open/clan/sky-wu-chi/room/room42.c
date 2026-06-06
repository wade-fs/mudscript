inherit ROOM;
void create() {
	set( "short", "pants" );
	set( "owner", "hild" );
	set( "object", ([
		"amount4"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount2"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount9"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount10" : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-pants",
	]) );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room116",
		"west"      : "/open/clan/sky-wu-chi/room/room49",
	]) );
	set( "build", 10080 );
	set( "light_up", 1 );
	set( "long", @LONG
斗室裡青煙繚繞，置著一張橫几、兩個蒲團，一柄烏鞘金吞的古劍供
在几頂，粉壁上懸著一幅中堂，筆力遒勁，寫的是唐代詩人賈島的一
首$HIW$《俠客》$NOR$：「$HIY$十年磨一劍$NOR$，$HIR$霜刃未曾試$NOR$。$HIC$今日把示君$NOR$，$HIM$誰有不平事$NOR$
？」廳側吊著一簾青幔，幔後透出些許燈光,周圍隱隱顯露出一股傲然
之氣!!映入眼簾令你驚訝的是堆落滿地的武功書籍,顯示此處的主人亦
對於武學的涉略頗廣!
LONG);
	setup();
	replace_program(ROOM);
}
