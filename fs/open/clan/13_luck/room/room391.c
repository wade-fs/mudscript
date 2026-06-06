inherit ROOM;
void create() {
	set( "short", "十三刀堂正殿" );
	set( "object", ([
		"amount8"  : 1,
		"amount10" : 1,
		"amount7"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount1"  : 1,
		"amount6"  : 1,
		"amount5"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount2"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount9"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-belt",
	]) );
	set( "owner", "roar" );
	set( "build", 10227 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room400",
		"west"      : "/open/clan/13_luck/room/room401.c",
		"east"      : "/open/clan/13_luck/room/room392.c",
		"north"     : "/open/clan/13_luck/room/room402.c",
	]) );
	set( "long", @LONG

         ██████████████████████████
         ■■  ■■  ■■  ■■  ■■  ■■  ■■  ■■  ■■
         ■■  ■■  ■■  ■■  ■■  ■■  ■■  ■■  ■■
         ██████████████████████████
         █田田田田田田田田田田田▄▄田田田田田田田田田田田█
         █|田田田田田田田田田田田田田田田田田田田田田田田|█
         █│∥∥  ∥∥  ∥∥            ∥∥  ∥∥  ∥∥│█
         █│∥∥  ∥∥  ∥∥            ∥∥  ∥∥  ∥∥│█
         █│██  ██  ██            ██  ██  ██│█

    這裡便是十三刀堂堂主的居所，堂主廳雖然沒有浪子殿寬闊，但是別
有一番氣魄，大廳的正中央站著一位平民打扮的刀客，身穿一襲青色長袍
，腰間則懸著一把小刀，不知就裡的人又怎會知道他就是這裡的當家刀客
呢??他留著一縷長鬚，混身上下充盈著一股隱約的刀氣，四周圍有幾位弟
子圍繞著他，可能正在安排出甚麼任務的各項事宜

LONG);
	setup();
	replace_program(ROOM);
}
