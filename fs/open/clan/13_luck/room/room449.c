inherit ROOM;
void create() {
	set( "short", "『執法堂』" );
	set( "owner", "poll" );
	set( "object", ([
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount9"  : 1,
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount3"  : 1,
	]) );
	set( "build", 10026 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room448",
		"east"      : "/open/clan/13_luck/room/room450.c",
	]) );
	set( "long", @LONG

     你現在所到之處顯現出一股令你驚畏的氣氛，你看到一個表情嚴肅的老
 者，正拿著一把記事簿，坐在椅子上，地上跪著一個披頭散髮的人，這裡就
 是墨教的執法堂，在這裡沒有任何人情可說，只要觸犯了規定，就必須來此
 依照情節的輕重加以處分，墨教嚴格的紀律就是依此而生，而老者的旁邊站
 著兩個人，看起來凶神惡煞的，量誰也不敢再此撒野。

LONG);
	setup();
	replace_program(ROOM);
}
