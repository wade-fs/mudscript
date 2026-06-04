inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", HIM + "過去時空" + NOR + " 山坡小徑");
  set ("long", @LONG
你現在正走在一條山坡小徑上﹐東邊不遠處可以望見水煙閣琉璃色的
屋瓦﹐小徑東北是一道白石階梯通往山巔的虹台﹐往西則是「水煙十景」
之中最有名的虹谷斷崖﹐小徑旁立著一個七、八尺高的石碑(stone)。

LONG);
  set("outdoors", "cele");
  set("exits", ([ /* sizeof() == 1 */
  "east" : "/d/cele/path1",
  "west"  : "/d/cele/path3",
]));

        set("item_desc", ([ /* sizeof() == 1 */
  "stone" : "
石碑上面幾個蒼勁古樸的字寫道﹕虹谷石台﹐乙丑年
水煙閣第六代 閣主 關雨樓 立。
你仔細一看﹐這幾個字跡絲毫沒有斧鑿痕跡﹐竟像是題字的人直接
用手指在岩石上寫出來一般。",
]));
        set("no_clean_up", 0);

        setup();

}



