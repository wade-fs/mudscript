inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
        set_name(YEL + "木牷塊" + NOR,({"wood stone","stone"}));
        set_weight(10);
        if(clonep())
                set_default_object(__FILE__);
        else
        {
        set("value",10000);
        set("unit","堆");
        set("base_unit","塊");
        set("long",
"一個長條圓筒狀的木塊～
看起來似乎是某一個木雕左手(left-head)的一部份～
謠傳如果將此物放置於(place)原本的位置，就會
被帶到某一個奇妙的地方。
\n");
        }
	set_amount(1);
        setup();
}

void init()
{
add_action("do_lock","lock");
add_action("do_place","place");
}

int do_lock(string arg)
{
object me,env;
        me=this_player();
        env=environment(me);
        if(!arg || arg!="left-head")
                return 0;
        if(!env->query("wood-area") || !env->query("evil-area") || !me->query_temp("evil/king/statue_search_wood"))
                return notify_fail("你眼前沒有任何東西可以符合你手上拿的木牷塊，所以不需要鎖定。\n");
        me->set_temp("evil/king/lock-left",1);
        tell_object(me,"你將手上拿的這塊木牷塊鎖定於木像的左手部位。\n");
return 1;
}


int do_place(string arg)
{
object me,env;
        me=this_player();
        env=environment(me);
        if(!arg || arg!="木像")
                return 0;
        if(!env->query("wood-area") || !me->query_temp("evil/king/statue_search_wood") || !env->query("evil-area"))
                return notify_fail("你找不到可以放置的地方。\n");
        if( !me->query_temp("evil/king/left-head") )
        {
                message_vision("$N不曉得要將$n往哪擺\。\n",me,this_object());
                tell_object(me,"(請先鎖定[lock]欲將放置的部位。)\n");
                return notify_fail("你突然覺得自己好像傻瓜。\n");
        }
        message_vision(YEL + "$N將$n放置於木像的左手部位。

喀～的一聲，木像突然開始活動了起來～

一瞬間～木像展開雙手將$N整個人抱住，只見到$N整個人融入了木像內，消失不見～

\n" + NOR,me,this_object());
        me->delete_temp("evil/king/lock-left");
        me->delete_temp("evil/king/statue_search_wood");
        me->move(__DIR__"k-02");
        message_vision("$N突然出現在這。\n",me);
	add_amount(-1);
        return 1;
}
