inherit ROOM;
void create() {
	set( "short", "$HIC$劍魔$HIM$紫雲蝶$NOR$" );
	set( "owner", "mekyn" );
	set( "object", ([
		"file10"   : "/obj/stone/powder",
		"file1"    : "/open/doctor/pill/human_pill",
		"amount6"  : 1,
		"file8"    : "/open/gsword/obj1/sadsword",
		"file4"    : "/open/capital/obj/4-3",
		"amount8"  : 1,
		"amount4"  : 1,
		"file6"    : "/open/capital/obj/4-3",
		"file5"    : "/open/capital/obj/4-3",
		"amount7"  : 1,
		"amount3"  : 800,
		"file9"    : "/open/killer/obj/fire-knife",
		"amount9"  : 1,
		"file2"    : "/open/doctor/pill/ice_pill",
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"amount2"  : 314,
		"amount10" : 5,
		"file7"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount5"  : 1,
		"amount1"  : 425,
	]) );
	set( "build", 10078 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/ou-cloud-club/room/room464",
		"east"      : "/open/clan/ou-cloud-club/room/room17",
	]) );
	set( "long", @LONG

    走進此地，眼前一片相思竹林隨風搖曳，似乎正在歡迎妳的到來
林中石階細佈如絲，耳邊不時傳來陣陣風鈴舞動之聲，彷彿人間仙樂
仔細一看，相思林中竹風飄逸不定，風吹鈴動，絲絲透露出無限哀愁
正所謂相思林中長相思，柳葉秋風吹，思念憶無涯。

LONG);
	setup();
	replace_program(ROOM);
}
