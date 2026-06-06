inherit ROOM;
void create() {
	set( "short", "$HIM$琉$HIR$璃$HIC$仙$HIY$境$NOR$" );
	set( "build", 10108 );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room200.c",
		"north"     : "/open/clan/time-limit/room/room198.c",
		"south"     : "/open/clan/time-limit/room/room197",
	]) );
	set( "long", @LONG
琉璃仙境是清香白蓮素還真的住所之一,地如其名,遍地的花朵,傳來陣陣花香,蝴蝶
翩翩飛舞穿梭其中,多種鳥類在樹上爭奇鬥艷,吱吱喳喳叫個不停,前方有一小橋建在
清澈的溪水上,小橋之後是座涼亭,涼亭內的石桌上有著泡茶的工具,是素還真經常和
好友一起品茗的地方,你不禁感嘆這裡果然是人間仙境

LONG);
	setup();
	replace_program(ROOM);
}
