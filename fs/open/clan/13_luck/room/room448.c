inherit ROOM;
void create() {
	set( "short", "『賞善堂』" );
	set( "owner", "poll" );
	set( "object", ([
		"amount3"  : 1,
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount1"  : 1,
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount4"  : 1,
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount6"  : 1,
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount2"  : 1,
	]) );
	set( "build", 10248 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room447",
		"east"      : "/open/clan/13_luck/room/room449",
	]) );
	set( "long", @LONG

     這裡是墨教的賞善堂，所有對墨教有功的人，都會受到賞賜，至於是什
 麼樣的賞賜，就全端看你前面這位慈祥的老者，他是墨教賞善使，和藹可親
 的他令你不禁想去親近他，他飽讀經書而且武功高強任何人想要不勞而獲，
 來此地盜寶的都要先過他這一關，歷代總鉅子對於賞善、執法二使都不敢有
 些許的不尊敬，除了他們的地位之外大概讓總人懼怕的就是他們的武功了吧。

LONG);
	setup();
	replace_program(ROOM);
}
