inherit ROOM;
void create() {
	set( "short", "女子宿舍的客廳" );
	set( "object", ([
		"amount3"  : 19,
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"file1"    : "/open/fire-hole/obj/g-pill",
		"file2"    : "/open/fire-hole/obj/r-pill",
		"amount6"  : 1,
		"amount7"  : 3,
		"amount2"  : 10,
		"amount4"  : 19,
		"file7"    : "/open/mon/obj/thousand-nectar",
		"file5"    : "/open/mogi/mountain/obj/frog-pill",
		"file4"    : "/open/mon/obj/mon-pill",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
		"amount1"  : 10,
	]) );
	set( "owner", "djlh" );
	set( "build", 10008 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room665",
		"east"      : "/open/clan/13_luck/room/room667.c",
		"south"     : "/open/clan/13_luck/room/room663.c",
	]) );
	set( "long", @LONG

███◣╔══╦═╗╔═╦══╦══╗╦╦╦╦S.H.E╦╦╦╦╦╦╦╦╦╦╦╦╦╗ 
█    █║  ═╣  ║║  ║  ═╣  ═╣我知道每陣風 吹著吹著就停息也知道每朵雲╣ 
████║  ═╣  ╚╣  ║  ═╣  ╦╝飄著飄著就散去 But I believe ╬╬╬╬╬╣ 
█    █╚══╩══╩═╩══╩═╝but I believe 因為我們 我們有愛情╬╬╬╬╣ 
███◤ 我相信我和你 一定會有結局 任時光再侵襲 擁抱一樣堅定 這世界有太多╬╬╣ 
╠╬╬會消逝的美麗 但你是你 so I believe ( 但你是你所以我相信 so I believe)╬╣ 
╠╬╬就像是每條河 總會流到海裡去 你知道我的心 也只願意奔向你  我說愛你╬╬╬╣ 
╠::☆∴╬╬╬╬就是愛你 這是真理 永遠別懷疑 真心會給人力氣╬╬╬∴°.*﹒☆╬╣ 
╠╬∴°*﹒﹒:☆╬穿越過所有距離 帶領我們走進永遠裡 Ah~ ~ Ah~~ Ah~~╬╬╬╬╬╣ 
╚╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩by Forever ╩╩╩╩╩╩╩╩╩╝ 
  
  
LONG);
	setup();
	replace_program(ROOM);
}
