inherit ROOM;
void create() {
	set( "short", "醉仙樓" );
	set( "object", ([
		"amount6"  : 1,
		"amount2"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount1"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount7"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount3"  : 1,
		"file7"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-pants",
	]) );
	set( "build", 11085 );
	set( "exits", ([
		"up"        : "/open/clan/nine-sky-dragon/room/room14",
		"down"      : "/open/clan/nine-sky-dragon/room/room12",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

 $HIR$花　間　一　壺　酒　　獨　酌　無　相　親$NOR$
　 $HIY$舉　杯　邀　明　月　　對　影　成　三　人$NOR$
　　 $HIC$月　既　不　解　飲　　影　徒　隨　我　身$NOR$
  　　 $HIG$暫　伴　月　將　影　　行　樂　須　及　春$NOR$
　　　　 $HIB$我　歌　月　徘　徊　　我　舞　影　零　亂$NOR$
  　　　 　$HIM$醒　時　同　交　歡　　醉　後　各　分　散$NOR$
　　　　　 　永　結　無　情　遊　　相　期　邈　雲　漢

LONG);
	setup();
	replace_program(ROOM);
}
