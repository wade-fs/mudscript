inherit ROOM;
void create() {
	set( "short", "$BBLU$密$BYEL$室$NOR$" );
	set( "exits", ([
		"out"       : "/open/clan/time-limit/room/room35",
	]) );
	set( "long", @LONG
密室裡到處都是水,空氣中飄來一股腥臭味,地上也有一些
動物的骨頭,前方有著巨大的人頭雕像,雕像下方刻著'薩拉扎 史萊哲林,
史上最偉大的巫師',原來這就是史萊哲林,忽然雕像的嘴巴張開,
一條巨蛇從雕像嘴巴爬出來,這是蛇妖,看到蛇妖眼睛會立即死亡,
而且還有劇毒的毒牙和巨大的體型作為武器,是最難對付的怪物

LONG);
	setup();
	replace_program(ROOM);
}
