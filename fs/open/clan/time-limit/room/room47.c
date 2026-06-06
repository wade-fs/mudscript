inherit ROOM;
void create() {
	set( "short", "$HIB$魁地奇$HIR$商品店$NOR$" );
	set( "owner", "soilclaw" );
	set( "object", ([
		"file3"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount7"  : 1,
		"amount2"  : 1,
		"amount5"  : 1,
		"file9"    : "/open/magic-manor/soil/obj/soil-claw",
		"file5"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount8"  : 1,
		"file1"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount6"  : 1,
		"amount9"  : 1,
		"file10"   : "/open/magic-manor/soil/obj/soil-claw",
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount4"  : 1,
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"file6"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount3"  : 1,
		"amount1"  : 1,
		"amount10" : 1,
		"file2"    : "/open/magic-manor/soil/obj/soil-claw",
		"file7"    : "/open/magic-manor/soil/obj/soil-claw",
	]) );
	set( "build", 10638 );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room46.c",
		"east"      : "/open/clan/time-limit/room/room45",
		"south"     : "/open/clan/time-limit/room/room51.c",
	]) );
	set( "long", @LONG
一來到商品店前,前方的人潮讓你擠不過去,原來大家都是來親眼目睹
最新型的飛天掃帚-火閃電,店員在店門口大聲說著剛剛英國的國家
代表隊才訂了七根火閃電,你也跟著人潮擠到門口看火閃電,
即使不懂魁地奇的你也覺得這根掃帚真的很漂亮,沒有任何分岔,
整跟掃帚燙金還在末端刻上出廠序號,讓你忍不住向店員詢問價錢

LONG);
	setup();
	replace_program(ROOM);
}
