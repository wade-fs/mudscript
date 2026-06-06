inherit ROOM;
#include <ansi.h>
void create ()
{
set ("short","紫光之扉");
set("long",@LONG
初到這裡，面前立刻浮現一個巨大身影，此人身長九尺，重於百斤，
此人是當今天下四絕高手之一的虎神--孫虎臣，只見他以家傳地虎護身勁
力抗此地異常炎熱的高溫，煞是大耗精元，若要一敗四絕高手以得名聲，
現在就是最好的機會了。
LONG);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 2 */
        "south"     : __DIR__"room32",
        "northeast" : __DIR__"room36",
      ]));
        set("objects", ([ /* sizeof() == 1 */
        "/open/magic_palace/npc/4-4.c" : 1,
      ]));
        setup();
}

void init()
{
	add_action("do_catch","catch");
}

int do_catch(string str)
{
    object me = this_player();
    object shiun = present("Tiger Shiun");
    if(shiun)
    {
    message_vision(HIW"\n孫虎臣冷笑道：「這點小技倆在我面前是行不通的。」\n"NOR,me);
    me->start_busy(2);
    shiun->kill_ob(me);
    }
    return 1;
}

int valid_leave(object me,string dir)
{
	object obj = present("Tiger Shiun");
        if( dir == "northeast" )
        {
        	if(obj)  return notify_fail(HIY"孫虎臣"HIW"笑道:『來來來，先討教幾招再說!!』\n"NOR);
        }

return 1;
}
