inherit ROOM;
void create() {
	set( "short", "$GRN$摩金夫人$RED$的$CYN$各式長袍$NOR$" );
	set( "object", ([
		"amount8"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount5"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount1"  : 1,
		"amount3"  : 1,
		"amount4"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount7"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount2"  : 1,
		"amount6"  : 1,
		"amount10" : 1,
	]) );
	set( "owner", "car" );
	set( "build", 10349 );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room52.c",
	]) );
	set( "long", @LONG
由於巫師世界和一般世界不同,需要穿著長袍,因此斜角巷也有販賣長袍,
一進入店裡,各式各樣的長袍都有,而且色彩繽紛,摩金夫人
拿著尺替客人量尺寸,並替客人選擇合身的長袍,店裡的員工也忙著
幫客人修改長袍的大小,還有員工將長袍燙得整整齊齊,包裝起來出貨了

LONG);
	setup();
	replace_program(ROOM);
}
