inherit ROOM;
void create() {
	set( "short", "$YEL$【小佩的小小書房】$NOR$ " );
	set( "owner", "peiyi" );
	set( "object", ([
		"amount1"  : 1,
		"file4"    : "/open/killer/headkill/obj/world_dag",
		"amount9"  : 1,
		"amount10" : 1,
		"file10"   : "/obj/gift/unknowdan",
		"file3"    : "/obj/gift/hobowdan",
		"file5"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file2"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount3"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount6"  : 1,
		"amount2"  : 1,
		"amount5"  : 1,
		"file6"    : "/open/magic-manor/obj/evil-kill-claw",
		"file1"    : "/obj/gift/xisuidan",
		"file9"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount4"  : 1,
	]) );
	set( "build", 10374 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room74",
	]) );
	set( "long", @LONG
    這間書房是小佩佩的藏書所在, 小佩佩一生的心血都放在這裡, 因
此這裡可不是一般人可以進來的, 若非小佩佩的允許, 想看一看都不行
。入口處掛著一幅捲軸(paper)。門上掛著一幅對聯, 四周都是書架, 書
架上有各式各樣的書籍畫冊, 尤其是關於跳舞方面的書籍更是琳瑯滿
目, 可見得小佩佩用功的程度。
LONG);
	setup();
	replace_program(ROOM);
}
