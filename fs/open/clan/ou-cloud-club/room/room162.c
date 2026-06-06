inherit ROOM;
void create() {
	set( "short", "$HIC$次元縫隙$NOR$" );
	set( "object", ([
		"amount7"  : 1,
		"file10"   : "/open/magic-manor/obj/evil-gwe-blade",
		"amount8"  : 18,
		"amount4"  : 1,
		"amount10" : 1,
		"file1"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"file8"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file7"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount9"  : 1,
		"file5"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount6"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file4"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount5"  : 1,
		"file2"    : "/open/magic-manor/obj/evil-kill-claw",
		"file6"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount2"  : 1,
		"amount1"  : 1,
	]) );
	set( "item_desc", ([
		"dragon" : @ITEM
武功修為已達學究天人境界著，可入(box)，尋找傳說中之冥魔寶盒

若為書生出身，可至(diamond)，應該會有不小的收穫

想快速增進內功修為的習武者，(ghost)裡的裝備，正是你所需要的

往北走，則可拿到傳送魔界之魔龍鱗

ITEM,
	]) );
	set( "light_up", 1 );
	set( "build", 13467 );
	set( "exits", ([
		"tower"     : "/open/clan/ou-cloud-club/room/room478.c",
		"out"       : "/open/clan/ou-cloud-club/room/hall.c",
		"diamond"   : "/open/clan/ou-cloud-club/room/room396.c",
		"box"       : "/open/clan/ou-cloud-club/room/room358.c",
		"ghost"     : "/open/clan/ou-cloud-club/room/room264.c",
		"north"     : "/open/clan/ou-cloud-club/room/room222",
	]) );
	set( "long", @LONG
一踏入此地,你感到空間驟然顛倒錯亂,時間竟似海水般潮起潮落,維持
世界的定律彷彿於剎那間失去了一切秩序,星辰稀稀落落的在黑暗穹蒼中忽
明忽滅,這邊應該就是世界的邊緣了吧,若你對於神的存在還感到一絲敬畏,
那麼最好趕快回頭離開此地吧,擅闖神的領域可不是什麼有趣的事.

一隻兇惡的火龍(dragon)駐守在此，散發出奇詭的氣息

LONG);
	setup();
	replace_program(ROOM);
}
