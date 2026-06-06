inherit ROOM;
void create() {
	set( "short", "$HIC$奇犽‧揍敵客$HIW$ソ$HIR$遊$HIY$戲$HIG$屋$NOR$" );
	set( "object", ([
		"file2"    : "/open/magic-manor/obj/master_snake_head",
		"amount2"  : 1,
		"file6"    : "/open/killer/obj/kill_yar_head",
		"amount3"  : 1,
		"amount5"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file7"    : "/open/ghost-hole/obj/light-spirit",
		"amount8"  : 1,
		"file4"    : "/obj/gift/hobowdan",
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
		"amount1"  : 1,
		"amount7"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 10022 );
	set( "item_desc", ([
		"Joy Station" : @ITEM

奇犽．揍敵客(killua)舉起好大好大的鐵鎚!!  哇!
                                         *****************.
                                         *               *.
往你頭上用力一敲!.                       *  500000000 Pt *.
                                         *               *.
*** 『 鏘 !』 ***.                       *****************.
                                                | |.
                                                | |.
你看到好多好多美麗的蝴蝶飛來飛去說!             | |.
                                                |_|.


『暢談』奇犽．揍敵客說道: 卡帶在小傑那裡啦！！

ITEM,
		"joy station" : @ITEM
奇犽．揍敵客(killua)舉起好大好大的鐵鎚!!  哇!
                                         *****************.
                                         *               *.
往你頭上用力一敲!.                       *  500000000 Pt *.
                                         *               *.
*** 『 鏘 !』 ***.                       *****************.
                                                | |.
                                                | |.
你看到好多好多美麗的蝴蝶飛來飛去說!             | |.
                                                |_|.


『暢談』奇犽．揍敵客說道: 卡帶在小傑那裡啦！！

ITEM,
		"station" : @ITEM
奇犽．揍敵客(killua)舉起好大好大的鐵鎚!!  哇!
                                         *****************.
                                         *               *.
往你頭上用力一敲!.                       *  500000000 Pt *.
                                         *               *.
*** 『 鏘 !』 ***.                       *****************.
                                                | |.
                                                | |.
你看到好多好多美麗的蝴蝶飛來飛去說!             | |.
                                                |_|.


『暢談』奇犽．揍敵客說道: 卡帶在小傑那裡啦！！

ITEM,
	]) );
	set( "light_up", 1 );
	set( "owner", "killua" );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room453",
	]) );
	set( "long", @LONG

    這裡是奇犽‧揍敵客ソ遊戲屋。平常練功累了，他都會跑來
這裡打電動。滿地的主機跟卡匣，從紅白機、ＳＥＧＡ、超任、
Ｓａｔｕｒｎ、ＰＳ、ＰＳ２、Ｎｉｎｔｅｎｄｏ６４、Ｇａｍ
ｅｂｏｙ、Ｇａｍｅｃｕｂｅ等等多的不勝枚舉，甚至連最新的
ＸＢＯＸ都有。

    咦？角落那台主機不是傳說中的ＪｏｙＳｔａｔｉｏｎ嗎？
莫非夢幻般的遊戲貪婪之島(ＧｒｅｅｄＩｓｌａｎｄ)就在裡面
？你不禁手癢想玩玩這傳說的遊戲。

一台遊戲主機 (Joy Station)正靜靜的躺在角落。

LONG);
	setup();
	replace_program(ROOM);
}
