inherit ROOM;
void create() {
	set( "short", "$RED$$HBGRN$阿嚕米的花園$NOR$" );
	set( "object", ([
		"amount5"  : 35,
		"file3"    : "/open/doctor/pill/human_pill",
		"amount3"  : 354,
		"amount2"  : 600,
		"amount4"  : 500,
		"file5"    : "/open/mon/obj/mon-pill",
		"file6"    : "/open/doctor/item/human_item",
		"file4"    : "/open/doctor/item/sky_item",
		"amount1"  : 192,
		"file1"    : "/open/doctor/item/ground_item",
		"amount6"  : 323,
		"file2"    : "/open/doctor/pill/sky_pill",
		"amount7"  : 116,
		"file7"    : "/obj/stone/powder",
	]) );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "build", 10480 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room251.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
此地花香鳥語，令人不禁放鬆心晴，原來這裡是$HIR$阿嚕米$NOR$
的後花園，滿園子的東瀛奇花異草，當然也有$CYN$黑牙聯$NOR$的秘草
～$HIG$富士山秘草$NOR$。為了要更進一步研究秘草的功用，當年$HIR$阿嚕
米$NOR$特地向$HIR$葉秀殺$NOR$請示，將它移植到此處栽種的，以便能早一
日發現能更壯大$CYN$黑牙聯$NOR$的方法。

LONG);
	setup();
	replace_program(ROOM);
}
