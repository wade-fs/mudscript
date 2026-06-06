inherit ROOM;
void create() {
	set( "short", "『$HIC$青龍居$NOR$』" );
	set( "owner", "hao" );
	set( "object", ([
		"amount1"  : 383,
		"amount6"  : 1,
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"file7"    : "/open/mon/obj/mon-pill",
		"file8"    : "/open/mogi/castle/obj/sspill",
		"amount4"  : 1,
		"file4"    : "/open/gsword/obj1/bpball",
		"file2"    : "/open/gsword/obj1/bbladeball",
		"file9"    : "/u/n/neverend/present/777",
		"amount8"  : 25,
		"file3"    : "/open/gsword/obj1/kring",
		"file6"    : "/open/gsword/obj1/karmor",
		"amount7"  : 10,
		"amount10" : 1,
		"amount5"  : 60,
		"amount9"  : 1,
		"amount2"  : 1,
		"amount3"  : 1,
		"file10"   : "/obj/gift/unknowdan",
		"file1"    : "/open/killer/obj/atman_pill",
	]) );
	set( "build", 10020 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/orient/room/room45",
		"west"      : "/open/clan/orient/room/room55.c",
	]) );
	set( "long", @LONG
狂想空間早期是由 wade, shorst, jcder 等人共同創立. 採用 es2 來
        的程式.後期的狂想空間歷經了不少波折,分分合合換了不少的地方在歷
        代大神lum,urd,weimin,konn及現任大神anmy 的努力下才能一直的發展
        在發展過程當中, 感謝所有參與的巫師與玩家的心血, 沒有他們就沒有
        現在的狂想空間. 但是儘管狂想空間已經熔合了所有人的心力, 它仍然
        是一個正在成長中的世界, 相信只有在玩家及巫師的努力狂想空間才能
        繼續的成長這裏還是一片渾沌.....不安,新奇,可塑性, 自由, 幻想...

LONG);
	setup();
	replace_program(ROOM);
}
