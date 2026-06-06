inherit ROOM;
void create() {
	set( "short", "$HIM$CPU的玄關$NOR$" );
	set( "object", ([
		"amount10" : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"amount9"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
		"amount7"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file7"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "light_up", 1 );
	set( "build", 12120 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"south"     : "/open/clan/sky-wu-chi/room/room152.c",
		"north"     : "/open/clan/sky-wu-chi/room/room143.c",
	]) );
	set( "long", @LONG
你走進了霸氣堂裡頭，看到了一幅紅底金字的牌匾寫著『氣吞山河』。
坐在正中的則是這個地方的主人『空瓶子』。你的眼睛就一直看著他，想著
他到底有何能耐能以霸氣自居。當你看到他的手的同時你嚇到了，因為一邊
是結著冰霜一邊則是燃燒著火燄。看他的樣子似乎是要修練一種不知道怎樣
的武功，他的護身氣勁居然有七重。且你看他運到第七重的同時，只聽見他
大喝一聲『般若氣吞七重勁』。沒想到他居然把這七重勁同時運出也同時融
合。也眼神也爆露出兇光。
LONG);
	setup();
	replace_program(ROOM);
}
