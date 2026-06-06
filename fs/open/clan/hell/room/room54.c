inherit ROOM;
void create() {
	set( "short", "$HIY$廢琳$HIG$安養院$NOR$" );
	set( "object", ([
		"file1"    : "/open/ping/obj/gold_hand",
		"amount2"  : 1,
		"file2"    : "/open/ping/obj/gold_hand",
		"amount1"  : 1,
	]) );
	set( "owner", "blur" );
	set( "build", 10074 );
	set( "exits", ([
		"north"     : "/open/clan/hell/room/room55.c",
		"south"     : "/open/clan/hell/room/room63.c",
		"east"      : "/open/clan/hell/room/room46",
		"west"      : "/open/clan/hell/room/room4.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
kalin自從轉到射手後...發覺嫁錯郎了..
原來射手之前的wiz是aol那隻^(OO)^頭..
sigh 1000000000
好在損友min有幫射手想了一寫quest給nike..
雖然min平時仗勢欺人..無惡不作..
但這次還是要感謝他吧..
或許是他覺得罪孽深重..藉此來贖罪吧..
anyway...kalin就是在此安養他的餘生了..
如果哪天你看到他..不妨拍拍他的頭..安慰一下..

LONG);
	setup();
	replace_program(ROOM);
}
