inherit ROOM;
void create() {
	set( "short", "$HIG$二年級生$HIY$教室$NOR$" );
	set( "owner", "wateribbon" );
	set( "object", ([
		"amount6"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"amount8"  : 1,
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount1"  : 1,
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
	]) );
	set( "build", 10424 );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room61",
		"east"      : "/open/clan/time-limit/room/room55.c",
		"west"      : "/open/clan/time-limit/room/room37",
		"north"     : "/open/clan/time-limit/room/room60.c",
	]) );
	set( "long", @LONG
二年級生已經對學校環境有所認識,也就不用像新生一樣要問路
才能到教室,而二年級生流行的話題是關於密室,傳說史萊哲林
留下一間密室在學校裡,只有史萊哲林的傳人可以打開這間密室,
進行血統純化運動,也就是殺死非純種巫師,聽說這間密室在二十年前
被打開過,而且捉到史萊哲林的傳人,但是這位傳人是誰卻無法得知

LONG);
	setup();
	replace_program(ROOM);
}
