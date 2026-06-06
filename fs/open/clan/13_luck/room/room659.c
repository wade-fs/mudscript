inherit ROOM;
void create() {
	set( "short", "安樂居安樂居" );
	set( "owner", "shinny" );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room655",
	]) );
	set( "long", @LONG
在你一進門，看見了一個身穿白衣背一把長劍的男子，他正站在一個
小窗旁欣賞著外面的景物，你仔細一看，原來他就是剛剛在往江湖道的山
間小道上路人們所說的一代武者「修羅」，傳說中他乃是傲雲山莊小懶蟲
的好友，以一招終極拳勢聞名江湖，之後他便居住於此不再過問江湖
事，在最近幾年中，他的名字就被江湖人士給漸漸的遺忘了。

LONG);
	setup();
	replace_program(ROOM);
}
