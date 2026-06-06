inherit ROOM;
void create() {
	set( "short", "- (弒羽皇天)" );
	set( "owner", "coling" );
	set( "build", 10635 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room471",
	]) );
	set( "long", @LONG
驚悚的殺氣回蕩在四周，劍氣、劍壓猛烈的四散出來，兩旁楓樹
隨著殺氣搖擺不定，落葉滿天飛舞著。在此陣的中間被封印著一把，
自古以來就噬血成狂的黑魔劍，由於最後被玫緹收服而封印於此，但
無比的劍壓恐怕也只有玫緹掌握的住，這把劍身泛黑的黑魔劍就叫，
                          『血狼』
LONG);
	setup();
	replace_program(ROOM);
}
