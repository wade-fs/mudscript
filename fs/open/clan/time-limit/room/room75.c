inherit ROOM;
void create() {
	set( "short", "$BWHT$空調機房$NOR$" );
	set( "object", ([
		"amount2"  : 1,
		"amount3"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount10" : 1,
		"amount5"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount1"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount8"  : 1,
		"amount4"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount6"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount7"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount9"  : 1,
	]) );
	set( "owner", "kerr" );
	set( "build", 10007 );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room77",
	]) );
	set( "long", @LONG
呼呼的風聲迎面而來, 只見數十台AHU正在運轉, 風車轉動的聲音充斥整各房間
頭頂上可看見規劃整齊的空調風管, 這數十台AHU正是Fab裡面溫度, 溼度,潔淨
度控制的主要, 沒有這些設備的轉動, 數千坪大的Fab怎能保持Class 1000,
Class 10K的環境需求.

LONG);
	setup();
	replace_program(ROOM);
}
