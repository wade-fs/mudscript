 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
仰頭一望，頭頂上密密麻麻的遍布著枝葉，濃密的程度，
使得即便白晝下的陽光也只能由枝葉間的微小空隙穿透進來，
如同黑夜裡的星辰般，在陰暗樹蔭籠罩的泥土地上閃爍著一點
一點的光茫。林間依稀給人非常古老的生命氣息，彷彿每株樹
木都是存在了千年時光的靈性生物，然而事實上，這片古林早
在天地初開之時就已座落於此，靜靜的渡過數千寒暑的冷暖，
冷眼盡觀帝國朝代的興衰。

LONG);
	set( "short", "$GRN$幽$YEL$暗$HIY$密$HIG$林$NOR$" );
	set( "object", ([
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount9"  : 1,
		"amount3"  : 14,
		"amount5"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount1"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"amount8"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
	]) );
	set( "exits", ([
		"up"        : "/open/clan/dark-forest/room/room7",
		"west"      : "/open/clan/dark-forest/room/room6.c",
		"north"     : "/open/clan/dark-forest/room/room5.c",
		"east"      : "/open/clan/dark-forest/room/room4.c",
		"south"     : "/open/clan/dark-forest/room/room3.c",
	]) );
	set( "item_desc", ([
		"煤油冥紙的屍體(corpse)" : @ITEM
這是一代豬神煤油冥紙,但是他已經死了,只剩下屍體在這裡
ITEM,
	]) );
	set( "light_up", 1 );
	set( "build", 10170 );
	setup();                                             
	call_other( "/obj/board/dark-forest_b", "???" );
	}
