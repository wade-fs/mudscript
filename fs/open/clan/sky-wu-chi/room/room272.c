inherit ROOM;
void create() {
	set( "short", "偽爾剛" );
	set( "owner", "working" );
	set( "light_up", 1 );
	set( "object", ([
		"file5"    : "/open/ping/questsfan/obj/diamond_boots",
		"file10"   : "/open/ping/questsfan/obj/diamond_legging",
		"file4"    : "/open/ping/questsfan/obj/diamond_armor",
		"file7"    : "/open/ping/questsfan/obj/diamond_cloak",
		"amount10" : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"amount1"  : 1,
		"file6"    : "/open/mogi/castle/obj/fire_book",
		"amount7"  : 1,
		"amount9"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/ping/questsfan/obj/diamond_skirt",
		"amount5"  : 1,
		"file8"    : "/open/gblade/obj/dragon_book",
		"amount3"  : 1,
		"file3"    : "/open/ping/questsfan/obj/diamond_hands",
		"file9"    : "/open/ping/questsfan/obj/diamond_hairpin",
		"amount8"  : 1,
		"file1"    : "/open/ping/questsfan/obj/diamond_belt",
	]) );
	set( "build", 10010 );
	set( "exits", ([
		"out"       : "/open/clan/sky-wu-chi/room/room175",
	]) );
	set( "long", @LONG
一粒藥丸...花拉拉拉拉...兩粒藥丸...花拉拉拉拉...
三粒藥丸...花拉拉拉拉...四粒藥丸...花...疑怎麼少了阿....
難道我的藥丸被偷了嗎???怎麼辦阿??那是我晚上要用的ㄟ...
阿一定是我那個死鬼...偷偷拿出去用了...他居然又給我在外面亂搞...
看他回來我怎麼修理他...sigh...怎麼辦阿??那是我晚上要用的ㄟ...
少了一粒藥效會差很多ㄟ...這下我可就對不起我的密友了說...
今晚就少玩幾次好了...真倒楣...死傢伙...有本事就別回來...

LONG);
	setup();
	replace_program(ROOM);
}
