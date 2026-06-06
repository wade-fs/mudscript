inherit ROOM;
void create() {
	set( "short", "$HIY$活米村$HIR$車站$NOR$" );
	set( "object", ([
		"amount8"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount5"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount1"  : 1,
		"amount3"  : 1,
		"amount4"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount7"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-shield",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount2"  : 1,
		"amount6"  : 1,
		"amount10" : 1,
	]) );
	set( "owner", "car" );
	set( "build", 10033 );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room11",
		"enter"     : "/open/clan/time-limit/room/room28",
	]) );
	set( "long", @LONG
經過幾個小時的旅程後終於到達終點站-活米村車站-,
具有巨人血統的魯霸-海格正在大喊一年級的新生向他靠攏,
不過這些新生似乎很怕他,遲遲不敢過去,二年級以上的舊生直接走向馬車,
說也奇怪,怎麼只有車子而沒看到馬,原來這是騎士墜鬼馬,
傳說只有真正見過死亡的人才能夠看的見騎士墜鬼馬,
讓看不見馬的馬車拖著走,讓你不禁毛骨聳然

LONG);
	setup();
	replace_program(ROOM);
}
