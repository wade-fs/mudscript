inherit ROOM;
void create() {
	set( "short", "$HIG$【洞內洞】$NOR$" );
	set( "owner", "working" );
	set( "object", ([
		"file8"    : "/open/killer/obj/s_pill",
		"amount8"  : 3000,
		"file1"    : "/open/killer/obj/s_pill",
		"amount1"  : 5000,
	]) );
	set( "build", 10412 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room398.c",
	]) );
	set( "long", @LONG

        這是修練內功的地方。屋子正中有塊採自天山之巔的千年玄冰，
    冰上冒出絲絲寒氣，屋裡因此寒氣逼人，你不由得打了一個寒顫，據
    說在那上面打坐事半功倍，你費勁地爬上了玄冰，結果給凍得慘兮兮
    的，趕緊爬了下來。

    時值隆冬，棉絮般的大雪紛紛揚揚的從灰暗的天空中飄落下來。

LONG);
	setup();
	replace_program(ROOM);
}
