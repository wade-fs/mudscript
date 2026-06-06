inherit ROOM;
void create() {
	set( "short", "$HIG$五年級生$HIY$教室$NOR$" );
	set( "owner", "wateribbon" );
	set( "object", ([
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount4"  : 1,
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount10" : 1,
		"amount7"  : 1,
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount8"  : 1,
		"amount2"  : 1,
		"amount5"  : 1,
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"file10"   : "/open/magic-manor/water/obj/water-ribbon",
		"amount6"  : 1,
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount1"  : 1,
		"amount3"  : 1,
	]) );
	set( "build", 10726 );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room58",
		"west"      : "/open/clan/time-limit/room/room25",
	]) );
	set( "long", @LONG
由於五年級生要參加普等巫測,許多學生都在教室裡溫習功課,有些學生在一旁
練習魔法,每個人都緊張兮兮的,因為這個考試將影響未來的選課和出路,
因此學生們都想取得好成績,對於不想上的課則想翹掉,這也讓衛斯理雙胞胎
發明的摸魚點心盒異常暢銷,常常有學生無源無故生病,讓教授們頭痛不已

LONG);
	setup();
	replace_program(ROOM);
}
