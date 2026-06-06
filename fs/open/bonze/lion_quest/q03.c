inherit ROOM;
#include <ansi.h>
#include "bonze.c" //使用共用檔案的話 則函數不能重複 且因為不是系統檔案 所以不需要<>的括號
//例如：重新編譯 /u/b/blazakira/bonzee/room/q01.c﹕編譯時段錯誤﹕/u/b/blazakira/bonzee/room/q01.c line 57: Redeclaration of function init. <===
//　　　編譯時段錯誤﹕/u/b/blazakira/bonzee/room/q01.c line 102: Redeclaration of function do_check. <===
//兩個檔案不能重複相同的函數名稱 如：init & do_check

void create ()
{
  set ("short", "林間小徑");
  set ("long", @LONG
你進入林間小徑沒多久，你發現了一座小池塘，也許這裡就是
少林寺的和尚平日取水飲用的地方。當你口渴的時候，或許你可以
停下腳步來喝一口水解渴。隱隱地，你聽見從少林寺的方向傳來一
陣陣的誦經梵音，沒想到這麼遠的距離竟讓你修煉多年堅毅的意志
稍稍鬆動，你深深感受到少林寺的佛法無邊。

　　根據傳言以及你的判斷，前方不遠就是所謂的門派聯盟的臨時
駐地。但是你卻看到一群人鬼鬼祟祟、形跡可疑地在聯盟駐地前排
迴。

LONG);
  set("item_desc", ([ /* sizeof() == 2 */
    "小池塘"   : "池塘中央隱隱有股水流緩緩冒出，聽說這裡就是少林寺所不為外人所知的秘密靈泉(Spirit spring)。\n",
    "spirit spring" : "嘗起來似乎沒有傳聞中起死回生的能力，不過隱隱感受得出身體中有股淡淡的暖流流轉經脈中但不明顯。\n",
  ]));
//  set("no_auc", 1);
//  set("light_up", 1);
  set("outdoors", "/u/b");
  set("no_transmit",1);
  set("exits", ([ /* sizeof() == 2 */
    "north" : __DIR__"q21.c",
	"east" : __DIR__"q02.c",
    "west" : __DIR__"q04.c",
	]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/b0_obj_pond.c" : 1,
  __DIR__"npc/junkman.c" : 1, //拾荒老頭
  ]));
  set ("資源/液體", ([/*
       "種類" : "水",
       "名稱" : "清水",
       "止渴" : 30*/
//因應挑水quest而設立獨立的液體
       "種類" : "靈泉",
       "名稱" : "靈水",
       "止渴" : 20
  ]) );
  setup();
}
//測試是否可以阻擋移動之npc
int valid_leave(object me, string dir)
{
	if (dir=="east" && me->query_temp("quests/bonze/mob") == 1) //如果要往east離開 且 有mark ("quests/bonze/mob") 時 阻擋之!
//	if(!wizardp(me)) //本次設定只針對npc 所以不影響巫師行動
		return notify_fail("STOP!\n");
	return ::valid_leave(me,dir); //為valid_leave(me,dir)函數的結尾
}
