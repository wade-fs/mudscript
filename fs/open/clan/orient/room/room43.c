inherit ROOM;
void create() {
	set( "short", "$HIW$『$HIY$甜郡主室$HIW$』$NOR$" );
	set( "owner", "spicy" );
	set( "object", ([
		"file8"    : "/u/n/neverend/present/777",
		"amount7"  : 1,
		"file9"    : "/open/sky/obj/lucky_grasslink",
		"file6"    : "/open/gblade/mob/lotch",
		"file4"    : "/open/sky/obj/lucky_grasslink",
		"amount6"  : 1,
		"file1"    : "/daemon/class/blademan/obj/skykey",
		"amount8"  : 1,
		"amount10" : 1,
		"file5"    : "/open/sky/obj/lucky_grasslink",
		"amount5"  : 1,
		"amount9"  : 1,
		"file2"    : "/open/sky/obj/lucky_grasslink",
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"amount1"  : 1,
		"amount2"  : 1,
		"file3"    : "/open/capital/obj/4-3",
		"amount4"  : 1,
		"file10"   : "/open/sky/obj/lucky_grasslink",
		"amount3"  : 1,
	]) );
	set( "build", 11353 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/orient/room/room51",
		"north"     : "/open/clan/orient/room/room49",
		"south"     : "/open/clan/orient/room/room38.c",
		"west"      : "/open/clan/orient/room/room50",
	]) );
	set( "long", @LONG
有一個女孩叫甜甜，從小生長在孤兒院，她有許多好朋友，相親相愛又相憐。
這裡的人情最溫暖，這裡的人們最和善，好像一個大家庭，大家都愛小甜甜。

一天又一天，一年又一年，轉眼之間已長大，依依不捨說再見。
每一個孩子都勇敢，每一個孩子都樂觀，自立自強有信心，前途光明又燦爛

LONG);
	setup();
	replace_program(ROOM);
}
