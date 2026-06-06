inherit ROOM;
void create() {
	set( "short", "LEON 劍房" );
	set( "object", ([
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"file1"    : "/open/mogi/dragon/obj/dragon-head",
		"amount4"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file8"    : "/open/mogi/castle/obj/fire-king-head",
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount9"  : 1,
		"amount10" : 1,
		"amount2"  : 1,
		"file2"    : "/open/mogi/castle/obj/fire-king-head",
		"amount1"  : 1,
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
		"amount6"  : 1,
		"amount8"  : 1,
	]) );
	set( "build", 10089 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room749",
	]) );
	set( "long", @LONG
人說劍是武器中的君子 在這邊你可以看到各種不同的劍 居然
還有英雄劍在這邊 這把不是郭襄的倚天劍嗎？來到這邊好像進
入劍的展示間 讓你流連忘返 只想把玩手中的劍 難怪許多名劍
在武林中消失了 原來都跑到這邊了 只要能夠擁有其中一把就足
夠制霸天下 成為武林中的傳奇 可惜似乎在暗處有人在監視著
所以你最後還是看看就算了
LONG);
	setup();
	replace_program(ROOM);
}
