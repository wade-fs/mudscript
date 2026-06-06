inherit ROOM;
void create() {
	set( "short", "$HIR$$BWHT$阿嚕米的任務室$NOR$" );
	set( "owner", "hild" );
	set( "object", ([
		"amount3"  : 1,
		"file8"    : "/open/main/room/sp/stone",
		"amount8"  : 1,
		"file3"    : "/open/main/room/sp/stone",
	]) );
	set( "item_desc", ([
		"pigpig" : @ITEM
美麗ITEM,
		"pss" : @ITEM
美麗
ITEM,
	]) );
	set( "light_up", 1 );
	set( "build", 10167 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"north"     : "/open/clan/sky-wu-chi/room/room434",
		"enter"     : "/open/clan/sky-wu-chi/room/room218",
		"east"      : "/open/clan/sky-wu-chi/room/room155.c",
		"west"      : "/open/clan/sky-wu-chi/room/room306.c",
	]) );
	set( "long", @LONG
整個武林，最近掀起一陣恐慌，傳說〔$CYN$黑牙聯殺手$NOR$〕又
再度活躍起來，每個人莫不驚慌害怕。整個房間傳來一陣血
腥的殺氣，桌子上到處是散亂的紙堆，牆上也滿是武功招式
的痕跡還看見很多機關，似乎通往很多地方？莫非這裡便是....？
LONG);
	setup();
	replace_program(ROOM);
}
