inherit ROOM;
void create() {
	set( "short", "$HIW$白無常說道﹕喂﹗新來的﹐你叫什麼名字?$NOR$" );
	set( "owner", "acelan" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/room126.c",
		"east"      : "/open/clan/hell/room/room123.c",
		"up"        : "/open/clan/hell/room/room109",
		"south"     : "/open/clan/hell/room/room13.c",
	]) );
	set( "long", @LONG

白無常用奇異的眼光盯著你﹐好像要看穿你的一切似的。

白無常「哼」的一聲﹐從袖中掏出一本像帳冊的東西翻看著。

白無常閤上冊子﹐說道﹕咦﹖陽壽未盡﹖怎麼可能﹖

白無常搔了搔頭﹐歎道﹕罷了罷了﹐你走吧。

一股陰冷的濃霧突然出現﹐很快地包圍了你。

LONG);
	setup();
	replace_program(ROOM);
}
